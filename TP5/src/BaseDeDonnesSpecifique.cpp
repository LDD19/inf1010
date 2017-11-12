#include "BaseDeDonnesSpecifique.h"
#include <assert.h>

using namespace std;

void BaseDeDonnesSpecifique::associerImage(GroupeImage* g, Image* i) {
    /* on ajoute l'image dans le groupe */
    (*g) += i;

    /* ajoute essaie d'ajoute l'image et le groupe à la base de de données */
    (*this) += i;
    (*this) += g;
}

bool BaseDeDonnesSpecifique::enleverImage(GroupeImage* g, const string& nom) {
    /* on enlève l'image du groupe */
    (*g) -= nom;

    /* on regarde si l'image existe dans un autre groupe */
    auto groupe = find_if(listS_.begin(), listS_.end(),
        [g, nom](GroupeImage* groupe) {
            return (groupe->obtenirImage(nom) != nullptr);
        }
    );

    /* on conserve l'image si un autre groupe la contient toujours */
    if(groupe != listS_.end())
        return false;

    /* on obtient l'image dans la base de données */
    auto image = find_if(listT_.begin(), listT_.end(),
        [nom](Image* image) {
            return (image->obtenirNomImage() == nom);
        }
    );

    /* l'image doit être présente */
    if(image != listT_.end()) {
        assert(false);
        return false;
    }

    /* on enlève l'image de la base de données */
    (*this) -= *image;
    return true;
}

ostream& operator<<(ostream& os, const BaseDeDonnesSpecifique& db) {
    /* on affiche toutes les images dans la base de données */
    os << "Images dans la base de données" << endl;
    os << "------------------------------" << endl;
    for_each(db.listT_.begin(), db.listT_.end(),
        [&](Image* image) {
            os << image->obtenirNomImage() << endl;
        }
    );
    os << endl;

    /* on affiche tous les groupes de la base de données */
    for_each(db.listS_.begin(), db.listS_.end(),
        [&](GroupeImage* groupe) {
            static int counter = 1;
            os << "Groupe "  << counter << endl;
            os << "--------" << endl;

            /* on affiche aussi le nom des images de chaque groupe */
            groupe->afficherImages(os);
            os << endl;
        }
    );

    return os;
}
