#-------------------------------------------------
#
# Project created by QtCreator 2017-11-06T14:43:48
#
#-------------------------------------------------

QT       += core gui dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mainwindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pkdbusInterface.cpp

HEADERS  += mainwindow.h \
    pkdbusInterface.h

INCLUDEPATH += /usr/include/packagekitqt5/PackageKit

LIBS += /usr/lib/x86_64-linux-gnu/libpackagekitqt5.so

DISTFILES +=
