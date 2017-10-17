#ifndef PIXEL_COULEUR_H
#define PIXEL_COULEUR_H

#include <stdint.h>

#include "Const.h"
#include "Pixel.h"

/* La taille des données des pixels. */
const int TAILLE_PIXEL_COULEUR = 3;

/**
 * Cette ennumération définie l'index des pixels.
 */
enum Couleur {
    /* L'index de la couleur rouge. */
    R = 2,

    /* L'index de la couleur vert. */
    G = 1,

    /* L'index de la couleur bleu. */
    B = 0,
};

class PixelCouleur : public Pixel
{
public:
    /**
     * Constructeur par défaut.
     */
    PixelCouleur();

    /**
     * Constructeur par paramètres.
     *
     * @param r La valeur de la composante rouge.
     * @param g La valeur de la composante vert.
     * @param b La valeur de la composante bleu.
     */
    PixelCouleur(uint8_t r, uint8_t g, uint8_t b);

    /**
     * Constructeur par paramètres.
     *
     * @param valeurs Les valeurs des pixels.
     */
    PixelCouleur(uint8_t* valeurs);

    /**
     * Destructeur.
     */
    ~PixelCouleur();

    /**
     * Cette méthode convertit le pixel de couleur en un pixel noir et blanc.
     *
     * @return La valeur du pixel noir et blanc.
     */
    bool convertirPixelBN() const;

    /**
     * Cette méthode convertit le pixel de couleur en un pixel gris.
     *
     * @return La valeur du pixel gris.
     */
    uint8_t convertirPixelGris() const;

    /*************
     * Mutateurs *
     *************/

    /**
     * Cette méthode modifie la valeur du pixel rouge.
     *
     * @param r La nouvelle valeur du pixel rouge.
     */
    void modifierTeinteR(uint8_t r);

    /**
     * Cette méthode modifie la valeur du pixel vert.
     *
     * @param g La nouvelle valeur du pixel vert.
     */
    void modifierTeinteG(uint8_t g);

    /**
     * Cette méthode modifie la valeur du pixel bleu.
     *
     * @param b La nouvelle valeur du pixel bleu.
     */
    void modifierTeinteB(uint8_t b);

    /**************
     * Accesseurs *
     **************/

    /**
     * Cette méthode retourne la valeur du pixel rouge.
     *
     * @return La valeur du pixel rouge.
     */
    uint8_t retournerR() const;

    /**
     * Cette méthode retourne la valeur du pixel vert.
     *
     * @return La valeur du pixel vert.
     */
    uint8_t retournerG() const;

    /**
     * Cette méthode retourne la valeur du pixel bleu.
     *
     * @return La valeur du pixel bleu.
     */
    uint8_t retournerB() const;

    /*************************
     * Opérateurs surchargés *
     *************************/

    bool operator==(const PixelCouleur& pixel) const;

private:
    /** Les composantes du pixel. */
    uint8_t donnee_[TAILLE_PIXEL_COULEUR];
};

#endif
