#include "mainwindow.h"
#include <QApplication>
#include <Windows.h>
#include "hellothread.h"
#include <qthread.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
