#include "Image.h"
//test
Image::Image()
{
	nomImage_ = "";
	nombrePixelEnHauteur_ = 0;
	nombrePixelEnLargeur_ = 0;
}

Image::~Image()
{
}

Image::Image(const string & nomImage, unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur)
{
		nomImage_ = nomImage;
		nombrePixelEnHauteur_ = nombrePixelHauteur;
		nombrePixelEnLargeur_ = nombrePixelLargeur;

}

void Image::doublerTailleEnLargeur()
{
	nombrePixelEnLargeur_ = nombrePixelEnLargeur_ * 2;
}

void Image::doublerTailleEnHauteur()
{
	nombrePixelEnHauteur_ = nombrePixelEnHauteur_ * 2;
}

unsigned int Image::obtenirNombrePixelHauteur() const
{
	return nombrePixelEnHauteur_;
}

unsigned int Image::obtenirNombrePixelLargeur() const
{
	return nombrePixelEnLargeur_;
}

string Image::obtenirNomImage() const
{
	return nomImage_;
}

void Image::modifierNomImage(const string & nomImage)
{
	nomImage_ = nomImage;
}

void Image::afficherImage() const
{

}

bool Image::ajouterPixel(Pixel & pixel, unsigned int positionLargeur, unsigned int positionHauteur)
{
	return false;
}

Pixel Image::obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const
{
	return Pixel();
}

void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int increment, char couleur)
{

}
