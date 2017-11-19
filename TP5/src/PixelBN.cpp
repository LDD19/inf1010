/**************************************************
 * Titre: Travail pratique #5 - PixelBN.cpp
 * Date:28 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#include "PixelBN.h"
#include "PixelCouleur.h"

PixelBN::PixelBN() : Pixel() {

}

PixelBN::PixelBN(bool p) : Pixel() {
    donnee_ = p;
}

PixelBN::~PixelBN() {

}

void PixelBN::mettreEnNegatif() {
    donnee_ = !donnee_;
}

Pixel* PixelBN::retournerCopieProfonde() const {
    return new PixelBN(donnee_);
}


bool PixelBN::convertirPixelBN() const {
    return donnee_;
}

uint8_t PixelBN::convertirPixelGris() const {
    return (donnee_?UINT8_MAX:0);
}

void PixelBN::convertirPixelCouleur(uint8_t* v) const {
    v[Couleur::R] = (donnee_?UINT8_MAX:0);
    v[Couleur::G] = (donnee_?UINT8_MAX:0);
    v[Couleur::B] = (donnee_?UINT8_MAX:0);
}

bool PixelBN::estMajoriteRouge() const {
    return false;
}

bool PixelBN::estMajoriteVert() const {
    return false;
}

bool PixelBN::estMajoriteBleu() const {
    return false;
}

double PixelBN::retournerIntensiteMoyenne() const {
    return (donnee_?1:0);
}

void PixelBN::modifierDonnee(bool donnee) {
    donnee_ = donnee;
}

uint8_t PixelBN::retournerR() const {
    return (donnee_?UINT8_MAX:0);
}

uint8_t PixelBN::retournerG() const {
    return (donnee_?UINT8_MAX:0);
}

uint8_t PixelBN::retournerB() const {
    return (donnee_?UINT8_MAX:0);
}

