/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * Date: Septembre 2017
 * Auteur: 
**************************************************/

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"

#include <string>
#include <iostream>

using namespace std;

/**
 *Question 1
 *Quelle est l’utilité de l’opérateur = et du constructeur par copie?
 *
 *Un constructeur par copie copie les valeurs d’un premier objet créé par 
 *le constructeur par défaut dans une nouvelle addresse mémoire aux valeurs 
 *identiques. L’opérateur = fait environ la même chose ; il affecte la valeur
 *d’un objet par une nouvelle valeur.
 *
 *Question 2
 *Dans quel cas est-il absolument nécessaire de les implémenter?
 *
 *Il est nécessaire d’implémenter un constructeur par copie lorqu’on copie une 
 *classe ayant un attribut qui est un pointeur X qui est situé sur la même addresse 
 *mémoire. Nécessairement, on veut garder les deux valeurs différentes du pointeur
 *X de chaque classe, mais sans constructeur par copie, la première valeur de X
 *sera supprimée avec delete en passant à la deuxième classe.
 *
 *Question 2
 *Qu’est-ce qui différencie l’opérateur = du constructeur par copie?
 *
 *L'opérateur = est appelée si on essaie d’affecter un autre objet après
 *l’initialisation alors que le constructeur par copie est appelé lors de 
 *la création de l’objet. Pour éviter des problèmes de compilation, il faut
 *supprimer le premier objet (qui est déjà affecté par l’opérateur =) avant
 *de passer au nouveau objet qu’on veut affecter par =.
 */

int main() {
    /* 1-Creez 9 pixels rouge  (255,0,0) */
    Pixel rouges[9];
    for(int i = 0; i < 9; i++)
        rouges[i] = Pixel(255, 0, 0);
	
    /* 2-Creez 9 pixels verts (0,255,0) */
    Pixel verts[9];
    for(int i = 0; i < 9; i++)
        verts[i] = Pixel(0,255,0);

    /* 3-Creez une image de taille 3*3 */
    Image image0 = Image("Image Rouge", 3, 3);
	
    /* 4-Ajouter à l'image créées à l'étape 3 les pixels rouges */
    for(int j = 0; j < 3; j++)
        for(int i = 0; i < 3; i++)
            image0.ajouterPixel(rouges[i+3*j],i, j);
	
    /* 5-Creez une deuxième image de taille 3*3 */
    Image image1 = Image("Image Verte", 3, 3)	;

    /* 6-Ajouter à l'image créées à l'étape 3 les pixels verts */
    for(int j = 0; j < 3; j++)
        for(int i = 0; i < 3; i++)
            image1.ajouterPixel(verts[i+3*j],i, j);

    /* 7-Creez un groupe d'image avec une capacite de 3 */
    GroupImage group = GroupImage("Album Photo", 3);

    /* 8-Ajoutez les deux images crées precédament au groupe */
    group+=image0;
    group+=image1;
	
    /* 9-Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités */
    image0.augmenterTeintePixel(1, 1, 50, 'b');
	 
    /* 10-Diminuer la teinte rouge du Pixel (1,1) de l'image 0 de 255 unités */
    image0.augmenterTeintePixel(1, 1, -255, 'r');

    /* 11-Augmentez la teinte bleu du Pixel (2,1) de l'image 1 de 100 unités */
    image1.augmenterTeintePixel(2, 1, 100, 'b');

    /* 12-Afficher le groupe d'image */
    cout << group;
	
    /* 13-Supprimer la premiere image du groupe d'image */
    group-=image0;
	
    /* 14-Afficher le groupe d'image */
    cout << group;

	return 0;
}
