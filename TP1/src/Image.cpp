#include "Image.h"

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
}

void Image::doublerTailleEnHauteur()
{
}

unsigned int Image::obtenirNombrePixelHauteur() const
{
	return 0;
}

unsigned int Image::obtenirNombrePixelLargeur() const
{
	return 0;
}

string Image::obtenirNomImage() const
{
	return string();
}

void Image::modifierNomImage(const string & nomImage)
{
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
