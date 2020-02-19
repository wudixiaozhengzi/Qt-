#include "mybotton.h"
#include <QDebug>

MyBotton::MyBotton(QWidget *parent) : QPushButton(parent)
{

}

MyBotton::~MyBotton()
{
    qDebug() <<u8"按钮被析构";
}
