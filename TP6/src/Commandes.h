#ifndef COMMANDES_H
#define COMMANDES_H

#include <QImage>

#include "InterfaceCommande.h"

/**
 * Cette classe définit une commande mettant une image en négatif.
 */
class MettreEnNegatif : public InterfaceCommande {
public:
    /**
     * Constructeur par paramètres.
     *
     * @param image L'image à convertir en négatif.
     */
    explicit MettreEnNegatif(QImage* image) :
        image_(image) {

    }

    /**
     * Destructeur.
     */
    virtual ~MettreEnNegatif() {

    }

    /************************
     * Méthodes Surchargées *
     ************************/

    virtual void Executer() {
        image_->invertPixels();
    }

    virtual void AnnulerCommande() {
        image_->invertPixels();
    }
private:
    /** L'image à convertir. */
    QImage* image_;
};

/**
 * Cette classe définie une commande que met l'image en gris.
 */
class ConvertirEnGris : public InterfaceCommande {
public:
    /**
     * Constructeur par paramètres.
     *
     * @param image L'image à convertir en gris.
     */
    explicit ConvertirEnGris(QImage* image) :
        image_(image),
        originale_(*image) {
        gris_ = originale_.convertToFormat(QImage::Format_Grayscale8);
    }

    /**
     * Destructeur.
     */
    virtual ~ConvertirEnGris() {

    }

    /************************
     * Méthodes Surchargées *
     ************************/

    virtual void Executer() {
        *image_ = gris_;
    }

    virtual void AnnulerCommande() {
        *image_ = originale_;
    }
private:
    /** L'image à convertir. */
    QImage* image_;

    /** L'image grise. */
    QImage gris_;

    /** Une copie de l'image originale. */
    QImage originale_;
};

/**
 * Cette classe définie une commande qui met l'image en noir et blanc.
 */
class ConvertirEnNoirEtBlanc : public InterfaceCommande {
public:
    /**
     * Constructeur par paramètres.
     *
     * @param image L'image à convertir en noir et blanc.
     */
    explicit ConvertirEnNoirEtBlanc(QImage* image) :
        image_(image),
        originale_(*image) {
        noirblanc_ = originale_.convertToFormat(QImage::Format_Mono);
    }

    /**
     * Destructeur.
     */
    virtual ~ConvertirEnNoirEtBlanc() {

    }

    /************************
     * Méthodes Surchargées *
     ************************/

    virtual void Executer() {
        *image_ = noirblanc_;
    }

    virtual void AnnulerCommande() {
        *image_ = originale_;
    }
private:
    /** L'image à convertir. */
    QImage *image_;

    /** L'image en noir et blanc. */
    QImage noirblanc_;

    /** Une copie d el'image originale. */
    QImage originale_;
};

#endif
