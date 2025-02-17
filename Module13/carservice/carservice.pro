TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

INCLUDEPATH += cars

SOURCES += \
    cars/car.cpp \
    cars/cargocar.cpp \
    cars/passengercar.cpp \
    main.cpp

HEADERS += \
    cars/car.h \
    cars/cargocar.h \
    cars/passengercar.h \
    cars/display.h \
    garage.h \
    servicestation.h
