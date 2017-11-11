#ifndef FONCTEUR_H
#define FONCTEUR_H

#include "GroupeImage.h"
#include <stdlib.h>
#include <random>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 3

/**
 * Ce foncteur compare deux images.
 */
class FoncteurEgalImages {
public:
    /**
     * Constructeur par valeurs.
     *
     * @param image Une image que l'on souhaite comparer avec d'autres.
     */
    FoncteurEgalImages(Image* image) {
        image_ = image;
    }

    /**
     * Destructeur.
     */
    ~FoncteurEgalImages() {

    }

    /**
     * Cette méthode compare l'image du foncteur avec une autre.
     *
     * @param comp L'image a comparer avec celle du foncteur.
     *
     * @return Si les images sont identique, `true`, sinon `false`.
     */
    bool operator() (Image* comp) const {
        if(comp != nullptr)
            return (*image_ == *comp);

        return false;
    }

private:
    /** L'image a comparer avec d'autres. */
    Image* image_;
};

/**
 * Ce foncteur compare le nom de deux images.
 */
class FoncteurImagesDeMemeNom {
public:
    /**
     * Constructeur par valeurs.
     *
     * @param nom Un nom que l'on souhaite comparer avec d'autres.
     */
    FoncteurImagesDeMemeNom(const std::string& nom) :
        nom_(nom) {
        
    }

    /**
     * Destructeur.
     */
    ~FoncteurImagesDeMemeNom() {

    }

    /**
     * Cette méthode compare le nom du foncteur avec un autre.
     *
     * @param comp Le nom a comparer avec celui du foncteur.
     *
     * @return Si les noms sont identique, `true`, sinon `false`.
     */
    bool operator() (const Image* comp) const {
        if(comp != nullptr)
            return (nom_ == *comp);

        return false;
    }

private:
    /** Le nom a comparer avec d'autres. */
    std::string nom_;
};

/**
 * Ce foncteur obtient la taille d'une image.
 */
class FoncteurObtenirTailleImage {
public:
    /**
     * Constructeur par défaut.
     */
    FoncteurObtenirTailleImage() {

    }

    /**
     * Destructeur.
     */
    ~FoncteurObtenirTailleImage() {

    }

    /**
     * Cette méthode retourne la taille de l'image.
     *
     * @param image L'image que l'on souhaite obtenir la taille.
     *
     * @return La taille de l'image.
     */
    uint_t operator() (const Image* image) const {
        return image->obtenirTaille();
    }
};

/**
 * Ce foncteur met une image en gris.
 */
class FoncteurMettreEnGris {
public:
    /**
     * Constructeur par défaut.
     */
    FoncteurMettreEnGris() {

    }

    /**
     * Destructeur.
     */
    ~FoncteurMettreEnGris() {

    }

    /**
     * Cette méthode met une image en gris.
     *
     * @param image L'image à mettre en gris.
     */
    void operator() (Image* image) const {
        if(image != nullptr)
            image->convertirGris();
    }
};

/**
 * Ce foncteur met une image en couleur.
 */
class FoncteurMettreEnCouleur {
public:
    /**
     * Constructeur par défaut.
     */
    FoncteurMettreEnCouleur() {

    }

    /**
     * Destructeur.
     */
    ~FoncteurMettreEnCouleur() {

    }

    /**
     * Cette méthode met une image en couleur.
     *
     * @param image L'image à mettre en couleur.
     */
    void operator() (Image* image) const {
        if(image != nullptr)
            image->convertirCouleur();
    }
};

/**
 * Ce foncteur met une image en noir et blanc.
 */
class FoncteurMettreEnBN {
public:
    /**
     * Constructeur par défaut.
     */
    FoncteurMettreEnBN() {

    }

    /**
     * Destructeur.
     */
    ~FoncteurMettreEnBN() {}

    /**
     * Cette méthode met une image en noir et blanc.
     *
     * @param image L'image à mettre en noir et blanc.
     */
    void operator() (Image* image) const {
        if(image != nullptr)
            image->convertirNB();
    }
};

/**
 * Ce foncteur met une image en négatif.
 */
class FoncteurMettreEnNegatif {
public:
    /**
     * Constructeur par défaut.
     */
    FoncteurMettreEnNegatif() {

    }

    /**
     * Destructeur.
     */
    ~FoncteurMettreEnNegatif() {

    }

    /**
     * Cette méthode met une image en négatif.
     *
     * @param image L'image à mettre en négatif.
     */
    void operator() (Image* image) const {
        if(image != nullptr)
            image->toutMettreEnNegatif();
    }
};

/**
 * Ce foncteur génère des nombres aléatoires.
 */
class FoncteurGenerateurNombresAlea {
public:
    /**
     * Constructeur par défaut.
     */
    FoncteurGenerateurNombresAlea() {
        min_ = RAND_MIN_DEFAUT;
        max_ = RAND_MAX_DEFAUT;

        /* on initialise la distribution uniforme */
        distribution_ = std::uniform_int_distribution<uint_t>(min_, max_);
    }

    /**
     * Constructeur par paramètres.
     *
     * @param min La valeur minimale du générateur de nombres aléatoires.
     * @param max La valeur maximale du générateur de nombres aléatoires.
     */
    FoncteurGenerateurNombresAlea(uint_t min, uint_t max) {
        /* on s'assure que les paramètre sont valides */
        if(max <= min) {
            min_ = RAND_MIN_DEFAUT;
            max_ = RAND_MAX_DEFAUT;
        } else {
            min_ = min;
            max_ = max;
        }

        /* on initialise la distribution uniforme */
        distribution_ = std::uniform_int_distribution<uint_t>(min_, max_);
    }

    /**
     * Destructeur.
     */
    ~FoncteurGenerateurNombresAlea() {

    }

    /**
     * Cette méthode retourne un nombre aléatoire.
     *
     * @return Un nombre aléatoire entre les bornes du foncteur.
     */
    uint_t operator() () {
        return distribution_(generateur_);
    }

private:
    /** La valeur minimale du générateur de nombres aléatoires. */
    uint_t min_;

    /** La valeur maximale du générateur de nombres aléatoires. */
    uint_t max_;

    /** Le générateur de nombre aléatoire. */
    std::default_random_engine generateur_;

    /** La distribution utilisée pour générer des nombres. */
    std::uniform_int_distribution<uint_t> distribution_;
};

#endif
