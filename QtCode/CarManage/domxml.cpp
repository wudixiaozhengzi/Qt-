#include "domxml.h"
#include <QFile>
#include <QDomDocument>//文件
#include <QDomProcessingInstruction>//格式头部
#include <QDomElement>//元素
#include <QTextStream>//文件流
#include <QDebug>
#include <QDateTime>
#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"

Domxml::Domxml()
{

}

//创建xml空文件
void Domxml::createXML(QString filePath)
{
    QFile file(filePath);//关联文件名字
    if(true==file.exists())
    {
        cout<<u8"文件已经存在";
        //如果存在，不创建
        return;
    }
    else
    {
        //只写方式打开
        bool isOk=file.open(QIODevice::WriteOnly);
        if(true==isOk)//如果打开成功
        {
            //创建xml文档
            QDomDocument doc;
            //创建xml头部格式
            QDomProcessingInstruction ins;
            ins=doc.createProcessingInstruction("xml","version=\'1.0\' encoding=\'UTF-8\'");
            //追加元素
            doc.appendChild(ins);

            //根节点元素
            QDomElement root =doc.createElement(u8"日销售清单");
            doc.appendChild(root);

            //保存
            QTextStream stream(&file);//文本流关联文件
            doc.save(stream,4);//4代表缩进字符
            file.close();

        }
        else {
            cout<<"WriteOnly error";
            return;
        }

    }

}

void Domxml::appendXML(QString filePath,QStringList list)
{
    QFile file(filePath);
    bool isOk=file.open(QIODevice::ReadOnly);
    if(true==isOk)
    {
        //file和xml文件对象关联
        QDomDocument doc;
        isOk=doc.setContent(&file);
        if(isOk)//如果关联成功
        {
            file.close();//关闭文件
            //获取根节点元素
            QDomElement root=doc.documentElement();
            //获取当前时间
            QDateTime date= QDateTime::currentDateTime();
            QString dateStr=date.toString("yyyy-MM-dd");

            //判断根节点下有没有子节点元素
            if(root.hasChildNodes())
            {
                //查找最后一个子节点
                QDomElement lastEmt=root.lastChildElement();
                if(lastEmt.attribute("date")==dateStr)
                {
                    //有当天日期
                    //写有效数据
                    writeXML(doc,lastEmt,list);
                }
                else
                {
                    //如果没有
                    //没有子节点
                    //创建日期子节点
                    QDomElement dateEmt=doc.createElement(u8"日期");
                    //创建date属性
                    QDomAttr dateAttr= doc.createAttribute("date");
                    //设定属性的值
                    dateAttr.setNodeValue(dateStr);
                    //节点和属性关联
                    dateEmt.setAttributeNode(dateAttr);

                    //把日期节点追加到根节点上
                    root.appendChild(dateEmt);

                    //写有效数据
                    writeXML(doc,dateEmt,list);
                }
            }
            else {
                //没有子节点
                //创建日期子节点
                QDomElement dateEmt=doc.createElement(u8"日期");
                //创建date属性
                QDomAttr dateAttr= doc.createAttribute("date");
                //设定属性的值
                dateAttr.setNodeValue(dateStr);
                //节点和属性关联
                dateEmt.setAttributeNode(dateAttr);

                //把日期节点追加到根节点上
                root.appendChild(dateEmt);

                //写有效数据
                writeXML(doc,dateEmt,list);

            }

            //保存文件
            isOk=file.open(QIODevice::WriteOnly);
            if(isOk)
            {
                QTextStream stream(&file);
                doc.save(stream,4);
                file.close();
            }
        }
        else
        {
            cout<<"setcontent error";
            return;
        }

    }
    else {
        cout<<"readonly error";
    }
}

void Domxml::writeXML(QDomDocument &doc, QDomElement &root, QStringList list)
{
    //当前时间获取
    QDateTime time= QDateTime::currentDateTime();
    QString timeStr=time.toString("hh-mm-ss");

    //创建时间节点元素
    QDomElement timeEmt=doc.createElement(u8"时间");
    //创建属性
    QDomAttr timeAttr= doc.createAttribute("time");
    //给属性赋值
    timeAttr.setNodeValue(timeStr);
    //时间节点元素和属性关联
    timeEmt.setAttributeNode(timeAttr);
    //把时间节点加到日期节点后面
    root.appendChild(timeEmt);

    QDomElement factory =doc.createElement(u8"厂家");
    QDomElement brand =doc.createElement(u8"品牌");
    QDomElement price =doc.createElement(u8"报价");
    QDomElement num =doc.createElement(u8"数量");
    QDomElement total =doc.createElement(u8"金额");

    QDomText text=doc.createTextNode(list.at(0));
    factory.appendChild(text);

    text=doc.createTextNode(list.at(1));
    brand.appendChild(text);

    text=doc.createTextNode(list.at(2));
    price.appendChild(text);

    text=doc.createTextNode(list.at(3));
    num.appendChild(text);

    text=doc.createTextNode(list.at(4));
    total.appendChild(text);

    timeEmt.appendChild(factory);
    timeEmt.appendChild(brand);
    timeEmt.appendChild(price);
    timeEmt.appendChild(num);
    timeEmt.appendChild(total);


}

void Domxml::readXML(QString filePath, QStringList &fList, QStringList &bList, QStringList &pList, QStringList &nList, QStringList &tList)
{
    QFile file(filePath);
    bool isOk=file.open(QIODevice::ReadOnly);
    if(true==isOk)
    {
        //file和xml文件对象关联
        QDomDocument doc;
        isOk=doc.setContent(&file);
        if(isOk)//如果关联成功
        {
            //获取根节点
            QDomElement root=doc.documentElement();
            file.close();
            QDateTime date=QDateTime::currentDateTime();
            QString  dateStr =date.toString("yyyy-MM-dd");

            if(root.hasChildNodes())
            {
                //找到最后一个节点元素
                QDomElement lastEmt =root.lastChildElement();
                if(lastEmt.attribute("date")==dateStr)
                {
                    //找出当前日期下所有时间子节点
                    QDomNodeList list= lastEmt.childNodes();
                    for(int i=0;i<list.size();i++)
                    {
                        //list.at(0).toElement();
                        //转换为元素，找到时间节点下的所有子节点
                        QDomNodeList subList = list.at(i).toElement().childNodes();
                        //厂家
                        QString factory= subList.at(0).toElement().text();
                        fList.append(factory);

                        QString brand= subList.at(1).toElement().text();
                        bList.append(brand);

                        QString price= subList.at(2).toElement().text();
                        pList.append(price);

                        QString num= subList.at(3).toElement().text();
                        nList.append(num);

                        QString total= subList.at(0).toElement().text();
                        tList.append(total);

                    }
                }
                else {
                    cout<< "没有当天日期";
                    return;
                }
            }
            else {
                cout<<"没有子节点";
                return;
            }
        }
        else {
            cout<<"setContent error";
            return;
        }
    }
    else {
        cout<<"readOnly error";
        return;
    }
}


