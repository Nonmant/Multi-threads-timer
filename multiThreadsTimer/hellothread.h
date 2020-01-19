#ifndef HELLOTHREAD_H
#define HELLOTHREAD_H
#include <qthread.h>
#include <windows.h>
#include <qobject.h>

class HelloThread: public QThread
{
    Q_OBJECT
    LARGE_INTEGER time, beginTime, freq;
    int i=0, id=0;
    double tim=0;
    double dt=0;//милисекунд
public slots:void receiveData(double dtIn, LARGE_INTEGER beginTimeIn, int idIn);
public:
    void cycle();
    void run();
signals: void sendTime(double time, int id);
};

#endif // HELLOTHREAD_H
