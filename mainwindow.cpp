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
    ComEmindsoftPkdbusRegistryInterface *myInterface= new ComEmindsoftPkdbusRegistryInterface(QString(),QString(),QDBusConnection::systemBus(),this);
    QObject::connect(myInterface,SIGNAL(isInstallSuccess(bool)),this,SLOT(isInstallSuccess(bool)));

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
//   QDBusConnection::sessionBus().connect(QString(), QString(), "com.emindsoft.pkdbus", "isInstallSuccess", this, SLOT(isInstallSuccess(bool)));

}

void MainWindow::isInstallSuccess(bool install)
{
    qDebug() << __FUNCTION__ << ": install == " << install;

}
