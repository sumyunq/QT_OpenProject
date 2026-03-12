#include "FileHelper.h"

FileHelper::FileHelper(QObject *parent)
    : QObject{parent}
{}

QString FileHelper::ReadFile(QString filePath, QString fileType)
{
    if (filePath.isEmpty()) {
        return QString();   // 返回空字符串
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open file:" << filePath << file.errorString();
        return QString();
    }

    // 根据文件类型决定读取方式
    QString lowerType = fileType.removeFirst().toLower();
    if (lowerType == "text" || lowerType == "txt" || lowerType == "utf8" ||
        lowerType == "json" || lowerType == "xml" || lowerType == "html" ||
        lowerType == "qss" || lowerType == "css") {
        // 文本模式读取，使用 UTF-8 编码（可根据需要改为系统编码）
        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Encoding::Utf8);
        return stream.readAll();
    } else {
        // 二进制模式读取，转换为 Base64 字符串
        QByteArray data = file.readAll();
        return QString::fromLatin1(data.toBase64());
    }
}

bool FileHelper::loadServerConfig(QString &host, quint16 &port)
{
    // 获取配置文件路径（应用程序目录下）
    QString configPath = QCoreApplication::applicationDirPath() + "/configuration/config.ini";
    // 指定 INI 格式
    QSettings settings(configPath, QSettings::IniFormat);

    // 检查配置文件是否存在
    if (!QFile::exists(configPath)) {
        qWarning() << "配置文件不存在，使用默认值";
        // 创建一个默认配置文件
        createDefaultConfig(configPath);
    }

    // 读取 Server 节下的配置
    settings.beginGroup("Server");
    host = settings.value("host", "127.0.0.1").toString();  // 默认值
    int portInt = settings.value("port", 8080).toInt();     // 默认值
    settings.endGroup();

    // 端口范围检查
    if (portInt < 1 || portInt > 65535) {
        qWarning() << "端口号无效，使用默认值 8080";
        portInt = 8080;
    }
    port = static_cast<quint16>(portInt);

    qDebug() << "远程服务配置: host=" << host << "port=" << port;
    return true;

}

void FileHelper::createDefaultConfig(const QString &path)
{
    QSettings settings(path, QSettings::IniFormat);
    settings.beginGroup("Server");
    settings.setValue("host", "127.0.0.1");
    settings.setValue("port", 8080);
    settings.endGroup();

    settings.beginGroup("Network");
    settings.setValue("useSSL", false);
    settings.setValue("timeout", 5000);
    settings.endGroup();

    settings.sync();
    qDebug() << "已创建默认配置文件:" << path;
}
