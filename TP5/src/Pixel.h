/**************************************************
 * Titre: Travail pratique #5 - Pixel.h
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

    /**
     * Cette méthode détermine si le pixel est majoritairement rouge.
     *
     * @return Si le pixel est majoritairement rouge, `true`, sinon `false`.
     */
    virtual bool estMajoriteRouge() const = 0;

    /**
     * Cette méthode détermine si le pixel est majoritairement vert.
     *
     * @return Si le pixel est majoritairement vert, `true`, sinon `false`.
     */
    virtual bool estMajoriteVert() const = 0;

    /**
     * Cette méthode détermine si le pixel est majoritairement bleu.
     *
     * @return Si le pixel est majoritairement bleu, `true`, sinon `false`.
     */
    virtual bool estMajoriteBleu() const = 0;

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

    /**
     * Cette méthode retourne l'intensité moyenne des trois couleurs
     * normalisées entre 0 et 1.
     *
     * @return L'intensité moyenne des trois couleurs.
     */
    virtual double retournerIntensiteMoyenne() const = 0;

    /************************
     * Opérateurs surchagés *
     ************************/

    virtual bool operator==(const Pixel& pixel) const;
};

#endif
