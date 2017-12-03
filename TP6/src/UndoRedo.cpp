/**************************************************
 * Titre: Travail pratique #6 - UndoRedo.cpp
 * Date: 3 Décembre 2017
**************************************************/
#include "UndoRedo.h"

using namespace std;

UndoRedo::UndoRedo() {

}

UndoRedo::~UndoRedo() {

}

void UndoRedo::insererDansUndosRedos(shared_ptr<InterfaceCommande> commande) {
    /* on vide la pile de commande annulée */
    while(!redos.empty()) redos.pop();

    /* on ajoute la nouvelle commande à la pile de commandes exécutées */
    undos.push(commande);
}

void UndoRedo::undo() {
    /* on s'assure qu'il y a au moins une commande à annuler */
    if(undos.empty()) return;

    /* on obtient la dernière commande */
    shared_ptr<InterfaceCommande> c = undos.top();

    /* on ajoute cette commande à la pile de commandes annulées */
    redos.push(c);

    /* on annule la commande */
    c->AnnulerCommande();

    /* on l'enlève de la pile de commandes exécutées */
    undos.pop();
}

void UndoRedo::redo() {
    /* on s'assure qu'il y a au moins une commande à reexécuter */
    if(redos.empty()) return;

    /* on obtient la dernière commande */
    shared_ptr<InterfaceCommande> c = redos.top();

    /* on ajoute cette commande à la pile de commande executées */
    undos.push(c);

    /* on reexécute la commande */
    c->Executer();

    /* on l'enlève de la pile de commandes annulées */
    redos.pop();
}

void UndoRedo::clear() {
    /* on vide la pile de commandes annulées */
    while(!redos.empty()) redos.pop();

    /* on vide la pile de commandes exécutées */
    while(!undos.empty()) undos.pop();
}
