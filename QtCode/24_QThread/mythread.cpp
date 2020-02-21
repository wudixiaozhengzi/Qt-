#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    //假设里边有一段很复杂的数据处理
    //需要耗时五秒
    sleep(5);

    emit isDone();
}
