#include "mainwindow.h"
#include <QMenuBar>//菜单栏
#include <QMenu>//菜单
#include <QAction>//菜单项
#include <QDebug>
#include <QToolBar>//工具栏
#include <QPushButton>
#include <QStatusBar>//状态栏
#include <QLabel>//标签
#include <QTextEdit>//文本编辑区
#include <QDockWidget>//浮动窗

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //菜单栏
    QMenuBar *mBar=menuBar();
    //添加菜单
    QMenu *pFile=mBar->addMenu(u8"文件");
    //添加菜单项、添加动作
    QAction *pNew = pFile->addAction(u8"新建");

    connect(pNew,&QAction::triggered,
            [=]()
            {
                qDebug() << u8"新建被摁下";
            }
            );
    pFile->addSeparator();//添加分割线
    QAction *pOpen=pFile->addAction(u8"打开");

    //工具栏，菜单项的快捷方式
    QToolBar *toolBar=addToolBar("toolBar");
    //工具栏添加快捷键
    toolBar->addAction(pNew);
    QPushButton *b=new QPushButton(this);
    b->setText("^_^");
    //添加小控件
    toolBar->addWidget(b);
    connect(b,&QPushButton::clicked,
            [=]()
            {
                b->setText("123");
            }
            );

    //状态栏
    QStatusBar *sBar=statusBar();
    QLabel *label=new QLabel(this);
    label->setText("Normal text file");
    sBar->addWidget(label);
    //addWidget 从左往右添加
    sBar->addWidget(new QLabel("2",this));
    //addPermanentWidget从右往左添加
    sBar->addPermanentWidget(new QLabel("3",this));

    //以文本编辑区作为核心控件
    QTextEdit *textEdit=new QTextEdit(this);
    setCentralWidget(textEdit);

    //浮动窗口
    QDockWidget *dock=new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    //给浮动窗口添加控件
    QTextEdit *textEdit1=new QTextEdit(this);
    dock->setWidget(textEdit1);

}

MainWindow::~MainWindow()
{

}
