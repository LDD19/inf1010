#include <stdio.h>

#include "GroupImage.h"

using namespace std;

GroupImage::GroupImage() {
    type_     = "";
    size_     = 0;
    capacity_ = 1;
    images_   = new Image*[capacity_];
}

GroupImage::~GroupImage() {
    delete [] images_;
}

GroupImage::GroupImage(const string& type, uint_t capacity) {
    type_     = type;
    size_     = 0;
    capacity_ = capacity;
    images_   = new Image*[capacity_];
}

GroupImage::GroupImage(const GroupImage& group) {
    type_     = group.getType();
    size_     = group.getSize();
    capacity_ = group.getCapacity();
    images_   = new Image*[capacity_];

    /* copy the images */
    for(uint_t i = 0; i < size_; i++)
        images_[i] = group.getImage(i);
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
    return size_;
}

uint_t GroupImage::getCapacity() const {
    return capacity_;
}

void GroupImage::addImage(Image& image) {
    /* make sure we can add another image into the list */
    if(size_ >= capacity_)
        return;

    /* add the image */
    images_[size_++] = &image;
}

void GroupImage::printImages() const {
    /* print all the image names */
    for(uint_t i = 0; i < size_; i++) {
        images_[i]->printImage();
    }
}

void GroupImage::doubleWidth(uint_t index) {
    /* make sure the index is valid */
    if(index >= size_)
        return;

    /* double the width of the image */
    images_[index]->doubleWidth();
}

void GroupImage::doubleHeight(uint_t index) {
    /* make sure the index is valid */
    if(index >= size_)
        return;

    /* double the height of the image */
    images_[index]->doubleHeight();
}
