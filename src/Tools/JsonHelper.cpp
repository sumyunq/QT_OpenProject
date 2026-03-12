#include "JsonHelper.h"

JsonHelper::JsonHelper() {}

void JsonHelper::DealHighAltitudeWeatherData(HighAltitudeWeatherDataSturct::WeatherRequestReturnData &WeatherData,QJsonDocument &jsonDocument)
{
    if (jsonDocument.isNull() || jsonDocument.isEmpty()) {
        qDebug() << "JSON文档为空";
        return;
    }

    // // 7. 根据JSON类型处理
    // if (jsonDoc.isObject()) {
    //     parseJsonObject(jsonDoc.object());
    // } else if (jsonDoc.isArray()) {
    //     parseJsonArray(jsonDoc.array());
    // }

    try {
        if (jsonDocument.isObject()) {

            QJsonObject tmp_jsonObj = jsonDocument.object();
            if (tmp_jsonObj.contains("status") && tmp_jsonObj["status"].isString())
            {
                WeatherData.status = tmp_jsonObj["status"].toString();
            }else{
                qDebug()<<"status 数据不存在 或 类型异常";
            }

            if (tmp_jsonObj.contains("count") && tmp_jsonObj["count"].isString())
            {
                WeatherData.count = tmp_jsonObj["count"].toString();
            }else{
                qDebug()<<"count 数据不存在 或 类型异常";
            }

            if (tmp_jsonObj.contains("info") && tmp_jsonObj["info"].isString())
            {
                WeatherData.info = tmp_jsonObj["info"].toString();
            }else{
                qDebug()<<"info 数据不存在 或 类型异常";
            }

            if (tmp_jsonObj.contains("infocode") && tmp_jsonObj["infocode"].isString())
            {
                WeatherData.infocode = tmp_jsonObj["infocode"].toString();
            }else{
                qDebug()<<"infocode 数据不存在 或 类型异常";
            }

            if (tmp_jsonObj.contains("lives") && tmp_jsonObj["lives"].isArray())
            {
                QJsonArray tmp_livesJsonObj = tmp_jsonObj["lives"].toArray();
                for (const QJsonValue& tmp_livesItem : tmp_livesJsonObj) {
                    if(tmp_livesItem.isObject()){
                        HighAltitudeWeatherDataSturct::LivesWeatherData tmp_LivesWeatherData;
                        QJsonObject tmp_livesJsonObj = tmp_livesItem.toObject();
                        if(tmp_livesJsonObj.contains("province") && tmp_livesJsonObj["province"].isString()){
                            tmp_LivesWeatherData.province = tmp_livesJsonObj["province"].toString();
                        }else{
                            qDebug()<<"lives 内 province 数据不存在 或 类型异常";
                        }
                        if(tmp_livesJsonObj.contains("city") && tmp_livesJsonObj["city"].isString()){
                            tmp_LivesWeatherData.city = tmp_livesJsonObj["city"].toString();
                        }else{
                            qDebug()<<"lives 内 city 数据不存在 或 类型异常";
                        }
                        if(tmp_livesJsonObj.contains("adcode") && tmp_livesJsonObj["adcode"].isString()){
                            tmp_LivesWeatherData.adcode = tmp_livesJsonObj["adcode"].toString();
                        }else{
                            qDebug()<<"lives 内 adcode 数据不存在 或 类型异常";
                        }
                        if(tmp_livesJsonObj.contains("weather") && tmp_livesJsonObj["weather"].isString()){
                            tmp_LivesWeatherData.weather = tmp_livesJsonObj["weather"].toString();
                        }else{
                            qDebug()<<"lives 内 weather 数据不存在 或 类型异常";
                        }
                        if(tmp_livesJsonObj.contains("temperature") && tmp_livesJsonObj["temperature"].isString()){
                            tmp_LivesWeatherData.temperature = tmp_livesJsonObj["temperature"].toString();
                        }else{
                            qDebug()<<"lives 内 temperature 数据不存在 或 类型异常";
                        }
                        if(tmp_livesJsonObj.contains("winddirection") && tmp_livesJsonObj["winddirection"].isString()){
                            tmp_LivesWeatherData.winddirection = tmp_livesJsonObj["winddirection"].toString();
                        }else{
                            qDebug()<<"lives 内 winddirection 数据不存在 或 类型异常";
                        }
                        if(tmp_livesJsonObj.contains("windpower") && tmp_livesJsonObj["windpower"].isString()){
                            tmp_LivesWeatherData.windpower = tmp_livesJsonObj["windpower"].toString();
                        }else{
                            qDebug()<<"lives 内 windpower 数据不存在 或 类型异常";
                        }
                        if(tmp_livesJsonObj.contains("humidity") && tmp_livesJsonObj["humidity"].isString()){
                            tmp_LivesWeatherData.humidity = tmp_livesJsonObj["humidity"].toString();
                        }else{
                            qDebug()<<"lives 内 humidity 数据不存在 或 类型异常";
                        }
                        if(tmp_livesJsonObj.contains("reporttime") && tmp_livesJsonObj["reporttime"].isString()){
                            tmp_LivesWeatherData.reporttime = tmp_livesJsonObj["reporttime"].toString();
                        }else{
                            qDebug()<<"lives 内 reporttime 数据不存在 或 类型异常";
                        }
                        WeatherData.livesWeatherData_Vector.append(tmp_LivesWeatherData);
                    }
                }
            }else{
                qDebug()<<"lives 数据不存在 或 类型异常";
            }

            if (tmp_jsonObj.contains("forecasts") && tmp_jsonObj["forecasts"].isArray())
            {
                QJsonArray tmp_livesJsonObjArray = tmp_jsonObj["forecasts"].toArray();
                for (const QJsonValue& tmp_forecastsItem : tmp_livesJsonObjArray) {
                    if(tmp_forecastsItem.isObject()){
                        QJsonObject tmp_forecastsObj = tmp_forecastsItem.toObject();
                        if(tmp_forecastsObj.contains("city") && tmp_forecastsObj["city"].isString()){
                            WeatherData.forecastsWeatherData.city = tmp_forecastsObj["city"].toString();
                        }else{
                            qDebug()<<"forecasts 内 city 数据不存在 或 类型异常";
                        }
                        if(tmp_forecastsObj.contains("adcode") && tmp_forecastsObj["adcode"].isString()){
                            WeatherData.forecastsWeatherData.adcode = tmp_forecastsObj["adcode"].toString();
                        }else{
                            qDebug()<<"forecasts 内 adcode 数据不存在 或 类型异常";
                        }
                        if(tmp_forecastsObj.contains("province") && tmp_forecastsObj["province"].isString()){
                            WeatherData.forecastsWeatherData.province = tmp_forecastsObj["province"].toString();
                        }else{
                            qDebug()<<"forecasts 内 province 数据不存在 或 类型异常";
                        }
                        // 处理数组:未来几天的天气数据
                        if (tmp_forecastsObj.contains("casts") && tmp_forecastsObj["casts"].isArray()) {

                            QJsonArray tmp_castsJsonObj = tmp_forecastsObj["casts"].toArray();
                            for (const QJsonValue& tmp_castsItem : tmp_castsJsonObj) {
                                if (tmp_castsItem.isObject()) {
                                    HighAltitudeWeatherDataSturct::CastsWeatherData tmp_castsDate;
                                    QJsonObject tmp_CastsWeatherDataObj = tmp_castsItem.toObject();
                                    if(tmp_CastsWeatherDataObj.contains("date") && tmp_CastsWeatherDataObj["date"].isString()){
                                        tmp_castsDate.date= tmp_CastsWeatherDataObj["date"].toString();
                                    }else{
                                        qDebug()<<"forecasts 内 casts 的 date 数据不存在 或 类型异常";
                                    }
                                    if(tmp_CastsWeatherDataObj.contains("week") && tmp_CastsWeatherDataObj["week"].isString()){
                                        tmp_castsDate.week= tmp_CastsWeatherDataObj["week"].toString();
                                    }else{
                                        qDebug()<<"forecasts 内 casts 的 week 数据不存在 或 类型异常";
                                    }
                                    if(tmp_CastsWeatherDataObj.contains("dayweather") && tmp_CastsWeatherDataObj["dayweather"].isString()){
                                        tmp_castsDate.dayweather= tmp_CastsWeatherDataObj["dayweather"].toString();
                                    }else{
                                        qDebug()<<"forecasts 内 casts 的 dayweather 数据不存在 或 类型异常";
                                    }
                                    if(tmp_CastsWeatherDataObj.contains("nightweather") && tmp_CastsWeatherDataObj["nightweather"].isString()){
                                        tmp_castsDate.nightweather= tmp_CastsWeatherDataObj["nightweather"].toString();
                                    }else{
                                        qDebug()<<"forecasts 内 casts 的 nightweather 数据不存在 或 类型异常";
                                    }
                                    if(tmp_CastsWeatherDataObj.contains("daytemp") && tmp_CastsWeatherDataObj["daytemp"].isString()){
                                        tmp_castsDate.daytemp= tmp_CastsWeatherDataObj["daytemp"].toString();
                                    }else{
                                        qDebug()<<"forecasts 内 casts 的 daytemp 数据不存在 或 类型异常";
                                    }
                                    if(tmp_CastsWeatherDataObj.contains("nighttemp") && tmp_CastsWeatherDataObj["nighttemp"].isString()){
                                        tmp_castsDate.nighttemp= tmp_CastsWeatherDataObj["nighttemp"].toString();
                                    }else{
                                        qDebug()<<"forecasts 内 casts 的 nighttemp 数据不存在 或 类型异常";
                                    }
                                    if(tmp_CastsWeatherDataObj.contains("daywind") && tmp_CastsWeatherDataObj["daywind"].isString()){
                                        tmp_castsDate.daywind= tmp_CastsWeatherDataObj["daywind"].toString();
                                    }else{
                                        qDebug()<<"forecasts 内 casts 的 daywind 数据不存在 或 类型异常";
                                    }
                                    if(tmp_CastsWeatherDataObj.contains("nightwind") && tmp_CastsWeatherDataObj["nightwind"].isString()){
                                        tmp_castsDate.nightwind= tmp_CastsWeatherDataObj["nightwind"].toString();
                                    }else{
                                        qDebug()<<"forecasts 内 casts 的 nightwind 数据不存在 或 类型异常";
                                    }
                                    if(tmp_CastsWeatherDataObj.contains("daypower") && tmp_CastsWeatherDataObj["daypower"].isString()){
                                        tmp_castsDate.daypower= tmp_CastsWeatherDataObj["daypower"].toString();
                                    }else{
                                        qDebug()<<"forecasts 内 casts 的 daypower 数据不存在 或 类型异常";
                                    }
                                    if(tmp_CastsWeatherDataObj.contains("nightpower") && tmp_CastsWeatherDataObj["nightpower"].isString()){
                                        tmp_castsDate.nightpower= tmp_CastsWeatherDataObj["nightpower"].toString();
                                    }else{
                                        qDebug()<<"forecasts 内 casts 的 nightpower 数据不存在 或 类型异常";
                                    }
                                    WeatherData.forecastsWeatherData.casts_Vector.append(tmp_castsDate);
                                }
                            }
                        }
                    }
                }
            }
            else{
                qDebug()<<"forecasts 数据不存在 或 类型异常";
            }
            qDebug() << "JSON数据正常处理完成";
        }
    } catch (const std::exception& e) {
        qDebug() << "处理JSON数据时发生异常:" << e.what();
    }
}
