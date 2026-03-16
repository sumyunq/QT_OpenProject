#ifndef GB26875CLIENTMODE_H
#define GB26875CLIENTMODE_H

#include <QWidget>

#include "../Tools/ConfigManager.h"
#include "../RemoteFireProtectionModule/FireAlarmDevice.h"
#include "../NetWorkModule/LocalTCPServer.h"
#include "../NetWorkModule/LocalTCPClient.h"


namespace Ui {
class GB26875ClientMode;
}

class GB26875ClientMode : public QWidget
{
    Q_OBJECT

public:
    explicit GB26875ClientMode(QWidget *parent = nullptr);
    ~GB26875ClientMode();
    //
    void InitMumbers();
    //
    void InitConnect();
    //
    void InitUIInformation();
public:
    FireAlarmDevice* clp_fireAlarmDevice;

    LocalTCPServer* cl_localTcpServer;//本地做服务器，用于通信
    LocalTCPClient* cl_localTcpClient;//用于连接远程服务器(如果有)

private slots:
    void on_pushButton_ConnectToServer_clicked();

    void on_pushButton_disConnect_clicked();

    void on_pushButton_sendToServer_clicked();

private:
    Ui::GB26875ClientMode *ui;
};

#endif // GB26875CLIENTMODE_H
