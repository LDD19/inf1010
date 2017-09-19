#include <iostream>

#include "Const.h"
#include "Pixel.h"

using namespace std;

Pixel::Pixel() {
    tauxRouge_ = 0;
    tauxVert_  = 0;
    tauxBleu_  = 0;
}

Pixel::Pixel(uint8_t tauxRouge, uint8_t tauxVert, uint8_t tauxBleu) {
    tauxRouge_ = tauxRouge;
    tauxVert_  = tauxVert;
    tauxBleu_  = tauxBleu;
}

Pixel::~Pixel() {

}

uint8_t Pixel::getTauxRouge() {
    return tauxRouge_;
}

uint8_t Pixel::getTauxVert() {
    return tauxVert_;
}

uint8_t Pixel::getTauxBleu() {
    return tauxBleu_;
}

void Pixel::modifierTeinteRouge(int8_t incrementRouge) {
    uint8_t next = tauxRouge_ + incrementRouge;

    if(next < MIN_CONCENTRATION_COULEUR)
        tauxRouge_ = MIN_CONCENTRATION_COULEUR;
    else if(next > MAX_CONCENTRATION_COULEUR)
        tauxRouge_ = MAX_CONCENTRATION_COULEUR;
    else
        tauxRouge_ = next;
}

void Pixel::modifierTeinteVert(int8_t incrementVert) {
    uint8_t next = tauxVert_ + incrementVert;

    if(next < MIN_CONCENTRATION_COULEUR)
        tauxVert_ = MIN_CONCENTRATION_COULEUR;
    else if(next > MAX_CONCENTRATION_COULEUR)
        tauxVert_ = MAX_CONCENTRATION_COULEUR;
    else
        tauxVert_ = next;
}

void Pixel::modifierTeinteBleu(int8_t incrementBleu) {
    uint8_t next = tauxBleu_ + incrementBleu;

    if(next < MIN_CONCENTRATION_COULEUR)
        tauxBleu_ = MIN_CONCENTRATION_COULEUR;
    else if(next > MAX_CONCENTRATION_COULEUR)
        tauxBleu_ = MAX_CONCENTRATION_COULEUR;
    else
        tauxBleu_ = next;
}

void Pixel::afficherPixel() const {
    cout << "Rouge : " << tauxRouge_ << "\n";
    cout << "Vert  : " << tauxVert_  << "\n";
    cout << "Bleu  : " << tauxBleu_  << "\n";
}
