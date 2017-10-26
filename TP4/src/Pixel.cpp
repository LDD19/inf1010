/**************************************************
 * Titre: Travail pratique #3 - Pixel.cpp
 * Date:22 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#include "Pixel.h"

Pixel::Pixel() {

}

Pixel::~Pixel() {

}

bool Pixel::operator==(const Pixel& pixel) const {
    /* on compare la teinte rouge */
    if(retournerR() != pixel.retournerR())
        return false;

    /* on compare la teinte verte */
    if(retournerG() != pixel.retournerG())
        return false;

    /* on compare la teinte bleu */
    if(retournerB() != pixel.retournerB())
        return false;

    return true;
}
