/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QLabel *label;
    QLineEdit *lineEditIP;
    QLineEdit *lineEditPort;
    QLabel *label_2;
    QPushButton *buttonConnect;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QString::fromUtf8("ClientWidget"));
        ClientWidget->resize(400, 300);
        label = new QLabel(ClientWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 81, 20));
        lineEditIP = new QLineEdit(ClientWidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));
        lineEditIP->setGeometry(QRect(120, 60, 113, 20));
        lineEditPort = new QLineEdit(ClientWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(120, 90, 113, 20));
        label_2 = new QLabel(ClientWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 81, 20));
        buttonConnect = new QPushButton(ClientWidget);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));
        buttonConnect->setGeometry(QRect(270, 80, 75, 23));

        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QApplication::translate("ClientWidget", "Form", nullptr));
        label->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\347\253\257IP", nullptr));
        lineEditIP->setText(QApplication::translate("ClientWidget", "127.0.0.1", nullptr));
        lineEditPort->setText(QApplication::translate("ClientWidget", "8888", nullptr));
        label_2->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\347\253\257\347\253\257\345\217\243", nullptr));
        buttonConnect->setText(QApplication::translate("ClientWidget", "connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
