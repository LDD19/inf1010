/**************************************************
 * Titre: Travail pratique #6 - InterfaceCommande.h
 * Date: 3 Décembre 2017
**************************************************/
#ifndef INTERFACECOMMANDE_H
#define INTERFACECOMMANDE_H

/**
 * Cette classe abtraite permet d'identifier les commandes possédant
 * les fonction Executer et AnnulerCommande.
 */
class InterfaceCommande {
public:
    /**
     * Constructeur.
     */
    InterfaceCommande() {

    }

    /**
     * Destructeur.
     */
    virtual ~InterfaceCommande() {

    }

    /***********************
     * Méthodes Virtuelles *
     ***********************/

    /**
     * Cette méthode exécute la commande demandée.
     */
    virtual void Executer() = 0;

    /**
     * Cette méthode annule la commande précédamment executée.
     */
    virtual void AnnulerCommande() = 0;
};

#endif
