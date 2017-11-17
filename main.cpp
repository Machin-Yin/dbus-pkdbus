#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    QProcess process;
//    if(QFile("/home/yin/work/test/buildfolder/build-dbus_pkdbus-Desktop-Debug/pkdbus").exists())
//    {
//        qDebug()<<"pkdbus exists";
//        process.startDetached("/home/yin/work/test/buildfolder/build-dbus_pkdbus-Desktop-Debug/pkdbus");
//        process.waitForFinished();
//        qDebug()<<"pkdbus started";
//    }

    return a.exec();
}
