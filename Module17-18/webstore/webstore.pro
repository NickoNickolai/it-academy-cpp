TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

SOURCES += \
    main.cpp \
    order.cpp \
    webstore.cpp

HEADERS += \
    order.h \
    webstore.h
