#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QString>
#include <QScrollArea>
#include <QLabel>
#include <QScrollBar>
#include <QScreen>
#include <QRect>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDir>
#include <QImageReader>
#include <QImageWriter>
#include <QMessageBox>
#include <QPointer>
#include <QTableWidget>
#include <QGroupBox>
#include <QPushButton>

#include "Image.h"
#include "UndoRedo.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    /**
     * Constructeur par valeurs.
     *
     * @param parent L'object QT parent.
     */
    explicit MainWindow(QWidget* parent = 0);

    /**
     * Destructeur.
     */
    ~MainWindow();
private slots:
    /**
     * Cette méthode permet la sélection et l'ouverture d'une image.
     */
    void ouvrirImage();

    /**
     * Cette méthode permet d'enregistrer l'image.
     */
    void enregistrerImage();

    /**
     * Cette méthode met à jour la vue de l'image.
     *
     * @param image L'image à mettre à jour.
     */
    void updateImage(QImage image);

    /**
     * Cette méthode initialise la table montrant l'informations de l'image.
     *
     * @param image L'image à afficher les informations.
     */
    void updateTableViewWidget(QImage image);

    /**
     * Cette méthode affiche un message à l'utilisateur.
     *
     * @param msg Le message à afficher.
     */
    void afficherMessage(QString msg);

    /**
     * Cette méthode affiche un message d'explication à l'utilisateur.
     */
    void about();
private:
    /**
     * Cette méthode crée les actions de la barre de menu.
     */
    void creeActions();

    /**
     * Cette méthode initialise les connections entres les signaux.
     */
    void initConnections();

    /**
     * Cette méthode initialise l'interface de l'utilisateur.
     */
    void initUI();

    /**
     * Cette méthode active les boutons dans l'interface.
     */
    void activateButtons();

    /**
     * Cette méthode permet de configurer une fenêtre de dialogue pour
     * demander un fichier à l'utilisateur.
     *
     * @param dialog     Le dialogue à montrer.
     */
    static void fileExplorer(QFileDialog &dialog);

    /** L'image que l'utilisateur traite actuellement. */
    Image image_;

    /** L'interface de l'utilisateur. */
    Ui::MainWindow* ui;

    /** La vue de l'image. */
    QPointer<QLabel> imageLabel_;

    /** L'action d'ouvrir un fichier. */
    QAction* actionOuvrir_;

    /** L'action d'ouvrir la vue qui explique le logiciel. */
    QAction* actionAPropos_;

    /** L'action d'enregistrer l'image. */
    QAction* actionEnregistrerSous_;

    /** L'action d'annuler la dernière commande. */
    QAction* undo_;

    /** L'action de reexécuter la dernière commande annulée. */
    QAction* redo_;

    /** Le groupe des boutons de l'application. */
    QGroupBox* groupBox_;

    /** Le bouton pour convertir l'image en noir et blanc. */
    QPushButton* boutonNB_;

    /** Le bouton pour convertir l'image en nuance de gris. */
    QPushButton* boutonGris_;

    /** Le bouton pour mettre l'image en négatif. */
    QPushButton* boutonNegatif_;

    /** La table qui montre les informations concernant l'image. */
    QTableWidget* tableWidget_;

    /** L'environnement avec la barre de déplacement. */
    QScrollArea* imageScrollArea_;
};

#endif
