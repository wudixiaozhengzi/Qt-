#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    tcpScoket=new QTcpSocket(this);

    isStart=true;

    connect(tcpScoket,&QTcpSocket::readyRead,
            [=]()
            {
                //取出接收的内容
                QByteArray buf =tcpScoket->readAll();
                if(true==isStart)
                {
                    isStart=false;
                    //解析头部信息 QString buf="hello##1024"
                    fileName =QString(buf).section("##",0,0);
                    fileSize=QString(buf).section("##",1,1).toInt();
                    recvSize=0;

                    //打开文件
                    file.setFileName(fileName);

                    bool isOk=file.open(QIODevice::WriteOnly);
                    if(false==isOk)
                    {
                        qDebug()<<"WriteOnly Error34";
                    }

                }
                else {//读取文件信息
                    qint64 len=file.write(buf);
                    recvSize+=len;

                    if(recvSize==fileSize)
                    {
                        file.close();
                        QMessageBox::information(this,u8"完成",u8"文件接受完成");

                        tcpScoket->disconnectFromHost();
                        tcpScoket->close();
                    }
                }
            }
            );
}

ClientWidget::~ClientWidget()
{
    delete ui;
}



void ClientWidget::on_buttonConnect_clicked()
{
    //获取服务器IP和端口
    QString ip=ui->lineEditIP->text();
    quint16 port=ui->lineEditPort->text().toInt();

    tcpScoket->connectToHost(QHostAddress(ip),port);
}
