#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}
void MyButton::mousePressEvent(QMouseEvent *e)
{
    //左键按下就打印一句话
    if(e->button()==Qt::LeftButton)
    {
        qDebug()<<u8"摁下的是左键";
        //事件接受后，就会往下传递
        e->ignore();//忽略，时间继续往下传递，给谁传递呢？
                    //事件传递给了父组件widget，不是给父类（基类）
    }else {
        //不作处理
        QPushButton::mousePressEvent(e);
        //事件的忽略，时间继续往下传递
    }


}
