QT -= gui

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++17

TEMPLATE = app

DESTDIR = ../build

#DEFINES += USE_DEBUG
#DEFINES += USE_VERBOSE_DEBUG

SOURCES += \
    card.cpp \
    deck.cpp \
    game.cpp \
    human.cpp \
    logger.cpp \
    main.cpp \
    player.cpp \
    pool.cpp \
    robot.cpp

HEADERS += \
    card.h \
    deck.h \
    game.h \
    human.h \
    logger.h \
    player.h \
    pool.h \
    robot.h
