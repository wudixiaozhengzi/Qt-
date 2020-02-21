#include "widget.h"
#include "ui_widget.h"
#include <QThread>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myTimer =new QTimer(this);

    //只要定时器启动，自动触发timeout()

    connect(myTimer,&QTimer::timeout,this,&Widget::dealTimerout);

    //分配空间
    thread=new MyThread(this);

    connect(thread,&MyThread::isDone,this,&Widget::dealDone);

    //当按窗口右上角关闭时，窗口触发destroyed
    connect(this,&Widget::destroyed,this,&Widget::stopThread)

}

void Widget::stopThread()
{
    //停止线程
    thread->quit();
    //等待线程处理完完成
    thread->wait();
}

void Widget::dealDone()
{
    qDebug()<<"it is over";
    myTimer->stop();//关闭定时器
}

void Widget::dealTimerout()
{
    static int i=0;
    i++;
    //设置lcd的值
    ui->lcdNumber->display(i);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //如果定时器没有启动
    if(myTimer->isActive()==false)
    {
        myTimer->start(100);
    }

    //启动线程，处理数据
    thread->start();


}





