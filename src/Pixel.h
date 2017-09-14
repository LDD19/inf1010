#ifndef PIXEL_H
#define PIXEL_H

#include <cstdint>



class Pixel
{
public:
	Pixel();
	~Pixel();

	Pixel(uint8_t tauxRouge, uint8_t tauxVert, uint8_t tauxBleu);

    uint8_t getTauxRouge();
    uint8_t getTauxVert();
    uint8_t getTauxBleu();

	void modifierTeinteRouge(int8_t incrementRouge);
	void modifierTeinteVert(int8_t incrementVert);
	void modifierTeinteBleu(int8_t incrementBleu);
		
	void afficherPixel() const;

private:
	uint8_t tauxRouge_;
	uint8_t tauxVert_;
	uint8_t tauxBleu_;
};

#endif
