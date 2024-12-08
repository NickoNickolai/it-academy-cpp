TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

SOURCES += \
    main.cpp \
    stringprocessor.cpp

HEADERS += \
    stringprocessor.h
