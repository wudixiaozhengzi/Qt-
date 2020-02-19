#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //this->setStyleSheet("QLabel{color:rgb(0,255,0);"
    //                         "background-color:red;"
    //                         "}");
    ui->label->setStyleSheet("QLabel{color:rgb(0,255,0);"
                             "background-color:green;"
                             "border-image:url(:/new/prefix1/D:/QT_learn/day02/image/Sunny.jpg);"
                             "}");
    ui->pushButton->setStyleSheet("QPushButton{"
                                  "border-image:url(:/new/prefix1/D:/QT_learn/day02/image/Sunny.jpg);"
                                  "}"
                                  "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/D:/QT_learn/day02/image/up.png);"
                                  "}"
                                  "QPushButton:pressed{"
                                  "border-image:url(:/new/prefix1/D:/QT_learn/day02/image/Luffy.png);"
                                  "}");

}

Widget::~Widget()
{
    delete ui;
}
