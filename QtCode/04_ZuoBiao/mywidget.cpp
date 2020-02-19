#include "mywidget.h"
#include <QPushButton>
#include <mybotton.h>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    /*坐标系统
     *对于父窗口，坐标相对于屏幕
     * 原点：相对与屏幕左上角
     * x：往右递增
     * y：往下递增
     */
    move(100,100);

    /*坐标系统
     *对于子窗口，坐标相对于屏幕
     * 原点：相对与父窗口空白区域左上角，不包括边框
     * x：往右递增
     * y：往下递增
     */
    QPushButton *b1 = new QPushButton(this);
    b1->move(100,100);
    b1->setText("x---x");
    b1->resize(200,100);

    QPushButton *b2 = new QPushButton(b1);
    b2->move(10,10);
    b2->setText("x--x");

    MyBotton *b3 = new MyBotton(this);
    b3->setText("123");
    //指定父对象后，或直接或间接继承于QObject
    //子对象如果是动态分配空间的new，不需要手动释放delete
    //系统会自动释放
}

MyWidget::~MyWidget()
{

}
