#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QSvgRenderer>
#include <QSvgWidget>
#include <QDateTime>


#include "./src/NetWorkModule/NetWorkAssistant.h"
#include "./src/Tools/GlobalTools.h"
#include "./src/Tools/ConfigManager.h"
#include "./src/Widgets/CastsWeather.h"
#include "./src/Widgets/GB26875ServerMode.h"
#include "./src/Widgets/GB26875ClientMode.h"
#include "./src/Widgets/Configuration.h"
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





private slots:

    void on_pushButton_showGB26875_Server_clicked();

    void on_pushButton_showGB26875_Client_clicked();

    void on_pushButton_showWeather_clicked();

    void on_testNet_clicked();

public:

    // GlobalTools *G_GlobalTools;
    NetWorkAssistant *G_NetWorkAssistant;

    CastsWeather *castWeather;
    Configuration *clp_configuration;

    QString  m_adcode;


    GB26875ServerMode *clp_GB26875ServerMode;
    GB26875ClientMode *clp_GB26875ClientMode;

private:
    Ui::MainWindow *ui;
    QSvgRenderer *svgTest;
    QSvgWidget *svgWidgets;
};
#endif // MAINWINDOW_H
