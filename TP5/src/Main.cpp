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

    /* on crée une file avec les images */
    queue<Image*> images;
    for(string nom : noms) {
        Image* image = new Image(originale+nom, TypeImage::Couleurs);
        images.push(image);
    }

    /* on crée 3 groupes d'images */
    GroupeImage groupe1;
    GroupeImage groupe2;
    GroupeImage groupe3;

    /* on crée une base de données */
    BaseDeDonnesSpecifique db;

    /* on y ajoute les 3 groupes */
    db += &groupe1;
    db += &groupe2;
    db += &groupe3;

    /* on ajoute les éléments de manière uniforme aux groupes */
    cout << "\tCHARGEMENT DES IMAGES\n" << endl;
    while(!images.empty()) {
        static int cntr = 1;

        /* on choisit à quel groupe il faut l'ajouter */
        Image* i = images.front();
        switch(cntr++) {
            case 1: db.associerImage(&groupe1, i); break;
            case 2: db.associerImage(&groupe2, i); break;
            case 3: db.associerImage(&groupe3, i); cntr = 1; break;
        }

        /* on enlève l'élèment de la file*/
        images.pop();
    }
    cout << endl;
    
    /* on affiche la base de données au complet */
    cout << "\tAFFICHAGE DE LA BASE DE DONNÉES\n" << endl;;
    cout << db;


    /* on convertit une image au hasard dans chaque groupe */
    cout << "\tCONVERSION D'IMAGES\n" << endl;
    FoncteurRandom r(0, 2);

    /* on convertit une image du groupe 1 en négatif */
    groupe1.obtenirImage(r())->toutMettreEnNegatif();

    /* on convertit une image du groupe 2 en gris */
    groupe2.obtenirImage(r())->convertirGris();

    /* on convertit une image du groupe 3 en noir et blanc */
    groupe3.obtenirImage(r())->convertirNB();
    
    /* TRAITEMENT DU GROUPE 1 */
    cout << "\n\tCALCUL DES MOYENNES\n" << endl;

    /* on affiche celle du groupe 1 */
    double moy = groupe1.obtenirIntensiteMoyenne();
    cout << "L'intensité moyenne du groupe 1 est de " << moy << "." << endl;
    cout << endl;

    /* on affiche toutes les images avec une intensité inférieure  */
    for(Image* image : db.obtenirListeImages()) {
        double m = image->retournerIntensiteMoyenne();
        string nom = image->obtenirNomImage();

        if(image->retournerIntensiteMoyenne() < moy)
            cout << "L'intensité moyenne de l'image " << nom << " est de " << m << "." << endl;
    }

    /* TRAITEMENT DU GROUPE 2 */
    cout << "\n\tCALCUL DE LA TAILLE\n" << endl;

    /* on affiche celle du groupe 2 */
    moy = groupe2.obtenirTailleMoyenne();
    cout << "La taille moyenne du groupe 2 est de " << moy << "." << endl;

    /* on affiche le nombre d'images dans la base de données */
    uint_t taille = db.obtenirListeImages().size();
    cout << "Il y a " << taille << " images dans la base de données." << endl;

    /*
     * Trouver et afficher le nombre d'images qui ont une tailles plus grande que
     * la moyenne calculée. Utiliser les fonctions std::bind et std::placeholders
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
     * FIXME: Je ne comprend pas pourquoi ils nous font faire ça, on veut le nombre
     * d'images totales dont la est taille plus grande que la moyenne. Là, ils nous
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

    /* on libère la mémoire */
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
     * conséquent, il n'y a aucune fuite de mémoire dans notre programme.
     */

    /* fin du programme */
    return 0;
}
