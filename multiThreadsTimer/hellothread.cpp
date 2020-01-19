#include "hellothread.h"
#include <windows.h>

void HelloThread::receiveData(double dtIn, LARGE_INTEGER beginTimeIn, int idIn)
{
    id=idIn;
    QueryPerformanceFrequency(&freq);
    dt=dtIn;
    beginTime=beginTimeIn;
    i=0;
}

void HelloThread::run(){
dt=0;
while(true)
        if(QueryPerformanceCounter(&time)&&(dt!=0)){
            tim=(time.QuadPart-beginTime.QuadPart)/(double)freq.QuadPart;
            if(tim>i*dt){
                i++;
                sendTime(tim,id);
            }

    }
}

void HelloThread::cycle(){

}
