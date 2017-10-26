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

    //GroupeImage groupe = GroupeImage();

    // Ajouter les 3 premieres images contenue dans le tableau de string
    // image au groupeImage1, en couleur


    // Creer un deuxieme groupe image identique au groupeImage precedent
    // en utilisant le constructeur par copie ou l'operateur egal (votre choix).
    // Nomme ce groupe groupeImage2


    // Afficher le contenu de groupeImage1


    // Afficher le contenu de groupeImage2


    // Ajouter toutes les images du tableau de string image au groupeImage2, en couleur


    // Tentez de convertir toutes les images d'un des groupes en Couleur


    // Mettre toutes les images du groupeImage1 en negatif


    // Enregistrer toutes les images du groupeImage2


    // Convertir toutes les images du groupeImage2 en gris


    // Enregistrer toutes les images du groupeImage2


    // Convertir toutes les images du groupeImage2 en Noir et Blanc


    // Enretisgrer toutes les images



    // N'oubliez pas de desallouer la memoire si necessaire


    // Permet d'afficher le contenu de la console
    PAUSE;

    // Fin du programme
    return 0;
}
