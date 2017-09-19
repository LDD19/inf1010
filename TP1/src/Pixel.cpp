#include <stdio.h>

#include "Pixel.h"
#include "Const.h"

using namespace std;

Pixel::Pixel() {
    valueRed_    = 0;
    valueGreen_  = 0;
    valueBlue_   = 0;
}

Pixel::~Pixel() {

}

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b) {
    valueRed_   = r;
    valueGreen_ = g;
    valueBlue_  = b;
}

Pixel::Pixel(const Pixel& pixel) {
    valueRed_   = pixel.getRed();
    valueGreen_ = pixel.getGreen();
    valueBlue_  = pixel.getBlue();
}

uint8_t Pixel::getRed() const {
    return valueRed_;
}

uint8_t Pixel::getGreen() const {
    return valueGreen_;
}

uint8_t Pixel::getBlue() const {
    return valueBlue_;
}

void Pixel::incrementRed(int r) {
    int next = valueRed_ + r;

    if(next < MIN_CONCENTRATION_COULEUR)
        valueRed_ = MIN_CONCENTRATION_COULEUR;
    else if(next > MAX_CONCENTRATION_COULEUR)
        valueRed_ = MAX_CONCENTRATION_COULEUR;
    else
        valueRed_ = next;
}

void Pixel::incrementGreen(int g) {
    int next = valueGreen_ + g;

    if(next < MIN_CONCENTRATION_COULEUR)
        valueGreen_ = MIN_CONCENTRATION_COULEUR;
    else if(next > MAX_CONCENTRATION_COULEUR)
        valueGreen_ = MAX_CONCENTRATION_COULEUR;
    else
        valueGreen_ = next;
}

void Pixel::incrementBlue(int b) {
    int next = valueBlue_ + b;

    if(next < MIN_CONCENTRATION_COULEUR)
        valueBlue_ = MIN_CONCENTRATION_COULEUR;
    else if(next > MAX_CONCENTRATION_COULEUR)
        valueBlue_ = MAX_CONCENTRATION_COULEUR;
    else
        valueBlue_ = next;
}

void Pixel::printPixel() const {
    printf("(%03d,%03d,%03d)", valueRed_, valueGreen_, valueBlue_);
}
