#include "widget.h"
#include "ui_widget.h"
#include <Qdebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    timerId=this->startTimer(1000);//毫秒为单位，每隔1s触发一次定时器
    this->timerId2=this->startTimer(500);
    connect(ui->pushButton,&MyButton::clicked,
            [=]()
            {
                qDebug()<<u8"按钮被摁下";
            }
            );

    //安装过滤器
    ui->label_2->installEventFilter(this);
    //设置一开始鼠标追踪
    ui->label_2->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    qDebug()<<(char)e->key();
    if(e->key()==Qt::Key_A)
    {
        qDebug()<<"Key_A";
    }
}

void Widget::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==this->timerId)
    {
        static int sec=0;
        ui->label->setText(QString("<center><h1>time out:%1</h1></center>").arg(sec++));
        if(sec==5){
            this->killTimer(timerId);
        }
    }
    else if(e->timerId()==this->timerId2)
    {
        static int sec=0;
        ui->label_2->setText(QString("<center><h1>time out:%1</h1></center>").arg(sec++));
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"+++++";
}

void Widget::closeEvent(QCloseEvent *event)
{
    int ret =QMessageBox::question(this,"question",u8"是否要关闭窗口");
    if(ret==QMessageBox::Yes)
    {
        //关闭窗口
        //处理关闭窗口事件，接受事件，事件就不会再往下传递
        event->accept();
    }
    else
    {
        //不关闭窗口
        //忽略时间，时间继续给父组件传递
        event->ignore();
    }
}

bool Widget::event(QEvent *event)
{
//    //事件分发
//    switch(event->type())
//    {
//        case QEvent::Close:
//            closeEvent(event);
//        break;
//        case QEvent::MouseMove:
//            mouseMoveEvent(event);
//        break;
//    }
    if(event->type()==QEvent::Timer)
    {
        //干掉定时器
        //如果返回true，时间停止传播
        return true;
    }
    else if(event->type()==QEvent::KeyPress){
        QKeyEvent *env=static_cast<QKeyEvent *>(event);//类型转换
        if(env->key()==Qt::Key_B)
        {
            return Widget::event(event);
        }
        return true;
    }
    else {
        return QWidget::event(event);
    }
}

bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj==ui->label_2)
    {
        //类型转换
        QMouseEvent *env=static_cast<QMouseEvent *>(e);
        //判断事件
        if(e->type()==QEvent::MouseMove)
        {
            ui->label_2->setText(QString("Mouse move:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;
        }
        else if(e->type()==QEvent::MouseButtonPress)
        {
            ui->label_2->setText(QString("Mouse press:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;
        }
        else if(e->type()==QEvent::MouseButtonDblClick)
        {
            ui->label_2->setText(QString("Mouse DblClick:(%1,%2)").arg(env->x()).arg(env->y()));
            return true;
        }
        else {
            return QWidget::eventFilter(obj,e);
        }
    }
    else {
        return QWidget::eventFilter(obj,e);
    }

}




