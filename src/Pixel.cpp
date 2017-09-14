#include <iostream>

#include "Const.h"
#include "Pixel.h"

using namespace std;

Pixel::Pixel() {
    this->tauxRouge_ = 0;
    this->tauxVert_  = 0;
    this->tauxBleu_  = 0;
}

Pixel::Pixel(uint8_t tauxRouge, uint8_t tauxVert, uint8_t tauxBleu) {
    this->tauxRouge_ = tauxRouge;
    this->tauxVert_  = tauxVert;
    this->tauxBleu_  = tauxBleu;
}

Pixel::~Pixel() {

}

uint8_t Pixel::getTauxRouge() {
    return this->tauxRouge_;
}

uint8_t Pixel::getTauxVert() {
    return this->tauxVert_;
}

uint8_t Pixel::getTauxBleu() {
    return this->tauxBleu_;
}

void Pixel::modifierTeinteRouge(int8_t incrementRouge) {
    uint8_t next = this->tauxRouge_ + incrementRouge;

    if(next < 0)
        this->tauxRouge_ = 0;
    else if(next > UINT8_MAX)
        this->tauxRouge_ = UINT8_MAX;
    else
        this->tauxRouge_ = next;
}

void Pixel::modifierTeinteVert(int8_t incrementVert) {
    uint8_t next = this->tauxVert_ + incrementVert;

    if(next < 0)
        this->tauxVert_ = 0;
    else if(next > UINT8_MAX)
        this->tauxVert_ = UINT8_MAX;
    else
        this->tauxVert_ = next;
}

void Pixel::modifierTeinteBleu(int8_t incrementBleu) {
    uint8_t next = this->tauxBleu_ + incrementBleu;

    if(next < 0)
        this->tauxBleu_ = 0;
    else if(next > UINT8_MAX)
        this->tauxBleu_ = UINT8_MAX;
    else
        this->tauxBleu_ = next;
}

void Pixel::afficherPixel() const {
    cout << "Rouge : " << this->tauxRouge_ << "\n";
    cout << "Vert  : " << this->tauxVert_  << "\n";
    cout << "Bleu  : " << this->tauxBleu_  << "\n";
}

