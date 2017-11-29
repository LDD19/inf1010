#-------------------------------------------------
#
# Project created by QtCreator 2017-11-07T15:15:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fichiers_TP6
TEMPLATE = app

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    src/Image.cpp \
    src/Main.cpp \
    src/MainWindow.cpp \
    src/UndoRedo.cpp

HEADERS += \
    src/InterfaceCommande.h \
    src/MainWindow.h \
    src/Commandes.h \
    src/ExceptionMauvaisFormatimage.h \
    src/Image.h \
    src/UndoRedo.h

FORMS += \
        ui/mainwindow.ui
