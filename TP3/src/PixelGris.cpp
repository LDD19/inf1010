#include "PixelGris.h"

PixelGris::PixelGris() : Pixel(TypePixel::NuanceDeGris) {
    donnee_ = 0;
}

PixelGris::PixelGris(uint8_t v) : Pixel(TypePixel::NuanceDeGris) {
    donnee_ = v;
}

PixelGris::~PixelGris() {

}

bool PixelGris::convertirPixelBN() const {
    if(donnee_ > 127)
        return true;
    else
        return false;
}

uint8_t* PixelGris::convertirPixelCouleur() const {
    /* on alloue la mémoire */
    uint8_t* pixels = new uint8_t[3];

    /* on initialise les pixels */
    pixels[0] = donnee_;
    pixels[1] = pixels[0];
    pixels[2] = pixels[0];

    return pixels;
}

void PixelGris::modifierDonnee(uint8_t donnee) {
    donnee_ = donnee;
}

uint8_t PixelGris::obtenirDonnee() const {
    return donnee_;
}

bool PixelGris::operator==(const PixelGris& pixel) const {
    /* le pixel de base doit être le même */
    if(!Pixel::operator==(pixel))
        return false;

    /* la valeur du pixel doit être la même */
    if(pixel.obtenirDonnee() != obtenirDonnee())
        return false;

    return true;
}
