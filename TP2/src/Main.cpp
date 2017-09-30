/**************************************************
 * Titre: Travail pratique #2 - Main.cpp
 * Date: Septembre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"

#include <string>
#include <iostream>

using namespace std;

/**
 * Question 1:
 * Quelle est l’utilité de l’opérateur = et du constructeur par copie?
 *
 * Un constructeur par copie copie les valeurs d’un objet existant dans une
 * nouvelle addresse mémoire. Il alloue de la nouvelle mémoire.
 *
 * Par défaut, l’opérateur = fait environ la même chose. Il affecte à chaque
 * attributs de l'objet à sa gauche les attributs de l'objet à droite. Il copie
 * essentiellement la classe, mais sans allouer un nouvel emplacement de
 * mémoire.
 *
 * Question 2:
 * Dans quel cas est-il absolument nécessaire de les implémenter?
 *
 * Il est nécessaire d’implémenter un constructeur par copie lorqu’on copie un
 * objet contenant un pointeur vers de la mémoire allouée dynamiquement ou
 * encore localement sur la pile. En copiant un tel pointeur, il en résulte que
 * deux objects différents contiennent le même pointeur.
 *
 * Puisque la durée de vie de l'autre objet n'est pas nécessairement connue,
 * alors la durée de vie de la mémoire pointée par ce pointeur est aussi
 * incertaine. Du coup, il est très probable qu'il y ait des fautes de mémoires
 * pouvant mener à la termination du programme.
 *
 * En implémentant un constructeur par copie ou l'opérateur =, il est possible
 * de copier la mémoire pointée par ce pointeur vers un nouvel emplacement. Par
 * conséquent, on obtient 2 pointeurs différents pointant chacun vers de la
 * mémoire différente.
 *
 * Question 3:
 * Qu’est-ce qui différencie l’opérateur = du constructeur par copie?
 *
 * L'opérateur = n'alloue pas de nouvel objet, tandis que le constructeur par
 * copie crée un nouvel objet en l'initialisant.
 * 
 * {@code
 *      // constructeur de paramètres (+1 objet)
 *      Base a(...);
 *      // constructeur par copie (+1 objet)
 *      Base b(a);
 *      // constructeur par défaut (+1 object)
 *      Base c;
 *      // copie des attributs avec l'opérateur = (aucun nouvel objet)
 *      c = a;
 *      // constructeur par copie, sémantique du c++ (+1 objet)
 *      Base d = c;
 *      // constructeur par copie dans le tas (+1 objet)
 *      Base* e = new Base(d);
 *      delete e;
 * }
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
