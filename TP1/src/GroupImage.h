#ifndef GROUPIMAGE_H
#define GROUPIMAGE_H

#include "Image.h"
#include "Const.h"

using namespace std;

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
     * @param type     The type of the group.
     * @param capacity The maximimum capacity of the group.
     */
    GroupImage(const string& type, uint_t capacity);

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
    void setType(const string& type);

    /**
     * This method returns the type of the group.
     *
     * @return The type of the group.
     */
    string getType() const;

    /**
     * This method returns the specified image.
     *
     * @param index The index of the image in the group.
     *
     * @return The specified image.
     */
    Image* getImage(uint_t index) const;

    /**
     * This method returns the number of images in the group.
     *
     * @return The size of the group.
     */
    uint_t getSize() const;

    /**
     * This method returns the maximum number of images in the group.
     *
     * @return The maximum size of the group.
     */
    uint_t getCapacity() const;

    /**
     * This method adds a new image to the group.
     *
     * @param image The image to add.
     */
    void addImage(Image& image);

    /**
     * This method lists the image in the group.
     */
    void printImages() const;

    /**
     * This method doubles the width of the specified image.
     *
     * @param index The index of the image.
     */
    void doubleWidth(uint_t index);

    /**
     * This method doubles the height of the specified image.
     *
     * @param index The index of the image.
     */
    void doubleHeight(uint_t index);

private:
    /**
     * The type of the group.
     */
    string type_;

    /**
     * The current size of the group.
     */
    uint_t size_;

    /**
     * The maximum capacity of the group.
     */
    uint_t capacity_;

    /**
     * The pointers to the images.
     */
    Image** images_;
};

#endif
