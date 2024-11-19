TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

SOURCES += \
    factorial.cpp \
    main.cpp

HEADERS += \
    factorial.h
