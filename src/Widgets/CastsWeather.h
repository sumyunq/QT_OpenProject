#ifndef CastsWeather_H
#define CastsWeather_H

#include <QWidget>
#include <QDateTime>

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

    void InitUIInformation();

    void DrawWeatherData(HighAltitudeWeatherDataSturct::WeatherRequestReturnData tmp_weatherData);

    //对接天气数据更新//    HighAltitudeWeatherDataSturct::WeatherRequestReturnData tmp_weatherData;
    void UpdateWeatherData(HighAltitudeWeatherDataSturct::WeatherRequestReturnData tmp_weatherData);

private:
    Ui::CastsWeather *ui;
};

#endif // CastsWeather_H
