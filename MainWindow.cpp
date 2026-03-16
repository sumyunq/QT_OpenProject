#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitUIInformation();

    InitMumbers();

    InitConnect();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->clp_configuration;

}

void MainWindow::InitMumbers()
{
    this->G_NetWorkAssistant = new NetWorkAssistant(this);
    // this->clp_fireAlarmDevice = new FireAlarmDevice();
    this->clp_GB26875ServerMode = new GB26875ServerMode();
    this->clp_GB26875ClientMode = new GB26875ClientMode();

    this->clp_GB26875ServerMode->hide();
    this->clp_GB26875ClientMode->hide();

    this->clp_configuration = new Configuration();

    // 单次定时器
    // QTimer::singleShot(3000, this, [this]() {
    //     // 3秒后执行这里,等待其连接成功
    //     this->clp_fireAlarmDevice->m_sourceAddress = this->G_NetWorkAssistant->getPeerAddressBytes(this->G_NetWorkAssistant->cl_localTcpClient->getTCPSocket());
    //     // this->clp_fireAlarmDevice->show();

    // });

    m_adcode ="440300";//默认深圳

    // QMovie *movie = new QMovie(":/img/resources/images/m.gif");
    // ui->testlabel->setMovie(movie);
    // movie->start();


    // // 添加左侧图标（前导图标）
    // QAction *leftAction = ui->lineEdit->addAction(
    //     QIcon(":/img/resources/images/nm.jpg"),  // 图标路径
    //     QLineEdit::LeadingPosition     // 左侧位置
    //     );

    // // 添加右侧图标（后置图标）
    // QAction *rightAction = ui->lineEdit->addAction(
    //     QIcon(":/img/resources/images/kl.jpeg"),   // 图标路径
    //     QLineEdit::TrailingPosition    // 右侧位置
    //     );

    // svgWidgets = new QSvgWidget(QString(":/img/resources/images/mmhh.svg"),this->ui->svg_widget);
    // svgTest = new QSvgRenderer(QString("resources/images/mmhh.svg"),svgWidgets);


}

void MainWindow::InitConnect()
{
    QObject::connect(this->G_NetWorkAssistant,&NetWorkAssistant::updateWeatherData,this->castWeather,&CastsWeather::UpdateWeatherData);

    QObject::connect(this->castWeather,&CastsWeather::ChooseCityCode,this,[this](const HighAltitudeWeatherDataSturct::AMap_adcode_citycode &citycode){
        this->m_adcode = citycode.adcode;
        qDebug()<<"更改城市adcode:"<<this->m_adcode;
    });

}

void MainWindow::InitUIInformation()
{

    this->setWindowTitle("wbliu");
    this->setWindowIcon(QIcon(QPixmap(":/img/resources/images/wbliu.png")));

    setAttribute(Qt::WA_StyledBackground, true);
    //隐藏系统标题栏
    // setWindowFlags(Qt::FramelessWindowHint);
    //设置主题
    // this->SetThemeStyle(QString("default"));

    castWeather = new CastsWeather(this->ui->widget_weather);
    this->ui->widget_weather->layout()->addWidget(castWeather);

    ui->statusBar->addPermanentWidget(new QLabel(QDateTime::currentDateTime().toString("yyyy-MM-dd"),this));


}

void MainWindow::SetThemeStyle(QString style)
{
    GlobalTools globalTools;
    // qDebug() << globalTools.fileHelper->ReadFile(QString("resources/style/default.css"));
    if(style == "default"){
        // this->setStyleSheet(globalTools.fileHelper->ReadFile(QString("resources/style/default.css")));
    }

}




void MainWindow::on_pushButton_showGB26875_Server_clicked()
{
    if(this->clp_GB26875ServerMode->isHidden()){
        this->clp_GB26875ServerMode->show();
    }
}


void MainWindow::on_pushButton_showGB26875_Client_clicked()
{
    if(this->clp_GB26875ClientMode->isHidden()){
        this->clp_GB26875ClientMode->show();
    }
}


void MainWindow::on_pushButton_showWeather_clicked()
{
}


void MainWindow::on_testNet_clicked()
{
    // this->G_NetWorkAssistant->TestSandRequest();
    // request.setUrl(QUrl("https://restapi.amap.com/v3/weather/weatherInfo?city=441900&key=23b1480f777d231887315b179e8c484f"));
    // 显示永久消息（直到被清除）
    this->ui->statusBar->showMessage(tr("天气数据来源高德"),2000);
    // this->G_NetWorkAssistant->RequestHighAltitudeWeatherData("https://restapi.amap.com/v3/weather/weatherInfo","23b1480f777d231887315b179e8c484f","441900","base");//请求实况天气
    this->G_NetWorkAssistant->RequestHighAltitudeWeatherData("https://restapi.amap.com/v3/weather/weatherInfo","23b1480f777d231887315b179e8c484f",this->m_adcode,"all");//请求预测的数据

}

