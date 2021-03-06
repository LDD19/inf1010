/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * Date: Septembre 2017
 * Auteur:
 **************************************************/

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"

using namespace std;

int main() {
    /* 1-Creez 9 pixels rouge  (255,0,0) */
    Pixel rouges[9];
    for(int i = 0 ; i < 9; i++)
        rouges[i] = Pixel(255, 0, 0);

    /* 2-Creez 9 pixels verts (0,255,0) */
    Pixel verts[9];
    for(int i = 0 ; i < 9; i++)
        verts[i] = Pixel(0, 255, 0);

    /* 3-Creez une image de taille 3*3 */
    Image image0 = Image("Image 0", 3, 3);

    /* 4-Ajouter à l'image créée à l'étape 3 les pixels rouges */
    for(int j = 0; j < 3; j++)
        for(int i = 0; i < 3; i++)
            image0.addPixel(rouges[i+3*j], i, j);

    /* 5-Creez une deuxième image de taille 3*3 */
    Image image1 = Image("Image 1", 3, 3);

    /* 6-Ajouter à l'image créées à l'étape 3 les pixels verts */
    for(int j = 0; j < 3; j++)
        for(int i = 0; i < 3; i++)
            image1.addPixel(verts[i+3*j], i, j);

    /* 7-Creez un groupe d'image avec une capacite de 3 */
    GroupImage group = GroupImage("Pictures", 3);

    /* 8-Ajoutez les deux images crées precédament au groupe */
    group.addImage(image0);
    group.addImage(image1);

    /* 9-Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités */
    image0.incrementValue(1, 1, 50, 'b');

    /* 10-Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités */
    image0.incrementValue(1, 1, -255, 'r');

    /* 11-Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités */
    image1.incrementValue(2, 1, 100, 'b');

    /* 12-Affichez les images de ce groupe */
    group.printImages();

    /* 13-Doublez la taille de la premiere image du groupe en largeur */
    group.getImage(0)->doubleWidth();

    /* 14-Doublez la taille de la deuxieme image du groupe en hauteur */
    group.getImage(1)->doubleHeight();

    /* 15-Afficher cette image */
    image1.printImage();

    return 0;
}
