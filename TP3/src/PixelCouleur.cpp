#include "PixelCouleur.h"

PixelCouleur::PixelCouleur() : Pixel(TypePixel::Couleur) {
    donnee_[Couleur::R] = 0;
    donnee_[Couleur::G] = 0;
    donnee_[Couleur::B] = 0;
}

PixelCouleur::PixelCouleur(uint8_t r, uint8_t g, uint8_t b) : Pixel(TypePixel::Couleur) {
    donnee_[Couleur::R] = r;
    donnee_[Couleur::G] = g;
    donnee_[Couleur::B] = b;
}

PixelCouleur::PixelCouleur(uint8_t* valeurs) : Pixel(TypePixel::Couleur) {
    donnee_[Couleur::R] = valeurs[Couleur::R];
    donnee_[Couleur::G] = valeurs[Couleur::G];
    donnee_[Couleur::B] = valeurs[Couleur::B];
}

PixelCouleur::~PixelCouleur() {

}

bool PixelCouleur::convertirPixelBN() const {
    uint_t somme = 0;
    somme += retournerR();
    somme += retournerG();
    somme += retournerB();
    somme /= TAILLE_PIXEL_COULEUR;

    return (somme < UINT8_MAX/TAILLE_PIXEL_COULEUR);
}

uint8_t PixelCouleur::convertirPixelGris() const {
    uint_t somme = 0;
    somme += retournerR();
    somme += retournerG();
    somme += retournerB();
    somme /= TAILLE_PIXEL_COULEUR;

    return somme;
}

void PixelCouleur::modifierTeinteR(uint8_t r) {
    donnee_[Couleur::R] = r;
}

void PixelCouleur::modifierTeinteG(uint8_t g) {
    donnee_[Couleur::G] = g;
}

void PixelCouleur::modifierTeinteB(uint8_t b) {
    donnee_[Couleur::B] = b;
}

uint8_t PixelCouleur::retournerR() const {
    return donnee_[Couleur::R];
}

uint8_t PixelCouleur::retournerG() const {
    return donnee_[Couleur::G];
}

uint8_t PixelCouleur::retournerB() const {
    return donnee_[Couleur::B];
}

bool PixelCouleur::operator==(const PixelCouleur& pixel) const {
    /* le pixel de base d oit être le même */
    if(!Pixel::operator==(pixel))
        return false;

    /* la teinte rouge doit être identique */
    if(retournerR() != pixel.retournerR())
        return false;

    /* la teinte verte  doit être identique */
    if(retournerG() != pixel.retournerG())
        return false;

    /* la teinte bleu doit être identique */
    if(retournerB() != pixel.retournerB())
        return false;

    return true;
}
