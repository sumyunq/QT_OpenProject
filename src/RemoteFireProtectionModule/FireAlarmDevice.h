#ifndef FIREALARMDEVICE_H
#define FIREALARMDEVICE_H

#include <QWidget>
#include <QLineEdit>
#include <QTimer>
#include <QDateTime>
#include <QTcpServer>
#include <QTcpSocket>

#include "../ProtocolModule/GB26875ServerProtoco1.h"

namespace Ui {
class FireAlarmDevice;
}

class FireAlarmDevice : public QWidget
{
    Q_OBJECT

public:
    explicit FireAlarmDevice(QWidget *parent = nullptr);
    ~FireAlarmDevice();

    //Initialize the internal members of the object
    void InitMumbers();

    //Initialize the necessary connection signal slots
    void InitConnect();

    void setIPSourceAddress(QTcpServer *tcpServer);
    void setIPSourceAddress(QTcpSocket *tcpSocket);

    void setIPDestinationAddress(QTcpServer *tcpServer);
    void setIPDestinationAddress(QTcpSocket *tcpSocket);
    void setIPDestinationAddress(QHostAddress hostAddress,quint16 port);

    QString getDestinationAddress();


    //可以写入日志后,定期删除GB26875::GB26875DataStruct

private slots:
    void on_comboBox_cmdType_currentIndexChanged(int index);

    void on_comboBox_InfoType_currentIndexChanged(int index);

    void on_pushButton_create_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

public:
    QByteArray dataPackage;


    // QByteArray m_sourceAddress;
    QByteArray m_destinationAddress;


    QList<GB26875::GB26875DataStruct> m_GB26875Data_List;

private:
    Ui::FireAlarmDevice *ui;
    QTimer* m_updateTimer;
};

#endif // FIREALARMDEVICE_H
