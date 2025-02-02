TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

INCLUDEPATH += include

SOURCES += \
    calculation.cpp \
    main.cpp

HEADERS += \
    calculation.h \
    include/exceptions.h \
    include/operations.h
