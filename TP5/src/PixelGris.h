/**************************************************
 * Titre: Travail pratique #5 - PixelGris.h
 * Date:28 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#ifndef PIXEL_GRIS_H
#define PIXEL_GRIS_H

#include <stdint.h>

#include "Const.h"
#include "Pixel.h"

class PixelGris : public Pixel
{
public:
    /**
     * Constructeur par défaut.
     */
    PixelGris();

    /**
     * Constructeur par paramètres.
     *
     * @param v La valeur du pixel gris.
     */
    PixelGris(uint8_t v);

    /**
     * Destructeur.
     */
    ~PixelGris();

    /************************
     * Méthodes surchargées *
     ************************/

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
     * Cette méthode modifie la valeur du pixel.
     *
     * @param donnee La nouvelle valeur du pixel.
     */
    void modifierDonnee(uint8_t donnee);

    /*************************
     * Accesseurs surchargés *
     *************************/

    virtual uint8_t retournerR() const;

    virtual uint8_t retournerG() const;

    virtual uint8_t retournerB() const;

private:
    /** La valeur du pixel gris. */
    uint8_t donnee_;
};

#endif
