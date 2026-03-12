/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *left_widget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *mid_widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *right_widget;
    QGridLayout *gridLayout;
    QPushButton *testNet;
    QWidget *svg_widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_weather;
    QHBoxLayout *horizontalLayout_2;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1738, 828);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        action = new QAction(MainWindow);
        action->setObjectName("action");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/resources/images/20200423170236_ihJPj.gif"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        left_widget = new QWidget(centralwidget);
        left_widget->setObjectName("left_widget");
        left_widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(left_widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        pushButton = new QPushButton(left_widget);
        pushButton->setObjectName("pushButton");

        verticalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(left_widget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_3->addWidget(pushButton_2);


        horizontalLayout->addWidget(left_widget);

        mid_widget = new QWidget(centralwidget);
        mid_widget->setObjectName("mid_widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mid_widget->sizePolicy().hasHeightForWidth());
        mid_widget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(mid_widget);
        verticalLayout_2->setObjectName("verticalLayout_2");

        horizontalLayout->addWidget(mid_widget);

        right_widget = new QWidget(centralwidget);
        right_widget->setObjectName("right_widget");
        gridLayout = new QGridLayout(right_widget);
        gridLayout->setObjectName("gridLayout");
        testNet = new QPushButton(right_widget);
        testNet->setObjectName("testNet");

        gridLayout->addWidget(testNet, 2, 0, 1, 1);

        svg_widget = new QWidget(right_widget);
        svg_widget->setObjectName("svg_widget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(svg_widget->sizePolicy().hasHeightForWidth());
        svg_widget->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(svg_widget);
        verticalLayout->setObjectName("verticalLayout");

        gridLayout->addWidget(svg_widget, 0, 0, 1, 2);

        widget_weather = new QWidget(right_widget);
        widget_weather->setObjectName("widget_weather");
        horizontalLayout_2 = new QHBoxLayout(widget_weather);
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        gridLayout->addWidget(widget_weather, 1, 0, 1, 1);


        horizontalLayout->addWidget(right_widget);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1738, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\244\251\346\260\224\346\250\241\345\235\227", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "GB26875\345\215\217\350\256\256\346\250\241\345\235\227", nullptr));
        testNet->setText(QCoreApplication::translate("MainWindow", "\345\244\251\346\260\224\346\225\260\346\215\256\346\265\213\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
