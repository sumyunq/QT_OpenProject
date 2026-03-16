#include "CastsWeather.h"
#include "ui_CastsWeather.h"

CastsWeather::CastsWeather(QWidget *parent)
    : QWidget(parent), ui(new Ui::CastsWeather)
{
    ui->setupUi(this);
    this->InitUIInformation();

    this->InitMumbers();
    this->InitConnect();
    this->ui->drawWeatherData->hide();
}

CastsWeather::~CastsWeather()
{
    delete ui;
}

void CastsWeather::InitMumbers()
{
    // 创建 tracer 并绑定 graph
    tracer_dayTemps = new QCPItemTracer(ui->drawWeatherData);
    tracer_dayTemps->setGraph(ui->drawWeatherData->graph(0));
    tracer_dayTemps->setStyle(QCPItemTracer::tsCircle);
    tracer_dayTemps->setPen(QPen(Qt::red));
    tracer_dayTemps->setBrush(Qt::red);
    tracer_dayTemps->setSize(8);

    label_dayTemps = new QCPItemText(ui->drawWeatherData);
    label_dayTemps->setLayer("overlay");
    label_dayTemps->setPositionAlignment(Qt::AlignTop | Qt::AlignHCenter);
    label_dayTemps->position->setParentAnchor(tracer_dayTemps->position);
    label_dayTemps->setFont(QFont("Arial", 9));
    label_dayTemps->setColor(Qt::white);
    label_dayTemps->setText("");

    tracer_nightTemps = new QCPItemTracer(ui->drawWeatherData);
    tracer_nightTemps->setGraph(ui->drawWeatherData->graph(1));
    tracer_nightTemps->setStyle(QCPItemTracer::tsCircle);
    tracer_nightTemps->setPen(QPen(Qt::blue)); // 可改用不同颜色区分
    tracer_nightTemps->setBrush(Qt::blue);
    tracer_nightTemps->setSize(8);

    label_nightTemps = new QCPItemText(ui->drawWeatherData);
    label_nightTemps->setLayer("overlay"); // 统一使用 overlay
    label_nightTemps->setPositionAlignment(Qt::AlignTop | Qt::AlignHCenter);
    label_nightTemps->position->setParentAnchor(tracer_nightTemps->position);
    label_nightTemps->setFont(QFont("Arial", 9));
    label_nightTemps->setColor(Qt::white);
    label_nightTemps->setText("");

    // 鼠标移动事件
    connect(ui->drawWeatherData, &QCustomPlot::mouseMove, this,
            [=](QMouseEvent *event) {
                if (!tracer_dayTemps->graph() || !tracer_nightTemps->graph())
                    return;  // 无数据时不处理

                double x = ui->drawWeatherData->xAxis->pixelToCoord(event->pos().x());
                // qDebug() << " 数据索引: " <<  x;
                int index = qRound(x);  // 四舍五入取整

                // 确保索引不越界
                if (index >= 0 && index < casts.size()) {
                    ui->label_dayweather->setText(this->casts.at(index).dayweather);
                    ui->label_daywind->setText(this->casts.at(index).daywind);
                    ui->label_daypower->setText(this->casts.at(index).daypower);
                    ui->label_nightweather->setText(this->casts.at(index).nightweather);
                    ui->label_nightwind->setText(this->casts.at(index).nightwind);
                    ui->label_nightpower->setText(this->casts.at(index).nightpower);


                    // 设置视频源（选择你的 MP4 文件）
                    if(ui->label_dayweather->text().contains("晴")){
                        // player->setSource(QUrl::fromLocalFile(":/img/resources/Icon/sunny-day.mp4"));
                        // // 开始播放
                        // player->play();
                    }


                } else {
                    qDebug() << "点击位置超出数据范围";
                }

                // 更新白天 tracer
                tracer_dayTemps->setGraphKey(x);
                tracer_dayTemps->updatePosition();
                double dayTemp = tracer_dayTemps->position->value();
                label_dayTemps->setText(QString::number(dayTemp, 'f', 1) + "°C");

                // 更新夜间 tracer
                tracer_nightTemps->setGraphKey(x);
                tracer_nightTemps->updatePosition();
                double nightTemp = tracer_nightTemps->position->value();
                label_nightTemps->setText(QString::number(nightTemp, 'f', 1) + "°C");

                ui->drawWeatherData->replot();
            });

    // player = new QMediaPlayer(this->ui->label_iconForWeather);
    // videoWidget = new QVideoWidget(this->ui->label_iconForWeather);

    // QVBoxLayout *layout = new QVBoxLayout(ui->label_iconForWeather);
    // layout->setContentsMargins(0, 0, 0, 0);
    // layout->addWidget(videoWidget);

    // 设置视频输出
    // player->setVideoOutput(videoWidget);


}

void CastsWeather::InitConnect()
{
    QObject::connect(this->ui->comboBox_city,&QComboBox::currentIndexChanged,this,[this](){
        emit(ChooseCityCode(this->list_adcode.at(this->ui->comboBox_city->currentIndex() + 2)));
    });
}

void CastsWeather::InitUIInformation()
{
    ui->drawWeatherData->setMouseTracking(true);
    // connect(ui->drawWeatherData, &QCustomPlot::mouseMove, this, &CastsWeather::showWeatherData);
    HighAltitudeWeatherDataSturct::Read_AMap_adcode_citycode(QString("resources/file/AMap_adcode_citycode.xlsx"), this->list_adcode);
    // qDebug()<< "读取" << this->list_adcode.size()<< "行数据";
    if(this->list_adcode.size() >= 2)
    {
        for(int i=2; i < this->list_adcode.size();i++){
            this->ui->comboBox_city->addItem(list_adcode.at(i).ChineseName);
        }
        //默认深圳
        this->ui->comboBox_city->setCurrentIndex(1943 - 2 - 1);
    }

    ui->casts_label->hide();
    ui->pushButton_airPressure->hide();
    ui->pushButton_apparentTemperature->hide();
    ui->pushButton_cloudage->hide();
    ui->pushButton_humidness->hide();
    ui->pushButton_overview->hide();
    ui->pushButton_precipitation->hide();
    ui->pushButton_uv->hide();
    ui->pushButton_visibility->hide();
    ui->pushButton_windSpeed->hide();
    ui->scrollArea->hide();
    ui->pushButton_left->hide();
    ui->pushButton_right->hide();


}


void CastsWeather::DrawWeatherData(HighAltitudeWeatherDataSturct::WeatherRequestReturnData tmp_weatherData)
{
    if(this->ui->drawWeatherData->isHidden())
        this->ui->drawWeatherData->show();
    // 获取预报数据向量
    this->casts.clear();
    this->casts = tmp_weatherData.forecastsWeatherData.casts_Vector;
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
    // ui->drawWeatherData->clearItems(); // 如果有额外文本元素

    // 设置 x 轴为文本轴
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (int i = 0; i < keys.size(); ++i) {
        textTicker->addTick(keys[i], tickLabels[i]);
    }
    ui->drawWeatherData->xAxis->setTicker(textTicker);
    ui->drawWeatherData->xAxis->setRange(-0.5, keys.size() - 0.5); // 留出边距

    ui->drawWeatherData->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

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

    // 设置字体颜色
    ui->drawWeatherData->xAxis->setLabelColor(Qt::white);
    ui->drawWeatherData->yAxis->setLabelColor(Qt::white);
    ui->drawWeatherData->xAxis->setTickLabelColor(Qt::white);
    ui->drawWeatherData->yAxis->setTickLabelColor(Qt::white);
    // customPlot->xAxis2->setTickLabelColor(Qt::white);
    // customPlot->yAxis2->setTickLabelColor(Qt::white);


    // 显示图例
    ui->drawWeatherData->legend->setVisible(true);
    ui->drawWeatherData->legend->setBrush(QColor(255, 255, 255, 200)); // 半透明背景

    // 允许用户交互（拖拽和缩放）
    ui->drawWeatherData->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    tracer_dayTemps->setGraph(ui->drawWeatherData->graph(0));  // 绑定到曲线

    tracer_nightTemps->setGraph(ui->drawWeatherData->graph(1));  // 绑定到曲线


    // // 设置绘图区背景图
    // QPixmap plotBg(":/img/resources/images/mainPage.png"); // 替换为你的图片路径
    // if (!plotBg.isNull()) {
    //     QCPAxisRect *rect = ui->drawWeatherData->axisRect();
    //     rect->setBackground(plotBg);
    //     rect->setBackgroundScaled(true);
    //     rect->setBackgroundScaledMode(Qt::IgnoreAspectRatio);
    // } else {
    //     qDebug() << "背景图片加载失败，请检查路径！";
    // }

    // 设置整个控件的背景色为半透明
    ui->drawWeatherData->setBackground(QBrush(QColor(68, 59, 106)));
    // 重绘
    ui->drawWeatherData->replot();

}

void CastsWeather::UpdateWeatherData(HighAltitudeWeatherDataSturct::WeatherRequestReturnData tmp_weatherData)
{
    this->ui->label_updateTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    this->DrawWeatherData(tmp_weatherData);

}

void CastsWeather::showWeatherData(QMouseEvent *event)
{

}
