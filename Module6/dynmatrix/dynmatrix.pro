TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

#DEFINES += USE_DIM2

SOURCES += \
    main.cpp \
    matrix.cpp

HEADERS += \
    matrix.h
