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
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_iconFor;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_updateTime;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QCustomPlot *drawWeatherData;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_10;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_11;
    QHBoxLayout *horizontalLayout;
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

    void setupUi(QWidget *CastsWeather)
    {
        if (CastsWeather->objectName().isEmpty())
            CastsWeather->setObjectName("CastsWeather");
        CastsWeather->resize(809, 618);
        gridLayout = new QGridLayout(CastsWeather);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_iconFor = new QLabel(CastsWeather);
        label_iconFor->setObjectName("label_iconFor");

        horizontalLayout_3->addWidget(label_iconFor);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_2 = new QLabel(CastsWeather);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        label_3 = new QLabel(CastsWeather);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        label_updateTime = new QLabel(CastsWeather);
        label_updateTime->setObjectName("label_updateTime");

        horizontalLayout_3->addWidget(label_updateTime);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

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
        gridLayout_3 = new QGridLayout(drawWeatherData);
        gridLayout_3->setObjectName("gridLayout_3");

        gridLayout_2->addWidget(drawWeatherData, 0, 0, 1, 1);

        stackedWidget->addWidget(page);

        gridLayout->addWidget(stackedWidget, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_10 = new QPushButton(CastsWeather);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setMinimumSize(QSize(30, 60));
        pushButton_10->setMaximumSize(QSize(30, 60));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/resources/Icon/left.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_10->setIcon(icon);

        horizontalLayout_2->addWidget(pushButton_10);

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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 715, 69));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        pushButton_11 = new QPushButton(CastsWeather);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setMinimumSize(QSize(30, 60));
        pushButton_11->setMaximumSize(QSize(30, 60));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/resources/Icon/right.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_11->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButton_11);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
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


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(CastsWeather);

        QMetaObject::connectSlotsByName(CastsWeather);
    } // setupUi

    void retranslateUi(QWidget *CastsWeather)
    {
        CastsWeather->setWindowTitle(QCoreApplication::translate("CastsWeather", "Form", nullptr));
        label_iconFor->setText(QCoreApplication::translate("CastsWeather", "\346\271\277\345\272\246\345\233\276\346\240\207", nullptr));
        label_2->setText(QCoreApplication::translate("CastsWeather", "\345\233\276\346\240\207", nullptr));
        label_3->setText(QCoreApplication::translate("CastsWeather", "\346\233\264\346\226\260\346\227\266\351\227\264:", nullptr));
        label_updateTime->setText(QCoreApplication::translate("CastsWeather", "\345\276\205\346\233\264\346\226\260", nullptr));
        pushButton_10->setText(QString());
        pushButton_11->setText(QString());
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
    } // retranslateUi

};

namespace Ui {
    class CastsWeather: public Ui_CastsWeather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASTSWEATHER_H
