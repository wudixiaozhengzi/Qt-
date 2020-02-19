#include "widget.h"
#include "ui_widget.h"
#include <QPainter>//设置画家
#include <QPen>//设置画笔
#include <QBrush>//设置画刷

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    x=0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    //两种方法创建画家对象
    //①
    //QPainter p(this);
    //②
    QPainter p;//创建画家对象
    p.begin(this);//指定当前窗口为绘图设备
    //绘图操作
    //p.drawxxxxx();
    //画背景图
    //p.drawPixmap(0,0,width(),height(),QPixmap("../image/d5d2c72f458e748b.jpg"));
    p.drawPixmap(rect(),QPixmap("../image/d5d2c72f458e748b.jpg"));

    //定义画笔
    QPen pen;
    pen.setWidth(5);//设置线宽
    pen.setColor(Qt::red);//设置简单颜色
    pen.setColor(QColor(15,9,214));//设置RGB颜色
    pen.setStyle(Qt::DashLine);//设置风格
    //画家用哪个画笔
    p.setPen(pen);

    //画直线
    p.drawLine(50,50,150,50);
    p.drawLine(50,50,50,150);

    //创建画刷对象
    QBrush brush;
    brush.setColor(Qt::red);//设置颜色
    brush.setStyle(Qt::Dense1Pattern);
    p.setBrush(brush);//画家用哪个画刷

    //画矩形
    p.drawRect(150,150,100,50);

    //画圆形
    p.drawEllipse(QPoint(150,150),50,25);

    //画个笑脸
    p.drawPixmap(x,130,80,80,QPixmap("../image/OnePiece.png"));

    p.end();
}



void Widget::on_pushButton_clicked()
{
    x+=20;
    if(x>width())
        x=0;
    //刷新窗口，让窗口重绘,整个窗口重绘
    update();//间接调用paintEvent()；
}
