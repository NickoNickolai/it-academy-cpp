TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

QMAKE_LFLAGS += -pthread

#DEFINES += USE_PROMISE
#DEFINES += USE_ASYNC

SOURCES += \
    arrproc.cpp \
    main.cpp

HEADERS += \
    arrproc.h
