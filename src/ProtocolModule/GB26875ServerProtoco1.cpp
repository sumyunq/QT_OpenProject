#include "GB26875ServerProtoco1.h"

GB26875ServerProtoco1::GB26875ServerProtoco1(QObject *parent)
    : QObject{parent}
{}

QByteArray GB26875::GB26875DataStruct::toByteArry(int commandType)
{
    // using namespace GB26875::InformationObject;
    // qDebug() <<"命令类型 " << commandType << "数据大小"<<dataInfo_list.size();
    QByteArray retByteArray;
    switch (commandType) {
    case 0:  // 预留
    {   return retByteArray;
    };
    case 1:  // 1：上传建筑消防设施系统状态(10字节=1+1+2+6))
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_001>()) {
                GB26875::InformationObject::InformationType_001 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_001>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
                std::reverse(info.systemStatus.begin(), info.systemStatus.end());//低字节传输在前
                retByteArray.append(info.systemStatus);
                retByteArray.append(info.systemStatusSendingTime);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 2:  // 2：上传建筑消防设施部件运行状态(46字节 = 1 + 1 + 1 + 4 + 2 + 31 +6)
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_002>()) {
                GB26875::InformationObject::InformationType_002 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_002>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
                retByteArray.append(info.componentType);
                retByteArray.append(info.componentAddress);
                std::reverse(info.componentStatus.begin(), info.componentStatus.end());
                retByteArray.append(info.componentStatus);
                retByteArray.append(info.componentDescription);
                retByteArray.append(info.componentsOperatingStatusSendingTime);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 3:  // 3：上传建筑消防设施部件模拟量值（16字节 = 1 + 1 + 1 + 4 + 1 + 2 +6）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_003>()) {
                GB26875::InformationObject::InformationType_003 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_003>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
                retByteArray.append(info.componentType);
                retByteArray.append(info.componentAddress);
                retByteArray.append(info.AnalogType);
                retByteArray.append(info.AnalogValuesSamplingTime);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 4:  // 4：上传建筑消防设施操作信息记录（10字节 = 1 + 1 + 1 + 1 +6）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_004>()) {
                GB26875::InformationObject::InformationType_004 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_004>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
                retByteArray.append(info.operationInformation);
                retByteArray.append(info.operatorNumber);
                retByteArray.append(info.OperationInformationRecordTime);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 5:  //5：上传建筑消防设施软件版本（4字节 = 1 + 1 +1 +1）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_005>()) {
                GB26875::InformationObject::InformationType_005 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_005>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
                retByteArray.append(info.softwareMajorVersionNumber);
                retByteArray.append(info.softwareMinorVersionNumber);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 6:  // 6：上传建筑消防设施系统配置情况（ 3 + L 字节 =  1 + 1 + 1  +  L）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_006>()) {
                GB26875::InformationObject::InformationType_006 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_006>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
                retByteArray.append(info.systemDescriptionLength);
                retByteArray.append(info.systemDescription);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 7:  // 7：上传建筑消防设施部件配置情况（36字节 = 1 +1 + 1 + 4 + 31  ）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_007>()) {
                GB26875::InformationObject::InformationType_007 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_007>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
                retByteArray.append(info.componentType);
                retByteArray.append(info.componentAddress);
                retByteArray.append(info.componentDescription);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 8:  // 8：上传建筑消防设施系统时间（8字节=1 + 1 + 6）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_008>()) {
                GB26875::InformationObject::InformationType_008 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_008>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
                retByteArray.append(info.systemTime);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 21:  // 21：上传用户信息传输装置运行状态（7字节 = 1 + 6）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_021>()) {
                GB26875::InformationObject::InformationType_021 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_021>();
                retByteArray.append(info.operatingStatus);
                retByteArray.append(info.stateOccurrenceTime);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 24:  // 24：上传用户信息传输装置操作信息记录（8字节 = 1 + 1 + 6）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_024>()) {
                GB26875::InformationObject::InformationType_024 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_024>();
                retByteArray.append(info.operationInformation);
                retByteArray.append(info.operatorNumber);
                retByteArray.append(info.operationRecordingTime);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 25:  // 25：上传用户信息传输装置软件版本（2字节 = 2）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_025>()) {
                GB26875::InformationObject::InformationType_025 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_025>();
                retByteArray.append(info.SoftwareVersionNumber);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 26:  // 26：上传用户信息传输装置配置情况（1+L字节 = 1 + L）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_026>()) {
                GB26875::InformationObject::InformationType_026 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_026>();
                retByteArray.append(info.configurationDescriptionLength);
                retByteArray.append(info.configurationDescription);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 28:  // 28：上传用户信息传输装置系统时间（6字节 = 6）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_028>()) {
                GB26875::InformationObject::InformationType_028 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_028>();
                retByteArray.append(info.SystemTime);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 61:  // 61：读建筑消防设施系统状态（2字节 = 1 + 1）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_061>()) {
                GB26875::InformationObject::InformationType_061 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_061>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 62:  // 62：读建筑消防设施系统部件状态（6字节 = 1 + 1 + 4）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_062>()) {
                GB26875::InformationObject::InformationType_062 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_062>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
                retByteArray.append(info.componentAddress);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 63:  // 63：读建筑消防设施部件模拟量值（6字节 = 1 + 1 + 4）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_063>()) {
                GB26875::InformationObject::InformationType_063 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_063>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
                retByteArray.append(info.componentAddress);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 64:  // 64：读建筑消防设施操作信息记录（9字节 = 1 + 1 + 1 + 6）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_064>()) {
                GB26875::InformationObject::InformationType_064 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_064>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
                retByteArray.append(info.recordCount);
                retByteArray.append(info.startTime);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 65:  // 65：读建筑消防设施软件版本（2字节 = 1 + 1 ）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_065>()) {
                GB26875::InformationObject::InformationType_065 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_065>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 66:  // 66：读建筑消防设施系统配置情况（2字节 = 1 + 1）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_066>()) {
                GB26875::InformationObject::InformationType_066 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_066>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 67:  // 67：读建筑消防设施部件配置情况（6字节 = 1 + 1 + 4）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_067>()) {
                GB26875::InformationObject::InformationType_067 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_067>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
                retByteArray.append(info.componentAddress);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 68:  // 68：读建筑消防设施系统时间（2字节 = 1 + 1）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_068>()) {
                GB26875::InformationObject::InformationType_068 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_068>();
                retByteArray.append(info.systemType);
                retByteArray.append(info.systemAddress);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 81:  // 81：读用户信息传输装置运行状态（1字节 = 1）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_081>()) {
                GB26875::InformationObject::InformationType_081 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_081>();
                retByteArray.append(info.ooo);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 84:  // 84：读用户信息传输装置操作信息记录（7字节 = 1 + 6）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_084>()) {
                GB26875::InformationObject::InformationType_084 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_084>();
                retByteArray.append(info.recordCount);
                retByteArray.append(info.startTime);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 85:  // 85：读用户信息传输装置软件版本（1字节 = 1）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_085>()) {
                GB26875::InformationObject::InformationType_085 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_085>();
                retByteArray.append(info.ooo);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 86:  // 86：读用户信息传输装置配置情况（1字节 = 1）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_086>()) {
                GB26875::InformationObject::InformationType_086 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_086>();
                retByteArray.append(info.ooo);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 88:  // 88：读用户信息传输装置系统时间（1字节 = 1）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_088>()) {
                GB26875::InformationObject::InformationType_088 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_088>();
                retByteArray.append(info.ooo);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 89:  // 89：初始化用户信息传输装置（1字节 = 1）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_089>()) {
                GB26875::InformationObject::InformationType_089 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_089>();
                retByteArray.append(info.ooo);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 90:  // 同步用户信息传输装置时间（6字节 =  6）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_090>()) {
                GB26875::InformationObject::InformationType_090 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_090>();
                retByteArray.append(info.centralSystemTime);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    case 91:  // 同步用户信息传输装置时间（6字节 =  6）
    {
        for (int i = 0; i < dataInfo_list.size(); ++i) {
            if (dataInfo_list[i].canConvert<GB26875::InformationObject::InformationType_091>()) {
                GB26875::InformationObject::InformationType_091 info = dataInfo_list[i].value<GB26875::InformationObject::InformationType_091>();
                retByteArray.append(info.timeoutSettingTime);
            } else {
                qDebug() << __FUNCTION__ << " "<< __LINE__ <<"索引 " << i << " 是其他类型:" << dataInfo_list[i];
            }
        }
        return retByteArray;
    };
    default:
    {
        qDebug() << "未知类型,请检查数据结构是否注册";
        break;
    }
    }
    return retByteArray;
}

QByteArray GB26875::GB26875DataStruct::combinationInfo()
{
    QByteArray dataPackage;
    //启动符号 2字节
    dataPackage.append(startSymbol);

    //控制单元 25字节
    //业务流水号 2字节
    dataPackage.append(businessTransactionSerialNumber);
    //协议版本号 2字节
    dataPackage.append(protocolVersionNumber);
    //时间标签 6字节
    dataPackage.append(timeLabel);
    //源地址 6字节 低字节在前
    QByteArray tmp_sourceAddress = sourceAddress;//做法一:构造新QByteArray对象,保证原字节数据不变
    std::reverse(tmp_sourceAddress.begin(), tmp_sourceAddress.end());
    dataPackage.append(tmp_sourceAddress);

    //目的地址 6字节 低字节在前
    std::reverse(destinationAddress.begin(), destinationAddress.end());//做法二:两遍反转置换,减少构造开销
    dataPackage.append(destinationAddress);
    std::reverse(destinationAddress.begin(), destinationAddress.end());

    //应用数据单元 2字节 低字节在前
    std::reverse(applicationDataUnitLength.begin(), applicationDataUnitLength.end());//做法二:两遍反转置换,减少构造开销
    dataPackage.append(applicationDataUnitLength);
    std::reverse(applicationDataUnitLength.begin(), applicationDataUnitLength.end());

    //命令字节 1字节 二进制数 具体请参照数据报说明 00~ff
    dataPackage.append(commandByte);

    //应用数据单元 最大1024字节 ( 1 + 1 + n * SingleLength )
    //数据对象类型 1字节 具体请参照数据报说明
    dataPackage.append(dataObjectType);
    //数据对象数目 1字节 对应n
    dataPackage.append(dataObjectCount);

    bool ok;
    dataPackage.append(toByteArry(dataObjectType.toHex().toInt(&ok, 16)));

    //校验和 1字节
    dataPackage.append(checksum);
    //结束符号 2字节 "##"
    dataPackage.append(endMark);

    return dataPackage;
}

void GB26875ServerProtoco1::Encoder(GB26875::GB26875DataStruct data)
{
    //先判断命令类型
    switch (data.commandByte[1]) {
    case 0x00:  // 预留
    {   };
    case 0x01:  // 控制命令
    {   };
    case 0x02:  // 发送数据
    {

    };
    case 0x03:  // 确认
    {

    };
    case 0x04:  // 请求
    {

    };
    case 0x05:  // 应答
    {

    };
    case 0x06:  // 否认
    {

    };
    default:
    {
        qDebug() << "未知命令";
        break;
    }
    }
}


