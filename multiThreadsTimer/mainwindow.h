#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QThread>
#include <QMainWindow>
#include <QDebug>
#include <Windows.h>
#include "hellothread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    signals: void sendData(double dtTo, LARGE_INTEGER beginTimeTo, int idTo);
    void sendData1(double dtTo, LARGE_INTEGER beginTimeTo, int idTo);
public slots:void receiveTime(double time, int id);
    void receiveTime1(double time, int id);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
