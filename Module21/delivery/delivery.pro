TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

INCLUDEPATH += strategies

SOURCES += \
    delivery.cpp \
    deliverycontext.cpp \
    strategies/airdelivery.cpp \
    strategies/expressdelivery.cpp \
    strategies/grounddelivery.cpp \
    main.cpp

HEADERS += \
    delivery.h \
    deliverycontext.h \
    strategies/airdelivery.h \
    strategies/expressdelivery.h \
    strategies/grounddelivery.h \
    strategies/ideliverystrategy.h
