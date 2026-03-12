#ifndef LOCALTCPCLIENT_H
#define LOCALTCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDateTime>
#include <QTimer>
#include <QDebug>

class LocalTCPClient : public QObject
{
    Q_OBJECT
public:
    explicit LocalTCPClient(QObject *parent = nullptr);
    ~LocalTCPClient();

    // 连接管理
    bool connectToServer(const QString& host, quint16 port);
    void disconnectFromServer();
    bool isConnected() const;

    // 数据发送
    qint64 sendData(const QByteArray& data);
    qint64 sendText(const QString& text);

    // 获取信息
    QString getServerInfo() const;
    QAbstractSocket::SocketState getState() const;
    QString getStateString() const;

    const QTcpSocket* getTCPSocket();


public slots:
    void reconnect();  // 重连

signals:
    // 连接状态信号
    void connected();
    void disconnected();
    void connectionError(const QString& error);

    // 数据信号
    void dataReceived(const QByteArray& data);
    void dataSent(qint64 bytes);

    // 状态信号
    void stateChanged(QAbstractSocket::SocketState state);


private slots:
    void onConnected();
    void onDisconnected();
    void onReadyRead();
    void onErrorOccurred(QAbstractSocket::SocketError socketError);
    void onStateChanged(QAbstractSocket::SocketState state);
    void onBytesWritten(qint64 bytes);

private:
    QTcpSocket *m_socket;
    QString m_host;
    quint16 m_port;
    QTimer *m_reconnectTimer;
    int m_reconnectAttempts;
    static const int MAX_RECONNECT_ATTEMPTS = 5;
    static const int RECONNECT_INTERVAL = 3000;  // 3秒

};

#endif // LOCALTCPCLIENT_H
