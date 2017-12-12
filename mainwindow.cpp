#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(380,200);
    QWidget *widget = new QWidget(this);

    installButton = new QPushButton("安装");
    installButton->setFixedSize(QSize(80,35));
//    installButton->setText("");
    uninstallButton = new QPushButton("卸载");
    uninstallButton->setFixedSize(QSize(80,35));
    openButton = new QPushButton("打开");
    openButton->setFixedSize(QSize(80,35));

    hboxLayout = new QHBoxLayout;
    hboxLayout->addWidget(installButton);
    hboxLayout->addWidget(uninstallButton);
    hboxLayout->addWidget(openButton);
    widget->setLayout(hboxLayout);
    setCentralWidget(widget);

    connect(installButton, SIGNAL(clicked()), this, SLOT(installPackage()));
    connect(uninstallButton, SIGNAL(clicked()), this, SLOT(removePackage()));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openApp()));
    ComEmindsoftPkdbusRegistryInterface *myInterface= new ComEmindsoftPkdbusRegistryInterface(QString(),QString(),QDBusConnection::systemBus(),this);
    QObject::connect(myInterface,SIGNAL(helloDbus(bool)),this,SLOT(slotHelloDbus(bool)));
    QObject::connect(myInterface,SIGNAL(isInstallSuccess(bool)),this,SLOT(isInstallSuccess(bool)));
    QObject::connect(myInterface,SIGNAL(isPacRmvSuccess(bool)),this,SLOT(isRemoveSuccess(bool)));


//    // 初始化自动生成的Proxy类com::emindsoft::pkdbus::registry
//    com::emindsoft::pkdbus::registry pkDbus("com.emindsoft.pkdbus",
//                                       "/pkdbus/registry",
//                                       QDBusConnection::sessionBus());

}

MainWindow::~MainWindow()
{

}

void MainWindow::installPackage()
{
    qDebug() << __FUNCTION__;
    QString packageName = "blueberry";


    com::emindsoft::pkdbus::registry pkDbus("com.emindsoft.pkdbus",
                                       "/pkdbus/registry",
                                       QDBusConnection::systemBus());

    pkDbus.installPackage(packageName);
}

void MainWindow::isInstallSuccess(bool install)
{
    qDebug() << __FUNCTION__ << ": install == " << install;

}

void MainWindow::removePackage()
{
    qDebug() << __FUNCTION__;
    QString packageId = "blueberry;1.1.5;all;installed:emindsoft-liuriver-main";

    com::emindsoft::pkdbus::registry pkDbus("com.emindsoft.pkdbus",
                                       "/pkdbus/registry",
                                       QDBusConnection::systemBus());

    pkDbus.removePackage(packageId);
}

void MainWindow::isRemoveSuccess(bool rem)
{
    qDebug() << "The remove package rem == " << rem;
}

void MainWindow::slotHelloDbus(bool hello)
{
    qDebug() << __FUNCTION__ << ": hello == " << hello;

}

void MainWindow::openApp()
{
    qDebug() << __FUNCTION__;
    QString appName =  "blueberry";
    com::emindsoft::pkdbus::registry pkDbus("com.emindsoft.pkdbus",
                                       "/pkdbus/registry",
                                       QDBusConnection::systemBus());

    pkDbus.openApp(appName);
//    QProcess *proc = new QProcess;
//    proc->start(appName);

}
