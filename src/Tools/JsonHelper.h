#ifndef JSONHELPER_H
#define JSONHELPER_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include "../DataStruct/HighAltitudeDataSturct.h"

class JsonHelper:public QObject
{
    Q_OBJECT
public:
    JsonHelper();

    //Analyze high-altitude weather data
    void DealHighAltitudeWeatherData(HighAltitudeWeatherDataSturct::WeatherRequestReturnData &WeatherData,QJsonDocument& jsonDocument);


};

#endif // JSONHELPER_H
