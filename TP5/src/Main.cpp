#ifndef PAUSE
    #ifdef _WIN32
        #include <Windows.h>
        #define PAUSE system("PAUSE")
    #else
        #include <unistd.h>
        #define PAUSE sleep(0)
    #endif
#endif

#include <iostream>
#include <string>
#include <queue>
#include <functional>

#include "GroupeImage.h"
#include "BaseDeDonnesSpecifique.h"
#include "Foncteur.h"

using namespace  std;

int main() {
    /* chemin vers les images */
    string base = "./res/";
    string originale = base + "Originale/";

    /* nom des 6 images */
	string noms[9] = {
        "Breaking-Bad.bmp",
        "Couleur.bmp",
        "Fall.bmp",
        "RM.bmp",
        "SolarEclipse.bmp",
        "Monkey.bmp",
        "WiC.bmp",
        "Sloth.bmp",
        "Green.bmp"
    };

    /* on cr�e une file avec les images */
    queue<Image*> images;
    for(string nom : noms) {
        Image* image = new Image(originale+nom, TypeImage::Couleurs);
        images.push(image);
    }

    /* on cr�e 3 groupes d'images */
	GroupeImage groupe1;
	GroupeImage groupe2;
	GroupeImage groupe3;

    /* on cr�e une base de donn�es */
    BaseDeDonnesSpecifique db;

    /* on y ajoute les 3 groupes */
    db += &groupe1;
    db += &groupe2;
    db += &groupe3;

    /* on ajoute les �l�ments de mani�re uniforme aux groupes */
	cout << "\tCHARGEMENT DES IMAGES\n" << endl;
    while(!images.empty()) {
        static int cntr = 1;

        /* on choisit � quel groupe il faut l'ajouter */
        Image* i = images.front();
        switch(cntr++) {
            case 1: db.associerImage(&groupe1, i); break;
            case 2: db.associerImage(&groupe2, i); break;
            case 3: db.associerImage(&groupe3, i); cntr = 1; break;
        }

        /* on enl�ve l'�l�ment de la file*/
        images.pop();
    }
	cout << endl;
	
    /* on affiche la base de donn�es au complet */
	cout << "\tAFFICHAGE DE LA BASE DE DONN�ES\n" << endl;;
    cout << db;


    /* on convertit une image au hasard dans chaque groupe */
    cout << "\tCONVERSION D'IMAGES\n" << endl;
    FoncteurRandom r(0, 2);

    /* on convertit une image du groupe 1 en n�gatif */
    groupe1.obtenirImage(r())->toutMettreEnNegatif();

    /* on convertit une image du groupe 2 en gris */
    groupe2.obtenirImage(r())->convertirGris();

    /* on convertit une image du groupe 3 en noir et blanc */
    groupe3.obtenirImage(r())->convertirNB();
	
	/* TRAITEMENT DU GROUPE 1 */
	cout << "\n\tCALCUL DES MOYENNES\n" << endl;

    /* on affiche celle du groupe 1 */
    double moy = groupe1.obtenirIntensiteMoyenne();
    cout << "L'intensit� moyenne du groupe 1 est de " << moy << "." << endl;
    cout << endl;

    /* on affiche toutes les images avec une intensit� inf�rieure  */
    for(Image* image : db.obtenirListeImages()) {
        double m = image->retournerIntensiteMoyenne();
        string nom = image->obtenirNomImage();

        if(image->retournerIntensiteMoyenne() < moy)
            cout << "L'intensit� moyenne de l'image " << nom << " est de " << m << "." << endl;
    }

	/* TRAITEMENT DU GROUPE 2 */
	cout << "\n\tCALCUL DE LA TAILLE\n" << endl;

    /* on affiche celle du groupe 2 */
    moy = groupe2.obtenirTailleMoyenne();
    cout << "La taille moyenne du groupe 2 est de " << moy << "." << endl;

    /* on affiche le nombre d'images dans la base de donn�es */
    uint_t taille = db.obtenirListeImages().size();
    cout << "Il y a " << taille << " images dans la base de donn�es." << endl;

    /*
     * Trouver et afficher le nombre d'images qui ont une tailles plus grande que
     * la moyenne calcul�e. Utiliser les fonctions std::bind et std::placeholders
     * pour effectuer le travail.
     *
     * FIXME: why the fuck on utiliserait ces fonctions?
     */

    /* on compte les images */
    list<Image*> liste = db.obtenirListeImages();
    uint_t nb = count_if(liste.begin(), liste.end(),
        [&moy](Image* img) {
            return (img->obtenirTaille() > moy);
        }
    );
    cout << "Il y a " << nb << " images plus grandes que la moyenne." << endl;

    /*
     * FIXME: Je ne comprend pas pourquoi ils nous font faire �a, on veut le nombre
     * d'images totales dont la est taille plus grande que la moyenne. L�, ils nous
     * font juste compter celles fesant partie du groupe 2...
     */

    groupe2.supprimerElements(
        bind(
            [](double t, double m) {
                return (t < m);
            },
            bind(
                FoncteurObtenirTailleImage(),
                placeholders::_1
            ),
            moy
        )
    );

	/* TRAITEMENT DU GROUPE 3 */
    cout << "\n\tCONVERSION EN NOIR ET BLANC\n" << endl;

    /* on convertit les images */
    groupe3.appliquerFoncteurUnaire(FoncteurMettreEnBN());

    cout << "\n\tENREGISTREMENT DES IMAGES\n" << endl;

    /* on enregistre toutes les images */
    groupe3.toutEnregistrer(base);

    /* permet d'afficher la console sous Windows */
    PAUSE;

    /* on lib�re la m�moire */
    for_each(liste.begin(), liste.end(),
        [](Image* img) {
            delete img;
        }
    );

    /*
     * En executant `valgrind`, soit
     *
     * $ make
     * $ valgrind ./build/image
     * 
     * on obtient "All heap blocks were freed -- no leaks are possible". Par
     * cons�quent, il n'y a aucune fuite de m�moire dans notre programme.
     */

    /* fin du programme */
    return 0;
}
