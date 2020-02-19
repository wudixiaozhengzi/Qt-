#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    //QPixmap图片背景透明
    p.drawPixmap(0,0,QPixmap("../image/butterfly.png"));
    //QBitmap图片背景透明
    p.drawPixmap(200,0,QBitmap("../image/butterfly.png"));

    //QPixmap图片背景不透明
    QPixmap pixmap;
    pixmap.load("../image/butterfly1.png");
    p.drawPixmap(0,200,pixmap);
    //QPixmap图片背景不透明
    QBitmap bitmap;
    bitmap.load("../image/butterfly1.png");
    p.drawPixmap(200,200,bitmap);


}






