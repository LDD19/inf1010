#include "Pixel.h"

Pixel::Pixel() {

}

Pixel::Pixel(TypePixel type) {
    type_ = type;
}

Pixel::~Pixel() {

}

TypePixel Pixel::getType() const {
    return type_;
}

bool Pixel::operator==(const Pixel& pixel) const {
    return (pixel.getType() == getType());
}
