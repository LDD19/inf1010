/**************************************************
 * Titre: Travail pratique #4 - Image.h
 * Date:28 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/

#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <fstream>

#include "TypeImage.h"
#include "Pixel.h"

const std::string NOM_PAR_DEFAUT = "image.ppm";

class Image {
public:
    /**
     * Constructeur par défaut.
     */
    Image();

    /**
     * Constructeur par paramètres.
     *
     * @param chemin Le chemin du fichier de l'image.
     * @param type   Le type d'image.
     */
    Image(const std::string& chemin, const TypeImage& type);

    /**
     * Constructeur par copie.
     *
     * @param image La référence à l'image à copier.
     */
    Image(const Image& image);

    /**
     * Destructeur.
     */
    ~Image();

    /**
     * Cette méthode sauvegarde l'image dans un fichier.
     *
     * @param nom Le nom du fichier à enregistrer.
     */
    void sauvegarderImage(const std::string &nom = NOM_PAR_DEFAUT);

    /**
     * Cette méthode lit un fichier dans l'image.
     *
     * @param nom  Le nom de l'image.
     * @param type Le type de l'image.
     */
    void lireImage(const std::string &nom, const TypeImage& type);

    /**
     * Cette méthode convertit l'image en image noir et blanc.
     */
    void convertirNB();

    /**
     * Cette méthode convertit l'image en image grise.
     */
    void convertirGris();

    /**
     * Cette méthode convertit l'image en image de couleurs.
     */
    void convertirCouleur();

    /**
     * Cette méthode met tout les pixels de l'image en négatif.
     */
    void toutMettreEnNegatif() const;

    /**
     * Cette méthode détermine si l'image est majoritairement rouge.
     *
     * @return Si l'image est majoritairement rouge, `true`, sinon `false`.
     */
    bool estMajoriteRouge() const;

    /**
     * Cette méthode détermine si l'image est majoritairement verte.
     *
     * @return Si l'image est majoritairement vert, `true`, sinon `false`.
     */
    bool estMajoriteVert() const;

    /**
     * Cette méthode détermine si l'image est majoritairement bleu.
     *
     * @return Si l'image est majoritairement bleu, `true`, sinon `false`.
     */
    bool estMajoriteBleu() const;

    /*************
     * Mutateurs *
     *************/

    /**
     * Cette méthode change le nom de l'image.
     *
     * @param nom Le nouveau nom de l'image.
     */
    void changerNomImage(const std::string& nom);

    /**************
     * Accesseurs *
     **************/

    /**
     * Cette méthode retourne le chemin du fichier de l'image.
     *
     * @return Le chemin de l'image.
     */
    std::string obtenirChemin() const;

    /**
     * Cette méthode retourne le nom de l'image.
     *
     * @return Le nom de l'image.
     */
    std::string obtenirNomImage() const;

    /**
     * Cette méthode retourne le type de l'image.
     *
     * @return Le type de l'image.
     */
    TypeImage obtenirType() const;

    /**
     * Cette méthode retourne la hauteur de l'image.
     *
     * @return La hauteur de l'image.
     */
    uint_t obtenirHauteur() const;

    /**
     * Cette méthode retourne la largeur de l'image.
     *
     * @return La largeur de l'image.
     */
    uint_t obtenirLargeur() const;

    /**
     * Cette méthode retourne la taille de l'image.
     *
     * @return La taille de l'image.
     */
    uint_t obtenirTaille() const;

    /**
     * Cette méthode retourne un pointeur vers un pixel précis.
     *
     * @param index L'index du pixel à retourner.
     * @return Un pointeur vers le pixel demandé ou `nullptr` si l'index est
     *         invalide.
     */
    Pixel* obtenirPixel(uint_t index) const;

    /**
     * Cette méthode retourne l'intensité moyenne de l'image normalisées entre
     * 0 et 1.
     *
     * @return L'intensité moyenne de l'image.
     */
    double retournerIntensiteMoyenne() const;

    /*************************
     * Opérateurs Surchargés *
     *************************/

    Image& operator=(const Image& image);
    bool operator==(const Image& image);
    bool operator==(const std::string& nom);
    friend bool operator==(const std::string& nom,  Image& image);
    friend std::ostream& operator<<(std::ostream& os, const Image& image);

private:
    /** Le chemin vers l'image. */
    std::string chemin_;

    /** Le nom de l'image. */
    std::string nom_;

    /** Le type de l'image. */
    TypeImage type_;

    /** La hauteur de l'image. */
    uint_t hauteur_;

    /** La largeur de l'image. */
    uint_t largeur_;

    /** Le tableau des pixels. */
    Pixel** pixels_;

    void detruirePixels();
};

std::string obtenirDossier(TypeImage type);
size_t bitmap_encode_rgb(const uint8_t* rgb, uint_t width, uint_t height, uint8_t** output);

#endif
