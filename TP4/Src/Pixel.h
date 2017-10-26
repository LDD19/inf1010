//
// Created by Gabriel Bernard
//

#ifndef TP3_PIXEL_H
#define TP3_PIXEL_H

typedef unsigned char unchar;

#define VALEUR_MAX_PIXEL 255
#define VALEUR_MIN_PIXEL 0

#include <iostream>
#include "TypePixel.h"

class Pixel
{
public:
    Pixel();
	Pixel(TypePixel tp);
	~Pixel();
	TypePixel getType() const;

    // Test valeur Pixel
    unsigned int testPixel(const unsigned int& valeur) const;
    unchar testPixel(const unchar& valeur) const;

    // Rendre virtuelles pures et modifier en accordance
    // partout où necessaire (elles sont implémentées ici seulement 
    // pour que le code compile, mais doivent etre modifiee)
    unchar retournerR() {return 0;};
    unchar retournerG() {return 0;};
    unchar retournerB() {return 0;};

	bool operator==(const Pixel& pixel) const;

protected:
	TypePixel type_;
	
};

#endif // PIXEL_H