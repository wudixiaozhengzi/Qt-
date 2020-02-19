#include "mainwidget.h"
#include <QPushButton>
#include <QDebug>   //打印

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);

    b2=new QPushButton(this);
    b2->setText("abc");

    connect(&b1,&QPushButton::pressed,this,&MainWidget::close);
    /*
     * &b1:信号发送者，指针类型
     * &QPushButton::pressed  处理的信号，&发送者的类名::信号名字
     * this  信号接受者
     * &MainWidget::close  槽函数，信号处理函数，&接收的类名::槽函数名字
    */

    /*自定义槽
     * Qt5：任意的成员函数，普通全局函数，静态函数
     * 槽函数需要和信号一致（参数，返回值）
     * 由于信号都是没有返回值的，所以，槽函数一定没有返回值
     *
     */
    connect(b2,&QPushButton::released,this,&MainWidget::mySlot);
    //释放b2，使b1隐藏
    connect(b2,&QPushButton::released,&b1,&QPushButton::hide);

    setWindowTitle("laoda");
    //this->setWindowTitle("laoda");

    b3.setParent(this);
    b3.setText(u8"切换到子窗口");
    b3.move(50,50);

    connect(&b3,&QPushButton::released,this,&MainWidget::changeWin);

    //处理子窗口信号，信号出现重载，需要指定
    void(SubWidget::*funSignal)()=&SubWidget::mySignal;
    connect(&subWin,funSignal,this,&MainWidget::dealSub);

    void(SubWidget::*testSignal)(int,QString)=&SubWidget::mySignal;
    connect(&subWin,testSignal,this,&MainWidget::dealSlot);

    //Lambda表达式，匿名函数对象
    //C++增加的新特性
    //配合信号一起使用，很方便
    QPushButton *b4=new QPushButton(this);
    b4->setText(u8"Lambda表达式");
    b4->move(150,150);
    connect(b4,&QPushButton::released,
            //=把外部所有局部变量、类中所有成员以值传递方式，只读
            //this类中所有成员以值传递方式
            //&把外部所有局部变量，引用符号。要注意内存的冲突
            [=]() mutable//mutable传进去之后可以修改
            {
                b4->setText("486512");
                qDebug() <<"111111";
            }
            );
    resize(400,300);

}

void MainWidget::mySlot()
{
    b2->setText("123");
}

void MainWidget::dealSlot(int a, QString str)
{
    //str.toUtf8()转化为字节数组QByteArray
    //data()    是将字节数组QByteArray转化为char *
    qDebug()<<a<<str.toUtf8().data();
}

void MainWidget::changeWin()
{
    //子窗口显示
    subWin.show();
    //本窗口隐藏
    this->hide();
}

void MainWidget::dealSub()
{
   subWin.hide();
    show();
}

MainWidget::~MainWidget()
{

}
