#ifndef PIXEL_H
#define PIXEL_H

#include <stdint.h>

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
    Pixel(uint8_t r, uint8_t g, uint8_t b);

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
    uint8_t getRed() const;

    /**
     * This method returns the green value of the pixel.
     *
     * @return The green value of the pixel.
     */
    uint8_t getGreen() const;

    /**
     * This method returns the blue value of the pixel.
     *
     * @return The blue value of the pixel.
     */
    uint8_t getBlue() const;

    /**
     * This method increments the red value of the pixel.
     *
     * @param r The red value to add.
     */
    void incrementRed(int r);

    /**
     * This method increments the green value of the pixel.
     *
     * @param g The green value to add.
     */
    void incrementGreen(int g);

    /**
     * This method increments the blue value of the pixel.
     *
     * @param b The blue value to add.
     */
    void incrementBlue(int b);

    /**
     * This method prints the red, green and blue values of the pixel.
     */
    void printPixel() const;

private:
    /**
     * The red value of the pixel.
     */
    uint8_t valueRed_;

    /**
     * The green value of the pixel.
     */
    uint8_t valueGreen_;

    /**
     * The blue value of the pixel.
     */
    uint8_t valueBlue_;
};

#endif
