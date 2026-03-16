#include "FireAlarmDevice.h"
#include "ui_FireAlarmDevice.h"

FireAlarmDevice::FireAlarmDevice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FireAlarmDevice)
{
    ui->setupUi(this);

    InitMumbers();
    InitConnect();

}

FireAlarmDevice::~FireAlarmDevice()
{
    delete ui;
}

void FireAlarmDevice::InitMumbers()
{
    m_updateTimer = new QTimer(this);
    m_updateTimer->start(1000);  // 每秒更新一次

    QRegularExpressionValidator* tmp_reg = new QRegularExpressionValidator(QRegularExpression("[0-9A-Fa-f]+"), this);

    //启动符号 2字节 "@@"

    //控制单元 25字节
    //业务流水号 2字节
    ui->lineEdit_businessTransactionSerialNumber->setValidator(tmp_reg);
    ui->lineEdit_businessTransactionSerialNumber->setMaxLength(4);
    //协议版本号 2字节
    ui->lineEdit_protocolVersionNumber->setValidator(tmp_reg);
    ui->lineEdit_protocolVersionNumber->setMaxLength(4);

    //时间标签 6字节
    ui->lineEdit_timeLabel->setValidator(tmp_reg);
    ui->lineEdit_timeLabel->setMaxLength(12);

    //源地址 6字节 低字节在前 255 255 255 255
    ui->lineEdit_sourceAddress->setValidator(tmp_reg);
    ui->lineEdit_sourceAddress->setMaxLength(12);

    //目的地址 6字节 低字节在前
    ui->lineEdit_destinationAddress->setValidator(tmp_reg);
    ui->lineEdit_destinationAddress->setMaxLength(12);

    //应用数据单元长度 2字节 低字节在前
    ui->lineEdit_applicationDataUnitLength->setValidator(tmp_reg);
    ui->lineEdit_applicationDataUnitLength->setMaxLength(4);

    //命令字节 1字节 二进制数 具体请参照数据报说明 00~ff
    ui->lineEdit_commandByte->setValidator(tmp_reg);
    ui->lineEdit_commandByte->setMaxLength(2);

    //应用数据单元 最大1024字节 ( 1 + 1 + n * SingleLength )
    //数据对象类型 1字节 具体请参照数据报说明(类型标识)
    ui->lineEdit_dataObjectType->setValidator(tmp_reg);
    ui->lineEdit_dataObjectType->setMaxLength(2);

    //数据对象数目 1字节 对应n
    ui->lineEdit_dataObjectCount->setValidator(tmp_reg);
    ui->lineEdit_dataObjectCount->setMaxLength(2);

    //校验和 1字节
    ui->lineEdit_checksum->setValidator(tmp_reg);
    ui->lineEdit_checksum->setMaxLength(2);

    //结束符号 2字节 "##"

    ui->Line_6_4->setMaxLength(64);  //限制大小为31字节

    ui->stackedWidget->setCurrentIndex(0);

    this->setWindowTitle("GB26875协议");
    this->setWindowIcon(QIcon(":/img/resources/images/title.png"));

}

void FireAlarmDevice::InitConnect()
{
    QObject::connect(this->ui->lineEdit_dataObjectCount,&QLineEdit::editingFinished,[this](){
        int index = this->ui->comboBox_InfoType->currentIndex();
        ui->lineEdit_dataObjectCount->setText(QString("%1").arg((ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16)), 2, 16, QChar('0')).toUpper());
        this->on_comboBox_InfoType_currentIndexChanged(index);
    });

    QObject::connect(this->ui->lineEdit_businessTransactionSerialNumber,&QLineEdit::editingFinished,[this](){
        ui->lineEdit_businessTransactionSerialNumber->setText(QString("%1").arg((ui->lineEdit_businessTransactionSerialNumber->text().toInt(nullptr, 16)), 4, 16, QChar('0')).toUpper());
    });

    QObject::connect(this->ui->lineEdit_protocolVersionNumber,&QLineEdit::editingFinished,[this](){
        ui->lineEdit_protocolVersionNumber->setText(QString("%1").arg((ui->lineEdit_protocolVersionNumber->text().toInt(nullptr, 16)), 4, 16, QChar('0')).toUpper());
    });

    QObject::connect(this->m_updateTimer,&QTimer::timeout,[this](){
        ui->lineEdit_timeLabel->setText(QString("%1").arg(QDateTime::currentSecsSinceEpoch(), 12, 16, QChar('0')).toUpper());
        ui->Line_1_4->setText(QString("%1").arg(QDateTime::currentSecsSinceEpoch(), 12, 16, QChar('0')).toUpper());
        ui->Line_2_7->setText(QString("%1").arg(QDateTime::currentSecsSinceEpoch(), 12, 16, QChar('0')).toUpper());
        ui->Line_8_3->setText(QString("%1").arg(QDateTime::currentSecsSinceEpoch(), 12, 16, QChar('0')).toUpper());
        ui->Line_90_1->setText(QString("%1").arg(QDateTime::currentSecsSinceEpoch(), 12, 16, QChar('0')).toUpper());

        // ui->lineEdit_sourceAddress->setText(QString("%1").arg(m_sourceAddress.toHex(), 12, 16, QChar('0')).toUpper());
        // qDebug()<<this->m_sourceAddress.toHex();


    });

    // QObject::connect(this->ui->lineEdit_sourceAddress,&QLineEdit::editingFinished,[this](){
    //     ui->lineEdit_sourceAddress->setText(QString("%1").arg((ui->lineEdit_sourceAddress->text().toInt(nullptr, 16)), 12, 16, QChar('0')).toUpper());
    // });

    // QObject::connect(this->ui->lineEdit_destinationAddress,&QLineEdit::editingFinished,[this](){
    //     ui->lineEdit_destinationAddress->setText(QString("%1").arg((ui->lineEdit_destinationAddress->text().toInt(nullptr, 16)), 12, 16, QChar('0')).toUpper());
    // });

    QObject::connect(this->ui->lineEdit_checksum,&QLineEdit::editingFinished,[this](){
        ui->lineEdit_checksum->setText(QString("%1").arg((ui->lineEdit_checksum->text().toInt(nullptr, 16)), 2, 16, QChar('0')).toUpper());
    });


    QObject::connect(this->ui->Line_6_4,&QLineEdit::editingFinished,[this](){
        ui->Line_6_3->setText(QString("%1").arg((ui->Line_6_4->text().toUtf8().size()), 2, 16, QChar('0')).toUpper());
    });
    QObject::connect(this->ui->Line_26_2,&QLineEdit::editingFinished,[this](){
        ui->Line_26_1->setText(QString("%1").arg((ui->Line_26_1->text().toUtf8().size()), 2, 16, QChar('0')).toUpper());
    });

    QObject::connect(this->ui->lineEdit_targetIPPort,&QLineEdit::editingFinished,[this](){

        QString input = ui->lineEdit_targetIPPort->text().trimmed();
        QStringList parts = input.split(':');
        if (parts.size() != 2) {
            qWarning() << "格式错误，应为 IP:端口";
            return;
        }

        QString ipStr = parts[0].trimmed();
        QString portStr = parts[1].trimmed();

        // 1. 解析 IP 地址的四个字节（点分十进制）
        QStringList ipParts = ipStr.split('.');
        if (ipParts.size() != 4) {
            qWarning() << "IP 地址格式错误";
            return;
        }

        bool ok;
        quint8 ipBytes[4];
        for (int i = 0; i < 4; ++i) {
            int val = ipParts[i].toInt(&ok);
            if (!ok || val < 0 || val > 255) {
                qWarning() << "IP 段无效";
                return;
            }
            ipBytes[i] = static_cast<quint8>(val);
        }

        // 2. 解析端口
        quint16 port = portStr.toUShort(&ok);
        if (!ok || port == 0) {
            qWarning() << "端口号无效";
            return;
        }

        // 3. 按小端序（低字节在前）构建字节数组
        QByteArray data;
        //  显示时不需要按低地址在前，字节序问题会自动处理
        // // IP 地址小端序：原顺序 [b1, b2, b3, b4] → 存储为 [b4, b3, b2, b1]
        // data.append(static_cast<char>(ipBytes[3])); // 原最低字节（b4）
        // data.append(static_cast<char>(ipBytes[2])); // b3
        // data.append(static_cast<char>(ipBytes[1])); // b2
        // data.append(static_cast<char>(ipBytes[0])); // b1
        // // 端口小端序：低字节在前
        // data.append(static_cast<char>(port & 0xFF));       // 低字节
        // data.append(static_cast<char>((port >> 8) & 0xFF)); // 高字节

        data.append(static_cast<char>(ipBytes[0]));
        data.append(static_cast<char>(ipBytes[1]));
        data.append(static_cast<char>(ipBytes[2]));
        data.append(static_cast<char>(ipBytes[3]));
        data.append(static_cast<char>(port >> 8) & 0xFF);
        data.append(static_cast<char>(port & 0xFF));

        // 4. 转换为十六进制字符串（大写）
        QString hexResult = data.toHex().toUpper();
        qDebug() << "小端序十六进制:" << hexResult;

        // 显示到 QLineEdit
        ui->lineEdit_destinationAddress->setText(hexResult);

    });


    ui->stackedWidget->setCurrentIndex(0);
}

void FireAlarmDevice::setIPSourceAddress(QTcpServer *tcpServer)
{
    if (!tcpServer || !tcpServer->isListening()) {
        qWarning() << "tcpServer is not listening";
        return;
    }
    QHostAddress serverAddress = tcpServer->serverAddress();
    quint16 serverPort = tcpServer->serverPort();

    // 仅支持 IPv4
    if (serverAddress.protocol() != QAbstractSocket::IPv4Protocol) {
        qWarning() << "Only IPv4 supported for source address";
        return;
    }

    quint32 ipv4 = serverAddress.toIPv4Address();

    // 分解 IP 字节（从高到低）
    quint8 ipBytes[4];
    ipBytes[0] = (ipv4 >> 24) & 0xFF;   // 最高位，如 192
    ipBytes[1] = (ipv4 >> 16) & 0xFF;   // 次高位，如 168
    ipBytes[2] = (ipv4 >> 8) & 0xFF;    // 次低位，如 0
    ipBytes[3] = ipv4 & 0xFF;            // 最低位，如 1

    // 构造6字节地址：IP (4字节) + 端口 (2字节)
    QByteArray srcAddr;
    // 构建 4 字节 IP
    srcAddr.append(static_cast<char>(ipBytes[0]));
    srcAddr.append(static_cast<char>(ipBytes[1]));
    srcAddr.append(static_cast<char>(ipBytes[2]));
    srcAddr.append(static_cast<char>(ipBytes[3]));

    // 添加 2 字节端口
    srcAddr.append(static_cast<char>((serverPort >> 8) & 0xFF));
    srcAddr.append(static_cast<char>(serverPort & 0xFF));

    ui->lineEdit_sourceAddress->setText(srcAddr.toHex().toUpper());
    ui->label_sourceAddress->setText(serverAddress.toString()+":"+QString::number(serverPort));
}

void FireAlarmDevice::setIPSourceAddress(QTcpSocket *tcpSocket)
{
    if (!tcpSocket || tcpSocket->state() != QAbstractSocket::ConnectedState) {
        qWarning() << "socket 未连接";
        return ;
    }

    QHostAddress localAddress = tcpSocket->localAddress();
    quint16 localPort = tcpSocket->localPort();
    qDebug() << __FUNCTION__ << __LINE__ << "端口"<< QString::number(localPort);


    // 确保是 IPv4 地址（6 字节编码仅支持 IPv4）
    if (localAddress.protocol() != QAbstractSocket::IPv4Protocol) {
        qWarning() << "仅支持 IPv4 地址";
        return ;
    }

    // 获取 IPv4 地址的 32 位整数（主机字节序）
    quint32 ipv4 = localAddress.toIPv4Address();

    // 分解 IP 字节（从高到低）
    quint8 ipBytes[4];
    ipBytes[0] = (ipv4 >> 24) & 0xFF;   // 最高位，如 192
    ipBytes[1] = (ipv4 >> 16) & 0xFF;   // 次高位，如 168
    ipBytes[2] = (ipv4 >> 8) & 0xFF;    // 次低位，如 0
    ipBytes[3] = ipv4 & 0xFF;            // 最低位，如 1

    // 仅用于显示，字节序应在传输时再更改
    // 构建 4 字节 IP
    QByteArray result;
    result.append(static_cast<char>(ipBytes[0]));
    result.append(static_cast<char>(ipBytes[1]));
    result.append(static_cast<char>(ipBytes[2]));
    result.append(static_cast<char>(ipBytes[3]));

    // 添加 2 字节端口
    result.append(static_cast<char>((localPort >> 8) & 0xFF));
    result.append(static_cast<char>(localPort & 0xFF));

    ui->lineEdit_sourceAddress->setText(result.toHex());
    ui->label_sourceAddress->setText(localAddress.toString()+":"+QString::number(localPort));
}

void FireAlarmDevice::setIPDestinationAddress(QTcpServer *tcpServer)
{
    if (!tcpServer || !tcpServer->isListening()) {
        qWarning() << "tcpServer is not listening";
        return;
    }
    QHostAddress serverAddress = tcpServer->serverAddress();
    quint16 serverPort = tcpServer->serverPort();

    // 仅支持 IPv4
    if (serverAddress.protocol() != QAbstractSocket::IPv4Protocol) {
        qWarning() << "Only IPv4 supported for source address";
        return;
    }

    quint32 ipv4 = serverAddress.toIPv4Address();

    // 分解 IP 字节（从高到低）
    quint8 ipBytes[4];
    ipBytes[0] = (ipv4 >> 24) & 0xFF;   // 最高位，如 192
    ipBytes[1] = (ipv4 >> 16) & 0xFF;   // 次高位，如 168
    ipBytes[2] = (ipv4 >> 8) & 0xFF;    // 次低位，如 0
    ipBytes[3] = ipv4 & 0xFF;            // 最低位，如 1

    // 构造6字节地址：IP (4字节) + 端口 (2字节)
    QByteArray srcAddr;
    // 构建 4 字节 IP
    srcAddr.append(static_cast<char>(ipBytes[0]));
    srcAddr.append(static_cast<char>(ipBytes[1]));
    srcAddr.append(static_cast<char>(ipBytes[2]));
    srcAddr.append(static_cast<char>(ipBytes[3]));

    // 添加 2 字节端口
    srcAddr.append(static_cast<char>((serverPort >> 8) & 0xFF));
    srcAddr.append(static_cast<char>(serverPort & 0xFF));

    ui->lineEdit_destinationAddress->setText(srcAddr.toHex().toUpper());
    ui->lineEdit_targetIPPort->setText(serverAddress.toString()+":"+QString::number(serverPort));
}

void FireAlarmDevice::setIPDestinationAddress(QTcpSocket *tcpSocket)
{
    if (!tcpSocket || tcpSocket->state() != QAbstractSocket::ConnectedState) {
        qWarning() << "socket 未连接";
        return ;
    }

    QHostAddress localAddress = tcpSocket->localAddress();
    quint16 localPort = tcpSocket->localPort();

    // 确保是 IPv4 地址（6 字节编码仅支持 IPv4）
    if (localAddress.protocol() != QAbstractSocket::IPv4Protocol) {
        qWarning() << "仅支持 IPv4 地址";
        return ;
    }

    // 获取 IPv4 地址的 32 位整数（主机字节序）
    quint32 ipv4 = localAddress.toIPv4Address();

    // 分解 IP 字节（从高到低）
    quint8 ipBytes[4];
    ipBytes[0] = (ipv4 >> 24) & 0xFF;   // 最高位，如 192
    ipBytes[1] = (ipv4 >> 16) & 0xFF;   // 次高位，如 168
    ipBytes[2] = (ipv4 >> 8) & 0xFF;    // 次低位，如 0
    ipBytes[3] = ipv4 & 0xFF;            // 最低位，如 1

    // 仅用于显示，字节序应在传输时再更改
    // 构建 4 字节 IP
    QByteArray result;
    result.append(static_cast<char>(ipBytes[0]));
    result.append(static_cast<char>(ipBytes[1]));
    result.append(static_cast<char>(ipBytes[2]));
    result.append(static_cast<char>(ipBytes[3]));

    // 添加 2 字节端口
    result.append(static_cast<char>((localPort >> 8) & 0xFF));
    result.append(static_cast<char>(localPort & 0xFF));

    ui->lineEdit_destinationAddress->setText(result.toHex());
    ui->lineEdit_targetIPPort->setText(localAddress.toString()+":"+QString::number(localPort));
}

void FireAlarmDevice::setIPDestinationAddress(QHostAddress hostAddress, quint16 port)
{

    // 确保是 IPv4 地址（6 字节编码仅支持 IPv4）
    if (hostAddress.protocol() != QAbstractSocket::IPv4Protocol) {
        qWarning() << "仅支持 IPv4 地址";
        return ;
    }

    // 获取 IPv4 地址的 32 位整数（主机字节序）
    quint32 ipv4 = hostAddress.toIPv4Address();

    // 分解 IP 字节（从高到低）
    quint8 ipBytes[4];
    ipBytes[0] = (ipv4 >> 24) & 0xFF;   // 最高位，如 192
    ipBytes[1] = (ipv4 >> 16) & 0xFF;   // 次高位，如 168
    ipBytes[2] = (ipv4 >> 8) & 0xFF;    // 次低位，如 0
    ipBytes[3] = ipv4 & 0xFF;            // 最低位，如 1

    // 仅用于显示，字节序应在传输时再更改
    // 构建 4 字节 IP
    QByteArray result;
    result.append(static_cast<char>(ipBytes[0]));
    result.append(static_cast<char>(ipBytes[1]));
    result.append(static_cast<char>(ipBytes[2]));
    result.append(static_cast<char>(ipBytes[3]));

    // 添加 2 字节端口
    result.append(static_cast<char>((port >> 8) & 0xFF));
    result.append(static_cast<char>(port & 0xFF));

    ui->lineEdit_destinationAddress->setText(result.toHex());
    ui->lineEdit_targetIPPort->setText(hostAddress.toString()+":"+QString::number(port));
}


QString FireAlarmDevice::getDestinationAddress()
{
    return this->ui->lineEdit_destinationAddress->text();
}

void FireAlarmDevice::on_comboBox_cmdType_currentIndexChanged(int index)
{
    ui->lineEdit_commandByte->setText(QString("%1").arg(ui->comboBox_cmdType->currentIndex(), 2, 16, QChar('0')).toUpper());
}


void FireAlarmDevice::on_comboBox_InfoType_currentIndexChanged(int index)
{
    // qDebug()<<"当前："<<index;
    QRegularExpression re(R"(^(\d+)(?:~(\d+))?[:：])");
    QRegularExpressionMatch match = re.match(ui->comboBox_InfoType->currentText());
    if (match.hasMatch()) {
        int start = match.captured(1).toInt();
        int end = match.captured(2).isEmpty() ? start : match.captured(2).toInt();
        // 使用 start 和 end
        if(start != end){
            ui->lineEdit_dataObjectCount->setText("0000");
            ui->lineEdit_applicationDataUnitLength->setText("0000");
        }
        ui->lineEdit_dataObjectType->setText(QString("%1").arg(start, 2, 16, QChar('0')).toUpper());
        //更新 应用数据单元长度
        switch(start){
        case 0:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(0, 4, 16, QChar('0')).toUpper());
            break;
        case 1:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg((10 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16)), 4, 16, QChar('0')).toUpper());
            break;
        case 2:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(46* ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 3:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(16 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 4:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(10 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 5:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(4 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 6:
            // 变长类型：3 + L 字节，需根据实际L计算
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg( (3 +  ui->Line_6_4->text().toUtf8().size()) * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 7:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(36 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 8:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(8 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 21:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(7 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 24:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(8 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 25:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(2 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 26:
            // 变长类型：1 + L 字节，需根据实际L计算
            // 转utf-8字节
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg( (1 +  ui->Line_26_2->text().toUtf8().size()) * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 28:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(6 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 61:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(2 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 62:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(6 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 63:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(6 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 64:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(9 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 65:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(2 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 66:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(2 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 67:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(6 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 68:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(2 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 81:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(1 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 84:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(7 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 85:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(1 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 86:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(1 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 88:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(1 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 89:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(1 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 90:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(6 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        case 91:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(1 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        default:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(0 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        }
    }

    this->ui->stackedWidget->setCurrentIndex(index);
}


void FireAlarmDevice::on_pushButton_create_clicked()
{
    GB26875::GB26875DataStruct tmp_dataPackage;
    //生成数据报
    tmp_dataPackage.startSymbol = QByteArray::fromHex(ui->lineEdit_startSymbol->text().toLatin1());
    tmp_dataPackage.businessTransactionSerialNumber = QByteArray::fromHex(ui->lineEdit_businessTransactionSerialNumber->text().toLatin1());
    tmp_dataPackage.protocolVersionNumber = QByteArray::fromHex(ui->lineEdit_protocolVersionNumber->text().toLatin1());
    tmp_dataPackage.timeLabel = QByteArray::fromHex(ui->lineEdit_timeLabel->text().toLatin1());
    tmp_dataPackage.sourceAddress = QByteArray::fromHex(ui->lineEdit_sourceAddress->text().toLatin1());
    tmp_dataPackage.destinationAddress = QByteArray::fromHex(ui->lineEdit_destinationAddress->text().toLatin1());
    tmp_dataPackage.applicationDataUnitLength = QByteArray::fromHex(ui->lineEdit_applicationDataUnitLength->text().toLatin1());
    tmp_dataPackage.commandByte = QByteArray::fromHex(ui->lineEdit_commandByte->text().toLatin1());
    tmp_dataPackage.dataObjectType = QByteArray::fromHex(ui->lineEdit_dataObjectType->text().toLatin1());
    tmp_dataPackage.dataObjectCount = QByteArray::fromHex(ui->lineEdit_dataObjectCount->text().toLatin1());

    //数据体
    QRegularExpression re(R"(^(\d+)(?:~(\d+))?[:：])");
    QRegularExpressionMatch match = re.match(ui->comboBox_InfoType->currentText());
    if (match.hasMatch()) {
        int start = match.captured(1).toInt();
        int end = match.captured(2).isEmpty() ? start : match.captured(2).toInt();

        switch(start){
        case 0:
        {
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(0, 4, 16, QChar('0')).toUpper());
        }
        break;
        case 1:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_001 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_1_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_1_2->text().toLatin1());
                tmp_Info.systemStatus =QByteArray::fromHex(ui->Line_1_3->text().toLatin1());
                tmp_Info.systemStatusSendingTime =QByteArray::fromHex(ui->Line_1_4->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));

            };
            break;
        }
        case 2:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_002 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_2_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_2_2->text().toLatin1());
                tmp_Info.componentType =QByteArray::fromHex(ui->Line_2_3->text().toLatin1());
                tmp_Info.componentAddress =QByteArray::fromHex(ui->Line_2_4->text().toLatin1());
                tmp_Info.componentStatus =QByteArray::fromHex(ui->Line_2_5->text().toLatin1());
                tmp_Info.componentDescription =QByteArray::fromHex(ui->Line_2_6->text().toLatin1());
                tmp_Info.componentsOperatingStatusSendingTime =QByteArray::fromHex(ui->Line_2_7->text().toLatin1());

                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 3:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_003 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_3_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_3_2->text().toLatin1());
                tmp_Info.componentType =QByteArray::fromHex(ui->Line_3_3->text().toLatin1());
                tmp_Info.componentAddress =QByteArray::fromHex(ui->Line_3_4->text().toLatin1());
                tmp_Info.AnalogType =QByteArray::fromHex(ui->Line_3_5->text().toLatin1());
                tmp_Info.AnalogValuesSamplingTime =QByteArray::fromHex(ui->Line_3_6->text().toLatin1());

                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 4:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_004 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_4_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_4_2->text().toLatin1());
                tmp_Info.operationInformation =QByteArray::fromHex(ui->Line_4_3->text().toLatin1());
                tmp_Info.operatorNumber =QByteArray::fromHex(ui->Line_4_4->text().toLatin1());
                tmp_Info.OperationInformationRecordTime =QByteArray::fromHex(ui->Line_4_5->text().toLatin1());

                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 5:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_005 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_5_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_5_2->text().toLatin1());
                tmp_Info.softwareMajorVersionNumber =QByteArray::fromHex(ui->Line_5_3->text().toLatin1());
                tmp_Info.softwareMinorVersionNumber =QByteArray::fromHex(ui->Line_5_4->text().toLatin1());

                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 6:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_006 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_6_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_6_2->text().toLatin1());

                tmp_Info.systemDescriptionLength =QByteArray::fromHex(ui->Line_6_3->text().toLatin1());
                if (ui->Line_6_4->text().toUtf8().size() > 31) {
                    ui->Line_6_4->text().toUtf8() = ui->Line_6_4->text().toUtf8().left(31);  // 截断处理，已做限制，可忽略
                }
                tmp_Info.systemDescription =ui->Line_6_4->text().toUtf8();

                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 7:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_007 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_7_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_7_2->text().toLatin1());
                tmp_Info.componentType =QByteArray::fromHex(ui->Line_7_3->text().toLatin1());
                tmp_Info.componentAddress =QByteArray::fromHex(ui->Line_7_4->text().toLatin1());

                QByteArray desc = ui->Line_7_5->text().toUtf8();
                if (desc.size() < 31) {
                    desc.append(31 - desc.size(), '\0');   // 补零至 31 字节
                } else if (desc.size() > 31) {
                    desc = desc.left(31);                  // 截断至前 31 字节
                }
                tmp_Info.componentDescription = desc;

                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 8:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_008 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_8_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_8_2->text().toLatin1());
                tmp_Info.systemTime =QByteArray::fromHex(ui->Line_8_3->text().toLatin1());

                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 21:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_021 tmp_Info;
                tmp_Info.operatingStatus =QByteArray::fromHex(ui->Line_21_1->text().toLatin1());
                tmp_Info.stateOccurrenceTime =QByteArray::fromHex(ui->Line_21_2->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 24:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_024 tmp_Info;
                tmp_Info.operationInformation =QByteArray::fromHex(ui->Line_24_1->text().toLatin1());
                tmp_Info.operatorNumber =QByteArray::fromHex(ui->Line_24_2->text().toLatin1());
                tmp_Info.operationRecordingTime =QByteArray::fromHex(ui->Line_24_3->text().toLatin1());

                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 25:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_025 tmp_Info;
                tmp_Info.SoftwareVersionNumber =QByteArray::fromHex(ui->Line_25_1->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 26:
            // 变长类型：1 + L 字节，需根据实际L计算
            // 转utf-8字节
            {
                for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                    GB26875::InformationObject::InformationType_026 tmp_Info;
                    tmp_Info.configurationDescriptionLength =QByteArray::fromHex(ui->Line_26_1->text().toLatin1());
                    tmp_Info.configurationDescription =ui->Line_6_4->text().toUtf8();

                    tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
                };
                break;
            }
        case 28:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_028 tmp_Info;
                tmp_Info.SystemTime =QByteArray::fromHex(ui->Line_28_1->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 61:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_061 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_61_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_61_2->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 62:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_062 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_62_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_62_2->text().toLatin1());
                tmp_Info.componentAddress =QByteArray::fromHex(ui->Line_62_3->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 63:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_063 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_63_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_63_2->text().toLatin1());
                tmp_Info.componentAddress =QByteArray::fromHex(ui->Line_63_3->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 64:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_064 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_64_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_64_2->text().toLatin1());
                tmp_Info.recordCount =QByteArray::fromHex(ui->Line_64_3->text().toLatin1());
                tmp_Info.startTime =QByteArray::fromHex(ui->Line_64_4->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 65:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_065 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_65_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_65_2->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 66:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_066 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_66_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_66_2->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 67:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_067 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_67_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_67_2->text().toLatin1());
                tmp_Info.componentAddress =QByteArray::fromHex(ui->Line_67_3->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 68:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_068 tmp_Info;
                tmp_Info.systemType =QByteArray::fromHex(ui->Line_68_1->text().toLatin1());
                tmp_Info.systemAddress =QByteArray::fromHex(ui->Line_68_2->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 81:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_081 tmp_Info;
                tmp_Info.ooo =QByteArray::fromHex(ui->Line_81_1->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 84:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_084 tmp_Info;
                tmp_Info.recordCount =QByteArray::fromHex(ui->Line_84_1->text().toLatin1());
                tmp_Info.startTime =QByteArray::fromHex(ui->Line_84_2->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 85:
        {
            for(int i = 0; i <  ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_085 tmp_Info;
                tmp_Info.ooo =QByteArray::fromHex(ui->Line_85_1->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 86:
        {
            for(int i = 0; i < ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_086 tmp_Info;
                tmp_Info.ooo =QByteArray::fromHex(ui->Line_86_1->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 88:
        {
            for(int i = 0; i < ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_088 tmp_Info;
                tmp_Info.ooo =QByteArray::fromHex(ui->Line_88_1->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 89:
        {
            for(int i = 0; i < ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_089 tmp_Info;
                tmp_Info.ooo =QByteArray::fromHex(ui->Line_89_1->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 90:
        {
            for(int i = 0; i < ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_090 tmp_Info;
                tmp_Info.centralSystemTime =QByteArray::fromHex(ui->Line_90_1->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        case 91:
        {
            for(int i = 0; i < ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16); ++i){
                GB26875::InformationObject::InformationType_091 tmp_Info;
                tmp_Info.timeoutSettingTime =QByteArray::fromHex(ui->Line_91_1->text().toLatin1());
                tmp_dataPackage.dataInfo_list.append(QVariant::fromValue(tmp_Info));
            };
            break;
        }
        default:
            ui->lineEdit_applicationDataUnitLength->setText(QString("%1").arg(0 * ui->lineEdit_dataObjectCount->text().toInt(nullptr, 16), 4, 16, QChar('0')).toUpper());
            break;
        }
    }

    tmp_dataPackage.checksum = QByteArray::fromHex(ui->lineEdit_checksum->text().toLatin1());
    tmp_dataPackage.endMark = QByteArray::fromHex(ui->lineEdit_endMark->text().toLatin1());

    m_GB26875Data_List.append(tmp_dataPackage);
    this->dataPackage.clear();
    this->dataPackage = tmp_dataPackage.combinationInfo();
    ui->textEdit->setText(tmp_dataPackage.combinationInfo().toHex());
}


void FireAlarmDevice::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "十六进制")
    {
        ui->textEdit->setText(dataPackage.toHex());
    }else if(arg1 == "十进制"){
        QStringList decList;
        for (int i = 0; i < dataPackage.size(); ++i) {
            decList << QString::number(static_cast<quint8>(dataPackage[i]));
        }
        ui->textEdit->setText(decList.join(" "));
    }
}

