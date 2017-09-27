#include <iostream>
#include <stdio.h>

#include "GroupImage.h"

using namespace std;

GroupImage::GroupImage() {
    type_ = "";
}

GroupImage::~GroupImage() {
}

GroupImage::GroupImage(const string& type) {
    type_ = type;
}

GroupImage::GroupImage(const GroupImage& group) {
    type_ = group.getType();

    /* copy the image pointers*/
    for(uint_t i = 0; i < size_; i++)
        images_.push_back(group.getImage(i));
}

void GroupImage::setType(const string& type) {
    type_ = type;
}

string GroupImage::getType() const {
    return type_;
}

Image* GroupImage::getImage(uint_t index) const {
    /* make sure the index is valid */
    if(index >= size_)
        return NULL;

    return images_[index];
}

uint_t GroupImage::getSize() const {
    return images_.size();
}

uint_t GroupImage::getCapacity() const {
    return images_.capacity();
}

void GroupImage::addImage(Image& image) {
    /* make sure the name isn't duplicated */
    for(uint_t i = 0; i < images_.size(); i++) {
        if(images_[i]->getName() == image) {
            cout << "Error: image name already present in the group" << endl;
            return;
        }
    }

    /* add the pointer into the vector */
    images_.push_back(&image);
}

void GroupImage::removeImage(const string& name) {
    /* search for the name */
    for(uint i = 0; i < images_.size(); i++) {
        if(images_[i]->getName() == name) {
            images_.erase(images_.begin() + i);
            return;
        }
    }

    cout << "Error: the image couldn't be found" << endl;
}

void GroupImage::printImages() const {
    /* print all the image names */
    for(uint_t i = 0; i < size_; i++)
        images_[i]->printImage();
}

void GroupImage::doubleWidth(uint_t index) {
    /* make sure the index is valid */
    if(index >= images_.size())
        return;

    /* double the width of the image */
    images_[index]->doubleWidth();
}

void GroupImage::doubleHeight(uint_t index) {
    /* make sure the index is valid */
    if(index >= images_.size())
        return;

    /* double the height of the image */
    images_[index]->doubleHeight();
}

GroupImage& GroupImage::operator+=(Image& i) {
    addImage(i);

    return (*this);
}

GroupImage& GroupImage::operator-=(const Image& i) {
    removeImage(i.getName());

    return (*this);
}

ostream& operator<<(ostream& o, const GroupImage& g) {
    /* generate the output */
    for(uint_t i = 0; i < g.getSize(); i++)
        o << g.getImage(i) << endl;

    return o;
}
