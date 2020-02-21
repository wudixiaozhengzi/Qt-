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

    //添加sqlite数据库
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    db.setDatabaseName("../info.db");


    //打开数据库
    if(false==db.open())//数据库打开失败a
    {
        QMessageBox::warning(this,u8"错误",db.lastError().text());
        return;
    }

    //插入
    QSqlQuery query;
    query.exec("inset into student(id,name,age,score) values(1,'mike',15,20);");

    //批量插入
    //odbc风格
    //预处理语句
    //?相当于占位符
   query.prepare("insert into student(name,age,score) values(?,?,?)");
    //给字段设置内容 list
    QVariantList nameList,ageList,scoreList;
    nameList<<"xiaoming"<<"xiaojiang"<<"xiaolong";
    ageList<<11<<22<<33;
    scoreList<<59<<69<<79;
    //给字段绑定相应的值，按顺序绑定
    query.addBindValue(nameList);
    query.addBindValue(ageList);
    query.addBindValue(scoreList);
    //执行预处理命令
    query.execBatch();


}

Widget::~Widget()
{
    delete ui;
}
