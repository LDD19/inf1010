#ifndef UNDOREDO_H
#define UNDOREDO_H

#include <stack>
#include <memory>

#include "InterfaceCommande.h"

/**
 * Cette classe permet de garder en mémoire les commandes effectuées. Chaque commande
 * doit dériver de la classe abstraite InterfaceCommande qui assure la possibilité
 * d'annuler une commande.
 *
 * Le stack `undos_` permet de garder toutes les commandes effectuées au fur et à mesure
 * qu'elles sont insérées grâce à la fonction UndoRedo::insererDansUndosRedos pour qu'on
 * puisse appeler UndoRedo::undo plus tard.
 *
 * La méthode UndoRedo::undo permet de retrouver la dernière commande utilisée, appelle
 * la fonction InterfaceCommande::annulerCommande, retire la commande du stack `undos_`
 * et l'ajoute dans le stack `redos_`. Ainsi, la méthode UndoRedo::redo peut appeler
 * InterfaceCommande::executer sur les commandes qui la remplisse dans le cas échéant.
 */
class UndoRedo {
public:
    /**
     * Constructeur.
     */
    UndoRedo();

    /**
     * Destructeur.
     */
    ~UndoRedo();

    /**
     * Cette méthode insère une commande dans la pile de commandes effectuées.
     *
     * @param commande La commande à insérer.
     */
    void insererDansUndosRedos(std::shared_ptr<InterfaceCommande> commande);

    /**
     * Cette méthode annule la dernière commande exécutée.
     */
    void undo();

    /**
     * Cette méthode reexécute la dernière commande annulée.
     */
    void redo();

    /**
     * Cette méthode réinitialise l'historique des commandes.
     */
    void clear();
private:
    /** La pile de commandes effectuées. */
    std::stack<std::shared_ptr<InterfaceCommande>> undos;

    /** La pile de commande annulées. */
    std::stack<std::shared_ptr<InterfaceCommande>> redos;
};

#endif
