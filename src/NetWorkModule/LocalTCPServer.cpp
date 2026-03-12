#include "LocalTCPServer.h"

LocalTCPServer::LocalTCPServer(QObject *parent)
    : QObject{parent}
{
    this->InitMumbers();
    this->InitConnect();



}

void LocalTCPServer::InitMumbers()
{
    cl_tcpServer = new QTcpServer(this);
    this->m_maxClients = 1000;


}

void LocalTCPServer::InitConnect()
{
    // QObject::connect(cl_tcpServer,&QTcpServer::newConnection,this, &LocalTCPServer::DealNewConection);
    // QObject::connect(cl_tcpServer,&QTcpServer::pendingConnectionAvailable,this, &LocalTCPServer::DealNewConection);

    // 连接 pendingConnectionAvailable 信号
    connect(cl_tcpServer, &QTcpServer::pendingConnectionAvailable,
            this, &LocalTCPServer::handlePendingConnections);
    // 连接错误信号
    connect(cl_tcpServer, &QTcpServer::acceptError,
            this, &LocalTCPServer::handleServerError);
}

void LocalTCPServer::DealNewConection()
{
    //处理新连接


}

bool LocalTCPServer::StartServer(quint16 port, const QHostAddress &address)
{
    if(!cl_tcpServer->isListening()){
        if (!cl_tcpServer->listen(address, port)) {
            qCritical() << "服务器启动失败:" << cl_tcpServer->errorString();
            return false;
        }
        qDebug() << "服务器启动成功，监听地址:" << address.toString() << "端口:" << port;
        return true;
    }else{
        qDebug() << "服务器正在监听地址:" << address.toString() << "端口:" << port;
        return true;
    }
}

void LocalTCPServer::StopServer()
{
    // 关闭所有客户端连接
    for (QTcpSocket *client : m_tcpClients) {
        client->disconnectFromHost();
        client->deleteLater();
    }
    m_tcpClients.clear();

    // 关闭服务器
    cl_tcpServer->close();
    qDebug() << "服务器已停止";
}

void LocalTCPServer::broadcast(const QByteArray& data) {
    // 向所有客户端广播数据
    for (QTcpSocket *client : m_tcpClients) {
        qDebug()<<"向所有客户端广播数据";
        if (client->state() == QAbstractSocket::ConnectedState) {
            client->write(data);
        }
    }
}

void LocalTCPServer::handlePendingConnections()
{
    // 检查连接数限制
    if (m_tcpClients.size() >= m_maxClients) {
        qWarning() << "已达到最大连接数限制，拒绝新连接";

        // 可以接受连接后立即关闭
        while (cl_tcpServer->hasPendingConnections()) {
            QTcpSocket *socket = cl_tcpServer->nextPendingConnection();
            socket->disconnectFromHost();
            socket->deleteLater();
        }
        return;
    }

    while (cl_tcpServer->hasPendingConnections()) {
        QTcpSocket *clientSocket = cl_tcpServer->nextPendingConnection();

        // 设置 socket 选项
        clientSocket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);
        clientSocket->setSocketOption(QAbstractSocket::LowDelayOption, 1); // TCP_NODELAY

        // 存储连接时间
        clientSocket->setProperty("connectTime", QDateTime::currentDateTime());

        // 连接信号
        connect(clientSocket, &QTcpSocket::readyRead,
                this, &LocalTCPServer::onReadyRead);
        connect(clientSocket, &QTcpSocket::disconnected,
                this, &LocalTCPServer::onDisconnected);
        connect(clientSocket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred),
                this, &LocalTCPServer::onErrorOccurred);

        // 添加到列表
        m_tcpClients.append(clientSocket);

        QString clientInfo = QString("%1:%2")
                                 .arg(clientSocket->peerAddress().toString())
                                 .arg(clientSocket->peerPort());

        qDebug() << "新客户端连接 [" << clientInfo
                 << "] 当前连接数:" << m_tcpClients.size();

        emit newClientConnected(clientSocket, clientInfo);
    }
}

void LocalTCPServer::onReadyRead()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;

    QByteArray data = clientSocket->readAll();

    // 更新最后活动时间
    clientSocket->setProperty("lastActivity", QDateTime::currentDateTime());

    qDebug() << "收到数据，大小:" << data.size() << "字节";

    emit dataReceived(clientSocket, data);

    // 处理数据
    processData(clientSocket, data);
}

void LocalTCPServer::onDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;

    QString clientInfo = QString("%1:%2")
                             .arg(clientSocket->peerAddress().toString())
                             .arg(clientSocket->peerPort());

    qDebug() << "客户端断开连接:" << clientInfo;

    m_tcpClients.removeOne(clientSocket);
    clientSocket->deleteLater();

    emit clientDisconnected(clientInfo);
}

void LocalTCPServer::onErrorOccurred(QAbstractSocket::SocketError error)
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;

    QString errorMsg = QString("客户端错误: %1").arg(clientSocket->errorString());
    qWarning() << errorMsg;

    // 对于致命错误，关闭连接
    if (error != QAbstractSocket::RemoteHostClosedError) {
        clientSocket->disconnectFromHost();
    }
}

void LocalTCPServer::handleServerError(QAbstractSocket::SocketError error)
{
    // //简单参考
    // QObject::connect(cl_tcpServer, &QTcpServer::acceptError, this,
    //                  [](QAbstractSocket::SocketError socketError) {
    //                      qDebug() << "TCP服务器接受连接错误:" << socketError;
    //                  }
    //                  );
    QString errorMsg = QString("服务器错误: %1").arg(cl_tcpServer->errorString());
    qCritical() << errorMsg;
    emit serverErrorOccurred(errorMsg);
}

void LocalTCPServer::processData(QTcpSocket *clientSocket, const QByteArray &data)
{
    // 在这里实现您的协议解析
    // 可以根据数据内容做出响应

    // 示例：简单回声服务
    // clientSocket->write(data);

    qDebug() << "收到数据:" << data.toHex() << "(" << data.size() << "字节)";
    // 如果是文本，也打印出来
    QString text = QString::fromUtf8(data);
    if (!text.isEmpty() && !text.contains(QChar::ReplacementCharacter)) {
        qDebug() << "收到文本:" << text;
    }
}
