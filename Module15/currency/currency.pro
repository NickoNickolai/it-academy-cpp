QT += core gui widgets

CONFIG += c++17

DESTDIR = ../build

INCLUDEPATH += widgets

SOURCES += \
    converter.cpp \
    settings.cpp \
    widgets/converterwgt.cpp \
    main.cpp \
    widgets/settingswgt.cpp

HEADERS += \
    converter.h \
    settings.h \
    widgets/converterwgt.h \
    widgets/settingswgt.h

FORMS += \
    widgets/converterwgt.ui \
    widgets/settingswgt.ui

RESOURCES += \
    resources.qrc
