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

    //打印qt支持的数据库驱动
    qDebug()<<QSqlDatabase::drivers();

    //添加Mysql数据库
    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");

    //连接数据库
    db.setHostName("127.0.0.1");      //连接数据库主机名，这里需要注意（若填的为”127.0.0.1“，出现不能连接，则改为localhost)
    db.setPort(3306);                 //连接数据库端口号，与设置一致
    db.setDatabaseName("test");      //连接数据库名，与设置一致
    db.setUserName("root");          //数据库用户名，与设置一致
    db.setPassword("88888888");    //数据库密码，与设置一致
    db.setDatabaseName("info");

    //打开数据库
    if(false==db.open())//数据库打开失败a
    {
        QMessageBox::warning(this,u8"错误",db.lastError().text());
        return;
    }

    QSqlQuery query;
    query.exec("create table student(id int primary key auto_increment,name varchar(255),age int,score int);");

/*    //如果要使用其他的数据库
    QSqlDatabase db1= QSqlDatabase::addDatabase("QMYSQL","a");
    QSqlQuery query(db1);
    db1.setHostName("127.0.0.1");
    db1.setPort(3306);
    db1.setDatabaseName("test");
    db1.setUserName("root");
    db1.setPassword("88888888");
    db1.setDatabaseName("test");

    if(false==db1.open())//数据库打开失败a
    {
        QMessageBox::warning(this,u8"错误",db.lastError().text());
        return;
    }
    QSqlQuery query1(db1);
    query1.exec("create table student(id int primary key auto_increment,name varchar(255),age int,score int);");
*/
    //插入
    //QSqlQuery query;
    query.exec("inset into student(id,name,age,score) values(1,'mike',15,20);");

    //批量插入
    //odbc风格
    //预处理语句
    //?相当于占位符
/*    query.prepare("insert into student(name,age,score) values(?,?,?)");
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

    //oracle风格
    //占位符:+自定义名字
    query.prepare("insert into student(name,age,score) values(:name,:age,:score)");
    QVariantList nameList,ageList,scoreList;
    nameList<<"xiaoming"<<"xiaojiang"<<"xiaolong";
    ageList<<15<<23<<23;
    scoreList<<549<<269<<739;
    //给字段绑定
    query.bindValue(":name",nameList);
    query.bindValue(":score",scoreList);
    query.bindValue(":age",ageList);
    //执行预处理命令
    query.execBatch();
*/
    query.exec("select *from student");
    while(query.next())//一行行遍历
    {
        //取出当前行内容
        qDebug()<<query.value(0).toInt()
                <<query.value(1).toString()
               <<query.value("age").toInt()
              <<query.value("score").toInt();
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonDel_clicked()
{
    //获取行编辑的内容
    QString name=ui->lineEdit->text();

    QString str=QString("delete from student where name='%1';").arg(name);

    //开启一个事务
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.exec(sql);

}

void Widget::on_buttonDel_2_clicked()
{
    //确定删除
    QSqlDatabase::database().commit();
}

void Widget::on_buttonCancel_clicked()
{
    //回滚
    QSqlDatabase::database().rollback();
}
