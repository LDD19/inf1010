#ifndef BASE_DE_DONNES_GENERIQUE
#define BASE_DE_DONNES_GENERIQUE

#include <list>
#include <algorithm>
#include <iterator>

/**
 * Cette classe définit une base de données générique.
 *
 * @tparam T Le type d'images à enregistrer.
 * @tparam S Le groupe de ces images.
 */
template<typename T, typename S>
class BaseDeDonnesGenerique {
public:
    /**
     * Constructeur par défaut.
     */
    BaseDeDonnesGenerique() {

    }

    /**
     * Destructeur.
     */
    ~BaseDeDonnesGenerique() {
    
    }

    /**
     * Cette méthode ajoute un objet de type T dans la base de données.
     *
     * @param t Un pointeur vers l'objet à ajouter.
     */
    void ajouter(T* t) {
        /* on regarde si le pointeur existe déjà dans la liste */
        auto tt = std::find_if(listT_.begin(), listT_.end(),
            [t](T* tt) {
                return (t == tt);
            }
        );
        
        /* on ajoute l'objet seulement s'il n'est déjà pas dans la liste */
        if(*tt != nullptr)
            listT_.insert(listT_.begin(), t);
    }

    /**
     * Cette méthode ajoute un objet de type S dans la base de données.
     *
     * @param s Un pointeur vers l'objet à ajouter.
     */
    void ajouter(S* s) {
        /* on regarde si le pointeur existe déjà dans la liste */
        auto ss = std::find_if(listS_.begin(), listS_.end(),
            [s](S* ss) {
                return (s == ss);
            }
        );

        /* on ajoute l'objet seulement s'il n'est déjà pas dans la liste */       
        if(*ss != nullptr)
            listS_.insert(listS_.begin(), s);
    }

    /**
     * Cette méthode supprime un objet de type T de la base de données.
     *
     * @param t Un pointeur vers l'objet à supprimer.
     *
     * @return Si l'objet fut supprimé, alors `true`, sinon `false`.
     */
    bool supprimer(const T* t) {
        /* on cherche le pointeur dans la liste */
        auto tt = std::find_if(listT_.begin(), listT_.end(),
            [t](T* tt) {
                return (t == tt);
            }
        );

        /* le pointeur ne fut pas trouvé */
        if(*tt == nullptr)
            return false;

        /* on enlève l'objet */
        listT_.erase(tt);
        return true;
    }

    /**
     * Cette méthode supprime un objet de type S de la base de données.
     *
     * @param s Un pointeur vers l'objet à supprimer.
     *
     * @return Si l'objet fut supprimé, alors `true`, sinon `false`.
     */
    bool supprimer(const S* s) {
        /* on cherche le pointeur dans la liste */
        auto ss = std::find_if(listS_.begin(), listS_.end(),
            [s](S* ss) {
                return (s == ss);
            }
        );

        /* le pointeur ne fut pas trouvé */
        if(*ss == nullptr)
            return false;

        /* on enlève l'objet */
        listS_.erase(ss);
        return true;
    }

    /**
     * Cette méthode supprime des objets de type T de la bas de données en
     * utilisant un prédicat.
     *
     * @tparam P Le type de prédicat.
     *
     * @param predicat Le prédicat à utiliser.
     *
     * @return Si au moins un objet fut supprimé, alors `true`, sinon `false`.
     */
    template<typename P>
    bool supprimerImage(const P& predicat) {
        /* on enlève les objects */
        auto t = std::remove_if(listT_.begin(), listT_.end(), predicat);

        /* on regarde si au moins un object fut enlevé */
        return (*t != nullptr);
    }

    /**
     * Cette méthode supprime des objets de type S de la bas de données en
     * utilisant un prédicat.
     *
     * @tparam P Le type de prédicat.
     *
     * @param predicat Le prédicat à utiliser.
     *
     * @return Si au moins un objet fut supprimé, alors `true`, sinon `false`.
     */
    template<typename P>
    bool supprimerGroupeImage(const P& predicat) {
        /* on enlève les objects */
        auto s = std::remove_if(listS_.begin(), listS_.end(), predicat);

        /* on regarde si au moins un object fut enlevé */
        return (*s != nullptr);
    }

    /**
     * Cette fonction vide la base de données entièrement.
     */
    void vider() {
        /* on vide les deux listes */
        listT_.clear();
        listS_.clear();
    }

    /**************
     * Accesseurs *
     **************/

    /**
     * Cette méthode retourne la liste d'objets de type T.
     *
     * @return La liste d'objets.
     */
    std::list<T*> obtenirListImages() const {
        return listT_;
    }

    /**
     * Cette méthode retourne la liste d'objets de type S.
     *
     * @return La liste d'objets.
     */
    std::list<S*> obtenirListGroupeImages() const {
        return listS_;
    }

    /**************************
     * Opérateurs surchargées *
     **************************/

    BaseDeDonnesGenerique& operator+=(T* t) {
        ajouter(t);
        return *this;
    }

    BaseDeDonnesGenerique& operator+=(S* s) {
        ajouter(s);
        return *this;
    }

    BaseDeDonnesGenerique& operator-=(T* t) {
        supprimer(t);
        return *this;
    }

    BaseDeDonnesGenerique& operator-=(S* s) {
        supprimer(s);
        return *this;
    }

protected:
    /** La liste d'objets de type T. */
    std::list<T*> listT_;

    /** La liste d'objets de type S. */
    std::list<S*> listS_;
};



#endif
