#include "ConfigManager.h"

#include <QDebug>
#include <QTimer>

std::unique_ptr<ConfigManager> ConfigManager::m_instance = nullptr;

ConfigManager& ConfigManager::instance(const QString &iniFilePath)
{
    if (!m_instance) {
        if (iniFilePath.isEmpty()) {
            qFatal("ConfigManager instance not created yet and no iniFilePath provided!");
        }
        m_instance.reset(new ConfigManager(iniFilePath));
    }
    return *m_instance;
}

ConfigManager::ConfigManager(const QString &iniFilePath, QObject *parent)
    : QObject(parent), m_settings(iniFilePath, QSettings::IniFormat), m_iniFilePath(iniFilePath)
{
    loadAll();

    m_fileWatcher.addPath(m_iniFilePath);
    connect(&m_fileWatcher, &QFileSystemWatcher::fileChanged,
            this, &ConfigManager::onFileChanged);
}

void ConfigManager::onFileChanged(const QString &path)
{
    QTimer::singleShot(100, [this, path]() {
        qDebug() << "[ConfigManager] Detected ini file change, reloading:" << path;

        m_settings.sync();

        m_lock.lockForWrite();
        loadAll();
        m_lock.unlock();

        emit configReloaded();

        // 重新添加到 watcher
        if (!m_fileWatcher.files().contains(m_iniFilePath))
            m_fileWatcher.addPath(m_iniFilePath);
    });
}

// ====== 线程安全读取配置接口 ======
ConfigManager::ServerConfig ConfigManager::getServerConfig() {
    QReadLocker locker(&m_lock);
    return server;
}

ConfigManager::RemoteHostConfig ConfigManager::getRemoteHostConfig() {
    QReadLocker locker(&m_lock);
    return remoteHost;
}

ConfigManager::ThreadConfig ConfigManager::getThreadConfig() {
    QReadLocker locker(&m_lock);
    return thread;
}

ConfigManager::DatabaseConfig ConfigManager::getDatabaseConfig() {
    QReadLocker locker(&m_lock);
    return database;
}

ConfigManager::PathsConfig ConfigManager::getPathsConfig() {
    QReadLocker locker(&m_lock);
    return paths;
}

ConfigManager::SecurityConfig ConfigManager::getSecurityConfig() {
    QReadLocker locker(&m_lock);
    return security;
}

ConfigManager::PerformanceConfig ConfigManager::getPerformanceConfig() {
    QReadLocker locker(&m_lock);
    return performance;
}

ConfigManager::CustomConfig ConfigManager::getCustomConfig() {
    QReadLocker locker(&m_lock);
    return custom;
}

// ====== loadAll 与各模块 load 函数 ======
void ConfigManager::loadAll() {
    loadServer();
    loadRemoteHost();
    loadThread();
    loadDatabase();
    loadPaths();
    loadSecurity();
    loadPerformance();
    loadCustom();
}

void ConfigManager::loadServer() {
    m_settings.beginGroup("Server");
    server.host = m_settings.value("host", "127.0.0.1").toString();
    server.port = m_settings.value("port", 8080).toInt();
    server.maxConnections = m_settings.value("maxConnections", 1000).toInt();
    server.backlog = m_settings.value("backlog", 128).toInt();
    server.handshakeTimeout = m_settings.value("handshakeTimeout", 10000).toInt();
    server.idleTimeout = m_settings.value("idleTimeout", 300).toInt();
    server.keepAlive = m_settings.value("keepAlive", true).toBool();
    server.tcpNoDelay = m_settings.value("tcpNoDelay", true).toBool();
    m_settings.endGroup();
}

void ConfigManager::loadRemoteHost() {
    m_settings.beginGroup("RemoteHost");
    remoteHost.host = m_settings.value("host", "127.0.0.1").toString();
    remoteHost.port = m_settings.value("port", 8080).toInt();
    remoteHost.connectTimeout = m_settings.value("connectTimeout", 5000).toInt();
    remoteHost.autoReconnect = m_settings.value("autoReconnect", true).toBool();
    remoteHost.heartbeatInterval = m_settings.value("heartbeatInterval", 30).toInt();
    m_settings.endGroup();
}

void ConfigManager::loadThread() {
    m_settings.beginGroup("Thread");
    thread.poolSize = m_settings.value("poolSize", 8).toInt();
    thread.queueSize = m_settings.value("queueSize", 1000).toInt();
    m_settings.endGroup();
}

void ConfigManager::loadDatabase() {
    m_settings.beginGroup("Database");
    database.type = m_settings.value("type", "mysql").toString();
    database.host = m_settings.value("host", "localhost").toString();
    database.port = m_settings.value("port", 3306).toInt();
    database.name = m_settings.value("name", "").toString();
    database.user = m_settings.value("user", "").toString();
    database.password = m_settings.value("password", "").toString();
    database.connectionPool = m_settings.value("connectionPool", 10).toInt();
    m_settings.endGroup();
}

void ConfigManager::loadPaths() {
    m_settings.beginGroup("Paths");
    paths.uploadDir = m_settings.value("uploadDir", "/data/uploads").toString();
    paths.tempDir = m_settings.value("tempDir", "/tmp/myserver").toString();
    paths.staticDir = m_settings.value("staticDir", "/var/www/html").toString();
    m_settings.endGroup();
}

void ConfigManager::loadSecurity() {
    m_settings.beginGroup("Security");
    security.enableSSL = m_settings.value("enableSSL", false).toBool();
    security.sslCertificate = m_settings.value("sslCertificate").toString();
    security.sslPrivateKey = m_settings.value("sslPrivateKey").toString();
    security.clientAuth = m_settings.value("clientAuth", false).toBool();
    m_settings.endGroup();
}

void ConfigManager::loadPerformance() {
    m_settings.beginGroup("Performance");
    performance.socketBufferSize = m_settings.value("socketBufferSize", 65536).toInt();
    performance.cacheSize = m_settings.value("cacheSize", 256).toInt();
    performance.enableCompression = m_settings.value("enableCompression", true).toBool();
    m_settings.endGroup();
}

void ConfigManager::loadCustom() {
    m_settings.beginGroup("Custom");
    custom.debugMode = m_settings.value("debugMode", false).toBool();
    custom.apiVersion = m_settings.value("apiVersion", 1.0).toDouble();
    m_settings.endGroup();
}