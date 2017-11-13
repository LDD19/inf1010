/**************************************************
 * Titre: Travail pratique #4 - GroupeImage.h
 * Date:28 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#ifndef GROUPE_IMAGE_H
#define GROUPE_IMAGE_H

#include <list>
#include <string>
#include <algorithm>

#include "Image.h"

class GroupeImage {
public:
    /**
     * Constructeur par défaut.
     */
    GroupeImage();

    /**
     * Constructeur par copie.
     */
    GroupeImage(const GroupeImage& groupe);

    /**
     * Destructeur.
     */
    ~GroupeImage();

    /**
     * Cette méthode convertit toutes les images en noir et blanc.
     */
    void toutMettreEnNB() const;

    /**
     * Cette méthode convertit toutes les images en gris.
     */
    void toutMettreEnGris() const;

    /**
     * Cette méthode convertit toutes les images en couleurs.
     */
    void toutMettreEnCouleur() const;

    /**
     * Cette méthode convertit toutes les images en négatif.
     */
    void toutMettreEnNegatif() const;

    /**
     * Cette méthode enregistre toutes les images.
     *
     * @param base Le dossier de base.
     */
    void toutEnregistrer(const std::string base) const;

    /**
     * Cette méthode applique un foncteur unaire sur toutes les images.
     *
     * @tparam F Un type de foncteur unaire à appliquer.
     *
     * @param foncteur Le foncteur unaire à appliquer.
     */
    template <class F>
    void appliquerFoncteurUnaire(const F& foncteur) {
        std::for_each(images_.begin(), images_.end(), foncteur);
    }

    /**
     * Cette méthode enlève les images selon un prédicat unaire.
     *
     * @tparam P Un type de prédicat unaire à utiliser.
     *
     * @param predicat Le prédicat unaire à utiliser.
     */
    template <class P>
    void supprimerElements(const P& predicat) {
        /* FIXME: c'est ignoble */
        images_.erase(
            std::remove_if(
                images_.begin(),
                images_.end(),
                predicat
            ),
            images_.end()
        );
    }

    /**
     * Cette méthode affiche le nom des images dans le groupe.
     *
     * @param os La sortie de texte.
     */
    void afficherImages(std::ostream& os) const;

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
     * Cette méthode retourne une image dans le groupe.
     *
     * @param indice Le nom de l'image.
     * @return Un pointeur vers l'image si le nom est valide, sinon `nullptr`.
     */
    Image* obtenirImage(const std::string& nom) const;

    /**
     * Cette méthode retourne l'intensité moyenne des images.
     *
     * @return L'intensité moyenne des images.
     */
    double obtenirIntensiteMoyenne() const;

    /**
     * Cette méthode retourne la taille moyenne des images.
     *
     * @return La taille moyenne des images.
     */
    double obtenirTailleMoyenne() const;

    /*************************
     * Opérateurs surchargés *
     *************************/

    GroupeImage& operator+=(Image* image);
    GroupeImage& operator-=(Image* image);
    GroupeImage& operator-=(const std::string& nom);
    GroupeImage& operator=(const GroupeImage& groupe);
    friend std::ostream& operator<<(std::ostream& os, const GroupeImage& image);
    Image* operator[](const unsigned int& indice) const;

private:
    /** Les images dans le groupe. */
    std::list<Image*> images_;
};

#endif
