//
// Created by Gabriel Bernard
//

#include "PixelBN.h"


PixelBN::PixelBN() : Pixel(TypePixel::NoireBlanc) {
	donnee_ = false;
}

PixelBN::PixelBN(bool p) : Pixel(TypePixel::NoireBlanc) {
	donnee_ = p;
}

PixelBN::~PixelBN() {}

unchar* PixelBN::convertirPixelCouleur() const {
    unchar valeur = (unchar)VALEUR_MIN_PIXEL;
    if(donnee_) {
        valeur = (unchar)VALEUR_MAX_PIXEL;
    }

	unchar* ret = new unchar[3];
	ret[0] = ret[1] = ret[2] = valeur;

	return ret;
}

unchar PixelBN::convertirPixelGris() const {
	return donnee_ ? VALEUR_MAX_PIXEL : VALEUR_MIN_PIXEL;
}

bool PixelBN::obtenirDonnee() const {
	return donnee_;
}

bool PixelBN::operator==(const PixelBN& pixel) const {
    return (pixel.type_ == type_ && pixel.obtenirDonnee() == donnee_);
}