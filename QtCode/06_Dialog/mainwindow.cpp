#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar=menuBar();
    setMenuBar(mBar);
    QMenu *menu=mBar->addMenu(u8"对话框");
    QAction *p1=menu->addAction(u8"模态对话框");
    connect(p1,&QAction::triggered,
            [=]()
            {
                QDialog dlg;
                dlg.exec();
                qDebug() <<"111111";
            }
            );

    QAction *p2=menu->addAction(u8"非模态对话框");
    connect(p2,&QAction::triggered,
            [=]()
            {
                //QDialog dlg;//如果在这里做静态变量的话，运行对话框会一闪而过
                //可以做成员，也可以动态分布，两种方法来解决问题
                //dlg.show();
                //两个对话框并不会相互阻塞
                //qDebug() <<"122211";
                //动态分布：
                //QDialog *p=new QDialog(this);
                //p->show();
                //但动态分布容易造成内存的冗余；
                QDialog *p=new QDialog;
                p->setAttribute(Qt::WA_DeleteOnClose);
                p->show();
            }
            );
    QAction *p3=menu->addAction(u8"关于对话框");
    connect(p3,&QAction::triggered,
            [=]()
            {
                QMessageBox::about(this,"about",u8"关于qt");
            }
            );
    QAction *p4=menu->addAction(u8"问题对话框");
    connect(p4,&QAction::triggered,
            [=]()
            {
                int ret=QMessageBox::question(this,"question",u8"are you ok?",QMessageBox::Ok|QMessageBox::Cancel);
                switch(ret)
                {
                    case QMessageBox::Ok:
                        qDebug()<<"i am ok.";
                    break;
                    case QMessageBox::Cancel:
                        qDebug()<<"i am bad";
                    break;
                    default:
                        break;
                }
            }
            );
    QAction *p5=menu->addAction(u8"文件对话框");
    connect(p5,&QAction::triggered,
            [=]()
            {
                QString path=QFileDialog::getOpenFileName(this,
                                                          "open",
                                                          "../",
                                                          "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)");//"../"上一级路径
                qDebug()<<path;
            }
            );

}

MainWindow::~MainWindow()
{

}
