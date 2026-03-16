/********************************************************************************
** Form generated from reading UI file 'CastsWeather.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASTSWEATHER_H
#define UI_CASTSWEATHER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CastsWeather
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QCustomPlot *drawWeatherData;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_city;
    QLabel *casts_label;
    QPushButton *pushButton_overview;
    QPushButton *pushButton_precipitation;
    QPushButton *pushButton_windSpeed;
    QPushButton *pushButton_humidness;
    QPushButton *pushButton_cloudage;
    QPushButton *pushButton_airPressure;
    QPushButton *pushButton_uv;
    QPushButton *pushButton_visibility;
    QPushButton *pushButton_apparentTemperature;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_iconForWeather;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *label_updateTime;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QLabel *label_daywind;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_daypower;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_dayweather;
    QLabel *label_nightweather;
    QLabel *label_nightwind;
    QLabel *label_nightpower;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_left;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_right;

    void setupUi(QWidget *CastsWeather)
    {
        if (CastsWeather->objectName().isEmpty())
            CastsWeather->setObjectName("CastsWeather");
        CastsWeather->resize(947, 618);
        CastsWeather->setStyleSheet(QString::fromUtf8("color: rgb(13, 191, 231);"));
        gridLayout = new QGridLayout(CastsWeather);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(CastsWeather);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName("gridLayout_2");
        drawWeatherData = new QCustomPlot(page);
        drawWeatherData->setObjectName("drawWeatherData");
        drawWeatherData->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(drawWeatherData);
        gridLayout_3->setObjectName("gridLayout_3");

        gridLayout_2->addWidget(drawWeatherData, 0, 0, 1, 1);

        stackedWidget->addWidget(page);

        gridLayout->addWidget(stackedWidget, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(CastsWeather);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        comboBox_city = new QComboBox(CastsWeather);
        comboBox_city->setObjectName("comboBox_city");
        comboBox_city->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(comboBox_city);

        casts_label = new QLabel(CastsWeather);
        casts_label->setObjectName("casts_label");
        casts_label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(casts_label);

        pushButton_overview = new QPushButton(CastsWeather);
        pushButton_overview->setObjectName("pushButton_overview");

        horizontalLayout->addWidget(pushButton_overview);

        pushButton_precipitation = new QPushButton(CastsWeather);
        pushButton_precipitation->setObjectName("pushButton_precipitation");

        horizontalLayout->addWidget(pushButton_precipitation);

        pushButton_windSpeed = new QPushButton(CastsWeather);
        pushButton_windSpeed->setObjectName("pushButton_windSpeed");

        horizontalLayout->addWidget(pushButton_windSpeed);

        pushButton_humidness = new QPushButton(CastsWeather);
        pushButton_humidness->setObjectName("pushButton_humidness");

        horizontalLayout->addWidget(pushButton_humidness);

        pushButton_cloudage = new QPushButton(CastsWeather);
        pushButton_cloudage->setObjectName("pushButton_cloudage");

        horizontalLayout->addWidget(pushButton_cloudage);

        pushButton_airPressure = new QPushButton(CastsWeather);
        pushButton_airPressure->setObjectName("pushButton_airPressure");

        horizontalLayout->addWidget(pushButton_airPressure);

        pushButton_uv = new QPushButton(CastsWeather);
        pushButton_uv->setObjectName("pushButton_uv");

        horizontalLayout->addWidget(pushButton_uv);

        pushButton_visibility = new QPushButton(CastsWeather);
        pushButton_visibility->setObjectName("pushButton_visibility");

        horizontalLayout->addWidget(pushButton_visibility);

        pushButton_apparentTemperature = new QPushButton(CastsWeather);
        pushButton_apparentTemperature->setObjectName("pushButton_apparentTemperature");

        horizontalLayout->addWidget(pushButton_apparentTemperature);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_iconForWeather = new QLabel(CastsWeather);
        label_iconForWeather->setObjectName("label_iconForWeather");

        horizontalLayout_3->addWidget(label_iconForWeather);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_3 = new QLabel(CastsWeather);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        label_updateTime = new QLabel(CastsWeather);
        label_updateTime->setObjectName("label_updateTime");

        horizontalLayout_3->addWidget(label_updateTime);


        gridLayout->addLayout(horizontalLayout_3, 5, 0, 1, 1);

        widget = new QWidget(CastsWeather);
        widget->setObjectName("widget");
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName("gridLayout_4");
        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");

        gridLayout_4->addWidget(label_10, 2, 3, 1, 1);

        label_daywind = new QLabel(widget);
        label_daywind->setObjectName("label_daywind");

        gridLayout_4->addWidget(label_daywind, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        label_daypower = new QLabel(widget);
        label_daypower->setObjectName("label_daypower");

        gridLayout_4->addWidget(label_daypower, 2, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");

        gridLayout_4->addWidget(label_8, 2, 0, 1, 1);

        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");

        gridLayout_4->addWidget(label_9, 1, 3, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        gridLayout_4->addWidget(label_6, 0, 3, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        label_dayweather = new QLabel(widget);
        label_dayweather->setObjectName("label_dayweather");

        gridLayout_4->addWidget(label_dayweather, 0, 1, 1, 1);

        label_nightweather = new QLabel(widget);
        label_nightweather->setObjectName("label_nightweather");

        gridLayout_4->addWidget(label_nightweather, 0, 4, 1, 1);

        label_nightwind = new QLabel(widget);
        label_nightwind->setObjectName("label_nightwind");

        gridLayout_4->addWidget(label_nightwind, 1, 4, 1, 1);

        label_nightpower = new QLabel(widget);
        label_nightpower->setObjectName("label_nightpower");

        gridLayout_4->addWidget(label_nightpower, 2, 4, 1, 1);


        gridLayout->addWidget(widget, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_left = new QPushButton(CastsWeather);
        pushButton_left->setObjectName("pushButton_left");
        pushButton_left->setMinimumSize(QSize(30, 60));
        pushButton_left->setMaximumSize(QSize(30, 60));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/resources/Icon/left.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_left->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_left);

        scrollArea = new QScrollArea(CastsWeather);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 853, 69));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        pushButton_right = new QPushButton(CastsWeather);
        pushButton_right->setObjectName("pushButton_right");
        pushButton_right->setMinimumSize(QSize(30, 60));
        pushButton_right->setMaximumSize(QSize(30, 60));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/resources/Icon/right.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_right->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButton_right);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(CastsWeather);

        QMetaObject::connectSlotsByName(CastsWeather);
    } // setupUi

    void retranslateUi(QWidget *CastsWeather)
    {
        CastsWeather->setWindowTitle(QCoreApplication::translate("CastsWeather", "Form", nullptr));
        label->setText(QCoreApplication::translate("CastsWeather", "\351\200\211\346\213\251\345\237\216\345\270\202:", nullptr));
        casts_label->setText(QCoreApplication::translate("CastsWeather", "\346\257\217\345\260\217\346\227\266\351\242\204\346\212\245", nullptr));
        pushButton_overview->setText(QCoreApplication::translate("CastsWeather", "\346\246\202\350\247\210", nullptr));
        pushButton_precipitation->setText(QCoreApplication::translate("CastsWeather", "\351\231\215\346\260\264", nullptr));
        pushButton_windSpeed->setText(QCoreApplication::translate("CastsWeather", "\351\243\216\351\200\237", nullptr));
        pushButton_humidness->setText(QCoreApplication::translate("CastsWeather", "\346\271\277\345\272\246", nullptr));
        pushButton_cloudage->setText(QCoreApplication::translate("CastsWeather", "\344\272\221\351\207\217", nullptr));
        pushButton_airPressure->setText(QCoreApplication::translate("CastsWeather", "\346\260\224\345\216\213", nullptr));
        pushButton_uv->setText(QCoreApplication::translate("CastsWeather", "\347\264\253\345\244\226\347\272\277", nullptr));
        pushButton_visibility->setText(QCoreApplication::translate("CastsWeather", "\345\217\257\350\247\201\345\272\246", nullptr));
        pushButton_apparentTemperature->setText(QCoreApplication::translate("CastsWeather", "\344\275\223\346\204\237\346\270\251\345\272\246", nullptr));
        label_iconForWeather->setText(QCoreApplication::translate("CastsWeather", "\346\271\277\345\272\246\345\233\276\346\240\207", nullptr));
        label_3->setText(QCoreApplication::translate("CastsWeather", "\346\233\264\346\226\260\346\227\266\351\227\264:", nullptr));
        label_updateTime->setText(QCoreApplication::translate("CastsWeather", "\345\276\205\346\233\264\346\226\260", nullptr));
        label_10->setText(QCoreApplication::translate("CastsWeather", "\346\231\232\344\270\212\351\243\216\345\212\233\357\274\232", nullptr));
        label_daywind->setText(QCoreApplication::translate("CastsWeather", "\346\234\252\347\237\245", nullptr));
        label_daypower->setText(QCoreApplication::translate("CastsWeather", "\346\234\252\347\237\245", nullptr));
        label_4->setText(QCoreApplication::translate("CastsWeather", "\347\231\275\345\244\251\345\244\251\346\260\224\347\216\260\350\261\241\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("CastsWeather", "\347\231\275\345\244\251\351\243\216\345\212\233\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("CastsWeather", "\346\231\232\344\270\212\351\243\216\345\220\221\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("CastsWeather", "\346\231\232\344\270\212\345\244\251\346\260\224\347\216\260\350\261\241\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("CastsWeather", "\347\231\275\345\244\251\351\243\216\345\220\221\357\274\232", nullptr));
        label_dayweather->setText(QCoreApplication::translate("CastsWeather", "\346\234\252\347\237\245", nullptr));
        label_nightweather->setText(QCoreApplication::translate("CastsWeather", "\346\234\252\347\237\245", nullptr));
        label_nightwind->setText(QCoreApplication::translate("CastsWeather", "\346\234\252\347\237\245", nullptr));
        label_nightpower->setText(QCoreApplication::translate("CastsWeather", "\346\234\252\347\237\245", nullptr));
        pushButton_left->setText(QString());
        pushButton_right->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CastsWeather: public Ui_CastsWeather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASTSWEATHER_H
