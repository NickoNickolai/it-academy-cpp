TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build

#DEFINES += USE_BOOST

contains( DEFINES, USE_BOOST ) {
    INCLUDEPATH += $(BOOST_ROOT)
}

SOURCES += \
    main.cpp \
    sysinfo.cpp

HEADERS += \
    sysinfo.h
