/**************************************************
 * Titre: Travail pratique #4 - Main.cpp
 * Date:28 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/

#ifdef _WIN32 
    #include <Windows.h>
    #define PAUSE system("PAUSE")
#else
    #include <unistd.h>
    #define PAUSE sleep(0)
#endif

#include <iostream>
#include <string>

#include "GroupeImage.h"

using namespace std;

int main() {
    /* chemin vers les images */
    string base = "./res/";
    string originale = base + "Originale/";

    /* nom des 6 images dans un tableau de string */
    string images[6] = {
        "Breaking-Bad.bmp",
        "Couleur.bmp",
        "Fall.bmp",
        "RM.bmp",
        "SolarEclipse.bmp",
        "WiC.bmp"
    };

    /* créer un groupe d'image */
    cout << "***************************" << endl;
    cout << "Création du groupe d'images" << endl;
    cout << "***************************" << endl << endl;

    GroupeImage groupeImage1 = GroupeImage();

    /* on ajoute les 3 premières images contenue dans le tableau */
    Image* image0 = new Image(originale+images[0], TypeImage::Couleurs);
    Image* image1 = new Image(originale+images[1], TypeImage::Couleurs);
    Image* image2 = new Image(originale+images[2], TypeImage::Couleurs);

    groupeImage1 += image0;
    groupeImage1 += image1;
    groupeImage1 += image2;

    /* on crée une copie du premier groupe */
    GroupeImage groupeImage2(groupeImage1);

    /* on affiche le premier groupe */
    cout << groupeImage1;

    /* on affiche le deuxième groupe */
    cout << groupeImage2;

    /* on ajoute toutes les images dans le deuxième groupe */
    cout << endl;
    for(string nom : images) {
        Image* image = new Image(originale+nom, TypeImage::Couleurs);

        /* si l'ajout ne succède pas, on libère l'image immédiatement */
        if(!groupeImage2.ajouterImage(image))
            delete image;
    }

    /* on convertit le deuxième groupe en couleur */
    cout << endl;
    groupeImage2.toutMettreEnCouleur();

    /* on met les images du premier groupe en négatif */
    cout << endl;
    groupeImage1.toutMettreEnNegatif();

    /* on sauvegarde le deuxième groupe */
    groupeImage2.toutEnregistrer(base);
    cout << endl;

    /* on convertit le deuxième groupe en gris */
    groupeImage2.toutMettreEnGris();
    cout << endl;

    /* on sauvegarde le deuxième groupe */
    groupeImage2.toutEnregistrer(base);
    cout << endl;

    /* on convertit le deuxième groupe en noir et blanc */
    groupeImage2.toutMettreEnNB();
    cout << endl;

    /* on enregistrer juste tout */
    groupeImage2.toutEnregistrer(base);
    groupeImage1.toutEnregistrer(base);

    /* on libère la mémoire */
    for(uint_t i = 0; i < groupeImage1.obtenirTaille(); i++) {
        Image* image = groupeImage1.obtenirImage(i);
        if(image != nullptr) 
            delete image;
    }

    for(uint_t i = 0; i < groupeImage2.obtenirTaille(); i++) {
        Image* image = groupeImage2.obtenirImage(i);
        if(image != nullptr) 
            delete image;
    }

    PAUSE;
    return 0;
}
