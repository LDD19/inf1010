//
// Created by Gabriel Bernard
//

#ifndef TP3_PIXEL_GRIS_H
#define TP3_PIXEL_GRIS_H

#include "Pixel.h"

class PixelGris :
	public Pixel
{
public:
	PixelGris();
	PixelGris(unsigned int);
	~PixelGris();

	bool convertirPixelBN() const;
	unchar* convertirPixelCouleur() const;

	unsigned int obtenirDonnee() const;

	bool operator==(const PixelGris& pixel) const;
private:
	unchar donnee_;
};

#endif // TP3_PIXEL_GRIS_H