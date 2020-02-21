#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QSqlQuery>
#include<QVariantList>

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
