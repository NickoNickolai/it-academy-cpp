TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

SOURCES += \
    main.cpp \
    forest.cpp \
    tree.cpp

HEADERS += \
    forest.h \
    tree.h
