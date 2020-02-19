#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

//绘图设备
//QPixmap:针对屏幕进行优化了，和平台相关，不能对图片进行修改
//QImage：和平台无关，可以对图片进行修改，在线程中绘图
//QPicture：保存绘图的状态（二进制文件）

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //绘图设备，400*300
    QPixmap pixmap(400,300);
    QPainter p(&pixmap);

    //通过画家填充背景色
    //p.fillRect(0,0,400,300,QBrush(Qt::white));
    //通过绘图设备填充背景色
    pixmap.fill(Qt::red);

    p.drawPixmap(0,0,80,80,QPixmap("../image/OnePiece.png"));
    //保存图片
    pixmap.save("../pixmap.png");
}

Widget::~Widget()
{
    delete ui;
}

