/**************************************************
 * Titre: Travail pratique #5 - PixelCouleur.h
 * Date:28 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
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
    /** L'index de la couleur rouge. */
    R = 2,

    /** L'index de la couleur vert. */
    G = 1,

    /** L'index de la couleur bleu. */
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
     * Destructeur.
     */
    ~PixelCouleur();

    /***********************
     * Méthode surchargées *
     ***********************/

    void mettreEnNegatif();

    Pixel* retournerCopieProfonde() const;

    bool convertirPixelBN() const;

    uint8_t convertirPixelGris() const;

    void convertirPixelCouleur(uint8_t* v) const;

    virtual bool estMajoriteRouge() const;

    virtual bool estMajoriteVert() const;

    virtual bool estMajoriteBleu() const;

    virtual double retournerIntensiteMoyenne() const;

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

    /*************************
     * Accesseurs surchargés *
     *************************/

    virtual uint8_t retournerR() const;

    virtual uint8_t retournerG() const;

    virtual uint8_t retournerB() const;

private:
    /** Les composantes du pixel. */
    uint8_t donnee_[TAILLE_PIXEL_COULEUR];
};

#endif
