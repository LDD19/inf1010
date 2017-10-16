#include "PixelBN.h"

PixelBN::PixelBN() : Pixel(TypePixel::NoireBlanc) {

}

PixelBN::PixelBN(bool p) : Pixel(TypePixel::NoireBlanc) {
    donnee_ = p;
}

PixelBN::~PixelBN() {

}

uint8_t* PixelBN::convertirPixelCouleur() const {
    /* on alloue la mémoire */
    uint8_t* pixels = new uint8_t[3];

    /* on iniitalise les pixels */
    pixels[0] = (donnee_?UINT8_MAX:0);
    pixels[1] = pixels[0];
    pixels[2] = pixels[0];

    return pixels;
}

uint8_t PixelBN::convertirPixelGris() const {
    return (donnee_?UINT8_MAX:0);
}

void PixelBN::modifierDonnee(bool donnee) {
    donnee_ = donnee;
}

bool PixelBN::obtenirDonnee() const {
    return donnee_;
}

bool PixelBN::operator==(const PixelBN& pixel) const {
    /* le pixel de base doit être le même */
    if(!Pixel::operator==(pixel))
        return false;

    /* la valeur du pixel doit être la même */
    if(pixel.obtenirDonnee() != obtenirDonnee())
        return false;

    return true;
}
