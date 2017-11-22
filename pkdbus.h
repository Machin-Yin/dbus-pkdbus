#ifndef PKDBUS_H
#define PKDBUS_H

#include <QObject>
#include <QtCore>
#include <QtDBus>
#include <packagekitqt5/PackageKit/Transaction>
#include <packagekitqt5/PackageKit/Daemon>

#include "pkdbusAdaptor.h"

//#include <Details>


class PkDbus : public QObject, protected QDBusContext
{
    Q_OBJECT    
    // 定义Interface名称为"com.test.hotel.registry"
    Q_CLASSINFO("D-Bus Interface", "com.emindsoft.pkdbus.registry")

public:
    explicit PkDbus(QObject *parent = 0);

signals:
    void isInstallSuccess(bool);

public slots:
    void installPackage(QString packageName);

private slots:
    void packageInstall(PackageKit::Transaction::Info, QString packageID, QString summary);
    void resolveFinished(PackageKit::Transaction::Exit status, uint runtime);
    void packageInstallFinished(PackageKit::Transaction::Exit status, uint runtime);

};

// qdbuscpp2xml -M -S pkdbus.h -o com.emindsoft.pkdbus.xml
// qdbusxml2cpp com.emindsoft.pkdbus.xml -a pkdbusAdaptor
// qdbusxml2cpp com.emindsoft.pkdbus.xml -p pkdbusInterface.cpp


//加入 /usr/share/dbus-1/services/com.emindsoft.pkdbus.service   sessionBuss()可以自动调起。 systemBus注册失败。
// 目录放错了，应该放到/usr/share/dbus-1/system-services里


#endif // PKDBUS_H
