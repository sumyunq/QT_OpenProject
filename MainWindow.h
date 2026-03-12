#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QSvgRenderer>
#include <QSvgWidget>
#include <QDateTime>


#include "./src/NetWorkModule/NetWorkAssistant.h"
#include "./src/Tools/GlobalTools.h"
#include "./src/Widgets/CastsWeather.h"
#include "./src/RemoteFireProtectionModule/FireAlarmDevice.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //
    void InitMumbers();
    //
    void InitConnect();
    //
    void InitUIInformation();
    //
    void SetThemeStyle(QString style);


    // GlobalTools *G_GlobalTools;
    NetWorkAssistant *G_NetWorkAssistant;

    CastsWeather *castWeather;


private slots:
    void on_testNet_clicked();


public:
    FireAlarmDevice* clp_fireAlarmDevice;

private:
    Ui::MainWindow *ui;
    QSvgRenderer *svgTest;
    QSvgWidget *svgWidgets;
};
#endif // MAINWINDOW_H
