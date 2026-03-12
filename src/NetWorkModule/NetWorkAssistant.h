#ifndef NETWORKASSISTANT_H
#define NETWORKASSISTANT_H

#include <QObject>
#include <QWidget>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "../Tools/GlobalTools.h"
#include "../ProtocolModule/GB26875ServerProtoco1.h"
#include "LocalTCPServer.h"
#include "LocalTCPClient.h"


class NetWorkAssistant : public QWidget
{
    Q_OBJECT
public:
    explicit NetWorkAssistant(QWidget *parent = nullptr);

    //Initialize the internal members of the object
    void InitMumbers();

    //Initialize the necessary connection signal slots
    void InitConnect();

    //Echo information
    void EchoInformation();

    //Send a request for weather data to Gaode
    void TestSandRequest();
    void RequestHighAltitudeWeatherData(QString url,QString key,QString adcode,QString extensions="",QString output="JSON");
    void DealHighAltitudeWeatherData(QByteArray data,QString extensions="",QString output="JSON");

    // 返回一个QTcpSocket的IPv4地址的16进制
    QByteArray getPeerAddressBytes(const QTcpSocket *socket);

signals:
    void updateWeatherData(HighAltitudeWeatherDataSturct::WeatherRequestReturnData weatherdata);

public:
    //The globally unique instance of QNetworkAccessManager
    QNetworkAccessManager *NetManager;

    //Handling requests
    QMap<QNetworkReply *,QString> ReplyMap;

    //测试
    GB26875ServerProtoco1* testHelper;
    GB26875::GB26875DataStruct data;


    // request.setUrl(QUrl("http://qt-project.org"));
    // request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

    // connect(reply, &QIODevice::readyRead, this, &MyClass::slotReadyRead);
    // connect(reply, &QNetworkReply::errorOccurred,
    //         this, &MyClass::slotError);
    // connect(reply, &QNetworkReply::sslErrors,
    //         this, &MyClass::slotSslErrors);
    // connect(manager, &QNetworkAccessManager::finished,
    //         this, &MyClass::replyFinished);

    // manager->get(QNetworkRequest(QUrl("http://qt-project.org")));

public:
    LocalTCPServer* cl_localTcpServer;//本地做服务器，用于通信
    LocalTCPClient* cl_localTcpClient;//用于连接远程服务器(如果有)
};

#endif // NETWORKASSISTANT_H
