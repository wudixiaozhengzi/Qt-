/********************************************************************************
** Form generated from reading UI file 'serverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWIDGET_H
#define UI_SERVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serverwidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit;
    QPushButton *buttonFile;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonSend;

    void setupUi(QWidget *Serverwidget)
    {
        if (Serverwidget->objectName().isEmpty())
            Serverwidget->setObjectName(QString::fromUtf8("Serverwidget"));
        Serverwidget->resize(400, 300);
        gridLayout = new QGridLayout(Serverwidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(120, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        label = new QLabel(Serverwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(120, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        textEdit = new QTextEdit(Serverwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 3);

        buttonFile = new QPushButton(Serverwidget);
        buttonFile->setObjectName(QString::fromUtf8("buttonFile"));

        gridLayout->addWidget(buttonFile, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(121, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 1, 1, 1);

        buttonSend = new QPushButton(Serverwidget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));

        gridLayout->addWidget(buttonSend, 2, 2, 1, 1);


        retranslateUi(Serverwidget);

        QMetaObject::connectSlotsByName(Serverwidget);
    } // setupUi

    void retranslateUi(QWidget *Serverwidget)
    {
        Serverwidget->setWindowTitle(QApplication::translate("Serverwidget", "Serverwidget", nullptr));
        label->setText(QApplication::translate("Serverwidget", "\346\234\215\345\212\241\345\231\250", nullptr));
        buttonFile->setText(QApplication::translate("Serverwidget", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        buttonSend->setText(QApplication::translate("Serverwidget", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Serverwidget: public Ui_Serverwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H
