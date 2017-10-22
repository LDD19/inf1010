/**************************************************
 * Titre: Travail pratique #3 - Main.cpp
 * Date:22 Octobre 2017
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

    GroupeImage groupe = GroupeImage();

	/* ajouter toutes les images au groupe en tant qu'image en couleurs */
    for(string img : images) {
        string chemin = originale + img;
        Image* image = new Image(chemin, TypeImage::Couleurs);
        groupe += image;
    }

	/* afficher le contenu du groupe d'image */
    cout << groupe;

	/* convertir toutes les images en couleurs */
    groupe.toutMettreEnCouleur();
    cout << endl;

	/* enregistrer toutes les images convertie */
    groupe.toutEnregistrer(base);
    cout << endl;

	/* convertir toutes les images en nuance de gris */
    groupe.toutMettreEnGris();
    cout << endl;

	/* enregistrer toutes les images grises */
    groupe.toutEnregistrer(base);
    cout << endl;

	/* convertir toutes les images en noir et blanc */
    groupe.toutMettreEnNB();
    cout << endl;

	/* enregistrer toutes les images */
    groupe.toutEnregistrer(base);
    cout << endl;

    /* on libère la mémoire */
    for(int i = groupe.obtenirTaille()-1; i >= 0; i--) {
        /* on s'assure que l'image est valide */
        Image* image = groupe.obtenirImage(i);
        if(image == nullptr)
            continue;

        /* tant qu'à y être, on retire l'image */
        groupe.retirerImage(image->obtenirNomImage());

        /* on libère la mémoire */
        delete image;
    }

    PAUSE;
    return 0;
}
