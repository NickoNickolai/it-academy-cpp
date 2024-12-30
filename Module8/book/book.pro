TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

SOURCES += \
    book.cpp \
    main.cpp

HEADERS += \
    book.h
