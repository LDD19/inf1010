//
// Created by Gabriel Bernard
//

#include "PixelCouleur.h"


PixelCouleur::PixelCouleur() : Pixel(TypePixel::Couleur) {
	donnee_[Couleur::R] = donnee_[Couleur::G] = donnee_[Couleur::B] = VALEUR_MIN_PIXEL;
}

PixelCouleur::PixelCouleur(const unchar& r, const unchar& g, const unchar& b) : Pixel(TypePixel::Couleur) {
    donnee_[Couleur::R] = testPixel(r);
    donnee_[Couleur::G] = testPixel(g);
    donnee_[Couleur::B] = testPixel(b);
}

PixelCouleur::~PixelCouleur() {}

unchar PixelCouleur::retournerR() const {
	return donnee_[Couleur::R];
}

unchar PixelCouleur::retournerG() const {
    return donnee_[Couleur::G];
}

unchar PixelCouleur::retournerB() const {
    return donnee_[Couleur::B];
}

unsigned int PixelCouleur::somme() const {
	unsigned int somme = donnee_[Couleur::R] + donnee_[Couleur::G] + donnee_[Couleur::B];
	return somme;
}

bool PixelCouleur::convertirPixelBN() const {
	unsigned int moyenne = somme() / 3;
	return moyenne > 127;
}

unchar PixelCouleur::convertirPixelGris() const {
	return somme() / 3;
}

void PixelCouleur::modifierTeinteRouge(unchar d) {
	donnee_[Couleur::R] = d;
}
void PixelCouleur::modifierTeinteVert(unchar d) {
	donnee_[Couleur::G] = d;
}
void PixelCouleur::modifierTeinteBleue(unchar d) {
	donnee_[Couleur::B] = d;
}

bool PixelCouleur::operator==(const PixelCouleur& pixel) const {
	return (pixel.type_ == type_ &&
			pixel.retournerR() == this->retournerR() &&
            pixel.retournerG() == this->retournerG() &&
            pixel.retournerB() == this->retournerB());
}