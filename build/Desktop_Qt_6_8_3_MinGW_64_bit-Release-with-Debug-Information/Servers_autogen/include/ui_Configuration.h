/********************************************************************************
** Form generated from reading UI file 'Configuration.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATION_H
#define UI_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Configuration
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *IP_labal;
    QLineEdit *IP_lineEdit_1;
    QLabel *label_3;
    QLineEdit *IP_lineEdit_2;
    QLabel *label_4;
    QLineEdit *IP_lineEdit_4;
    QLabel *label_5;
    QLineEdit *IP_lineEdit_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Port_label;
    QLineEdit *Port_lineEdit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QPushButton *save_pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancel_pushButton;

    void setupUi(QWidget *Configuration)
    {
        if (Configuration->objectName().isEmpty())
            Configuration->setObjectName("Configuration");
        Configuration->resize(458, 233);
        gridLayout = new QGridLayout(Configuration);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 5, 1, 1);

        widget = new QWidget(Configuration);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        IP_labal = new QLabel(widget);
        IP_labal->setObjectName("IP_labal");
        IP_labal->setMinimumSize(QSize(80, 0));
        IP_labal->setMaximumSize(QSize(80, 16777215));
        IP_labal->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(IP_labal);

        IP_lineEdit_1 = new QLineEdit(widget);
        IP_lineEdit_1->setObjectName("IP_lineEdit_1");
        IP_lineEdit_1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(IP_lineEdit_1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_3);

        IP_lineEdit_2 = new QLineEdit(widget);
        IP_lineEdit_2->setObjectName("IP_lineEdit_2");
        IP_lineEdit_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(IP_lineEdit_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_4);

        IP_lineEdit_4 = new QLineEdit(widget);
        IP_lineEdit_4->setObjectName("IP_lineEdit_4");
        IP_lineEdit_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(IP_lineEdit_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_5);

        IP_lineEdit_3 = new QLineEdit(widget);
        IP_lineEdit_3->setObjectName("IP_lineEdit_3");
        IP_lineEdit_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(IP_lineEdit_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Port_label = new QLabel(widget);
        Port_label->setObjectName("Port_label");
        Port_label->setMinimumSize(QSize(80, 0));
        Port_label->setMaximumSize(QSize(80, 16777215));
        Port_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(Port_label);

        Port_lineEdit = new QLineEdit(widget);
        Port_lineEdit->setObjectName("Port_lineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Port_lineEdit->sizePolicy().hasHeightForWidth());
        Port_lineEdit->setSizePolicy(sizePolicy);
        Port_lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(Port_lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(widget, 1, 2, 1, 5);

        save_pushButton = new QPushButton(Configuration);
        save_pushButton->setObjectName("save_pushButton");

        gridLayout->addWidget(save_pushButton, 2, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        cancel_pushButton = new QPushButton(Configuration);
        cancel_pushButton->setObjectName("cancel_pushButton");

        gridLayout->addWidget(cancel_pushButton, 2, 4, 1, 1);


        retranslateUi(Configuration);

        QMetaObject::connectSlotsByName(Configuration);
    } // setupUi

    void retranslateUi(QWidget *Configuration)
    {
        Configuration->setWindowTitle(QCoreApplication::translate("Configuration", "Form", nullptr));
        IP_labal->setText(QCoreApplication::translate("Configuration", "\346\234\215\345\212\241\345\231\250IP:", nullptr));
        IP_lineEdit_1->setText(QCoreApplication::translate("Configuration", "127", nullptr));
        label_3->setText(QCoreApplication::translate("Configuration", ".", nullptr));
        IP_lineEdit_2->setText(QCoreApplication::translate("Configuration", "0", nullptr));
        label_4->setText(QCoreApplication::translate("Configuration", ".", nullptr));
        IP_lineEdit_4->setText(QCoreApplication::translate("Configuration", "0", nullptr));
        label_5->setText(QCoreApplication::translate("Configuration", ".", nullptr));
        IP_lineEdit_3->setText(QCoreApplication::translate("Configuration", "1", nullptr));
        Port_label->setText(QCoreApplication::translate("Configuration", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243:", nullptr));
        Port_lineEdit->setText(QCoreApplication::translate("Configuration", "8080", nullptr));
        save_pushButton->setText(QCoreApplication::translate("Configuration", "\344\277\235\345\255\230\351\205\215\347\275\256", nullptr));
        cancel_pushButton->setText(QCoreApplication::translate("Configuration", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Configuration: public Ui_Configuration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATION_H
