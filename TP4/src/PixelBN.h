/**************************************************
 * Titre: Travail pratique #3 - PixelBN.h
 * Date:22 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#ifndef PIXEL_BN_H
#define PIXEL_BN_H

#include "Pixel.h"
#include "TypePixel.h"

class PixelBN: public Pixel
{
public:
    /**
     * Constructeur par défaut.
     */
    PixelBN();

    /**
     * Constructeur par paramètres.
     *
     * @param p La valeur du pixel.
     */
    PixelBN(bool p);

    /**
     * Destructeur.
     */
    ~PixelBN();

    /**
     * Cette méthode convertit le pixel blanc et noir en pixel de couleur.
     * L'appeleur de cette méthode doit prendre la responsabilité de libérer la
     * mémoire allouée.
     *
     * @param Un pointeur vers les composantes du pixel de couleur.
     */
    uint8_t* convertirPixelCouleur() const;

    /**
     * Cette méthode convertit le pixel blanc et noir en pixel gris.
     *
     * @return La valeur du pixel gris.
     */
    uint8_t convertirPixelGris() const;

    /*************
     * Mutateurs *
     *************/

    void modifierDonnee(bool donnee);

    /**************
     * Accesseurs *
     **************/

    bool obtenirDonnee() const;

    /************************
     * Opérateurs Surchagés *
     ************************/

    bool operator==(const PixelBN& pixel) const;

private:
    /** La valeur du pixel. */
    bool donnee_;
};

#endif
