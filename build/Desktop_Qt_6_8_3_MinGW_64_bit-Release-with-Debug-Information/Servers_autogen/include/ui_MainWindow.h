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
#include <QtWidgets/QSpacerItem>
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
    QPushButton *pushButton_showWeather;
    QPushButton *pushButton_showGB26875_Server;
    QPushButton *pushButton_showGB26875_Client;
    QWidget *mid_widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *right_widget;
    QGridLayout *gridLayout;
    QPushButton *testNet;
    QWidget *svg_widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_weather;
    QHBoxLayout *horizontalLayout_2;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1738, 828);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow#MainWindow{\n"
"	border-image: url(:/img/resources/images/weatherBackground.png);\n"
"}"));
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
        pushButton_showWeather = new QPushButton(left_widget);
        pushButton_showWeather->setObjectName("pushButton_showWeather");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        pushButton_showWeather->setFont(font);

        verticalLayout_3->addWidget(pushButton_showWeather);

        pushButton_showGB26875_Server = new QPushButton(left_widget);
        pushButton_showGB26875_Server->setObjectName("pushButton_showGB26875_Server");
        pushButton_showGB26875_Server->setFont(font);

        verticalLayout_3->addWidget(pushButton_showGB26875_Server);

        pushButton_showGB26875_Client = new QPushButton(left_widget);
        pushButton_showGB26875_Client->setObjectName("pushButton_showGB26875_Client");
        pushButton_showGB26875_Client->setFont(font);

        verticalLayout_3->addWidget(pushButton_showGB26875_Client);


        horizontalLayout->addWidget(left_widget);

        mid_widget = new QWidget(centralwidget);
        mid_widget->setObjectName("mid_widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mid_widget->sizePolicy().hasHeightForWidth());
        mid_widget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(mid_widget);
        verticalLayout_2->setObjectName("verticalLayout_2");

        horizontalLayout->addWidget(mid_widget);

        right_widget = new QWidget(centralwidget);
        right_widget->setObjectName("right_widget");
        right_widget->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QWidget#right_widget  {\n"
"\n"
"\n"
"color: white;           /* \350\256\276\347\275\256\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"}"));
        gridLayout = new QGridLayout(right_widget);
        gridLayout->setObjectName("gridLayout");
        testNet = new QPushButton(right_widget);
        testNet->setObjectName("testNet");

        gridLayout->addWidget(testNet, 1, 0, 1, 1);

        svg_widget = new QWidget(right_widget);
        svg_widget->setObjectName("svg_widget");
        sizePolicy.setHeightForWidth(svg_widget->sizePolicy().hasHeightForWidth());
        svg_widget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(svg_widget);
        verticalLayout->setObjectName("verticalLayout");

        gridLayout->addWidget(svg_widget, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        widget_weather = new QWidget(right_widget);
        widget_weather->setObjectName("widget_weather");
        horizontalLayout_2 = new QHBoxLayout(widget_weather);
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        gridLayout->addWidget(widget_weather, 2, 0, 1, 2);


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
        pushButton_showWeather->setText(QCoreApplication::translate("MainWindow", "\345\244\251\346\260\224\346\250\241\345\235\227", nullptr));
        pushButton_showGB26875_Server->setText(QCoreApplication::translate("MainWindow", "GB26875\345\215\217\350\256\256\346\250\241\345\235\227\357\274\210\346\234\215\345\212\241\345\231\250\346\250\241\345\274\217\357\274\211", nullptr));
        pushButton_showGB26875_Client->setText(QCoreApplication::translate("MainWindow", "GB26875\345\215\217\350\256\256\346\250\241\345\235\227\357\274\210\345\256\242\346\210\267\347\253\257\346\250\241\345\274\217\357\274\211", nullptr));
        testNet->setText(QCoreApplication::translate("MainWindow", "\345\244\251\346\260\224\346\225\260\346\215\256\346\233\264\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
