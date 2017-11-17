# -------------------------------------------------
# Project created by QtCreator 2010-07-14T10:30:53
# -------------------------------------------------
QT += dbus
QT -= gui
TARGET = pkdbus
#CONFIG += console
#CONFIG -= app_bundle
TEMPLATE = app
SOURCES += pkdbus.cpp \
    pkdbusAdaptor.cpp
HEADERS += pkdbus.h \
    pkdbusAdaptor.h
INCLUDEPATH += /usr/include/packagekitqt5/PackageKit \
#               /usr/include/polkit-qt5-1/PolkitQt1

LIBS += /usr/lib/x86_64-linux-gnu/libpackagekitqt5.so \
#        /usr/lib/x86_64-linux-gnu/polkit-1/extensions/libnullbackend.so

DISTFILES += \
    com.emindsoft.pkdbus.xml


