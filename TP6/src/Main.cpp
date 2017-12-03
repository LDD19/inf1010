/**************************************************
 * Titre: Travail pratique #6 - Main.cpp
 * Date: 3 Décembre 2017
**************************************************/
#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
