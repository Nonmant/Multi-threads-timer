#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qobject.h>
#include <qthread.h>
#include "hellothread.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    HelloThread *thread = new HelloThread;
    thread->start();

    QObject::connect(this,SIGNAL(sendData(double,LARGE_INTEGER,int)),thread,SLOT(receiveData(double,LARGE_INTEGER,int)));
    QObject::connect(thread,SIGNAL(sendTime(double,int)),this,SLOT(receiveTime(double,int)));

    HelloThread *thread1 = new HelloThread;
    thread1->start();
    QObject::connect(this,SIGNAL(sendData1(double,LARGE_INTEGER,int)),thread1,SLOT(receiveData(double,LARGE_INTEGER,int)));
    QObject::connect(thread1,SIGNAL(sendTime(double,int)),this,SLOT(receiveTime1(double,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveTime(double time, int id){
        ui->labelTimeLeft->setText(QString::number(time));
    qDebug()<<"got"<<time;
}
void MainWindow::receiveTime1(double time, int id){
        ui->labelTimeRight->setText(QString::number(time));
    qDebug()<<"got"<<time;
}



void MainWindow::on_pushButton_clicked()
{
    LARGE_INTEGER beginTime;
    QueryPerformanceCounter(&beginTime);
    sendData(0.1, beginTime, 1);
    sendData1(0.5, beginTime, 2);
    QObject::disconnect(this,SIGNAL(sendData(double,LARGE_INTEGER,int)),0,0);
    QObject::disconnect(this,SIGNAL(sendData1(double,LARGE_INTEGER,int)),0,0);
    ui->pushButton->setEnabled(false);
}
