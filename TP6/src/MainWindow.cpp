/**************************************************
 * Titre: Travail pratique #6 - MainWindow.cpp
 * Date: 3 Décembre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#include <QFileInfo>
#include <iostream>
#include <string>

#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "ExceptionMauvaisFormatimage.h"

using namespace std;

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    imageLabel_ = new QLabel();
    ui->setupUi(this);
    creeActions();
    initUI();
    initConnections();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::ouvrirImage() {
    /* on crée un dialogue pour ouvrir une image */
    QFileDialog dialog(this, tr("Ouvrir une image"));
    fileExplorer(dialog);

    try {
        /* on demande un fichier à l'utilisateur */
        if(dialog.exec() != QDialog::Accepted) return;

        /* on ouvre l'image */
        image_.ouvrirImage(dialog.selectedFiles().first());

        /* on permet l'enregistrement de l'image */
        actionEnregistrerSous_->setEnabled(true);
    } catch(const ExceptionMauvaisFormatImage& ex) {
        afficherMessage(ex.what());
    }
}

void MainWindow::enregistrerImage() {
    /* on demande un fichier JPEG à l'utilisateur */
    QString filename = QFileDialog::getSaveFileName(
        this,
        tr("Enregistrer l'image"),
        tr(""),
        tr("JPEG (*.jpg);;All Files (*)")
    );

    /* on ajoute l'extension */
    filename.append(".jpg");

    /* on enregistre l'image */
    if(!filename.isEmpty())
        image_.enregistrerImage(filename);
}

void MainWindow::updateImage(QImage image){
    static bool first = true;

    /* on montre l'image */
    QPixmap pixmap = QPixmap::fromImage(image);
    imageLabel_->resize(pixmap.size());
    imageLabel_->setPixmap(pixmap);

    /* en update le statut */
    const QString message = tr("Image \"%1\", %2x%3, Profondeur: %4")
            .arg(QDir::toNativeSeparators(
                image_.obtenirNomDuFichier().filePath()))
            .arg(image.width())
            .arg(image.height())
            .arg(image.depth());
    ui->statusBar->showMessage(message);

    /* on active les boutons à la première ouverture */
    if(first) {
        activateButtons();
        first = false;
    }
}

void MainWindow::updateTableViewWidget(QImage image) {
    tableWidget_->setItem(0, 1, new QTableWidgetItem(image_.obtenirNomDuFichier().baseName()));
    tableWidget_->setItem(1, 1, new QTableWidgetItem(QString::number(image.width())));
    tableWidget_->setItem(2, 1, new QTableWidgetItem(QString::number(image.height())));
}


void MainWindow::afficherMessage(QString msg) {
    QMessageBox message(0);
    message.setText(msg);
    message.exec();
}

void MainWindow::about() {
    string msg = "Poly GIMP est une application QT simple permettant de ";
    msg.append("lire une image et de la transformer en noir et blanc, nuance ");
    msg.append("de gris ou negatif.\n©INF1010 automne 2017");
    afficherMessage(QString::fromStdString(msg));
}

void MainWindow::creeActions() {
    /* action fichier + ouvrir */
    actionOuvrir_ = new QAction(tr("Ouvrir"), this);
    actionOuvrir_->setShortcut(QKeySequence::Open);

    /* action fichier + enregistrer sous */
    actionEnregistrerSous_ = new QAction(tr("Enregistrer sous"), this);
    actionEnregistrerSous_->setEnabled(false);
    actionEnregistrerSous_->setShortcut(QKeySequence::SaveAs);

    /* action aide + à propos */
    actionAPropos_ = new QAction(tr("À propos"), this);

    /* action édition + undo */
    undo_ = new QAction(tr("Undo"), this);
    undo_->setShortcut(QKeySequence::Undo);

    /* action édition + redo */
    redo_ = new QAction(tr("Redo"), this);
    redo_->setShortcut(QKeySequence::Redo);
}

void MainWindow::initConnections() {
    /* on connecte le signal pour ouvrir une image */
    QObject::connect(actionOuvrir_, SIGNAL(triggered()), this, SLOT(ouvrirImage()));
    
    /* on connecte le signal pour enregistrer une image */
    QObject::connect(actionEnregistrerSous_, SIGNAL(triggered()), this, SLOT(enregistrerImage()));
    
    /* on connecte le signal pour montrer le à propos */
    QObject::connect(actionAPropos_, SIGNAL(triggered()), this, SLOT(about()));

    /* on connecte le signal pour annuler une commande */
    QObject::connect(undo_, SIGNAL(triggered()), &image_, SLOT(undo()));

    /* on connecte le signal pour reexécuter une commande */
    QObject::connect(redo_, SIGNAL(triggered()), &image_, SLOT(redo()));
    
    /* on connecte le signal de mise à jour de l'image */
    QObject::connect(&image_, SIGNAL(changementImage(QImage)), this, SLOT(updateImage(QImage)));
    QObject::connect(&image_, SIGNAL(changementImage(QImage)), this, SLOT(updateTableViewWidget(QImage)));

    /* on connecte le signal pour changer l'image ne noir et blanc */
    QObject::connect(boutonNB_, SIGNAL(released()), &image_, SLOT(convertirEnNoirEtBlanc()));
    
    /* on connecte le signal pour changer l'image en gris */
    QObject::connect(boutonGris_, SIGNAL(released()), &image_, SLOT(convertirEnNuanceDeGris()));

    /* on connecte le signal pour changer l'image en négatif */
    QObject::connect(boutonNegatif_, SIGNAL(released()), &image_, SLOT(mettreEnNegatif()));
}

void MainWindow::initUI() {
    /* on donne une taille plus appropriée à l'interface */
    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);

    /* on centre l'interface dans l'écran */
    QSize newSize(this->width(), this->height());
    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            newSize,
            qApp->desktop()->availableGeometry()
        )
    );

    /* on donne accès à la table */
    tableWidget_ = ui->tableWidget;

    /* on configure la scrollbar */
    imageScrollArea_ = ui->ImageScrollArea;
    imageScrollArea_->setBackgroundRole(QPalette::Dark);

    /* on ajoute le menu fichier à la barre de menu principale */
    QMenu* filemenu = menuBar()->addMenu(tr("&Fichier"));
    filemenu->addAction(actionOuvrir_);
    filemenu->addAction(actionEnregistrerSous_);

    /* on ajoute le menu edition à la barre de menu principale */
    QMenu* editmenu = menuBar()->addMenu(tr("&Édition"));
    editmenu->addAction(undo_);
    editmenu->addAction(redo_);

    /* on ajoute le menu aide à la barre de menu principale */
    QMenu* aboutmenu = menuBar()->addMenu(tr("&Aide"));
    aboutmenu->addAction(actionAPropos_);

    /* on obtient la boite de bouton */
    groupBox_ = ui->groupBox;

    /* on obtient le layout de la boite de bouton */
    QLayout *groupBoxLayout = groupBox_->layout();

    /* on crée le bouton noir et blanc */
    boutonNB_ = new QPushButton("Noir et Blanc");
    boutonNB_->setEnabled(false);

    /* on crée le bouton nuance de gris */
    boutonGris_ = new QPushButton("Nuance de Gris");
    boutonGris_->setEnabled(false);

    /* on crée le bouton négatif */
    boutonNegatif_ = new QPushButton("Négatif");
    boutonNegatif_->setEnabled(false);

    /* on ajoute les boutons à la boite */
    groupBoxLayout->addWidget(boutonNB_);
    groupBoxLayout->addWidget(boutonGris_);
    groupBoxLayout->addWidget(boutonNegatif_);

    /* on ajoute l'image au scroll area */
    imageScrollArea_->setWidget(imageLabel_);
}

void MainWindow::activateButtons() {
    boutonNB_->setEnabled(true);
    boutonGris_->setEnabled(true);
    boutonNegatif_->setEnabled(true);
}

void MainWindow::fileExplorer(QFileDialog &dialog) {
    /* on obtient les dossiers standards des images */
    const QStringList locations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);

    /* on définit le dossier par défaut du dialogue */
    if(locations.isEmpty())
        dialog.setDirectory(QDir::currentPath());
    else
        dialog.setDirectory(locations.last());

    /* on détermine les extensions d'images supportés par QT */
    QByteArrayList supported = QImageReader::supportedMimeTypes();

    /* on définit un filtre de fichier pour le dialogue */
    QStringList filters;
    foreach(const QByteArray &mimeType, supported)
        filters.append(mimeType);

    /* on ajoute ce filtre au dialogue */
    dialog.setMimeTypeFilters(filters);
}

