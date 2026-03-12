#include "LocalTCPClient.h"

LocalTCPClient::LocalTCPClient(QObject *parent)
    : QObject(parent)
    , m_socket(nullptr)
    , m_port(0)
    , m_reconnectTimer(nullptr)
    , m_reconnectAttempts(0) {

    // 创建 socket
    m_socket = new QTcpSocket(this);

    // 连接信号
    connect(m_socket, &QTcpSocket::connected, this, &LocalTCPClient::onConnected);
    connect(m_socket, &QTcpSocket::disconnected, this, &LocalTCPClient::onDisconnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &LocalTCPClient::onReadyRead);
    connect(m_socket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred),
            this, &LocalTCPClient::onErrorOccurred);
    connect(m_socket, &QTcpSocket::stateChanged, this, &LocalTCPClient::onStateChanged);
    connect(m_socket, &QTcpSocket::bytesWritten, this, &LocalTCPClient::onBytesWritten);

    // 创建重连定时器
    m_reconnectTimer = new QTimer(this);
    m_reconnectTimer->setInterval(RECONNECT_INTERVAL);
    m_reconnectTimer->setSingleShot(true);
    connect(m_reconnectTimer, &QTimer::timeout, this, &LocalTCPClient::reconnect);
}

LocalTCPClient::~LocalTCPClient() {
    disconnectFromServer();
}

bool LocalTCPClient::connectToServer(const QString& host, quint16 port) {
    if (isConnected()) {
        qWarning() << "已经连接到服务器，请先断开";
        return false;
    }

    m_host = host;
    m_port = port;
    m_reconnectAttempts = 0;

    qDebug() << "正在连接到服务器:" << host << ":" << port;
    m_socket->connectToHost(host, port);

    return true;
}

void LocalTCPClient::disconnectFromServer() {
    if (m_socket && m_socket->state() != QAbstractSocket::UnconnectedState) {
        m_socket->disconnectFromHost();

        // 等待断开完成
        if (m_socket->state() != QAbstractSocket::UnconnectedState) {
            m_socket->waitForDisconnected(3000);
        }
    }

    m_reconnectTimer->stop();
    m_reconnectAttempts = 0;
}

bool LocalTCPClient::isConnected() const {
    return m_socket && m_socket->state() == QAbstractSocket::ConnectedState;
}

qint64 LocalTCPClient::sendData(const QByteArray& data) {
    if (!isConnected()) {
        qWarning() << "未连接到服务器，无法发送数据";
        return -1;
    }

    qint64 bytes = m_socket->write(data);
    if (bytes > 0) {
        m_socket->flush();
        qDebug() << "发送数据:" << data.toHex() << "(" << bytes << "字节)";
    }

    return bytes;
}

qint64 LocalTCPClient::sendText(const QString& text) {
    QByteArray data = text.toUtf8();
    return sendData(data);
}

QString LocalTCPClient::getServerInfo() const {
    if (!m_socket) return "未连接";

    return QString("%1:%2")
        .arg(m_socket->peerAddress().toString())
        .arg(m_socket->peerPort());
}

QAbstractSocket::SocketState LocalTCPClient::getState() const {
    return m_socket ? m_socket->state() : QAbstractSocket::UnconnectedState;
}

QString LocalTCPClient::getStateString() const {
    switch (getState()) {
    case QAbstractSocket::UnconnectedState: return "未连接";
    case QAbstractSocket::HostLookupState: return "正在查找主机";
    case QAbstractSocket::ConnectingState: return "正在连接";
    case QAbstractSocket::ConnectedState: return "已连接";
    case QAbstractSocket::BoundState: return "已绑定";
    case QAbstractSocket::ClosingState: return "正在关闭";
    case QAbstractSocket::ListeningState: return "监听中";
    default: return "未知状态";
    }
}

const QTcpSocket* LocalTCPClient::getTCPSocket()
{
    return this->m_socket;
}

void LocalTCPClient::reconnect() {
    if (m_reconnectAttempts >= MAX_RECONNECT_ATTEMPTS) {
        qWarning() << "重连次数已达到最大限制" << MAX_RECONNECT_ATTEMPTS;
        emit connectionError("重连失败，已达到最大尝试次数");
        return;
    }

    m_reconnectAttempts++;
    qDebug() << "尝试重连第" << m_reconnectAttempts << "次...";

    if (m_socket->state() == QAbstractSocket::UnconnectedState) {
        m_socket->connectToHost(m_host, m_port);
    }
}

// 私有槽函数实现
void LocalTCPClient::onConnected() {
    qDebug() << "成功连接到服务器:" << getServerInfo();
    m_reconnectAttempts = 0;
    emit connected();
}

void LocalTCPClient::onDisconnected() {
    qDebug() << "与服务器断开连接";
    emit disconnected();
}

void LocalTCPClient::onReadyRead() {
    QByteArray data = m_socket->readAll();
    qDebug() << "收到数据:" << data.toHex() << "(" << data.size() << "字节)";

    // 如果是文本，也打印出来
    QString text = QString::fromUtf8(data);
    if (!text.isEmpty() && !text.contains(QChar::ReplacementCharacter)) {
        qDebug() << "收到文本:" << text;
    }

    emit dataReceived(data);
}

void LocalTCPClient::onErrorOccurred(QAbstractSocket::SocketError socketError) {
    QString errorString = m_socket->errorString();
    qWarning() << "Socket错误:" << socketError << "-" << errorString;

    emit connectionError(errorString);

    // 根据错误类型决定是否重连
    switch (socketError) {
    case QAbstractSocket::ConnectionRefusedError:
    case QAbstractSocket::RemoteHostClosedError:
    case QAbstractSocket::HostNotFoundError:
    case QAbstractSocket::SocketTimeoutError:
    case QAbstractSocket::NetworkError:
        // 这些错误可以尝试重连
        if (!m_reconnectTimer->isActive()) {
            m_reconnectTimer->start();
        }
        break;

    default:
        // 其他错误不自动重连
        break;
    }
}

void LocalTCPClient::onStateChanged(QAbstractSocket::SocketState state) {
    qDebug() << "本机 Socket状态变化:" << getStateString();
    emit stateChanged(state);
}

void LocalTCPClient::onBytesWritten(qint64 bytes) {
    qDebug() << "已发送" << bytes << "字节";
    emit dataSent(bytes);
}
