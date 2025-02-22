TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

#DEFINES += USE_OPS_ARRAY

INCLUDEPATH += include

SOURCES += \
    calculation.cpp \
    main.cpp

HEADERS += \
    calculation.h \
    include/exceptions.h \
    include/operations.h
