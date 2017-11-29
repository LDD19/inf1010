#include <QImageReader>
#include <QMessageBox>
#include <QGuiApplication>
#include <QDir>

#include "Image.h"
#include "Commandes.h"
#include "ExceptionMauvaisFormatimage.h"

using namespace std;

Image::Image() {

}

Image::Image(const std::string& chemin) {
    /* on ouvre l'image */
    ouvrirImage(QString::fromStdString(chemin));
}

Image::Image(const QString& chemin) {
    /* on ouvre l'image */
    ouvrirImage(chemin);
}

bool Image::ouvrirImage(const QString& chemin) {
    /* on tente de lire l'image */
    QImageReader reader(chemin);
    reader.setAutoTransform(true);
    const QImage image= reader.read();

    /* on s'assure que l'image fut bien lue */
    if(image.isNull()) {
        /* on génère un message d'erreur */
        QString path = QDir::toNativeSeparators(chemin);
        QString error = reader.errorString();
        QString msg = tr("Impossible de lire l'image %1: %2").arg(path, error);

        /* on lance l'exception */
        ExceptionMauvaisFormatImage(msg).raise();
    }

    /* l'image fut lue comme prévu */
    image_ = image;
    fichier_ = QFileInfo(chemin);
    undoRedo_.clear();
    
    /* on émet un signal pour avertir la vue que l'image a changée */
    emit changementImage(image);

    return true;
}

bool Image::enregistrerImage(const QString &chemin) {
    /* on enregistre l'image */
    image_.save(chemin);

    return true;
}

QFileInfo Image::obtenirNomDuFichier() const {
    return fichier_;
}

void Image::convertirEnNuanceDeGris() {
    /* on exécute la commande */
    shared_ptr<InterfaceCommande> c(new ConvertirEnGris(&image_));
    c->Executer();
    undoRedo_.insererDansUndosRedos(c);

    /* on émet un signal pour avertir la vue que l'image a changée */
    emit changementImage(image_);
}

void Image::convertirEnNoirEtBlanc() {
    /* on exécute la commande */
    shared_ptr<InterfaceCommande> c(new ConvertirEnNoirEtBlanc(&image_));
    c->Executer();
    undoRedo_.insererDansUndosRedos(c);

    /* on émet un signal pour avertir la vue que l'image a changée */
    emit changementImage(image_);
}

void Image::mettreEnNegatif() {
    /* on exécute la commande */
    shared_ptr<InterfaceCommande> c(new MettreEnNegatif(&image_));
    c->Executer();
    undoRedo_.insererDansUndosRedos(c);

    /* on émet un signal pour avertir la vue que l'image a changée */
    emit changementImage(image_);
}

void Image::undo() {
    /* on annule la dernière modification */
    undoRedo_.undo();

    /* on émet un signal pour avertir la vue que l'image a changée */
    emit changementImage(image_);
}

void Image::redo() {
    /* on reexécute la dernière modification annulée */
    undoRedo_.redo();

    /* on émet un signal pour avertir la vue que l'image a changée */
    emit changementImage(image_);
}
