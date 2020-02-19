#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QDateTime>
#include <QDataStream>//数据流

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

void Widget::on_ButtonRead_clicked()
{
    QString path=QFileDialog::getOpenFileName(this,"open","../","TXT(*.txt)");

    if(path.isEmpty()==false)
    {
        //文件对象
        QFile file(path);
        //打开文件,只读方式打开
        bool isok=file.open(QIODevice::ReadOnly);
        if(isok==true)
        {
            //读文件,默认只识别utf8编码
            #if 0
            //暴力一次读完（不推荐）
            QByteArray array= file.readAll();
            //显示到编辑区
            ui->textEdit->setText(QString(array));
#endif
            //一行一行来读代码
            QByteArray array;
            while(file.atEnd()==false)
            {
                //读一行
                array+=file.readLine();
            }
            ui->textEdit->setText(array);
        }
        //关闭文件
    file.close();

    //获取文件信息
    QFileInfo info(path);
    qDebug()<<u8"文件名字"<<info.fileName().toUtf8().data();
    qDebug()<<u8"文件后缀"<<info.suffix();
    qDebug()<<u8"文件大小"<<info.size();
    qDebug()<<u8"文件创建时间"<<info.created().toString("yyyy-MM-dd hh:mm:ss");//2019-02-14

    }

}

void Widget::on_ButtonWrite_clicked()
{
    QString path= QFileDialog::getSaveFileName(this,"save","../","TXT(*.txt)");
    if(path.isEmpty()==false)
    {
        QFile file;//创建文件对象
        //关联文件名字
        file.setFileName(path);
        //打开方式，只写方式
        bool isOk=file.open(QIODevice::WriteOnly);
        if(isOk==true)
        {   //获取编辑区的内容
            QString str=ui->textEdit->toPlainText();
            //写文件
            //把字符串QString转化为字节数组QByteArray
            file.write(str.toUtf8());
            //转换为本地平台编码
            //file.write(str.toLocal8Bit());

            ////QString->QByteArray
            //QString buf="123";
            //QByteArray a= buf.toUtf8();//有中文
            //
            ////QByteArray->char *
            //char *b=a.data();
            //
            ////char *->QString
            //char *p="abc";
            //QString c=QString(p);
        }
    file.close();
    }
}
