//
// Created by Gabriel Bernard
//

#ifndef TP3_PIXELBN_H
#define TP3_PIXELBN_H

#include "Pixel.h"
#include "TypePixel.h"

class PixelBN: public Pixel
{
public:
	PixelBN();
	PixelBN(bool p);
	~PixelBN();

	unchar* convertirPixelCouleur() const;
	unchar convertirPixelGris() const;

	bool obtenirDonnee() const;

	bool operator==(const PixelBN& pixel) const;

private:
	bool donnee_;
};

#endif // TP3_PIXELBN_H