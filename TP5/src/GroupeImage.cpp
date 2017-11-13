/**************************************************
 * Titre: Travail pratique #4 - GroupeImage.cpp
 * Date:28 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#include <iostream>
#include <algorithm>
#include "GroupeImage.h"

using namespace std;

GroupeImage::GroupeImage() {

}

GroupeImage::GroupeImage(const GroupeImage& groupe) {
    for(uint_t i = 0; i < groupe.obtenirTaille(); i++) {
        Image* image = new Image();
        (*image) = (*groupe.obtenirImage(i));
        ajouterImage(image);
    }
}

GroupeImage::~GroupeImage() {

}

void GroupeImage::toutMettreEnNB() const {
    for(Image* image : images_) image->convertirNB();
}

void GroupeImage::toutMettreEnGris() const {
    for(Image* image : images_) image->convertirGris();
}

void GroupeImage::toutMettreEnCouleur() const {
    for(Image* image : images_) image->convertirCouleur();
}

void GroupeImage::toutMettreEnNegatif() const {
    for(Image* image : images_) image->toutMettreEnNegatif();
}

void GroupeImage::toutEnregistrer(const string base) const {
    for(Image* image : images_) {
        string dossier = obtenirDossier(image->obtenirType());
        string chemin = base + dossier + image->obtenirNomImage();
        image->sauvegarderImage(chemin);
    }
}

void GroupeImage::afficherImages(ostream& os) const {
    for(Image* image : images_)
        os << image->obtenirNomImage() << endl;
}

bool GroupeImage::ajouterImage(Image* image) {
    /* on cherche si une image a déjà ce nom */
    auto img = find_if(images_.begin(), images_.end(),
        [image](Image* img) {
            return (image->obtenirNomImage() == *img);
        }
    );

    /* si une image est trouvée, on n'ajoute rien */
    if(img != images_.end()) {
        cout << image->obtenirNomImage() << " n'a pas été ajoutée." << endl;
        return false;
    }

    /* on ajoute l'image */
    images_.insert(images_.end(), image);
    cout << image->obtenirNomImage() << " a bien été ajoutée." << endl;

    return true;
}

bool GroupeImage::retirerImage(const std::string& nom) {
    /* on cherche si une image a ce nom */
    auto img = find_if(images_.begin(), images_.end(),
        [nom](Image* img) {
            return (nom == *img);
        }
    );

    /* si aucune image n'a été trouvée, on n'enlève rien */
    if(img == images_.end()) {
        cout << nom << " n'a pas été retirée." << endl;
        return false;
    }

    /* on enlève l'image */
    images_.erase(img);
    cout << nom << " a été retirée." << endl;

    return true;
}

uint_t GroupeImage::obtenirTaille() const {
    return images_.size();
}

Image* GroupeImage::obtenirImage(uint_t indice) const {
    auto it = images_.begin();
    advance(it, indice);
    return *it;
}

Image* GroupeImage::obtenirImage(const string& nom) const {
    /* on cherche l'image par nom */
    auto image = find_if(images_.begin(), images_.end(),
        [nom](Image* image) {
            return (nom == *image);
        }
    );

    /* l'image n'a pas été trouvée */
    if(image == images_.end())
        return nullptr;

    /* l'image a été trouvée */
    return *image;
}

double GroupeImage::obtenirIntensiteMoyenne() const {
    double somme = 0;

    /* on somme l'intensité de chaque image */
    for_each(images_.begin(), images_.end(),
        [&somme](Image* image) {
            somme += image->retournerIntensiteMoyenne();
        }
    );

    /* on retourne l'intensité moyenne du groupe */
    return somme/images_.size();
}

double GroupeImage::obtenirTailleMoyenne() const {
    float somme = 0;

    /* on somme la taille de chaque image */
    for_each(images_.begin(), images_.end(),
        [&somme](Image* image) {
            somme += image->obtenirTaille();
        }
    );

    /* on retourne la taille moyenne du groupe */
    return somme/images_.size();
}

GroupeImage& GroupeImage::operator+=(Image* image) {
    ajouterImage(image);

    return *this;
}

GroupeImage& GroupeImage::operator-=(Image* image) {
    retirerImage(image->obtenirNomImage());

    return *this;
}

GroupeImage& GroupeImage::operator-=(const std::string& nom) {
    retirerImage(nom);

    return *this;
}

GroupeImage& GroupeImage::operator=(const GroupeImage& groupe) {
    /* on enlève toutes les images */
    images_.clear();

    /* on ajoute chaque image */
    for_each(groupe.images_.begin(), groupe.images_.end(),
        [this](Image* image) {
            this->images_.insert(images_.end(), image);
        }
    );

    return *this;
}

ostream& operator<<(ostream& os, const GroupeImage& groupeImage) {
    os << endl;
    os << "********************************" << endl;
    os << "Affichage des images du groupe :  " << endl;
    os << "********************************" << endl << endl;
    
    for  (Image* image : groupeImage.images_)
        os << *image << endl
           << "------------------------------------------------------" << endl;

    return os;
}
