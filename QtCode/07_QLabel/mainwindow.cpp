#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QCompleter>
#include <QStringList>
#include <QMovie>
#include <QtWebView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("123");

    //QLineEdit
    QString str=ui->lineEdit->text();
    qDebug()<<str;
    //设置QLineEdit内容
    ui->lineEdit->setText("123456");
    //设置QLineEdit内容显示间隙
    ui->lineEdit->setTextMargins(15,0,0,0);
    //设置QLineEdit内容显示方式
    //ui->lineEdit->setEchoMode(QLineEdit::Password);
    //提示输入
    QStringList list;
    list<<"hello"<<"how are you "<<"Hehe";
    QCompleter *com=new QCompleter(list,this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(com);

    //QLabel设置文本内容
    ui->labelText->setText("^-^");
    //QLabel设置图片
    ui->labelImage->setPixmap(QPixmap(":/new/prefix1/D:/QT_learn/day02/image/LuffyQ.png"));
    //让图片自动适应label大小
    ui->labelImage->setScaledContents(true);

    //创建动画
    QMovie *myMovie=new QMovie(":/new/prefix1/D:/QT_learn/day02/image/mario.gif");
    //设定动画
    ui->labelGif->setMovie(myMovie);
    //让动画自动适应label大小
    ui->labelGif->setScaledContents(true);
    //启动动画
    myMovie->start();

    //设置html
    ui->labelUrl ->setText(u8"<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
    ui->labelUrl ->setOpenExternalLinks(true);

    //设置数码管
    ui->lcdNumber->display(123);

    //进度条
    ui->progressBar->setMinimum(0);//设定最小值
    ui->progressBar->setMaximum(200);//设定最大值
    ui->progressBar->setValue(100);//设定当前值

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
    static int i=0;

    ui->stackedWidget->setCurrentIndex(((++i)+1)%3);
}
