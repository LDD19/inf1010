#include <iostream>

#include "GroupImage.h"

using namespace std;

GroupImage::GroupImage() {
    type_     = "";
    capaciteImages_ = 0;
}

GroupImage::~GroupImage() {
}

GroupImage::GroupImage(const string& type, uint_t capaciteImages) {
    type_     = type;
    capaciteImages_ = capaciteImages;
}

GroupImage::GroupImage(const GroupImage& group) {
    type_     = group.obtenirType();
    capaciteImages_ = group.obtenirCapaciteGroup();

    /* copy the image pointers*/
    for(uint_t i = 0; i < obtenirTailleGroup(); i++)
        images_.push_back(group.obtenirImage(i));
}

void GroupImage::modifierType(const string& type) {
    type_ = type;
}

string GroupImage::obtenirType() const {
    return type_;
}

Image* GroupImage::obtenirImage(uint_t indiceImage) const {
    /* make sure the index is valid */
    if(indiceImage >= obtenirTailleGroup())
        return NULL;

    return images_[indiceImage];
}

uint_t GroupImage::obtenirTailleGroup() const {
    return images_.size();
}

uint_t GroupImage::obtenirCapaciteGroup() const {
    return capaciteImages_;
}

void GroupImage::ajouterImage(Image& image) {
    /* make sure there's space available */
    if(obtenirTailleGroup() >= obtenirCapaciteGroup()) {
        cout << "The group is at its maximum capacity." << endl;
        return;
    }

    /* make sure the name isn't duplicated */
    for(uint_t i = 0; i < obtenirTailleGroup(); i++) {
        if(images_[i]->getName() == image) {
            cout << "Error: image name already present in the group." << endl;
            return;
        }
    }

    /* add the pointer into the vector */
    images_.push_back(&image);
    cout << "The image \"" << image.getName()
         << "\" has been successfully added." << endl;
}

void GroupImage::removeImage(const string& name) {
    /* search for the name */
    for(uint i = 0; i < obtenirTailleGroup(); i++) {
        if(images_[i]->getName() == name) {
            images_.erase(images_.begin() + i);

            cout << "The image \"" << name
                 << "\" has been successfully removed." << endl;
            return;
        }
    }

    cout << "Error: the image couldn't be found." << endl;
}

void GroupImage::afficherImages() const {
    /* print all the image names */
    for(uint_t i = 0; i < obtenirTailleGroup(); i++)
        images_[i]->printImage();
}

void GroupImage::doublerTailleImageEnLargeur(uint_t indiceImage) {
    /* make sure the index is valid */
    if(indiceImage >= obtenirTailleGroup()) {
        cout << "Error: the index is invalid." << endl;
        return;
    }

    /* double the width of the image */
    images_[indiceImage]->doublerTailleImageEnLargeur();
    cout << "The image width has been doubled." << endl;
}

void GroupImage::doublerTailleImageEnHauteur(uint_t indiceImage) {
    /* make sure the index is valid */
    if(indiceImage >= obtenirTailleGroup()) {
        cout << "Error: the index is invalid." << endl;
        return;
    }

    /* double the height of the image */
    images_[indiceImage]->doublerTailleImageEnHauteur();
    cout << "The image height has been doubled." << endl;
}

GroupImage& GroupImage::operator+=(Image& i) {
    ajouterImage(i);

    return (*this);
}

GroupImage& GroupImage::operator-=(const Image& i) {
    removeImage(i.getName());

    return (*this);
}

ostream& operator<<(ostream& o, const GroupImage& g) {
    /* generate the output */
    for(uint_t i = 0; i < g.obtenirTailleGroup(); i++)
        o << *g.obtenirImage(i) << endl;

    return o;
}
