#-------------------------------------------------
#
# Project created by QtCreator 2016-10-30T16:40:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MaxRenegadeVsZork3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Room.cpp \
    PointOfInterest.cpp \
    items.cpp \
    healthitem.cpp \
    weapon.cpp \
    puzzleitem.cpp \
    Smoke.cpp \
    ItemInterface.cpp

HEADERS  += mainwindow.h \
    Room.h \
    PointOfInterest.h \
    items.h \
    healthitem.h \
    weapon.h \
    puzzleitem.h \
    Smoke.h \
    ItemInterface.h

FORMS    += mainwindow.ui
