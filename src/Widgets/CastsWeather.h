#ifndef CastsWeather_H
#define CastsWeather_H

#include <QWidget>
#include <QDateTime>
#include <QList>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>

#include "../DataStruct/HighAltitudeDataSturct.h"
#include "../qcustomplot/qcustomplot.h"



namespace Ui {
class CastsWeather;
}

class CastsWeather : public QWidget
{
    Q_OBJECT

public:
    explicit CastsWeather(QWidget *parent = nullptr);
    ~CastsWeather();

    void InitMumbers();
    void InitConnect();
    void InitUIInformation();

    void DrawWeatherData(HighAltitudeWeatherDataSturct::WeatherRequestReturnData tmp_weatherData);

    //对接天气数据更新//    HighAltitudeWeatherDataSturct::WeatherRequestReturnData tmp_weatherData;
    void UpdateWeatherData(HighAltitudeWeatherDataSturct::WeatherRequestReturnData tmp_weatherData);

signals:
    void ChooseCityCode(HighAltitudeWeatherDataSturct::AMap_adcode_citycode citycode);


private slots:
    void showWeatherData(QMouseEvent *event);

public:
    QCPItemTracer *tracer_dayTemps;
    QCPItemText *label_dayTemps;
    QCPItemTracer *tracer_nightTemps;
    QCPItemText *label_nightTemps;

    //城市编码列表
    QList<HighAltitudeWeatherDataSturct::AMap_adcode_citycode> list_adcode;
    //天气数据
    QVector<HighAltitudeWeatherDataSturct::CastsWeatherData> casts;

    // // 视频相关
    // QMediaPlayer *player;
    // QVideoWidget *videoWidget;


private:
    Ui::CastsWeather *ui;


};

#endif // CastsWeather_H
