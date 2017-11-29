#ifndef IMAGE_H
#define IMAGE_H

#include <QObject>
#include <QString>
#include <QImage>
#include <QPointer>
#include <QFileInfo>
#include <string>
#include <memory>

#include "InterfaceCommande.h"
#include "UndoRedo.h"

/**
 * Cette classe définit une image dans notre application.
 */
class Image : public QObject {
    Q_OBJECT
public:
    /**
     * Constructeur par défault.
     */
    Image();

    /**
     * Constructeur par paramètres.
     *
     * @param chemin Le chemin vers le fichier de l'image.
     */
    Image(const std::string& chemin);

    /**
     * Constructeur par paramètres.
     *
     * @param chemin Le chemin vers le fichier de l'image.
     */
    Image(const QString& chemin);

    /**
     * Cette fonction gère l'ouverture d'une image.
     *
     * @param chemin Le chemin du fichier de l'image à ouvrir.
     *
     * @return Si l'image fut ouverte, `true`, sinon `false`.
     */
    bool ouvrirImage(const QString &chemin);
    
    /**
     * Cette fonction gère l'enregistrement d'une image.
     * 
     * @param chemin Le chemin du fichier de l'image à enregistrer.
     * 
     * @return Si l'image fut enregistrée, `true`, sinon `false`.
     */
    bool enregistrerImage(const QString &chemin);

    /**************
     * Accesseurs *
     **************/

    /**
     * Cette méthode retourne le nom du fichier de l'image.
     *
     * @return Le nom du fichier de l'image.
     */
    QFileInfo obtenirNomDuFichier() const;
signals:
    /**
     * Ce signal indique qu'un changement s'est effectué dans l'image.
     *
     * @param image L'image qui a été modifiée.
     */
    void changementImage(const QImage& image);
public slots:
    /**
     * Cette méthode gère un signal qui a pour but de convertir l'image
     * en nuance de gris.
     */
    void convertirEnNuanceDeGris();

    /**
     * Cette méthode gère un signal qui a pour but de convertir l'image en
     * noir et blanc.
     */
    void convertirEnNoirEtBlanc();

    /**
     * Cette méthode gère un signal qui a pour but de mettre l'image en
     * négatif.
     */
    void mettreEnNegatif();

    /**
     * Cette méthode gère un signal qui a pour but d'annuler la dernière
     * commande.
     */
    void undo();

    /**
     * Cette méthode gère un signal qui a pour but de reexécuter la
     * dernière commande.
     */
    void redo();
private:
    /** L'image en tant que telle. */
    QImage image_;

    /** Les informations du fichier de l'image. */
    QFileInfo fichier_;

    /** L'historique des commandes exécutées. */
    UndoRedo undoRedo_;
};

#endif
