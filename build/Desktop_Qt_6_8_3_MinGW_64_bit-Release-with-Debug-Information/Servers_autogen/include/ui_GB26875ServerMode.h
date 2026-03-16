/********************************************************************************
** Form generated from reading UI file 'GB26875ServerMode.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GB26875SERVERMODE_H
#define UI_GB26875SERVERMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GB26875ServerMode
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;

    void setupUi(QWidget *GB26875ServerMode)
    {
        if (GB26875ServerMode->objectName().isEmpty())
            GB26875ServerMode->setObjectName("GB26875ServerMode");
        GB26875ServerMode->resize(818, 547);
        gridLayout = new QGridLayout(GB26875ServerMode);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(GB26875ServerMode);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        listView = new QListView(GB26875ServerMode);
        listView->setObjectName("listView");

        verticalLayout_2->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(GB26875ServerMode);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(GB26875ServerMode);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        textEdit = new QTextEdit(GB26875ServerMode);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 1, 1, 1, 1);

        scrollArea = new QScrollArea(GB26875ServerMode);
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
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 395, 527));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName("gridLayout_2");
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea, 0, 0, 2, 1);


        retranslateUi(GB26875ServerMode);

        QMetaObject::connectSlotsByName(GB26875ServerMode);
    } // setupUi

    void retranslateUi(QWidget *GB26875ServerMode)
    {
        GB26875ServerMode->setWindowTitle(QCoreApplication::translate("GB26875ServerMode", "Form", nullptr));
        label->setText(QCoreApplication::translate("GB26875ServerMode", "\345\234\250\347\272\277\345\210\227\350\241\250\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("GB26875ServerMode", "\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GB26875ServerMode", "\345\217\221\351\200\201\346\225\260\346\215\256\345\214\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GB26875ServerMode: public Ui_GB26875ServerMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GB26875SERVERMODE_H
