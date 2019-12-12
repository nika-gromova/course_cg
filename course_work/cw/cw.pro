#-------------------------------------------------
#
# Project created by QtCreator 2019-11-08T21:40:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cw
TEMPLATE = app

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
    box.cpp \
        main.cpp \
        mainwindow.cpp \
        point2d.cpp \
        point3d.cpp \
    pyramid.cpp \
    tori.cpp \
    triangle.cpp \
        vector3d.cpp \
        ray.cpp \
        rgbcolor.cpp \
        material.cpp \
        geometricobject.cpp \
        sphere.cpp \
        maths.cpp \
        world.cpp \
        viewfeild.cpp \
        tracer.cpp \
        mypaintwidget.cpp \
        worlddata.cpp \
    light.cpp \
    rectangle.cpp \
    cone.cpp \
    cylinder.cpp \
    disk.cpp

HEADERS += \
    box.h \
        mainwindow.h \
    point3d.h \
    point2d.h \
    pyramid.h \
    tori.h \
    triangle.h \
    vector3d.h \
    ray.h \
    rgbcolor.h \
    material.h \
    constants.h \
    geometricobject.h \
    sphere.h \
    maths.h \
    world.h \
    viewfeild.h \
    tracer.h \
    mypaintwidget.h \
    worlddata.h \
    light.h \
    rectangle.h \
    cone.h \
    cylinder.h \
    disk.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    myres.qrc
