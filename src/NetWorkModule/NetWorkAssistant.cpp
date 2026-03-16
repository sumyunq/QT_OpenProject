#include "NetWorkAssistant.h"

NetWorkAssistant::NetWorkAssistant(QWidget *parent)
    : QWidget{parent}
{
    this->InitMumbers();

    this->InitConnect();

}

void NetWorkAssistant::InitMumbers()
{
    this->NetManager = new QNetworkAccessManager(this);
    // this->WeatherRequest.setUrl(QUrl("https://restapi.amap.com/v3/weather/weatherInfo?city=441900&key=23b1480f777d231887315b179e8c484f"));
    // this->WeatherRequest.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

    testHelper = new GB26875ServerProtoco1();
    data.dataObjectType[0] = 0x05;
    qDebug()<<data.combinationInfo().toHex()<< "大小："<< data.combinationInfo().size();

    // this->cl_localTcpServer = new LocalTCPServer(this);
    // this->cl_localTcpClient = new LocalTCPClient(this);

    // cl_localTcpServer->StartServer(6868);
    // loadServerConfig(QString &host, quint16 &port)

    // cl_localTcpClient->connectToServer("127.0.0.1",6868);
    // cl_localTcpServer->broadcast(data.combinationInfo());
}

void NetWorkAssistant::InitConnect()
{
    connect(this->NetManager, &QNetworkAccessManager::finished,
            this, &NetWorkAssistant::EchoInformation);

}

void NetWorkAssistant::EchoInformation()
{
    qDebug()<<"请求完成!";
    // // 打印完整请求和响应信息
    // for (QMap<QNetworkReply *,QString >::Iterator it = ReplyMap.begin();it != ReplyMap.end(); it++) {

    //     qDebug() << "请求URL:" << it.key()->url().toString();
    //     qDebug() << "请求方法:" << it.key()->operation();
    //     qDebug() << "响应头:" << it.key()->rawHeaderPairs();
    //     qDebug() << "数据:" << it.key()->readAll();
    //     qDebug() << "响应数据大小:" << it.key()->size();

    // }

    // ReplyMap.clear();
}

void NetWorkAssistant::TestSandRequest()
{
    QNetworkRequest request;
    request.setUrl(QUrl("https://restapi.amap.com/v3/weather/weatherInfo?city=441900&key=23b1480f777d231887315b179e8c484f&extensions=all"));

    QNetworkReply *reply = this->NetManager->get(request);
    this->ReplyMap.insert(reply,"高德");

    connect(reply, &QIODevice::readyRead, this, []{
        qDebug()<<"数据可读";
    });
    connect(reply, &QNetworkReply::errorOccurred,
            this, []{
                qDebug()<<"error";
            });
    connect(reply, &QNetworkReply::sslErrors,
            this, []{
                qDebug()<<"sslErrors";
            });
}

void NetWorkAssistant::RequestHighAltitudeWeatherData(QString url, QString key, QString adcode, QString extensions, QString output)
{
    QNetworkRequest WeatherRequest;
    WeatherRequest.setUrl(QUrl(QString("%1?key=%2&city=%3&extensions=%4&output=%5").arg(url,key,adcode,extensions,output)));

    QNetworkReply *WeatherReply = this->NetManager->get(WeatherRequest);
    this->ReplyMap.insert(WeatherReply,"高德");//这个要改,不过目前既没影响，也没啥用处，写这个是因为考虑到可能会使用其他平台的天气API

    connect(WeatherReply, &QNetworkReply::finished, this, [WeatherReply,this,extensions,output]{

        WeatherReply->deleteLater();
        if (WeatherReply->error() != QNetworkReply::NoError) {
            qWarning() << "天气数据请求失败:" << WeatherReply->errorString();
            return;
        }
        qDebug() << "请求URL:" << WeatherReply->url().toString();
        qDebug() << "请求方法:" << WeatherReply->operation();
        qDebug() << "响应头:" <<WeatherReply->rawHeaderPairs();

        // 此时 readAll() 能够保证数据完整
        QByteArray data = WeatherReply->readAll();

        // 处理返回的数据信息
        DealHighAltitudeWeatherData(data, extensions, output);

    });

    connect(WeatherReply, &QNetworkReply::errorOccurred,this, []{
        qDebug()<<"error";
    });
    connect(WeatherReply, &QNetworkReply::sslErrors,this, []{
        qDebug()<<"sslErrors";
    });

}

void NetWorkAssistant::DealHighAltitudeWeatherData(QByteArray data, QString extensions, QString output)
{
    GlobalTools tmp_globalTools;
    HighAltitudeWeatherDataSturct::WeatherRequestReturnData tmp_weatherData;
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &parseError);
    // 检查JSON解析错误
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "JSON解析错误:" << parseError.errorString();
        qDebug() << "错误位置:" << parseError.offset;
        return;
    }
    qDebug()<<"处理天气数据";
    //处理天气数据（仅支持JSON格式,XML暂不考虑）
    tmp_globalTools.jsonHelper->DealHighAltitudeWeatherData(tmp_weatherData,jsonDoc);

    //绑定并发送一个更新信号，就能够完成对数据的更新
    emit(updateWeatherData(tmp_weatherData));

}

QByteArray NetWorkAssistant::getPeerAddressBytes(const QTcpSocket *socket)
{
    if (!socket || socket->state() != QAbstractSocket::ConnectedState) {
        qWarning() << "socket 未连接";
        return QByteArray();
    }

    QHostAddress peerAddress = socket->peerAddress();
    quint16 peerPort = socket->peerPort();

    // 确保是 IPv4 地址（6 字节编码仅支持 IPv4）
    if (peerAddress.protocol() != QAbstractSocket::IPv4Protocol) {
        qWarning() << "仅支持 IPv4 地址";
        return QByteArray();
    }

    // 获取 IPv4 地址的 32 位整数（主机字节序）
    quint32 ipv4 = peerAddress.toIPv4Address();

    // 分解 IP 字节（从高到低）
    quint8 ipBytes[4];
    ipBytes[0] = (ipv4 >> 24) & 0xFF;   // 最高位，如 192
    ipBytes[1] = (ipv4 >> 16) & 0xFF;   // 次高位，如 168
    ipBytes[2] = (ipv4 >> 8) & 0xFF;    // 次低位，如 0
    ipBytes[3] = ipv4 & 0xFF;            // 最低位，如 1

    // 仅用于显示，字节序应在传输时再更改
    // // 按小端序（低字节在前）构建 4 字节 IP
    // QByteArray result;
    // result.append(static_cast<char>(ipBytes[3])); // 先存最低位
    // result.append(static_cast<char>(ipBytes[2]));
    // result.append(static_cast<char>(ipBytes[1]));
    // result.append(static_cast<char>(ipBytes[0])); // 最后存最高位

    // // 按小端序添加 2 字节端口
    // result.append(static_cast<char>(peerPort & 0xFF));       // 低字节
    // result.append(static_cast<char>((peerPort >> 8) & 0xFF)); // 高字节

    // 构建 4 字节 IP
    QByteArray result;
    result.append(static_cast<char>(ipBytes[0]));
    result.append(static_cast<char>(ipBytes[1]));
    result.append(static_cast<char>(ipBytes[2]));
    result.append(static_cast<char>(ipBytes[3]));

    // 添加 2 字节端口
    result.append(static_cast<char>((peerPort >> 8) & 0xFF));
    result.append(static_cast<char>(peerPort & 0xFF));

    return result;
}
