#ifndef LOCALTCPSERVER_H
#define LOCALTCPSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDateTime>


class LocalTCPServer : public QObject
{
    Q_OBJECT
public:
    explicit LocalTCPServer(QObject *parent = nullptr);
    ~LocalTCPServer();

    //Initialize the internal members of the object
    void InitMumbers();

    //Initialize the necessary connection signal slots
    void InitConnect();

    void DealNewConection();

    bool StartServer(quint16 port, const QHostAddress& address = QHostAddress::Any);
    void StopServer();
    void broadcast(const QByteArray& data);

signals:
    void newClientConnected(QTcpSocket *socket, const QString& clientInfo);
    void updateList();
    void updateMessage(const QByteArray data);

    void clientDisconnected(const QString& clientInfo);
    void dataReceived(QTcpSocket *socket, const QByteArray& data);
    void serverErrorOccurred(const QString& errorString);

private slots:
    void handlePendingConnections();
    void onReadyRead();
    void onDisconnected();
    void onErrorOccurred(QAbstractSocket::SocketError error);
    void handleServerError(QAbstractSocket::SocketError error);
    void processData(QTcpSocket *clientSocket, const QByteArray& data);


public:
    QTcpServer *cl_tcpServer;
    QList<QTcpSocket*> m_tcpClients;
    int m_maxClients;//最大连接数

};

#endif // LOCALTCPSERVER_H
