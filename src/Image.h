#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include "Const.h"

#include <iostream>

using namespace std;

class Image
{
public:
	Image();
	~Image();

	Image(const string& nomImage, uint8_t nombrePixelHauteur, uint8_t nombrePixelLargeur);

	void doublerTailleEnLargeur();
	void doublerTailleEnHauteur();

	uint_t obtenirNombrePixelHauteur() const;
	uint_t obtenirNombrePixelLargeur() const;
	string obtenirNomImage() const;

	void modifierNomImage(const string & nomImage);

	void afficherImage() const;

	bool ajouterPixel(Pixel & pixel,unsigned int positionLargeur, unsigned int positionHauteur);
	Pixel obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const ;
	void augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur);


private :
	string nomImage_;
	unsigned int nombrePixelEnHauteur_;
	unsigned int nombrePixelEnLargeur_;
	Pixel** pixels_;

};

#endif
