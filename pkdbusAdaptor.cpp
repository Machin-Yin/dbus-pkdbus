/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp com.emindsoft.pkdbus.xml -a pkdbusAdaptor
 *
 * qdbusxml2cpp is Copyright (C) 2016 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "pkdbusAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class RegistryAdaptor
 */

RegistryAdaptor::RegistryAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

RegistryAdaptor::~RegistryAdaptor()
{
    // destructor
}

void RegistryAdaptor::installPackage(const QString &packageName)
{
    // handle method call com.emindsoft.pkdbus.registry.installPackage
    QMetaObject::invokeMethod(parent(), "installPackage", Q_ARG(QString, packageName));
}

void RegistryAdaptor::removePackage(const QString &pacId)
{
    // handle method call com.emindsoft.pkdbus.registry.removePackage
    QMetaObject::invokeMethod(parent(), "removePackage", Q_ARG(QString, pacId));
}

