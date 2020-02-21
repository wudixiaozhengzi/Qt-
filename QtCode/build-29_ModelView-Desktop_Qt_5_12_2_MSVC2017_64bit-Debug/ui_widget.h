/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(535, 368);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(Widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 5);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 2);

        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 4, 1, 1);

        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 4, 1, 1);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 2, 1, 1, 3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\345\242\236\345\212\240", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "\347\241\256\345\256\232\345\210\240\351\231\244", nullptr));
        pushButton_4->setText(QApplication::translate("Widget", "\345\217\226\346\266\210\345\210\240\351\231\244", nullptr));
        pushButton_5->setText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\344\272\272", nullptr));
        pushButton_6->setText(QApplication::translate("Widget", "\346\237\245\346\211\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
