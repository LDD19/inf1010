#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include "Const.h"

#include <string>
#include <ostream>

/**
 * This class defines an image. An image has a name and pixels data.
 */
class Image
{
public:
    /**
     * Default constructor.
     */
    Image();

    /**
     * Destructor.
     */
    ~Image();

    /**
     * Overloaded constructor.
     *
     * @param name   The name of the image.
     * @param height The height of the image.
     * @param width  The width of the image.
     */
    Image(const std::string& name, uint_t height, uint_t width);

    /**
     * Copy constructor.
     *
     * @param image The object to copy from.
     */
    Image(const Image& image);

    /**
     * Copy constructor.
     *
     * @param image The image to copy.
     */
     //Image(const Image& image);

    /**
     * This method doubles the height of the image.
     */
    void doubleHeight();

    /**
     * This method doubles the width of the image.
     */
    void doubleWidth();

    /**
     * This method returns the height of the image.
     *
     * @return The height of the image.
     */
    uint_t getHeight() const;

    /**
     * This method returns the width of the image.
     *
     * @return The width of the image.
     */
    uint_t getWidth() const;

    /**
     * This method returns the name of the image.
     *
     * @return The name of the image.
     */
    std::string getName() const;

    /**
     * This method sets the name of the image.
     *
     * @param name The new name of the image.
     */
    void setName(const std::string& name);

    /**
     * This method prints the image.
     */
    void printImage() const;

    /**
     * This method adds a Pixel to the specified location.
     *
     * @param pixel The pixel to add.
     * @param x     The x location of the pixel.
     * @param y     The y location of the pixel.
     *
     * @return True if the pixel was succesfully added, else False if the
     *         specified location is out of the image.
     */
    bool addPixel(Pixel& pixel, uint_t x, uint_t y);

    /**
     * This method returns the specified pixel.
     *
     * @param x The x location of the pixel.
     * @param y The y location of the pixel.
     *
     * @return A pointer to the specified pixel, else a NULL pointer if the
     *         specified location is out of the image.
     */
    Pixel getPixel(uint_t x, uint_t y) const;

    /**
     * This method increments the color value of the pixel at the specified
     * location.
     *
     * @param x     The x location of the pixel.
     * @param y     The y location of the pixel.
     * @param value The value to add to the color.
     * @param color The color to modify, either 'r', 'g' or 'b'.
     */
    void incrementValue(uint_t x, uint_t y, int value, char color);

    //***********************
    // overloaded operators *
    //***********************

    Image& operator=(const Image& i);

    bool operator==(const Image& i) const;

    bool operator==(const std::string& s) const;

    friend bool operator==(const std::string& s, const Image& i);

    friend std::ostream& operator<<(std::ostream& o, const Image& i);

private :
    /**
     * The name of the image.
     */
    std::string name_;

    /**
     * The height of the image.
     */
    uint_t height_;

    /**
     * The width of the image.
     */
    uint_t width_;

    /**
     * The pixels data of the image.
     */
    Pixel** pixels_;

    /**
     * This method allocates the memory for the pixels.
     */
    void allocatePixels();

    /**
     * This method reallocates the memory for the pixels. In the same way that
     * realloc() keeps the old data from malloc(), this method keeps the old
     * pixels that still fit in the new image.
     *
     * @param height The new height of the image.
     * @param width  The new width of the image.
     */
    void reallocatePixels(uint_t height, uint_t width);

    /**
     * This method frees the memory of the pixels.
     */
    void freePixels();

    /**
     * This method copies all the pixels from another image.
     *
     * @param image The image to copy pixels from.
     */
    void copyPixels(const Image& image);
};

#endif
