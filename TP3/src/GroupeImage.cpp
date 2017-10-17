#include <iostream>
#include "GroupeImage.h"

using namespace std;

GroupeImage::GroupeImage() {

}

GroupeImage::~GroupeImage() {

}

void GroupeImage::toutMettreEnNB() {
    for(Image* image : images_) image->convertirNB();
}

void GroupeImage::toutMettreEnGris() {
    for(Image* image : images_) image->convertirGris();
}

void GroupeImage::toutMettreEnCouleur() {
    for(Image* image : images_) image->convertirCouleur();
}

void GroupeImage::toutEnregistrer(const string base) const {
    for(Image* image : images_) {
        string dossier = obtenirDossier(image->obtenirType());
        string chemin = base + dossier + image->obtenirNomImage();
        image->sauvegarderImage(chemin);
    }
}

bool GroupeImage::ajouterImage(Image* image) {
    /* on s'assure qu'une image avec le même nom de fichier n'existe pas */
    for(uint_t i = 0; i <  images_.size(); i++) {
        if(image->obtenirNomImage() == *(images_[i])) {
            cout << image->obtenirNomImage() << " n'a pas été ajoutée." << endl;
            return false;
        }
    }

    /* on ajoute l'image */
    images_.push_back(image);
    cout << image->obtenirNomImage() << " a bien été ajoutée." << endl;

    return true;
}

bool GroupeImage::retirerImage(const std::string& nom) {
    /* on cherche l'image */
    for(uint_t i = 0; i < images_.size(); i++) {
        if(!(nom == *(images_[i])))
            continue;

        /* on enlève l'image de la liste */
        images_.erase(images_.begin()+i);
        cout << nom << " a bien été retirée." << endl;

        return true;
    }

    return false;
}

uint_t GroupeImage::obtenirTaille() const {
    return images_.size();
}

Image* GroupeImage::obtenirImage(uint_t indice) const {
    /* on s'assure que l'indice est valide */
    if(indice >= images_.size())
        return nullptr;

    return images_[indice];
}

GroupeImage& GroupeImage::operator+=(Image* image) {
    ajouterImage(image);

    return *this;
}

GroupeImage& GroupeImage::operator-=(Image* image) {
    retirerImage(image->obtenirNomImage());

    return *this;
}

ostream& operator<<(ostream& os, const GroupeImage& groupeImage) {
    os << endl;
    os << "********************************" << endl;
    os << "Affichage des images du groupe :  " << endl;
    os << "********************************" << endl << endl;
    
    for  (unsigned int j= 0; j < groupeImage.images_.size(); j++)
        os << *groupeImage.images_[j] << endl
           << "------------------------------------------------------" << endl;
    os << endl;

    return os;
}
