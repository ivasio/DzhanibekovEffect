#-------------------------------------------------
#
# Project created by QtCreator 2017-04-27T23:22:10
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DzhanibekovEffect
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    scene.cpp \
    axes.cpp

HEADERS  += dialog.h \
    scene.h \
    axes.h

FORMS    += dialog.ui

RESOURCES += \
    shaders.qrc

DISTFILES +=
