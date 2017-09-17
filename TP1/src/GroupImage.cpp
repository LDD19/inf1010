#include "GroupImage.h"

GroupImage::GroupImage()
{
	type_ = "";
	capaciteImages_ = 0;
}

GroupImage::~GroupImage()
{
}

GroupImage::GroupImage(const string & type, unsigned int capaciteImages)
{
	type_ = type;
	capaciteImages_ = capaciteImages;
}

void GroupImage::modifierType(const string & type)
{
	type_ = type;
}

string GroupImage::obtenirType() const
{
	return type_;
}

Image GroupImage::obtenirImage(unsigned int indiceImage) const
{
	return Image();
}

unsigned int GroupImage::obtenirNombreImages() const
{
	return 0;
}

void GroupImage::ajouterImage(const Image & image)
{
}

void GroupImage::afficherImages() const
{
}

void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage)
{
}

void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage)
{
}
