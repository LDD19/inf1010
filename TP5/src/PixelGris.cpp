/**************************************************
 * Titre: Travail pratique #4 - PixelGris.cpp
 * Date:28 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#include "PixelGris.h"
#include "PixelCouleur.h"

PixelGris::PixelGris() : Pixel() {
    donnee_ = 0;
}

PixelGris::PixelGris(uint8_t v) : Pixel() {
    donnee_ = v;
}


PixelGris::~PixelGris() {

}

void PixelGris::mettreEnNegatif() {
    donnee_ = UINT8_MAX-donnee_;
}

Pixel* PixelGris::retournerCopieProfonde() const {
    return new PixelGris(donnee_);
}

bool PixelGris::convertirPixelBN() const {
    if(donnee_ > 127)
        return true;
    else
        return false;
}

uint8_t PixelGris::convertirPixelGris() const {
    return donnee_;
}

void PixelGris::convertirPixelCouleur(uint8_t* v) const {
    v[Couleur::R] = donnee_;
    v[Couleur::G] = donnee_;
    v[Couleur::B] = donnee_;
}

bool PixelCouleur::estMajoriteRouge() const {
    return false;
}

bool PixelCouleur::estMajoriteVert() const {
    return false;
}

bool PixelCouleur::estMajoriteBleu() const {
    return false;
}

double PixelCouleur::retournerIntensiteMoyenne() const {
    return donnee_/((double) UINT8_MAX);
}

void PixelGris::modifierDonnee(uint8_t donnee) {
    donnee_ = donnee;
}

uint8_t PixelGris::retournerR() const {
    return donnee_;
}

uint8_t PixelGris::retournerG() const {
    return donnee_;
}

uint8_t PixelGris::retournerB() const {
    return donnee_;
}
