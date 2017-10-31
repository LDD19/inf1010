#ifndef FONCTEUR_H
#define FONCTEUR_H

#include "GroupeImage.h"
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 3

class FoncteurEgalImages
{
public:
	FoncteurEgalImages(Image* image) {
	}
	~FoncteurEgalImages() {}

	bool FoncteurEgalImages::operator() (Image* imageAComparer) const {
	}

private:
	Image* image_;
};

class FoncteurImagesDeMemeNom
{
public:
	FoncteurImagesDeMemeNom(const std::string& nom) {
	}
	~FoncteurImagesDeMemeNom() {};

	bool operator() ( Image* image) const {
	}

private:
	std::string nom_;
};

class FoncteurObtenirTailleImage
{
public:
	FoncteurObtenirTailleImage() {}
	~FoncteurObtenirTailleImage() {}

	unsigned int operator() (const Image* image) const {
	}
};


class FoncteurMettreEnGris
{
public:
	FoncteurMettreEnGris() {}
	~FoncteurMettreEnGris() {}

	void operator() (Image* image) {
	}

};

class FoncteurMettreEnCouleur
{
public:
	FoncteurMettreEnCouleur() {}
	~FoncteurMettreEnCouleur() {}

	void operator() (Image* image) {
	}

};

class FoncteurMettreEnBN
{
public:
	FoncteurMettreEnBN() {}
	~FoncteurMettreEnBN() {}

	void operator() (Image* image) {
	}

};

class FoncteurMettreEnNegatif
{
public:
	FoncteurMettreEnNegatif() {}
	~FoncteurMettreEnNegatif() {}

	void operator() (Image* image) {
	}

};

class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea() {
	}

	FoncteurGenerateurNombresAlea(unsigned int min, unsigned int max) {
	}

	~FoncteurGenerateurNombresAlea() {}

	unsigned int operator() () const {
	}

private:
	unsigned int min_;
	unsigned int max_;
};

#endif
