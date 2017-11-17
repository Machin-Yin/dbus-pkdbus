#include "pkdbus.h"
#include <iostream>
//#include <unistd.h>

using namespace std;

PkDbus::PkDbus(QObject *parent) : QObject(parent)
{
//    new RegistryAdaptor(this);
    qDebug() << __FUNCTION__;

    (void) new RegistryAdaptor(this);
    if (!QDBusConnection::sessionBus().registerService("com.emindsoft.pkdbus")) {
        qDebug() << "another pkdbus is already running";
        QCoreApplication::instance()->quit();
    }

    if (!QDBusConnection::sessionBus().registerObject("/pkdbus/registry", this)) {
        qDebug() << "unable to register service interface to dbus";
        QCoreApplication::instance()->quit();
    }

//    QDBusConnection bus = QDBusConnection::sessionBus();
//    PkDbus pkDbus;
//    // RegistryAdaptor是qdbusxml2cpp生成的Adaptor类
//    RegistryAdaptor myAdaptor(&pkDbus);

//    if (!bus.registerService("com.emindsoft.pkdbus")) {
//            qDebug() << bus.lastError().message();
//            exit(1);
//    }

//    bus.registerObject("/pkdbus/registry", this);

}

void PkDbus::installPackage(QString packageName)
{
    qDebug() << __FUNCTION__ << packageName;

//    PolkitQt1::Authority::Result result;

//    result = PolkitQt1::Authority ("org.kde.foo.action2",
//                                      message().service(),
//                                      true);
//    if (result == PolkitQt1::Authority::Yes) {
//        qDebug() << message().service() << QString(" authorized");
//    } else {
//        qDebug() << QString("Not authorized");
//        QCoreApplication::instance()->quit();
//        return;
//    }


    PackageKit::Transaction *resolveTransaction = PackageKit::Daemon::resolve(packageName,
                                                                              //                                                   PackageKit::Transaction::FilterNone);
                                                                              PackageKit::Transaction::FilterArch);
    connect(resolveTransaction,
            SIGNAL(package(PackageKit::Transaction::Info,QString,QString)),
            this,
            SLOT(packageInstall(PackageKit::Transaction::Info,QString,QString)));
    connect(resolveTransaction,
            SIGNAL(finished(PackageKit::Transaction::Exit, uint)),
            this,
            SLOT(resolveFinished(PackageKit::Transaction::Exit, uint)));

}

void PkDbus::packageInstall(PackageKit::Transaction::Info, QString packageID, QString summary)
{
    Q_UNUSED(summary);
    qDebug() << "packageInstall() packageID " << packageID;
     
    PackageKit::Transaction *installTransaction = PackageKit::Daemon::installPackage(packageID);
    connect(installTransaction,
            SIGNAL(finished(PackageKit::Transaction::Exit, uint)),
            this,
            SLOT(packageInstallFinished(PackageKit::Transaction::Exit, uint)));
}

void PkDbus::resolveFinished(PackageKit::Transaction::Exit status, uint runtime)
{
    Q_UNUSED(runtime);
    qDebug() << "testResolveFinished() status: " << status << endl;
    qDebug() << "testResolveFinished() on of seconds: " << runtime << endl;
    if (status == PackageKit::Transaction::Exit::ExitSuccess)
    {
        qDebug() << "Package Resolve Success!";
    }
    else
    {
        emit isInstallSuccess(false);
        qDebug() << "Package Resolve Failure!";
    }
}

void PkDbus::packageInstallFinished(PackageKit::Transaction::Exit status, uint runtime)
{
//    Q_UNUSED(runtime);
    qDebug() << "packageInstallFinished() status: " << status << endl;
    if (status == PackageKit::Transaction::Exit::ExitSuccess)
    {
        emit isInstallSuccess(true);
        qDebug() << "Package Install Success!";
    }
    else
    {
        emit isInstallSuccess(false);
        qDebug() << "Package Install Failure!";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "main()::" << endl;
//    QCoreApplication::setSetuidAllowed(true);
//    setuid(0);

//    QDBusConnection bus = QDBusConnection::systemBus();
    PkDbus pkDbus;
//    // RegistryAdaptor是qdbusxml2cpp生成的Adaptor类
//    RegistryAdaptor myAdaptor(&pkDbus);

//    if (!bus.registerService("com.emindsoft.pkdbus")) {
//            qDebug() << bus.lastError().message();
//            exit(1);
//    }

//    bus.registerObject("/pkdbus/registry", &pkDbus);

    return a.exec();
}

