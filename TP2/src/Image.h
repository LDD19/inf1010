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
    Image(const std::string& nomImage, uint_t nombrePixelHauteur, uint_t nombrePixelLargeur);

    /**
     * Copy constructor.
     *
     * @param image The object to copy from.
     */
    Image(const Image& image);

    /**
     * This method doubles the height of the image.
     */
    void doublerTailleEnHauteur();

    /**
     * This method doubles the width of the image.
     */
    void doublerTailleEnLargeur();

    /**
     * This method returns the height of the image.
     *
     * @return The height of the image.
     */
    uint_t obtenirTailleHauteur() const;

    /**
     * This method returns the width of the image.
     *
     * @return The width of the image.
     */
    uint_t obetenirTailleLargeur() const;

    /**
     * This method returns the name of the image.
     *
     * @return The name of the image.
     */
    std::string obtenirNomImage() const;

    /**
     * This method sets the name of the image.
     *
     * @param name The new name of the image.
     */
    void modifierNomImage(const std::string& nomImage);

    /**
     * This method prints the image.
     */
    void afficherImage() const;

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
    bool ajouterPixel(Pixel& pixel, uint_t positionLargeur, uint_t positionHauteur);

    /**
     * This method returns the specified pixel.
     *
     * @param x The x location of the pixel.
     * @param y The y location of the pixel.
     *
     * @return A pointer to the specified pixel, else a NULL pointer if the
     *         specified location is out of the image.
     */
    Pixel obtenirPixel(uint_t positionLargeur, uint_t positionHauteur) const;

    /**
     * This method increments the color value of the pixel at the specified
     * location.
     *
     * @param x     The x location of the pixel.
     * @param y     The y location of the pixel.
     * @param value The value to add to the color.
     * @param color The color to modify, either 'r', 'g' or 'b'.
     */
    void augmenterTeintePixel(uint_t positionLargeur, uint_t positionHauteur, int value, char couleur);

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
    std::string nomImage_;

    /**
     * The height of the image.
     */
    uint_t nombrePixelHauteur_;

    /**
     * The width of the image.
     */
    uint_t nombrePixelLargeur_;

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
    void reallocatePixels(uint_t nombrePixelHauteur, uint_t nombrePixelLargeur);

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
