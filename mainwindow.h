#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include "pkdbusInterface.h"
#include <QtCore>
#include <QtDBus>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton *installButton;
    QPushButton *uninstallButton;
    QPushButton *openButton;
    QHBoxLayout *hboxLayout;

public slots:
    void installPackage();
    void removePackage();

private slots:
    void isInstallSuccess(bool install);
    void slotHelloDbus(bool);
    void isRemoveSuccess(bool rem);
};

#endif // MAINWINDOW_H
