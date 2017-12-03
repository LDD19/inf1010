/**************************************************
 * Titre: Travail pratique #6 - ExceptionsMauvaisFormatImage.h
 * Date: 3 Décembre 2017
 * Auteurs: Gabriel-Andrew Pollo-Guilbert, Si Da Li
**************************************************/
#ifndef EXCEPTIONMAUVAISFORMATIMAGE_H
#define EXCEPTIONMAUVAISFORMATIMAGE_H

#include <QException>
#include <QString>

/**
 * Cette classe définit l'exception lancée lorsque l'image que l'on tente
 * d'ouvrir n'est pas dans un format reconnu par la classe QImage.
 */
class ExceptionMauvaisFormatImage : public QException {
public:
    /**
     * Constructeur par paramètres.
     *
     * @param message Le message contenu dans l'exception.
     */
    ExceptionMauvaisFormatImage(QString message) :
        message_(message) {

    }

    /**
     * Destructeur.
     */
    ~ExceptionMauvaisFormatImage() {

    }

    /************************
     * Méthodes Surchargées *
     ************************/

    void raise() {
        throw *this;
    }

    ExceptionMauvaisFormatImage* clone() const {
        return new ExceptionMauvaisFormatImage(*this);
    }

    const char* what() const throw() {
        return message_.toLatin1().data();
    }
private:
    /** Le message contenu dans l'exception. */
    QString message_;
};

#endif
