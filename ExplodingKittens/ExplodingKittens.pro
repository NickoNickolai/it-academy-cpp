QT -= gui
QT += core network

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++17

TEMPLATE = app

DESTDIR = ../build

#DEFINES += USE_DEBUG
#DEFINES += USE_VERBOSE_DEBUG
DEFINES += PORT_SRV=12345

INCLUDEPATH += network

SOURCES += \
    card.cpp \
    deck.cpp \
    game.cpp \
    human.cpp \
    logger.cpp \
    main.cpp \
    network/tcpclient.cpp \
    network/tcpserver.cpp \
    player.cpp \
    pool.cpp \
    remotegame.cpp \
    remoteplayer.cpp \
    robot.cpp \
    settings.cpp

HEADERS += \
    card.h \
    deck.h \
    game.h \
    human.h \
    logger.h \
    netstructs.h \
    network/tcpclient.h \
    network/tcpserver.h \
    player.h \
    pool.h \
    remotegame.h \
    remoteplayer.h \
    robot.h \
    settings.h
