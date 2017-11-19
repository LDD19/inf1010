/**************************************************
 * Titre: Travail pratique #5 - PixelCouleur.cpp
 * Date:28 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#include "PixelCouleur.h"

PixelCouleur::PixelCouleur() : Pixel() {
    donnee_[Couleur::R] = 0;
    donnee_[Couleur::G] = 0;
    donnee_[Couleur::B] = 0;
}

PixelCouleur::PixelCouleur(uint8_t r, uint8_t g, uint8_t b) : Pixel() {
    donnee_[Couleur::R] = r;
    donnee_[Couleur::G] = g;
    donnee_[Couleur::B] = b;
}

PixelCouleur::~PixelCouleur() {

}

void PixelCouleur::mettreEnNegatif() {
    donnee_[Couleur::R] = UINT8_MAX-donnee_[Couleur::R];
    donnee_[Couleur::G] = UINT8_MAX-donnee_[Couleur::G];
    donnee_[Couleur::B] = UINT8_MAX-donnee_[Couleur::B];
}

Pixel* PixelCouleur::retournerCopieProfonde() const {
    uint8_t r = donnee_[Couleur::R];
    uint8_t g = donnee_[Couleur::G];
    uint8_t b = donnee_[Couleur::B];

    return new PixelCouleur(r, g, b);
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

void PixelCouleur::convertirPixelCouleur(uint8_t* v) const {
    v[Couleur::R] = retournerR();
    v[Couleur::G] = retournerG();
    v[Couleur::B] = retournerB();
}

bool PixelCouleur::estMajoriteRouge() const {
    return (donnee_[Couleur::R] > donnee_[Couleur::G])
        && (donnee_[Couleur::R] > donnee_[Couleur::B]);
}

bool PixelCouleur::estMajoriteVert() const {
    return (donnee_[Couleur::G] > donnee_[Couleur::R])
        && (donnee_[Couleur::G] > donnee_[Couleur::B]);
}

bool PixelCouleur::estMajoriteBleu() const {
    return (donnee_[Couleur::B] > donnee_[Couleur::R])
        && (donnee_[Couleur::B] > donnee_[Couleur::G]);
}

double PixelCouleur::retournerIntensiteMoyenne() const {
    double somme = 0;
    somme += donnee_[Couleur::R];
    somme += donnee_[Couleur::G];
    somme += donnee_[Couleur::B];
    somme /= 3;
    somme /= (double) UINT8_MAX;

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
