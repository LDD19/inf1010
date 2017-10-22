/**************************************************
 * Titre: Travail pratique #3 - Pixel.h
 * Date:22 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#ifndef PIXEL_H
#define PIXEL_H

#include <stdint.h>

#include "Const.h"
#include "TypePixel.h"

/**
 * Cette classe définie un pixel de base.
 *
 * TODO: Implémenter des fonctions statiques pour tester la valeur du pixel.
 */
class Pixel
{
public:
    /**
     * Constructeur par défaut.
     */
    Pixel();

    /**
     * Constructeur par paramètres.
     *
     * @param type Le type du pixel.
     */
    Pixel(TypePixel type);

    /**
     * Destructeur.
     */
    ~Pixel();

    /**************
     * Accesseurs *
     **************/

    /**
     * Cette méthode retourne le type de pixel.
     *
     * @return Le type de pixel.
     */
    TypePixel getType() const;

    /************************
     * Opérateurs surchagés *
     ************************/

    bool operator==(const Pixel& pixel) const;

protected:
    /** Le type du pixel. */
    TypePixel type_;
};

#endif
