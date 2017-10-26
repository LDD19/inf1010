/**************************************************
 * Titre: Travail pratique #3 - PixelGris.h
 * Date:22 Octobre 2017
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

    /**
	 * Cette méthode convertit le pixel gris en pixel blanc et noir.
	 *
	 * @return La valeur du pixel noir et blanc.
	 */
	bool convertirPixelBN() const;

	/**
	 * Cette méthode convertit le pixel gris en un pixel de couleur. L'appeleur
     * de cette méthode doit prendre le devoir de libérer la mémoire allouée.
	 *
	 * @return Un pointeur vers les composantes du pixel de couleur.
	 */
	uint8_t* convertirPixelCouleur() const;

	/*************
	 * Mutateurs *
	 *************/


    /**
     * Cette méthode modifie la valeur du pixel.
     *
     * @param donnee La nouvelle valeur du pixel.
     */
    void modifierDonnee(uint8_t donnee);

	/**************
	 * Accesseurs *
	 **************/

    /**
     * Cette méthode retourne la valeur du pixel.
     *
     * @return La valeur du pixel.
     */
	uint8_t obtenirDonnee() const;

	/************************
	 * Opérateurs suchargés *
	 ************************/

	bool operator==(const PixelGris& pixel) const;

private:
    /** La valeur du pixel gris. */
	uint8_t donnee_;
};

#endif
