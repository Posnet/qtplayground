#-------------------------------------------------
#
# Project created by QtCreator 2014-03-12T16:36:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simplegui
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    coordinates.cpp \
    ball.cpp

HEADERS  += dialog.h \
    coordinates.h \
    ball.h

FORMS    += dialog.ui
