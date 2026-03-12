#include "CastsWeather.h"
#include "ui_CastsWeather.h"

CastsWeather::CastsWeather(QWidget *parent)
    : QWidget(parent), ui(new Ui::CastsWeather)
{
    ui->setupUi(this);
    this->InitUIInformation();
}

CastsWeather::~CastsWeather()
{
    delete ui;
}

void CastsWeather::InitUIInformation()
{

}


void CastsWeather::DrawWeatherData(HighAltitudeWeatherDataSturct::WeatherRequestReturnData tmp_weatherData)
{
    // 获取预报数据向量
    QVector<HighAltitudeWeatherDataSturct::CastsWeatherData> casts = tmp_weatherData.forecastsWeatherData.casts_Vector;
    if (casts.isEmpty()) return;

    // 准备数据容器
    QVector<double> keys;          // x 轴位置（索引）
    QVector<double> dayTemps;      // 白天温度
    QVector<double> nightTemps;    // 夜间温度
    QVector<QString> tickLabels;   // x 轴标签（日期或星期）

    for (int i = 0; i < casts.size(); ++i) {
        const HighAltitudeWeatherDataSturct::CastsWeatherData &cast = casts[i];

        // 将 QString 温度转换为 double
        bool okDay, okNight;
        double dayTemp = cast.daytemp.toDouble(&okDay);
        double nightTemp = cast.nighttemp.toDouble(&okNight);

        // 如果转换失败，跳过该数据点（或设为 NaN）
        if (!okDay && !okNight) continue;  // 两者都无效则跳过
        // 对于单个无效，可以用前一个值替代或设为 NaN，这里简单处理：无效时设为 0
        if (!okDay) dayTemp = 0;
        if (!okNight) nightTemp = 0;

        keys.append(i);
        dayTemps.append(dayTemp);
        nightTemps.append(nightTemp);

        // 生成 x 轴标签：例如 "周一\n12/20" 或直接使用日期/星期
        // QString label = cast.week + "\n" + cast.date;  // 可根据需要调整格式
        QString label = cast.date;  // 可根据需要调整格式
        tickLabels.append(label);
    }

    // 如果没有任何有效数据，直接返回
    if (keys.isEmpty()) return;

    // 清除之前的图表（如果需要保留其他元素，可选择性清除）
    ui->drawWeatherData->clearGraphs();
    ui->drawWeatherData->clearItems(); // 如果有额外文本元素

    // 设置 x 轴为文本轴
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (int i = 0; i < keys.size(); ++i) {
        textTicker->addTick(keys[i], tickLabels[i]);
    }
    ui->drawWeatherData->xAxis->setTicker(textTicker);
    ui->drawWeatherData->xAxis->setRange(-0.5, keys.size() - 0.5); // 留出边距

    // 添加白天温度曲线
    ui->drawWeatherData->addGraph();
    ui->drawWeatherData->graph(0)->setData(keys, dayTemps);
    ui->drawWeatherData->graph(0)->setName("白天温度");
    ui->drawWeatherData->graph(0)->setPen(QPen(Qt::red, 2));
    ui->drawWeatherData->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::red, 5));

    // 添加夜间温度曲线
    ui->drawWeatherData->addGraph();
    ui->drawWeatherData->graph(1)->setData(keys, nightTemps);
    ui->drawWeatherData->graph(1)->setName("夜间温度");
    ui->drawWeatherData->graph(1)->setPen(QPen(Qt::blue, 2));
    ui->drawWeatherData->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::blue, 5));

    // 设置 y 轴范围（根据数据动态调整，留出余量）
    double minY = qMin(*std::min_element(dayTemps.begin(), dayTemps.end()),
                       *std::min_element(nightTemps.begin(), nightTemps.end()));
    double maxY = qMax(*std::max_element(dayTemps.begin(), dayTemps.end()),
                       *std::max_element(nightTemps.begin(), nightTemps.end()));
    ui->drawWeatherData->yAxis->setRange(minY - 2, maxY + 2);

    // 设置坐标轴标签
    ui->drawWeatherData->xAxis->setLabel("日期");
    ui->drawWeatherData->yAxis->setLabel("温度 (°C)");

    // 显示图例
    ui->drawWeatherData->legend->setVisible(true);
    ui->drawWeatherData->legend->setBrush(QColor(255, 255, 255, 200)); // 半透明背景

    // 允许用户交互（拖拽和缩放）
    ui->drawWeatherData->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    // 重绘
    ui->drawWeatherData->replot();

}

void CastsWeather::UpdateWeatherData(HighAltitudeWeatherDataSturct::WeatherRequestReturnData tmp_weatherData)
{
    this->ui->label_updateTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    this->DrawWeatherData(tmp_weatherData);
}
