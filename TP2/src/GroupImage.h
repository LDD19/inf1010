/**************************************************
 * Titre: Travail pratique #2 - GroupImage.h
 * Date: Septembre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/

#ifndef GROUPIMAGE_H
#define GROUPIMAGE_H

#include <vector>
#include <ostream>

#include "Image.h"
#include "Const.h"

/**
 * This class defines a group of image. It has a name and a set of images.
 *
 * We store pointer to the image rather than copy its structure. The problem
 * with copying the structure is that we're duplicating a pointer to a
 * dynamically allocated area of memory. This, in turn, would cause the
 * pixels data of the added image to be freed twice, corrupting the memory.
 *
 * One solution would be deep copying the whole image object, but that isn't
 * really efficient. Simply storing the pointer to the image object is perfect
 * for speed and memory safety.
 */
class GroupImage
{
public:
    /**
     * Default constructor.
     */
    GroupImage();

    /**
     * Destructor.
     */
    ~GroupImage();

    /**
     * Overloaded constructor.
     *
     * @param type The type of the group.
     */
    GroupImage(const std::string& type, uint_t capaciteImages);

    /**
     * Copy constructor.
     *
     * @param group The object to copy from.
     */
    GroupImage(const GroupImage& group);

    /**
     * This method sets the type of the group.
     *
     * @param type The type of the group.
     */
    void modifierType(const std::string& type);

    /**
     * This method returns the type of the group.
     *
     * @return The type of the group.
     */
    std::string obtenirType() const;

    /**
     * This method returns the specified image.
     *
     * @param index The index of the image in the group.
     *
     * @return The specified image.
     */
    Image* obtenirImage(uint_t indiceImage) const;

    /**
     * This method returns the number of images in the group.
     *
     * @return The size of the group.
     */
    uint_t obtenirTailleGroup() const;

    /**
     * This method returns the maximum number of images in the group.
     *
     * @return The maximum size of the group.
     */
    uint_t obtenirCapaciteGroup() const;

    /**
     * This method adds a new image to the group.
     *
     * @param image The image to add.
     */
    void ajouterImage(Image& image);

    /**
     * This method removes an image from the group.
     *
     * @param name The name of the image to remove.
     */
    void retirerImage(const std::string& name);

    /**
     * This method lists the image in the group.
     */
    void afficherImages() const;

    /**
     * This method doubles the width of the specified image.
     *
     * @param index The index of the image.
     */
    void doublerTailleImageEnLargeur(uint_t indiceImage);

    /**
     * This method doubles the height of the specified image.
     *
     * @param index The index of the image.
     */
    void doublerTailleImageEnHauteur(uint_t indiceImage);

    //***********************
    // overloaded operators *
    //***********************

    GroupImage& operator+=(Image& i);

    GroupImage& operator-=(const Image& i);

    friend std::ostream& operator<<(std::ostream& o, const GroupImage& g);

private:
    /**
     * The type of the group.
     */
    std::string type_;

    /**
     * The current capcity of the group.
     */
    uint_t capaciteImages_;

    /**
     * The pointers to the images.
     */
    std::vector<Image*> images_;
};

#endif
