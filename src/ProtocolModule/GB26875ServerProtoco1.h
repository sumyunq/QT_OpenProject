#ifndef GB26875SERVERPROTOCO1_H
#define GB26875SERVERPROTOCO1_H

#include <QObject>
#include <QBitArray>
#include <QByteArray>
#include <QVariant>

//GB26875具体的信息对象
namespace GB26875{
namespace InformationObject{
//低字节传输在前 由 本地保证(换句话说，在本地就应该保证数据按低字节在前进行存储,不要延迟到数据报拼接过程,解析到本地同理)
//信息类型: 0~255
//1：上传建筑消防设施系统状态(10字节=1+1+2+6))
typedef struct UploadBuildingFireProtectionFacilitySystemStatus{
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
    //系统状态 2字节 低字节传输在前 对应位数据的作用请参照数据报详细说明
    QByteArray systemStatus;
    //系统状态发送时间 6字节
    QByteArray systemStatusSendingTime;
}InformationType_001;

//2：上传建筑消防设施部件运行状态(46字节 = 1 + 1 + 1 + 4 + 2 + 31 +6)
typedef struct UploadBuildingFireProtectionEquipmentComponentsOperatingStatus{
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
    //部件类型 1字节 表示的具体类型请参照数据报详细说明
    QByteArray componentType;
    //部件地址 4字节
    QByteArray componentAddress;
    //部件状态 2字节 低字节传输在前 对应位数据的作用请参照数据报详细说明
    QByteArray componentStatus;
    //部件说明 31字节
    QByteArray componentDescription;
    //部件状态发送时间 6字节
    QByteArray componentsOperatingStatusSendingTime;
}InformationType_002;

//3：上传建筑消防设施部件模拟量值（16字节 = 1 + 1 + 1 + 4 + 1 + 2 +6）
typedef struct UploadBuildingFireProtectionFacilitiesComponentsAnalogValues{
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
    //部件类型 1字节 表示的具体类型请参照数据报详细说明
    QByteArray componentType;
    //部件地址 4字节
    QByteArray componentAddress;
    //模拟量类型 1字节 具体类型请参照数据报详细说明
    QByteArray AnalogType;
    //模拟量采样时间 6字节
    QByteArray AnalogValuesSamplingTime;
}InformationType_003;

//4：上传建筑消防设施操作信息记录（10字节 = 1 + 1 + 1 + 1 +6）
typedef struct UploadBuildingFireProtectionFacilitiesOperationInformationRecord{
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
    //操作信息 1字节
    QByteArray operationInformation;
    //操作员编号 1字节
    QByteArray operatorNumber;
    //操作记录时间 6字节
    QByteArray OperationInformationRecordTime;
}InformationType_004;

//5：上传建筑消防设施软件版本（4字节 = 1 + 1 +1 +1）
typedef struct UploadBuildingFireProtectionFacilitiesSoftwareVersion{
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
    //软件 主版本号 1字节
    QByteArray softwareMajorVersionNumber;
    //软件 次版本号 1字节
    QByteArray softwareMinorVersionNumber;
}InformationType_005;

//6：上传建筑消防设施系统配置情况（ 3 + L 字节 =  1 + 1 + 1  +  L）
typedef struct UploadBuildingFireProtectionFacilitiesSystemConfigurationdetails {
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
    //系统说明长度 1字节
    QByteArray systemDescriptionLength;
    //系统说明 L字节
    QByteArray systemDescription;
}InformationType_006;

//7：上传建筑消防设施部件配置情况（36字节 = 1 +1 + 1 + 4 + 31  ）
typedef struct UploadBuildingFireProtectionFacilitiesComponentsConfigurationdetails {
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
    //部件类型 1字节 表示的具体类型请参照数据报详细说明
    QByteArray componentType;
    //部件地址 4字节
    QByteArray componentAddress;
    //部件说明 31字节
    QByteArray componentDescription;
}InformationType_007;

//8：上传建筑消防设施系统时间（8字节=1 + 1 + 6）
typedef struct UploadBuildingFireProtectionFacilitiesSystemTime{
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
    //建筑消防设施的系统时间 6字节
    QByteArray systemTime;
}InformationType_008;

//21：上传用户信息传输装置运行状态（7字节 = 1 + 6）
typedef struct UploadUserInformationTransmissionDeviceOperatingStatus{
    //状态 1字节
    QByteArray operatingStatus;
    //状态发生时间 6字节
    QByteArray stateOccurrenceTime;
}InformationType_021;

//24：上传用户信息传输装置操作信息记录（8字节 = 1 + 1 + 6）
typedef struct UploadUserInformationTransmissionDeviceOperatingInformationRecord {
    //操作信息 1字节
    QByteArray operationInformation;
    //操作员编号 1字节
    QByteArray operatorNumber;
    //操作的记录时间 6字节
    QByteArray operationRecordingTime;
}InformationType_024;

//25：上传用户信息传输装置软件版本（2字节 = 2）
typedef struct UploadUserInformationTransmissionDeviceSoftwareVersion{
    //软件版本号 2字节
    QByteArray SoftwareVersionNumber;
}InformationType_025;

//26：上传用户信息传输装置配置情况（1+L字节 = 1 + L）
typedef struct UploadUserInformationTransmissionDeviceConfigurationDescription{
    //配置说明长度 1字节
    QByteArray configurationDescriptionLength;
    //配置说明 L字节
    QByteArray configurationDescription;
}InformationType_026;


//28：上传用户信息传输装置系统时间（6字节 = 6）
typedef struct UploadUserInformationTransmissionDeviceSystemTime{
    //用户信息传输装置的系统时间 6字节
    QByteArray SystemTime;
}InformationType_028;

//61：读建筑消防设施系统状态（2字节 = 1 + 1）
typedef struct DownloadBuildingFireProtectionFacilitySystemStatus{
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
}InformationType_061;

//62：读建筑消防设施系统部件状态（6字节 = 1 + 1 + 4）
typedef struct DownloadBuildingFireProtectionEquipmentComponentsOperatingStatus{
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
    //部件地址 4字节
    QByteArray componentAddress;
}InformationType_062;

//63：读建筑消防设施部件模拟量值（6字节 = 1 + 1 + 4）
typedef struct DownloadBuildingFireProtectionFacilitiesComponentsAnalogValues{
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
    //部件地址 4字节
    QByteArray componentAddress;
}InformationType_063;

//64：读建筑消防设施操作信息记录（9字节 = 1 + 1 + 1 + 6）
typedef struct DownloadBuildingFireProtectionFacilitiesOperationInformationRecord{
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
    //查询操作信息记录数目：1字节
    QByteArray recordCount;
    //查询记录的指定起始时间：6字节
    QByteArray startTime;
}InformationType_064;

//65：读建筑消防设施软件版本（2字节 = 1 + 1 ）
typedef struct DownloadBuildingFireProtectionFacilitiesSoftwareVersion{
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
}InformationType_065;

//66：读建筑消防设施系统配置情况（2字节 = 1 + 1）
typedef struct DownloadBuildingFireProtectionFacilitiesSystemConfigurationdetails {
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
}InformationType_066;

//67：读建筑消防设施部件配置情况（6字节 = 1 + 1 + 4）
typedef struct DownloadBuildingFireProtectionFacilitiesComponentsConfigurationdetails {
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
    //部件地址 4字节
    QByteArray componentAddress;
}InformationType_067;

//68：读建筑消防设施系统时间（2字节 = 1 + 1）
typedef struct DownloadBuildingFireProtectionFacilitiesSystemTime{
    //系统类型 1字节
    QByteArray systemType;
    //系统地址 1字节
    QByteArray systemAddress;
}InformationType_068;

//81：读用户信息传输装置运行状态（1字节 = 1）
typedef struct DownloadUserInformationTransmissionDeviceOperatingStatus{
    //预留 1字节
    QByteArray ooo;
}InformationType_081;

//84：读用户信息传输装置操作信息记录（7字节 = 1 + 6）
typedef struct DownloadUserInformationTransmissionDeviceOperatingInformationRecord {
    //查询操作信息记录数目 1字节
    QByteArray recordCount;
    //查询记录的指定起始时间 6字节
    QByteArray startTime;
}InformationType_084;

//85：读用户信息传输装置软件版本（1字节 = 1）
typedef struct DownloadUserInformationTransmissionDeviceSoftwareVersion{
    //预留 1字节
    QByteArray ooo;
}InformationType_085;

//86：读用户信息传输装置配置情况（1字节 = 1）
typedef struct DownloadUserInformationTransmissionDeviceConfigurationDescription{
    //预留 1字节
    QByteArray ooo;
}InformationType_086;

//88：读用户信息传输装置系统时间（1字节 = 1）
typedef struct DownloadUserInformationTransmissionDeviceSystemTime{
    //预留 1字节
    QByteArray ooo;
}InformationType_088;

//89：初始化用户信息传输装置（1字节 = 1）
typedef struct InitializationUserInformationTransmissionDevice{
    //预留 1字节
    QByteArray ooo;
}InformationType_089;

//90：同步用户信息传输装置时间（6字节 =  6）
typedef struct SynchronizeUserInformationTransmissionDeviceTime{
    //中心系统时间：6字节
    QByteArray centralSystemTime;
}InformationType_090;

//91：查岗命令（1字节 =1）
typedef struct InspectionOrder{
    //查岗应答超时设定时间（单位：min）：1字节
    QByteArray timeoutSettingTime;
}InformationType_091;

}


typedef struct GB26875DataStruct{

    //注：本地保存原始数据,combinationInfo时再修正字节顺序（部分数据要求低字节在前）
    //启动符号 2字节 "@@"
    QByteArray startSymbol;

    //控制单元 25字节
    //业务流水号 2字节
    QByteArray businessTransactionSerialNumber;
    //协议版本号 2字节
    QByteArray protocolVersionNumber;
    //时间标签 6字节
    QByteArray timeLabel;
    //源地址 6字节 低字节在前
    QByteArray sourceAddress;
    //目的地址 6字节 低字节在前I'n'fa'ma
    QByteArray destinationAddress;
    //应用数据单元长度 2字节 低字节在前
    QByteArray applicationDataUnitLength;
    //命令字节 1字节 二进制数 具体请参照数据报说明 00~ff
    QByteArray commandByte;

    //应用数据单元 最大1024字节 ( 1 + 1 + n * SingleLength )
    //数据对象类型 1字节 具体请参照数据报说明(类型标识)
    QByteArray dataObjectType;
    //数据对象数目 1字节 对应n
    QByteArray dataObjectCount;

    //具体的信息数据对象
    QList<QVariant> dataInfo_list;

    //校验和 1字节
    QByteArray checksum;

    //结束符号 2字节 "##"
    QByteArray endMark;

    GB26875DataStruct(){
        startSymbol.resize(2);
        startSymbol[0] = 0x40;
        startSymbol[1] = 0x40;

        //这种快一点
        businessTransactionSerialNumber = QByteArray(2,0x00);

        protocolVersionNumber.resize(2);
        protocolVersionNumber.fill(0x00);//resize后默认随机值

        timeLabel.resize(6);
        timeLabel.fill(0x00);

        sourceAddress.resize(6);
        sourceAddress.fill(0x00);

        destinationAddress.resize(6);
        destinationAddress.fill(0x00);

        applicationDataUnitLength.resize(2);
        applicationDataUnitLength.fill(0x00);

        commandByte.resize(1);
        commandByte.fill(0x00);

        dataObjectType.resize(1);
        dataObjectType.fill(0x00);

        dataObjectCount.resize(1);
        dataObjectCount.fill(0x00);

        checksum.resize(1);
        checksum.fill(0x00);

        endMark.resize(2);
        endMark[0] = 0x23;
        endMark[1] = 0x23;
    };

    //根据类型标志，封装数据对象
    QByteArray toByteArry(int commandType = 0);
    QByteArray combinationInfo();

}GB26875DataStruct;

};

// 注册结构体到 Qt 元类型系统
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_001)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_002)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_003)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_004)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_005)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_006)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_007)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_008)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_021)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_024)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_025)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_026)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_028)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_061)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_062)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_063)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_064)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_065)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_066)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_067)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_068)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_081)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_084)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_085)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_086)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_088)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_089)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_090)
Q_DECLARE_METATYPE(GB26875::InformationObject::InformationType_091)

class GB26875ServerProtoco1 : public QObject
{
    Q_OBJECT
public:
    explicit GB26875ServerProtoco1(QObject *parent = nullptr);

    //编码
    void Encoder(GB26875::GB26875DataStruct data);
    //解码
    GB26875::GB26875DataStruct Decode();

signals:
};

#endif // GB26875SERVERPROTOCO1_H
