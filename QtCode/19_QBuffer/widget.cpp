#include "widget.h"
#include "ui_widget.h"
#include <QBuffer>
#include <QDebug>
#include <QDataStream>
#include <QByteArray>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QByteArray array;
    QBuffer memFile(&array);//创建内存文件
    memFile.open(QIODevice::WriteOnly);
    memFile.write("156134");
    memFile.write("2264384132");
    memFile.close();

    qDebug()<<memFile.buffer();
    qDebug()<<"array"<<array;

    QBuffer memFile1;
    memFile1.open(QIODevice::WriteOnly);
    QDataStream stream(&memFile1);
    stream<< QString(u8"测试")<<250;
    memFile1.close();

    qDebug()<<memFile1.buffer();

    memFile1.open(QIODevice::ReadOnly);
    QDataStream in;
    in.setDevice(&memFile1);
    QString str;
    int a;
    in>>str>>a;
    memFile1.close();
    qDebug()<<str.toUtf8().data()<<a;
}

Widget::~Widget()
{
    delete ui;
}
