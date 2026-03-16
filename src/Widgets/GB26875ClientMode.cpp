#include "GB26875ClientMode.h"
#include "ui_GB26875ClientMode.h"

GB26875ClientMode::GB26875ClientMode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GB26875ClientMode)
{
    ui->setupUi(this);
    this->InitUIInformation();
    this->InitMumbers();
    this->InitConnect();
}

GB26875ClientMode::~GB26875ClientMode()
{
    delete ui;
}

void GB26875ClientMode::InitMumbers()
{
    this->cl_localTcpServer = new LocalTCPServer(this);
    this->cl_localTcpClient = new LocalTCPClient(this);

    //默认做客户端,
    // cl_localTcpClient->connectToServer("127.0.0.1",6868);
    this->clp_fireAlarmDevice = new FireAlarmDevice(this->ui->scrollAreaWidgetContents);
    this->ui->scrollAreaWidgetContents->layout()->addWidget(this->clp_fireAlarmDevice);

}

void GB26875ClientMode::InitConnect()
{


    QObject::connect(this->cl_localTcpClient,&LocalTCPClient::connected,this, [=](){
        //连接到服务器,更新部分标签 >—<
        this->clp_fireAlarmDevice->setIPSourceAddress(this->cl_localTcpClient->m_socket);
    });

    QObject::connect(this->cl_localTcpClient,&LocalTCPClient::disconnected,this, [=](){
        // 断开连接
    });
    QObject::connect(this->cl_localTcpClient,&LocalTCPClient::connectionError,this, [=](const QString& error){
        // 连接错误
        this->ui->textEdit_ServerMessage->append("连接错误:"+error);
    });

    QObject::connect(this->cl_localTcpClient,&LocalTCPClient::dataReceived,this, [=](const QByteArray& data){
        this->ui->textEdit_ServerMessage->append("收到服务器消息:"+data.toHex().toUpper());
    });
    QObject::connect(this->cl_localTcpClient,&LocalTCPClient::dataSent,this, [=](qint64 bytes){
        this->ui->textEdit_ServerMessage->append("发送数据:"+QString::number(bytes));
    });

    QObject::connect(this->cl_localTcpClient,&LocalTCPClient::stateChanged,this, [=](QAbstractSocket::SocketState state){
        // this->ui->textEdit_ServerMessage->append("收到服务器消息:"+data.toHex().toUpper());
        //状态变化
    });


}

void GB26875ClientMode::InitUIInformation()
{
    this->setWindowTitle("GB26875协议客户端");
    this->setWindowIcon(QIcon(":/img/resources/images/title.png"));
}

void GB26875ClientMode::on_pushButton_ConnectToServer_clicked()
{
    QString IPv4 =ui->lineEdit_IP_1->text() +"."+ ui->lineEdit_IP_2->text()+"."+ui->lineEdit_IP_3->text()+"."+ui->lineEdit_IP_4->text();
    quint16 port = ui->lineEdit_IP_Port->text().toInt();
    if(this->cl_localTcpClient->connectToServer(IPv4,port)){
        //已连接到服务器,可以发送数据
        this->ui->pushButton_disConnect->setEnabled(true);
        this->ui->pushButton_sendToServer->setEnabled(true);

        // 获取远程服务器地址和端口
        this->clp_fireAlarmDevice->setIPDestinationAddress(this->cl_localTcpClient->m_socket->peerAddress(),this->cl_localTcpClient->m_socket->peerPort());
    };
}


void GB26875ClientMode::on_pushButton_disConnect_clicked()
{
    // 断开连接
    this->cl_localTcpClient->disconnectFromServer();
    this->ui->pushButton_disConnect->setEnabled(false);
    this->ui->pushButton_sendToServer->setEnabled(false);
}


void GB26875ClientMode::on_pushButton_sendToServer_clicked()
{
    //发送数据至服务器
    this->cl_localTcpClient->sendData(this->clp_fireAlarmDevice->dataPackage);
}

