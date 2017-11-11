/**************************************************
 * Titre: Travail pratique #4 - Image.cpp
 * Date:28 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#include <iostream>
#include <sstream>

#include "Image.h"
#include "PixelCouleur.h"
#include "PixelBN.h"
#include "PixelGris.h"

using namespace std;

string couperNom(const string chemin);
string obtenirTypeEnString(const TypeImage type);
Pixel* nouveauPixel(char* valeurs, const TypeImage& type);
void ecrirePixel(uint8_t* valeurs, const Pixel* pixel);

Image::Image() {
    type_   = TypeImage::Couleurs;
    chemin_ = "";
    pixels_ = nullptr;
    nom_    = "";
}

Image::Image(const string& chemin, const TypeImage& type) {
    type_   = type;
    chemin_ = chemin;
    pixels_ = nullptr;
    nom_    = couperNom(chemin);

    /* on lit l'image */
    lireImage(chemin_, type_);
    if(pixels_ == nullptr) {
        cerr << "Erreur lors de la lecture de l'image." << endl;
    }
}

Image::~Image() {
    /* on détruit les pixels */
    detruirePixels();
}

void Image::lireImage(const string& nom, const TypeImage& type) {
    /* on détruit les pixels actuels */
    detruirePixels();

    /* on ouvre un stream pour lire l'image */
    ifstream bmpIn(chemin_.c_str(), ios::in | ios::binary);
    if(!bmpIn.is_open()) {
        cerr << "Erreur, le fichier "
             << nom
             << " n'a pas pu etre ouvert."
             << endl;
        exit(9);
    }
    
    /* on lit l'en-tête de l'image BMP */
    char info[54];
    bmpIn.read(info, 54);

    /* on obtient les dimensions de l'image */
    largeur_ = *(uint_t*)&info[18];
    hauteur_ = *(uint_t*)&info[22];

    /* on obtient la quantité de bits par pixel */
    uint8_t depth = *(uint8_t*)&info[28];
    if(depth != 24) {
        cerr << "This bmp is a "
             << depth
             << " and this program only supports 24 bytes bmp files"
             << endl;
        exit(10);
    }

    /* on envoit le curseur aux données de l'image */
    int offset = *(int*)&info[10];
    bmpIn.seekg(offset);

    /* on alloue la mémoire pour les pixels */
    pixels_ = new Pixel*[obtenirTaille()];

    /* on lit l'image */
    uint_t x, y, pos = 0;
    for (y = 0; y < hauteur_; y++) {
        for (x = 0; x < largeur_; x++) {
            /* on calcule l'indice du prochain pixel */
            int indice = (hauteur_ - 1 - y) * largeur_ + x;

            /* on lit le prochain pixel dans l'ordre B, G et R*/
            char buffer[3];
            bmpIn.read(buffer, 3);
            pos += 3;

            /* on crée le pixel */
            pixels_[indice] = nouveauPixel(buffer, type);
        }

        /* on ignore le padding de la rangée */
        while (pos % 4) {
            char buffer;
            bmpIn.read(&buffer, 1);
            pos += 1;
        }
    }

    /* on ferme le stream */
    bmpIn.close();
}

void Image::sauvegarderImage(const string &nom) {
    /* on ouvre un stream pour écrire l'image */
    ofstream bmpOut(nom.c_str(), ios::out | ios::binary);
    if(!bmpOut.is_open()) {
        cerr << "Erreur, le fichier "
             << nom
             << " n'a pas pu être ouvert."
             << endl;
        exit(12);
    }

    cout << "Sauvegarde de l'image " << nom << "." << endl;
    
    /* on écrit les pixels */
    uint8_t *rgb = new uint8_t[obtenirTaille() * 3];
    for (uint_t i = 0; i < obtenirTaille(); i++) {
        ecrirePixel(&rgb[i*3], pixels_[i]);
    }

    /* on ajoute l'en-tête */
    uint8_t* output;
    size_t output_size = bitmap_encode_rgb(rgb, largeur_, hauteur_, &output);

    /* on écrit l'image */
    bmpOut.write((char*)output, output_size);

    /* on ferme le fichier */
    bmpOut.close();

    /* on libère la mémoire */
    delete[] rgb;
    delete[] output;
}

void Image::convertirNB() {
    /* inutile de convertir si l'image est déjà en noir et blanc */
    if(type_ == TypeImage::NoirBlanc) {
        cout << "L'image "
             << nom_
             << "est déjà en noir et blanc, conversion inutile."
             << endl;
        return;
    }

    /* on convertit chaque pixels */
    for(uint_t i = 0; i < obtenirTaille(); i++) {
        Pixel* pixel = pixels_[i];
        Pixel* np = new PixelBN(pixel->convertirPixelBN());

        delete pixel;
        pixels_[i] = np;
    }

    /* on change le type de l'image */
    cout << "Conversion de l'image " << nom_ << " en image noir et blanc."<< endl;
    type_ = TypeImage::NoirBlanc;
}

void Image::convertirGris() {
    /* inutile de convertir si l'image est déjà grise */
    if(type_ == TypeImage::Gris) {
        cout << "L'image "
             << nom_
             << "est déjà grise, conversion inutile."
             << endl;
        return;
    }

    /* on convertit chaque pixels */
    for(uint_t i = 0; i < obtenirTaille(); i++) {
        Pixel* pixel = pixels_[i];
        Pixel* np = new PixelGris(pixel->convertirPixelGris());

        delete pixel;
        pixels_[i] = np;
    }

    /* on change le type de l'image */
    cout << "Conversion de l'image " << nom_ << " en image grise."<< endl;
    type_ = TypeImage::Gris;
}

void Image::convertirCouleur() {
    /* inutile de convertir si l'image est déjà en couleur */
    if(type_ == TypeImage::Couleurs) {
        cout << "L'image "
             << nom_
             << "est déjà en couleur, conversion inutile."
             << endl;
        return;
    }

    for(uint_t i = 0; i < obtenirTaille(); i++) {
        Pixel* pixel = pixels_[i];

        uint8_t valeurs[3];
        pixel->convertirPixelCouleur(valeurs);

        uint8_t r = valeurs[Couleur::R];
        uint8_t g = valeurs[Couleur::G];
        uint8_t b = valeurs[Couleur::B];
        Pixel* np = new PixelCouleur(r, g, b);

        delete pixel;
        pixels_[i] = np;
    }

    /* on change le type de l'image */
    cout << "Conversion de l'image " << nom_ << " en image de couleurs."<< endl;
    type_ = TypeImage::Couleurs;
}

void Image::toutMettreEnNegatif() const {
    /* on met chaque pixels en négatif */
    for(uint_t i = 0; i < obtenirTaille(); i++)
        pixels_[i]->mettreEnNegatif();
}

bool Image::estMajoriteRouge() const {
    float compte = 0;

    /* on compte le nombre de pixel majoritairement rouge */
    for(uint_t i = 0; i < obtenirTaille(); i++)
        if(pixels_[i]->estMajoriteRouge())
            compte += 1;

    return (compte/obtenirTaille() > 0.50?true:false);
}

bool Image::estMajoriteVert() const {
    float compte = 0;

    /* on compte le nombre de pixel majoritairement vert */
    for(uint_t i = 0; i < obtenirTaille(); i++)
        if(pixels_[i]->estMajoriteVert())
            compte += 1;

    return (compte/obtenirTaille() > 0.50?true:false);
}

bool Image::estMajoriteBleu() const {
    float compte = 0;

    /* on compte le nombre de pixel majoritairement bleu */
    for(uint_t i = 0; i < obtenirTaille(); i++)
        if(pixels_[i]->estMajoriteBleu())
            compte += 1;

    return (compte/obtenirTaille() > 0.50?true:false);
}

void Image::changerNomImage(const string& nom) {
    nom_ = nom;
}

string Image::obtenirChemin() const {
    return chemin_;
}

string Image::obtenirNomImage() const {
    return nom_;
}

TypeImage Image::obtenirType() const {
    return type_;
}

uint_t Image::obtenirHauteur() const {
    return hauteur_;
}

uint_t Image::obtenirLargeur() const {
    return largeur_;
}

uint_t Image::obtenirTaille() const {
    return hauteur_*largeur_;
}

Pixel* Image::obtenirPixel(uint_t index) const {
    /* on s'assure que l'index est valide */
    if(index >= obtenirTaille())
        return nullptr;

    return pixels_[index];
}

double Image::retournerIntensiteMoyenne() const {
    float somme = 0;

    /* on somme l'intensité de chaque pixel */
    for(uint_t i = 0; i < obtenirTaille(); i++)
        somme += pixels_[i]->retournerIntensiteMoyenne();

    return somme/obtenirTaille();
}

Image& Image::operator=(const Image& image) {
    /* on s'assure de ne pas s'assigner soi-même */
    if(this == &image)
        return *this;

    /* on détruit les anciens pixels */
    detruirePixels();

    /* on copie l'image */
    type_    = image.obtenirType();
    chemin_  = image.obtenirChemin();
    nom_     = image.obtenirNomImage();
    hauteur_ = image.obtenirHauteur();
    largeur_ = image.obtenirLargeur();
    pixels_  = new Pixel*[image.obtenirTaille()];
    
    /* on copie chaque pixels */
    for(uint_t i = 0; i < obtenirTaille(); i++) {
        Pixel* pixel = image.obtenirPixel(i);

        /* on copie le pixel si possible */
        if(pixel == nullptr)
            pixels_[i] = nullptr;
        else
            pixels_[i] = pixel->retournerCopieProfonde();
    }

    return *this;
}

bool Image::operator==(const Image& image) {
    /* le nom de fichier de l'image doit être le même */
    if(image.obtenirNomImage() != nom_)
        return false;

    /* la hauteur des images doit être la même */
    if(image.obtenirHauteur() != hauteur_)
        return false;

    /* la largeur des images doit être la même */
    if(image.obtenirLargeur() != largeur_)
        return false;

    /* les pixels doivent être identiques */
    for(uint_t i = 0; i < obtenirTaille(); i++)
        if (image.pixels_[i] != pixels_[i])
            return false;

    return true;
}

bool Image::operator==(const string& nom) {
    return (nom_ == nom);
}

bool operator==(const string& nom, const Image& image) {
    return (image.obtenirNomImage() == nom);
}

std::ostream& operator<<(std::ostream& os, const Image& image) {
    os << "Nom de l'image : " << image.obtenirNomImage() << endl;
    os << "Chemin de l'original : " << image.obtenirChemin() << endl;
    os << "Taille de l'image : " << image.obtenirTaille() << " pixels" << endl;
    os << "Résolution en pixels : " 
       << image.obtenirLargeur() << "x" 
       << image.obtenirHauteur() << endl;
    os << "Type de l'image : " << obtenirTypeEnString(image.obtenirType());

    return os;
}

void Image::detruirePixels() {
    /* on s'assure qu'il y a des pixels */
    if(pixels_ == nullptr) 
        return;

    /* on détruit les pixels actuels */
    for(uint_t i = 0; i < obtenirTaille(); i++) {
        /* on s'assure qu'il y a un pixel */
        if(pixels_[i] == nullptr)
            continue;

        /* on libère la mémoire */
        delete pixels_[i];
        pixels_[i] = nullptr;
    }
    delete[] pixels_;
}

string couperNom(const string chemin) {
    const char* cc = chemin.c_str();

    /* on trouve la position de la dernière barre oblique */
    int i = chemin.length();
    while(i >= 0 && cc[i] != '/' && cc[i] != '\\') i--;

    /* on s'assure qu'il y en avait une */
    if(i < 0)
        return "";

    /* on coupe le chemin pour obtenir le nom du fichier */
    return chemin.substr(i+1, chemin.length()-1);
}

string obtenirTypeEnString(const TypeImage type) {
    switch(type) {
        case TypeImage::NoirBlanc:
            return "Noir et Blanc";
        case TypeImage::Gris:
            return "Gris";
        case TypeImage::Couleurs:
            return "Couleurs";
        default:
            return "";
    }
}

Pixel* nouveauPixel(char* valeurs, const TypeImage& type) {
    uint_t moy = 0;
    switch(type) {
        case TypeImage::NoirBlanc:
            moy += valeurs[Couleur::R];
            moy += valeurs[Couleur::G];
            moy += valeurs[Couleur::B];
            moy /= 3;

            return new PixelBN(moy > 127);
        case TypeImage::Gris:
            moy += valeurs[Couleur::R];
            moy += valeurs[Couleur::G];
            moy += valeurs[Couleur::B];
            moy /= 3;

            return new PixelGris(moy);
        case TypeImage::Couleurs:
            uint8_t r = valeurs[Couleur::R];
            uint8_t g = valeurs[Couleur::G];
            uint8_t b = valeurs[Couleur::B];

            return new PixelCouleur(r, g, b);
    }

    return nullptr;
}

void ecrirePixel(uint8_t* valeurs, const Pixel* pixel) {
    valeurs[0] = pixel->retournerR();
    valeurs[1] = pixel->retournerG();
    valeurs[2] = pixel->retournerB();
}

string obtenirDossier(TypeImage type) {
    switch(type) {
        case TypeImage::NoirBlanc:
            return "Noir et Blanc/";
        case TypeImage::Gris:
            return "Nuances de Gris/";
        case TypeImage::Couleurs:
            return "Couleurs/";
        default:
            return "";
    }
}
