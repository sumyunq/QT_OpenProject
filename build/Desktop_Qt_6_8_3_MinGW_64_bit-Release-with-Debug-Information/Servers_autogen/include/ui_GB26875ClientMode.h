/********************************************************************************
** Form generated from reading UI file 'GB26875ClientMode.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GB26875CLIENTMODE_H
#define UI_GB26875CLIENTMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GB26875ClientMode
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_IP_Port;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ConnectToServer;
    QPushButton *pushButton_disConnect;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_IP_1;
    QLabel *label;
    QLineEdit *lineEdit_IP_2;
    QLabel *label_2;
    QLineEdit *lineEdit_IP_3;
    QLabel *label_3;
    QLineEdit *lineEdit_IP_4;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit_ServerMessage;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *textEdit_SendMessage;
    QPushButton *pushButton_sendToServer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;

    void setupUi(QWidget *GB26875ClientMode)
    {
        if (GB26875ClientMode->objectName().isEmpty())
            GB26875ClientMode->setObjectName("GB26875ClientMode");
        GB26875ClientMode->resize(1015, 627);
        gridLayout = new QGridLayout(GB26875ClientMode);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_5 = new QLabel(GB26875ClientMode);
        label_5->setObjectName("label_5");

        horizontalLayout_2->addWidget(label_5);

        lineEdit_IP_Port = new QLineEdit(GB26875ClientMode);
        lineEdit_IP_Port->setObjectName("lineEdit_IP_Port");

        horizontalLayout_2->addWidget(lineEdit_IP_Port);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_ConnectToServer = new QPushButton(GB26875ClientMode);
        pushButton_ConnectToServer->setObjectName("pushButton_ConnectToServer");

        horizontalLayout_2->addWidget(pushButton_ConnectToServer);

        pushButton_disConnect = new QPushButton(GB26875ClientMode);
        pushButton_disConnect->setObjectName("pushButton_disConnect");
        pushButton_disConnect->setEnabled(false);

        horizontalLayout_2->addWidget(pushButton_disConnect);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_4 = new QLabel(GB26875ClientMode);
        label_4->setObjectName("label_4");

        horizontalLayout->addWidget(label_4);

        lineEdit_IP_1 = new QLineEdit(GB26875ClientMode);
        lineEdit_IP_1->setObjectName("lineEdit_IP_1");
        lineEdit_IP_1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lineEdit_IP_1);

        label = new QLabel(GB26875ClientMode);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);

        lineEdit_IP_2 = new QLineEdit(GB26875ClientMode);
        lineEdit_IP_2->setObjectName("lineEdit_IP_2");
        lineEdit_IP_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lineEdit_IP_2);

        label_2 = new QLabel(GB26875ClientMode);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_2);

        lineEdit_IP_3 = new QLineEdit(GB26875ClientMode);
        lineEdit_IP_3->setObjectName("lineEdit_IP_3");
        lineEdit_IP_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lineEdit_IP_3);

        label_3 = new QLabel(GB26875ClientMode);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_3);

        lineEdit_IP_4 = new QLineEdit(GB26875ClientMode);
        lineEdit_IP_4->setObjectName("lineEdit_IP_4");
        lineEdit_IP_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lineEdit_IP_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_6 = new QLabel(GB26875ClientMode);
        label_6->setObjectName("label_6");

        horizontalLayout_3->addWidget(label_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        textEdit_ServerMessage = new QTextEdit(GB26875ClientMode);
        textEdit_ServerMessage->setObjectName("textEdit_ServerMessage");

        verticalLayout->addWidget(textEdit_ServerMessage);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_7 = new QLabel(GB26875ClientMode);
        label_7->setObjectName("label_7");

        horizontalLayout_4->addWidget(label_7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        textEdit_SendMessage = new QTextEdit(GB26875ClientMode);
        textEdit_SendMessage->setObjectName("textEdit_SendMessage");

        verticalLayout_2->addWidget(textEdit_SendMessage);


        horizontalLayout_5->addLayout(verticalLayout_2);

        pushButton_sendToServer = new QPushButton(GB26875ClientMode);
        pushButton_sendToServer->setObjectName("pushButton_sendToServer");
        pushButton_sendToServer->setEnabled(false);

        horizontalLayout_5->addWidget(pushButton_sendToServer);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_3, 3, 1, 1, 1);

        scrollArea = new QScrollArea(GB26875ClientMode);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("\n"
"QScrollArea {\n"
"    border: 1px solid #cccccc;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QScrollArea > QWidget > QWidget {\n"
"    background-color: transparent;\n"
"}\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 494, 547));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName("gridLayout_2");
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 3, 0, 1, 1);


        retranslateUi(GB26875ClientMode);

        QMetaObject::connectSlotsByName(GB26875ClientMode);
    } // setupUi

    void retranslateUi(QWidget *GB26875ClientMode)
    {
        GB26875ClientMode->setWindowTitle(QCoreApplication::translate("GB26875ClientMode", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("GB26875ClientMode", "\347\253\257\345\217\243\357\274\232", nullptr));
        lineEdit_IP_Port->setText(QCoreApplication::translate("GB26875ClientMode", "7358", nullptr));
        pushButton_ConnectToServer->setText(QCoreApplication::translate("GB26875ClientMode", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        pushButton_disConnect->setText(QCoreApplication::translate("GB26875ClientMode", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        label_4->setText(QCoreApplication::translate("GB26875ClientMode", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200:", nullptr));
        lineEdit_IP_1->setText(QCoreApplication::translate("GB26875ClientMode", "127", nullptr));
        label->setText(QCoreApplication::translate("GB26875ClientMode", ".", nullptr));
        lineEdit_IP_2->setText(QCoreApplication::translate("GB26875ClientMode", "0", nullptr));
        label_2->setText(QCoreApplication::translate("GB26875ClientMode", ".", nullptr));
        lineEdit_IP_3->setText(QCoreApplication::translate("GB26875ClientMode", "0", nullptr));
        label_3->setText(QCoreApplication::translate("GB26875ClientMode", ".", nullptr));
        lineEdit_IP_4->setText(QCoreApplication::translate("GB26875ClientMode", "1", nullptr));
        label_6->setText(QCoreApplication::translate("GB26875ClientMode", "\346\234\215\345\212\241\345\231\250\346\266\210\346\201\257\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("GB26875ClientMode", "\345\267\262\345\217\221\351\200\201\346\225\260\346\215\256\346\212\245\357\274\232", nullptr));
        pushButton_sendToServer->setText(QCoreApplication::translate("GB26875ClientMode", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GB26875ClientMode: public Ui_GB26875ClientMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GB26875CLIENTMODE_H
