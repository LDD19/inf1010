/**************************************************
 * Titre: Travail pratique #2 - Pixel.h
 * Date: Septembre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/

#ifndef PIXEL_H
#define PIXEL_H

#include <stdint.h>
#include <ostream>

/**
 * This class defines a pixel. It consists of a red, green and blue value.
 */
class Pixel
{
public:
    /**
     * Default constructor.
     */
    Pixel();

    /**
     * Destructor.
     */
    ~Pixel();

    /**
     * Overloaded constructor.
     *
     * @param r The red value of the pixel.
     * @param g The green value of the pixel.
     * @param b The blue value of the pixel.
     */
    Pixel(uint8_t tauxRouge, uint8_t tauxVert, uint8_t tauxBleu);

    /**
     * Copy constructor.
     *
     * @param pixel The object to copy from.
     */
    Pixel(const Pixel& pixel);

    /**
     * This method returns the red value of the pixel.
     *
     * @return The red value of the pixel.
     */
    uint8_t obtenirTauxRouge() const;

    /**
     * This method returns the green value of the pixel.
     *
     * @return The green value of the pixel.
     */
    uint8_t obtenirTauxVert() const;

    /**
     * This method returns the blue value of the pixel.
     *
     * @return The blue value of the pixel.
     */
    uint8_t obtenirTauxBleu() const;

    /**
     * This method increments the red value of the pixel.
     *
     * @param r The red value to add.
     */
    void modifierTeinteRouge(int incrementRouge);

    /**
     * This method increments the green value of the pixel.
     *
     * @param g The green value to add.
     */
    void modifierTeinteVert(int incrementVert);

    /**
     * This method increments the blue value of the pixel.
     *
     * @param b The blue value to add.
     */
    void modifierTeinteBleu(int incrementBleu);

    /**
     * This method prints the red, green and blue values of the pixel.
     */
    void afficherPixel() const;

    /**
     * This method returns the pixel as a single character, either 'R', 'G',
     * 'B' or 'Q'.
     *
     * @return The character representing the pixel.
     */
	char asChar() const;

    //***********************
    // overloaded operators *
    //***********************

    bool operator==(const Pixel& p) const;

    bool operator==(char c) const;

    friend bool operator==(char c, const Pixel& p);

    friend std::ostream& operator<<(std::ostream& o, const Pixel& p);

private:
    /**
     * The red value of the pixel.
     */
    uint8_t tauxRouge_;

    /**
     * The green value of the pixel.
     */
    uint8_t tauxVert_;

    /**
     * The blue value of the pixel.
     */
    uint8_t tauxBleu_;
};

#endif
