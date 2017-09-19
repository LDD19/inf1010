#include <stdio.h>
#include <assert.h>

#include "Image.h"

Image::Image() {
    name_   = "";
    height_ = 1;
    width_  = 1;
    pixels_ = NULL;

    allocatePixels();
}

Image::~Image() {
    freePixels();
}

Image::Image(const string& name, uint_t height, uint_t width) {
    name_   = name;
    height_ = height;
    width_  = width;
    pixels_ = NULL;

    allocatePixels();
}

Image::Image(const Image& image) {
    name_   = image.getName();
    height_ = image.getHeight();
    width_  = image.getWidth();
    pixels_ = NULL;

    allocatePixels();
    copyPixels(image);
}

void Image::doubleHeight() {
    reallocatePixels(2*height_, width_);
}

void Image::doubleWidth() {
    reallocatePixels(height_, 2*width_);
}

uint_t Image::getHeight() const {
    return height_;
}

uint_t Image::getWidth() const {
    return width_;
}

string Image::getName() const {
    return name_;
}

void Image::setName(const string& name) {
    name_ = name;
}

void Image::printImage() const {
    printf("%s:\n", name_.c_str());
    for(uint_t j = 0; j < height_; j++) {
        for(uint_t i = 0; i < width_; i++) {
            pixels_[j][i].printPixel();
            printf(" ");
        }
        printf("\n");
    }
}

bool Image::addPixel(Pixel& pixel, uint_t x, uint_t y) {
    /* make sure the desired location is valid */
    if(x >= width_ || y >= height_)
        return false;

    /* replace the pixel */
    pixels_[y][x] = pixel;

    return true;
}

Pixel Image::getPixel(uint_t x, uint_t y) const {
    /* make sure the desired location is valid */
    if(x >= width_ || y >= height_)
        return Pixel();

    /* get the pixel */
    return pixels_[y][x];
}

void Image::incrementValue(uint_t x, uint_t y, int value, char color) {
    /* make sure the desired location is valid */
    if(x >= width_ || y >= height_)
        return;

    /* increment the specified color */
    switch(color) {
        case 'r':
        case 'R':
            pixels_[y][x].incrementRed(value);
            break;
        case 'g':
        case 'G':
            pixels_[y][x].incrementGreen(value);
            break;
        case 'b':
        case 'B':
            pixels_[y][x].incrementBlue(value);
            break;
    }
}

void Image::allocatePixels() {
    /* this method shouldn't be called with pixels data allocated */
    assert(pixels_ == NULL);

    /* allocate the memory for the pixels */
    pixels_ = new Pixel*[height_];
    for(uint_t j = 0; j < height_; j++)
        pixels_[j] = new Pixel[width_];
}

void Image::reallocatePixels(uint_t height, uint_t width) {
    /* this method shouldn't be called without pixels data allocated */
    assert(pixels_ != NULL);

    /* allocate the new memory for the pixels */
    Pixel** temp = new Pixel*[height];
    for(uint_t j = 0; j < height; j++)
        temp[j] = new Pixel[width];

    /* find the limits of the old pixel data */
    uint_t minx = width < width_ ? width : width_;
    uint_t miny = height < height_ ? height : height_;

    /* copy the old pixel data that fits into the new image */
    for(uint_t j = 0; j < miny; j++)
        for(uint_t i = 0; i < minx; i++)
            temp[j][i] = pixels_[j][i];

    /* free the old pixels data */
    freePixels();

    /* update the attributes of the object */
    width_  = width;
    height_ = height;
    pixels_ = temp;
}

void Image::freePixels() {
    /* this method shouldn't be called without pixels data allocated */
    assert(pixels_ != NULL);

    /* free the memory of the pixels */
    for(uint_t j = 0; j < height_; j++)
        delete [] pixels_[j];
    delete [] pixels_;

    /* remove the pointer */
    pixels_ = NULL;
}

void Image::copyPixels(const Image& image) {
    /* make sure there is enough pixels */
    assert(width_ == image.getWidth());
    assert(height_ == image.getHeight());

    /* copy the pixels */
    for(uint_t j = 0; j < height_; j++)
        for(uint_t i = 0; i < width_; i++)
            pixels_[j][i] = image.getPixel(i, j);
}
