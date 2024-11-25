TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

#DEFINES += USE_SCENARIO

SOURCES += \
    game.cpp \
    main.cpp \
    player.cpp

HEADERS += \
    game.h \
    player.h
