#ifndef GB26875SERVERMODE_H
#define GB26875SERVERMODE_H

#include <QWidget>
#include <QStringListModel>

#include "../Tools/ConfigManager.h"
#include "../RemoteFireProtectionModule/FireAlarmDevice.h"
#include "../NetWorkModule/LocalTCPServer.h"
#include "../NetWorkModule/LocalTCPClient.h"

namespace Ui {
class GB26875ServerMode;
}

class GB26875ServerMode : public QWidget
{
    Q_OBJECT

public:
    explicit GB26875ServerMode(QWidget *parent = nullptr);
    ~GB26875ServerMode();

    //
    void InitMumbers();
    //
    void InitConnect();
    //
    void InitUIInformation();

    void updateListView();


public:
    FireAlarmDevice* clp_fireAlarmDevice;

    LocalTCPServer* cl_localTcpServer;//本地做服务器，用于通信
    LocalTCPClient* cl_localTcpClient;//用于连接远程服务器(如果有)

    QStringListModel *connect_list_model;

private:
    Ui::GB26875ServerMode *ui;
};

#endif // GB26875SERVERMODE_H
