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
     * Cette méthode retourne les valeurs couleurs du pixel.
     *
     * @param v Un pointeur vers les couleurs a modifier.
     */
    void convertirPixelCouleur(uint8_t* v) const;

    /************************
     * Méthodes surchargées *
     ************************/
    
    void mettreEnNegatif();

    Pixel* retournerCopieProfonde() const;

    bool convertirPixelBN() const;

    uint8_t convertirPixelGris() const;

    /*************
     * Mutateurs *
     *************/

    /**
     * Cette méthode modifie la valeur du pixel.
     *
     * @param donnee La nouvelle valeur du pixel.
     */
    void modifierDonnee(bool donnee);

    /*************************
     * Accesseurs surchargés *
     *************************/

    uint8_t retournerR() const;

    uint8_t retournerG() const;

    uint8_t retournerB() const;

private:
    /** La valeur du pixel. */
    bool donnee_;
};

#endif
