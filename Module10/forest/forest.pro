TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

INCLUDEPATH += forest tree

SOURCES += \
    main.cpp \
    forest/forest.cpp \
    forest/leafy.cpp \
    forest/needles.cpp \
    tree/birch.cpp \
    tree/maple.cpp \
    tree/oak.cpp \
    tree/pine.cpp \
    tree/tree.cpp

HEADERS += \
    forest/forest.h \
    forest/leafy.h \
    forest/needles.h \
    tree/birch.h \
    tree/maple.h \
    tree/oak.h \
    tree/pine.h \
    tree/tree.h
