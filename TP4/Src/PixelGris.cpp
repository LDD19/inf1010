//
// Created by Gabriel Bernard
//

#include "PixelGris.h"

PixelGris::PixelGris() : Pixel(TypePixel::NuanceDeGris) {}

PixelGris::PixelGris(unsigned int donnee) : Pixel(TypePixel::NuanceDeGris) {
    if(donnee < VALEUR_MAX_PIXEL) {
        donnee_ = donnee;
    } else {
        donnee_ = VALEUR_MAX_PIXEL;
    }
}

PixelGris::~PixelGris() {}

unchar* PixelGris::convertirPixelCouleur() const {
	unchar *ret = new unchar[3];
	ret[0] = ret[1] = ret[2] = donnee_;
	return ret;
}

bool PixelGris::convertirPixelBN() const {
	return donnee_ > 127;
}

unsigned int PixelGris::obtenirDonnee() const {
	return donnee_;
}

bool PixelGris::operator==(const PixelGris &pixel) const {
    return (pixel.getType() == type_ &&
            pixel.obtenirDonnee() == donnee_);
}