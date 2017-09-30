/**************************************************
 * Titre: Travail pratique #2 - Image.cpp
 * Date: Septembre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/

#include <iostream>
#include <assert.h>

#include "Image.h"

using namespace std;

Image::Image() {
    nomImage_   = "";
    nombrePixelHauteur_ = 0;
    nombrePixelLargeur_  = 0;
    pixels_ = NULL;

    allocatePixels();
}

Image::~Image() {
    freePixels();
}

Image::Image(const string& nomImage, uint_t nombrePixelHauteur, uint_t nombrePixelLargeur) {
    nomImage_   = nomImage;
    nombrePixelHauteur_ = nombrePixelHauteur;
    nombrePixelLargeur_  = nombrePixelLargeur;
    pixels_ = NULL;

    allocatePixels();
}

Image::Image(const Image& image) {
    nomImage_   = image.obtenirNomImage();
    nombrePixelHauteur_ = image.obtenirTailleHauteur();
    nombrePixelLargeur_  = image.obetenirTailleLargeur();
    pixels_ = NULL;

    allocatePixels();
    copyPixels(image);
}

void Image::doublerTailleEnHauteur() {
    reallocatePixels(2*nombrePixelHauteur_, nombrePixelLargeur_);
}

void Image::doublerTailleEnLargeur() {
    reallocatePixels(nombrePixelHauteur_, 2*nombrePixelLargeur_);
}

uint_t Image::obtenirTailleHauteur() const {
    return nombrePixelHauteur_;
}

uint_t Image::obetenirTailleLargeur() const {
    return nombrePixelLargeur_;
}

string Image::obtenirNomImage() const {
    return nomImage_;
}

void Image::modifierNomImage(const string& nomImage) {
    nomImage_ = nomImage;
}

void Image::afficherImage() const {
    cout << obtenirNomImage() << ":" << endl;
    for(uint_t j = 0; j < nombrePixelHauteur_; j++) {
        for(uint_t i = 0; i < nombrePixelLargeur_; i++) {
            pixels_[j][i].afficherPixel();
            cout << " ";
        }
        cout << endl;
    }
}

bool Image::ajouterPixel(Pixel& pixel, uint_t positionLargeur, uint_t positionHauteur) {
    /* make sure the desired location is valid */
    if(positionLargeur >= nombrePixelLargeur_ || positionHauteur >= nombrePixelHauteur_)
        return false;

    /* replace the pixel */
    pixels_[positionHauteur][positionLargeur] = pixel;

    return true;
}

Pixel Image::obtenirPixel(uint_t positionLargeur, uint_t positionHauteur) const {
    /* make sure the desired location is valid */
    if(positionLargeur >= nombrePixelLargeur_ || positionHauteur >= nombrePixelHauteur_)
        return Pixel();

    /* get the pixel */
    return pixels_[positionHauteur][positionLargeur];
}

void Image::augmenterTeintePixel(uint_t positionLargeur, uint_t positionHauteur, int value, char couleur) {
    /* make sure the desired location is valid */
    if(positionLargeur >= nombrePixelLargeur_ || positionHauteur >= nombrePixelHauteur_)
        return;

    /* increment the specified color */
    switch(couleur) {
        case 'r':
        case 'R':
            pixels_[positionHauteur][positionLargeur].modifierTeinteRouge(value);
            break;
        case 'g':
        case 'G':
            pixels_[positionHauteur][positionLargeur].modifierTeinteVert(value);
            break;
        case 'b':
        case 'B':
            pixels_[positionHauteur][positionLargeur].modifierTeinteBleu(value);
            break;
    }
}

void Image::allocatePixels() {
    /* this method shouldn't be called with pixels data allocated */
    assert(pixels_ == NULL);

    /* allocate the memory for the pixels */
    pixels_ = new Pixel*[nombrePixelHauteur_];
    for(uint_t j = 0; j < nombrePixelHauteur_; j++)
        pixels_[j] = new Pixel[nombrePixelLargeur_];
}

void Image::reallocatePixels(uint_t nombrePixelHauteur, uint_t nombrePixelLargeur) {
    /* this method shouldn't be called without pixels data allocated */
    assert(pixels_ != NULL);

    /* allocate the new memory for the pixels */
    Pixel** temp = new Pixel*[nombrePixelHauteur];
    for(uint_t j = 0; j < nombrePixelHauteur; j++)
        temp[j] = new Pixel[nombrePixelLargeur];

    /* find the limits of the old pixel data */
    uint_t minx = nombrePixelLargeur < nombrePixelLargeur_ ? nombrePixelLargeur : nombrePixelLargeur_;
    uint_t miny = nombrePixelHauteur < nombrePixelHauteur_ ? nombrePixelHauteur : nombrePixelHauteur_;

    /* copy the old pixel data that fits into the new image */
    for(uint_t j = 0; j < miny; j++)
        for(uint_t i = 0; i < minx; i++)
            temp[j][i] = pixels_[j][i];

    /* free the old pixels data */
    freePixels();

    /* update the attributes of the object */
    nombrePixelLargeur_  = nombrePixelLargeur;
    nombrePixelHauteur_ = nombrePixelHauteur;
    pixels_ = temp;
}

void Image::freePixels() {
    /* this method shouldn't be called without pixels data allocated */
    assert(pixels_ != NULL);

    /* free the memory of the pixels */
    for(uint_t j = 0; j < nombrePixelHauteur_; j++)
        delete [] pixels_[j];
    delete [] pixels_;

    /* remove the pointer */
    pixels_ = NULL;
}

void Image::copyPixels(const Image& image) {
    /* make sure there is enough pixels */
    assert(nombrePixelLargeur_ == image.obetenirTailleLargeur());
    assert(nombrePixelHauteur_ == image.obtenirTailleHauteur());

    /* copy the pixels */
    for(uint_t j = 0; j < nombrePixelHauteur_; j++)
        for(uint_t i = 0; i < nombrePixelLargeur_; i++)
            pixels_[j][i] = image.obtenirPixel(i, j);
}

Image& Image::operator=(const Image& i) {
    /* we copy the basic parameters */
    nomImage_ = i.obtenirNomImage();
    nombrePixelLargeur_ = i.obetenirTailleLargeur();
    nombrePixelHauteur_ = i.obtenirTailleHauteur();

    /* we copy all the pixels */
    freePixels();
    allocatePixels();
    copyPixels(i);

    return (*this);
}

bool Image::operator==(const Image& i) const {
    /* basic attributes must be the same */
    if(nomImage_ != i.obtenirNomImage())
        return false;

    if(nombrePixelLargeur_ != i.obetenirTailleLargeur())
        return false;

    if(nombrePixelHauteur_ != i.obtenirTailleHauteur())
        return false;


    /* compare the pixels data */
    for(uint_t positionHauteur = 0; positionHauteur < nombrePixelHauteur_; positionHauteur++)
        for(uint_t positionLargeur = 0; positionLargeur < nombrePixelLargeur_; positionLargeur++)
            if(!(pixels_[positionHauteur][positionLargeur] == i.obtenirPixel(positionLargeur, positionHauteur)))
                return false;


    /* everything is equal */
    return true;
}

bool Image::operator==(const string& s) const {
    return (nomImage_ == s);
}

bool operator==(const string& s, const Image& i) {
    return (i == s);
}

ostream& operator<<(ostream& o, const Image& i) {
    /* generate the image output */
    o << i.obtenirNomImage() << ":" << endl;
    for(uint_t positionHauteur = 0; positionHauteur < i.obtenirTailleHauteur(); positionHauteur++) {
        for(uint_t positionLargeur = 0; positionLargeur < i.obetenirTailleLargeur(); positionLargeur++) {
            o << i.obtenirPixel(positionLargeur, positionHauteur).asChar() << " ";
        }
        o << endl;
    }

    return o;
}
