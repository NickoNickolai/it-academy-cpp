TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

SOURCES += \
        handler.cpp \
        main.cpp

HEADERS += \
    handler.h
