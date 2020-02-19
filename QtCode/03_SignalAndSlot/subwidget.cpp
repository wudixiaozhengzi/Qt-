#include "subwidget.h"
#pragma execution_character_set("utf-8")
SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("xiaodi");
    b.setParent(this);
    b.setText(u8"切换到主窗口");
    connect(&b,&QPushButton::clicked,this,&SubWidget::sendSlot);
    //因为子窗口没有主窗口的指针，所以要先发送信号回主窗口
    resize(400,300);
}

void SubWidget::sendSlot()
{
    emit mySignal();
    emit mySignal(250,u8"子窗口");
}
