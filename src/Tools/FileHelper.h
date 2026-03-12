#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QDebug>
#include <QSettings>
#include <QCoreApplication>

class FileHelper : public QObject
{
    Q_OBJECT
public:
    explicit FileHelper(QObject *parent = nullptr);
    QString ReadFile(QString filePath,QString fileType =".txt");

    static bool loadServerConfig(QString& host, quint16& port);
    static void createDefaultConfig(const QString& path);
signals:


};

#endif // FILEHELPER_H
