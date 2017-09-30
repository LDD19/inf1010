#include <iostream>
#include <iomanip>

#include "Pixel.h"
#include "Const.h"

using namespace std;

Pixel::Pixel() {
    tauxRouge_    = 0;
    tauxVert_  = 0;
    tauxBleu_   = 0;
}

Pixel::~Pixel() {

}

Pixel::Pixel(uint8_t tauxRouge, uint8_t tauxVert, uint8_t b) {
    tauxRouge_   = tauxRouge;
    tauxVert_ = tauxVert;
    tauxBleu_  = tauxBleu;
}

Pixel::Pixel(const Pixel& pixel) {
    tauxRouge_   = pixel.obtenirTauxRouge();
    tauxVert_ = pixel.obtenirTauxVert();
    tauxBleu_  = pixel.obtenirTauxBleu();
}

uint8_t Pixel::obtenirTauxRouge() const {
    return tauxRouge_;
}

uint8_t Pixel::obtenirTauxVert() const {
    return tauxVert_;
}

uint8_t Pixel::obtenirTauxBleu() const {
    return tauxBleu_;
}

void Pixel::modifierTeinteRouge(int incrementRouge) {
    int next = tauxRouge_ + incrementRouge;

    if(next < MIN_CONCENTRATION_COULEUR)
        tauxRouge_ = MIN_CONCENTRATION_COULEUR;
    else if(next > MAX_CONCENTRATION_COULEUR)
        tauxRouge_ = MAX_CONCENTRATION_COULEUR;
    else
        tauxRouge_ = next;
}

void Pixel::modifierTeinteVert(int incrementVert) {
    int next = tauxVert_ + incrementVert;

    if(next < MIN_CONCENTRATION_COULEUR)
        tauxVert_ = MIN_CONCENTRATION_COULEUR;
    else if(next > MAX_CONCENTRATION_COULEUR)
        tauxVert_ = MAX_CONCENTRATION_COULEUR;
    else
        tauxVert_ = next;
}

void Pixel::modifierTeinteBleu(int incrementBleu) {
    int next = tauxBleu_ + incrementBleu;

    if(next < MIN_CONCENTRATION_COULEUR)
        tauxBleu_ = MIN_CONCENTRATION_COULEUR;
    else if(next > MAX_CONCENTRATION_COULEUR)
        tauxBleu_ = MAX_CONCENTRATION_COULEUR;
    else
        tauxBleu_ = next;
}

void Pixel::afficherPixel() const {
    cout << setfill('0')
         << "(" << setw(3) << (int) tauxRouge_
         << "," << setw(3) << (int) tauxVert_
         << "," << setw(3) << (int) tauxBleu_
         << ")";
}

char Pixel::asChar() const {
    if(tauxRouge_   >  MIN_CONCENTRATION_COULEUR
    && tauxVert_ == MIN_CONCENTRATION_COULEUR
    && tauxBleu_  == MIN_CONCENTRATION_COULEUR) {
        return 'R';
    }

    if(tauxRouge_   == MIN_CONCENTRATION_COULEUR
    && tauxVert_ >  MIN_CONCENTRATION_COULEUR
    && tauxBleu_  == MIN_CONCENTRATION_COULEUR) {
        return 'G';
    }

    if(tauxRouge_   == MIN_CONCENTRATION_COULEUR
    && tauxVert_ == MIN_CONCENTRATION_COULEUR
    && tauxBleu_  >  MIN_CONCENTRATION_COULEUR) {
        return 'B';
    }

	return 'Q';
}

bool Pixel::operator==(const Pixel& p) const {
    if(tauxRouge_   == p.obtenirTauxRouge()
    && tauxVert_ == p.obtenirTauxVert()
    && tauxBleu_  == p.obtenirTauxBleu())
        return true;

    return false;
}

bool Pixel::operator==(char c) const {
    if(asChar() == c)
        return true;

    return false;
}

bool operator==(char c, const Pixel& p) {
    if(p.asChar() == c)
        return true;

    return false;
}

ostream& operator<<(ostream& o, const Pixel& p) {
    return o << p.asChar();
}
