﻿#include "mythread.h"
#include <QThread>
#include <QDebug>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop=false;
}

void MyThread::myTimeout()
{
    while(isStop==false)
    {
        QThread::sleep(1);
        emit mySignal();
        qDebug()<<u8"子线程号："<<QThread::currentThread();

        if(isStop==true)
        {
            break;
        }

    }
}

void MyThread::setFlag(bool flag)
{
    isStop = flag;
}
