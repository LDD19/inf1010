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

}

Image::Image(const Image& image) {
    cout << image.obtenirHauteur() << endl;

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

}

void Image::lireImage(const string& nom, const TypeImage& type) {
    /* on détruit les pixels actuels */
    if(pixels_ != nullptr) {
        unsigned int i;
        for(i = 0; i < obtenirTaille(); i++) {
            delete pixels_[i];
            pixels_ = nullptr;
        }
        delete[] pixels_;
    }

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
    if(type_ == TypeImage::NoirBlanc)
        return;

    if(type_ == TypeImage::Gris) {
        /* si l'image existante est grise*/
        for(uint_t i = 0; i < obtenirTaille(); i++) {
            Pixel* pixel = pixels_[i];

            PixelGris* pg = static_cast<PixelGris*>(pixel);
            Pixel* np = new PixelBN(pg->convertirPixelBN());

            delete pixel;
            pixels_[i] = np;
        }
    } else if(type_ == TypeImage::Couleurs) {
        /* si l'image existante est en couleurs */
        for(uint_t i = 0; i < obtenirTaille(); i++) {
            Pixel* pixel = pixels_[i];

            PixelCouleur* pc = static_cast<PixelCouleur*>(pixel);
            Pixel* np = new PixelBN(pc->convertirPixelBN());

            delete pixel;
            pixels_[i] = np;
        }
    }

    /* on change le type de l'image */
    type_ = TypeImage::NoirBlanc;
}

void Image::convertirGris() {
    /* inutile de convertir si l'image est déjà grise */
    if(type_ == TypeImage::Gris)
        return;

    if(type_ == TypeImage::NoirBlanc) {
        /* si l'image existante est en noir et blanc */
        for(uint_t i = 0; i < obtenirTaille(); i++) {
            Pixel* pixel = pixels_[i];

            PixelBN* pbn = static_cast<PixelBN*>(pixel);
            Pixel* np = new PixelBN(pbn->convertirPixelGris());

            delete pixel;
            pixels_[i] = np;
        }
    } else if(type_ == TypeImage::Couleurs) {
        /* si l'image existante est en couleurs */
        for(uint_t i = 0; i < obtenirTaille(); i++) {
            Pixel* pixel = pixels_[i];

            PixelCouleur* pc = static_cast<PixelCouleur*>(pixel);
            Pixel* np = new PixelBN(pc->convertirPixelGris());

            delete pixel;
            pixels_[i] = np;
        }
    }

    /* on change le type de l'image */
    type_ = TypeImage::NoirBlanc;
}

void Image::convertirCouleur() {
    /* inutile de convertir si l'image est déjà en couleur */
    if(type_ == TypeImage::Couleurs)
        return;

    if(type_ == TypeImage::NoirBlanc) {
        /* si l'image existante est en noir et blanc */
        for(uint_t i = 0; i < obtenirTaille(); i++) {
            Pixel* pixel = pixels_[i];

            PixelBN* pbn = static_cast<PixelBN*>(pixel);
            Pixel* np = new PixelBN(pbn->convertirPixelCouleur());

            delete pixel;
            pixels_[i] = np;
        }
    } else if(type_ == TypeImage::Gris) {
        /* si l'image existante est en couleurs */
        for(uint_t i = 0; i < obtenirTaille(); i++) {
            Pixel* pixel = pixels_[i];

            PixelGris* pg = static_cast<PixelGris*>(pixel);
            Pixel* np = new PixelBN(pg->convertirPixelCouleur());

            delete pixel;
            pixels_[i] = np;
        }
    }

    /* on change le type de l'image */
    type_ = TypeImage::Couleurs;
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

bool operator==(const string& nom, Image& image) {
    return (image == nom);
}

string couperNom(const string chemin) {
    const char* cc = chemin.c_str();

    /* on trouve la position de la dernière barre oblique */
    int i = chemin.length();
    while(i >= 0 && (cc[i] != '/' || cc[i] != '\\')) i--;

    /* on s'assure qu'il y en avait une */
    if(i < 0)
        return "";

    /* on coupe le chemin pour obtenir le nom du fichier */
    return chemin.substr(i, chemin.length()-1);
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

    return new Pixel();
}

void ecrirePixel(uint8_t* valeurs, const Pixel* pixel) {
    switch (pixel->getType()) {
        case TypePixel::Couleur: {
            const PixelCouleur* pc = static_cast<const PixelCouleur*>(pixel);

            valeurs[0] = pc->retournerR();
            valeurs[1] = pc->retournerG();
            valeurs[2] = pc->retournerB();

            return;
        }
        case TypePixel::NoireBlanc: {
            const PixelBN* pbn = static_cast<const PixelBN*>(pixel);

            valeurs[0] = pbn->obtenirDonnee()?UINT8_MAX:0;
            valeurs[1] = valeurs[0];
            valeurs[2] = valeurs[0];

            return;
        }
        case TypePixel::NuanceDeGris: {
            const PixelGris* pg = static_cast<const PixelGris*>(pixel);

            valeurs[0] = pg->obtenirDonnee();
            valeurs[1] = valeurs[0];
            valeurs[2] = valeurs[0];

            return;
        }
    }
}
