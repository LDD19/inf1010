/**************************************************
 * Titre: Travail pratique #4 - Pixel.h
 * Date:28 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#ifndef PIXEL_H
#define PIXEL_H

#include <stdint.h>

#include "Const.h"
#include "TypePixel.h"

/**
 * Cette classe définie un pixel de base.
 */
class Pixel
{
public:
    /**
     * Constructeur par défaut.
     */
    Pixel();

    /**
     * Destructeur.
     */
    virtual ~Pixel();

    /**
     * Cette méthode met le pixel en négatif.
     */
    virtual void mettreEnNegatif() = 0;

    /**
     * Cette méthode retourne une copie profonde du pixel.
     *
     * @return Un pointeur vers la copie du pixel.
     */
    virtual Pixel* retournerCopieProfonde() const = 0;

    /**
     * Cette méthode retourne la valeur blanc et noir du pixel.
     *
     * @return La valeur blanc et noir du pixel.
     */
    virtual bool convertirPixelBN() const = 0;

    /**
     * Cette méthode retourne la valeur grise du pixel.
     *
     * @return La valeur du pixel grise.
     */
    virtual uint8_t convertirPixelGris() const = 0;

    /**
     * Cette méthode retourne les teintes du pixel.
     *
     * @param v La buffer dans lequel on met les teintes.
     */
    virtual void convertirPixelCouleur(uint8_t* v) const = 0;

    /**************
     * Accesseurs *
     **************/

    /**
     * Cette méthode retourne la teinte rouge du pixel.
     *
     * @return La teinte rouge du pixel.
     */
    virtual uint8_t retournerR() const = 0;

    /**
     * Cette méthode retourne la teinte verte du pixel.
     *
     * @return La teinte verte du pixel.
     */
    virtual uint8_t retournerG() const = 0;

    /**
     * Cette méthode retourne la teinte bleu du pixel.
     *
     * @return La teinte bleu du pixel.
     */
    virtual uint8_t retournerB() const = 0;

    /************************
     * Opérateurs surchagés *
     ************************/

    virtual bool operator==(const Pixel& pixel) const;
};

#endif
