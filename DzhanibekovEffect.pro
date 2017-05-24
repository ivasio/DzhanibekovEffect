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
    body.cpp \
    ServiceClasses/alert.cpp \
    ServiceClasses/numberinput.cpp \
    ServiceClasses/positivenumberinput.cpp \
    ServiceClasses/servicefunctions.cpp \
    ServiceClasses/maths.cpp

HEADERS  += dialog.h \
    scene.h \
    body.h \
    ServiceClasses/alert.h \
    ServiceClasses/numberinput.h \
    ServiceClasses/positivenumberinput.h \
    ServiceClasses/servicefunctions.h \
    ServiceClasses/maths.h

FORMS    += dialog.ui

RESOURCES += \
    shaders.qrc

DISTFILES +=
