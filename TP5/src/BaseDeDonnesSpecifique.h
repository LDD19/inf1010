/**************************************************
 * Titre: Travail pratique #5 - BaseDeDonnesSpecifique.h
 * Date:28 Octobre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#ifndef BASE_DE_DONNES_SPECIFIQUE_H
#define BASE_DE_DONNES_SPECIFIQUE_H

#include "BaseDeDonnesGenerique.h"
#include "GroupeImage.h"
#include "Image.h"

class BaseDeDonnesSpecifique : public BaseDeDonnesGenerique<Image,GroupeImage> {
public:
    void associerImage(GroupeImage* g, Image* i);
    bool enleverImage(GroupeImage* g, const std::string& nom);

    std::list<Image*> obtenirListeImages() const;
    
    friend std::ostream& operator<<(std::ostream& os, const BaseDeDonnesSpecifique& dataBase);

    

};
#endif
