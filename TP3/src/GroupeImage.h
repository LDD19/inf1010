#ifndef GROUPE_IMAGE_H
#define GROUPE_IMAGE_H

#include <vector>
#include <string>

#include "Image.h"

class GroupeImage {
public:
    /**
     * Constructeur par défaut.
     */
    GroupeImage();

    /**
     * Destructeur.
     */
    ~GroupeImage();

    /**
     * Cette méthode convertit toutes les images en noir et blanc.
     */
    void toutMettreEnNB();

    /**
     * Cette méthode convertit toutes les images en gris.
     */
    void toutMettreEnGris();

    /**
     * Cette méthode convertit toutes les images en couleurs.
     */
    void toutMettreEnCouleur();

    /**
     * Cette méthode enregistre toutes les images.
     *
     * @param base Le dossier de base.
     */
    void toutEnregistrer(const std::string base) const;

    /*************
     * Mutateurs *
     *************/

    /**
     * Cette méthode ajoute une image dans le groupe.
     *
     * @param image Le pointeur de l'image à ajouter.
     * @return Après succès, la valeur `true` est retournée, sinon `false`.
     */
    bool ajouterImage(Image* image);

    /**
     * Cette méthode supprime une image du groupe.
     *
     * @param nom Le nom de l'image à supprimer.
     * @return Après succès, la valeur `true` est retournée, sinon `false`.
     */
    bool retirerImage(const std::string& nom);

    /**************
     * Accesseurs *
     **************/

    /**
     * Cette méthode retourne la taille du groupe.
     *
     * @return La taille du groupe.
     */
    uint_t obtenirTaille() const;

    /**
     * Cette méthode retourne une image dans le groupe.
     *
     * @param indice L'indice de l'image dans le groupe.
     * @return Un pointeur vers l'image si le nom est valide, sinon `nullptr`.
     */
    Image* obtenirImage(uint_t indice) const;

    /**
     * Cette méthode retourne le nombre d'images dans le groupe.
     *
     * @return Le nombre d'images dans le groupe.
     */
    uint_t obtenirNombreImages() const;

    /*************************
     * Opérateurs surchargés *
     *************************/

    GroupeImage& operator+=(Image* image);
    GroupeImage& operator-=(Image* image);
    friend std::ostream& operator<<(std::ostream& os, const GroupeImage& image);
    Image* operator[](const unsigned int& indice) const;

private:
    /* Les images dans le groupe. */
    std::vector<Image*> images_;
};

#endif
