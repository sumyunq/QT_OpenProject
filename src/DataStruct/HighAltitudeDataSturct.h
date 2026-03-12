#ifndef HIGHALTITUDEDATASTURCT_H
#define HIGHALTITUDEDATASTURCT_H

#include <QObject>


namespace HighAltitudeWeatherDataSturct {

// QString HighAltitudeWeatherURL="";//高德天气查询API服务地址

typedef struct WeatherRequestData{
    QString key;
    QString city;
    QString extensions; //base:Return to real-time weather conditions; all:Return the weather forecast
    QString output = "JSON";//choose JSON or XML
}WeatherRequest;

typedef struct LivesWeatherData
{
    //实况天气数据
    QString province;//省份名
    QString city;//城市名
    QString adcode;//区域编码
    QString weather;//天气现象（汉字描述）
    QString temperature;//实时气温，单位：摄氏度
    QString winddirection;//风向描述
    QString windpower;//风力级别，单位：级
    QString humidity;//空气湿度
    QString reporttime;//数据发布的时间
}LivesWeatherData;


typedef struct CastsWeatherData
{
    //预报数据 list 结构，元素 cast,按顺序为当天、第二天、第三天、第四天的预报数据
    QString date;//日期
    QString week;//星期几
    QString dayweather;//白天天气现象
    QString nightweather;//晚上天气现象
    QString daytemp;//白天温度
    QString nighttemp;//晚上温度
    QString daywind;//白天风向
    QString nightwind;//晚上风向
    QString daypower;//白天风力
    QString nightpower;//晚上风力
}CastsWeatherData;


typedef struct ForecastsWeatherData
{
    //预报天气信息数据
    QString city;//城市名称
    QString adcode;//城市编码
    QString province;//省份名称
    QVector<CastsWeatherData> casts_Vector;//预报数据
}ForecastsWeatherData;

typedef struct WeatherRequestReturnData{
    //返回结果参数说明。
    /*实况天气每小时更新多次，预报天气每天更新3次，分别在8、11、18点左右更新。
    由于天气数据的特殊性以及数据更新的持续性，无法确定精确的更新时间，请以接口返回数据的 reporttime 字段为准。*/
    QString status;//值为 0 或 1; 0:失败; 1:成功;
    QString count;//返回的结果总数目
    QString info; //返回的状态信息
    QString infocode; //返回的状态说明,10000代表正确
    QVector<LivesWeatherData> livesWeatherData_Vector;//实况天气数据信息,具体数据见前面的声明
    ForecastsWeatherData forecastsWeatherData;//预测天气数据信息,具体数据见前面的声明
}WeatherRequestReturnData;

}








#endif // HIGHALTITUDEDATASTURCT_H
