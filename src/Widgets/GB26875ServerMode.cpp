#include "GB26875ServerMode.h"
#include "ui_GB26875ServerMode.h"

GB26875ServerMode::GB26875ServerMode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GB26875ServerMode)
{
    ui->setupUi(this);

    this->InitUIInformation();

    this->InitMumbers();
    this->InitConnect();
}

GB26875ServerMode::~GB26875ServerMode()
{
    delete ui;
}

void GB26875ServerMode::InitMumbers()
{
    this->cl_localTcpServer = new LocalTCPServer(this);
    this->cl_localTcpClient = new LocalTCPClient(this);

    // 获取 ConfigManager 单例
    ConfigManager& config = ConfigManager::instance();
    auto server = config.getServerConfig();

    cl_localTcpServer->StartServer(server.port);

    this->clp_fireAlarmDevice = new FireAlarmDevice(this->ui->scrollAreaWidgetContents_2);
    this->ui->scrollAreaWidgetContents_2->layout()->addWidget(this->clp_fireAlarmDevice);
    this->clp_fireAlarmDevice->setIPSourceAddress(this->cl_localTcpServer->cl_tcpServer);

    this->connect_list_model = new QStringListModel(this);

    ui->listView->setModel(this->connect_list_model);
}

void GB26875ServerMode::InitConnect()
{
    //绑定相关信号槽
    QObject::connect(this->cl_localTcpServer,&LocalTCPServer::newClientConnected,this,[=](QTcpSocket *socket, const QString& clientInfo){
        this->ui->textEdit->append("新客户端["+ socket->peerAddress().toString()+":"+QString::number(socket->peerPort())+"]已连接。");
    });
    QObject::connect(this->cl_localTcpServer,&LocalTCPServer::updateList,this,&GB26875ServerMode::updateListView);

    QObject::connect(this->cl_localTcpServer,&LocalTCPServer::updateMessage,this,[=](const QByteArray& data){
        // this->ui->textEdit->append("收到来自["+ socket->peerAddress().toString()+":"+QString::number(socket->peerPort())+"]的消息:"+ data.toHex().toUpper());
        // //解析消息之后需要进行对应的处理。。。

    });

    QObject::connect(this->cl_localTcpServer,&LocalTCPServer::clientDisconnected,this,[=](const QString& clientInfo){
        this->ui->textEdit->append("客户端["+ clientInfo+"]已断开连接。");
    });

    QObject::connect(this->cl_localTcpServer,&LocalTCPServer::dataReceived,this,[=](QTcpSocket *socket, const QByteArray& data){
        this->ui->textEdit->append("收到来自["+ socket->peerAddress().toString()+":"+QString::number(socket->peerPort())+"]的消息:"+ data.toHex().toUpper());
    });
    QObject::connect(this->cl_localTcpServer,&LocalTCPServer::serverErrorOccurred,this,[=](const QString& errorString){
        this->ui->textEdit->append("服务器出现错误，请检查!:");

    });

}

void GB26875ServerMode::InitUIInformation()
{
    this->setWindowTitle("GB26875协议服务器端");
    this->setWindowIcon(QIcon(":/img/resources/images/title.png"));
}

void GB26875ServerMode::updateListView()
{
    QStringList dataList;
    for (int i = 0; i < this->cl_localTcpServer->m_tcpClients.size(); ++i) {
        dataList << QString("%1:%2").arg(this->cl_localTcpServer->m_tcpClients.at(i)->peerAddress().toString())
        .arg(this->cl_localTcpServer->m_tcpClients.at(i)->peerPort());
    }
    this->connect_list_model->setStringList(dataList);
}
