#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QObject>
#include <QSettings>
#include <QString>
#include <QFileSystemWatcher>
#include <QReadWriteLock>
#include <memory>

class ConfigManager : public QObject
{
    Q_OBJECT
public:
    static ConfigManager& instance(const QString &iniFilePath = QString());

    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    // ==== 配置结构体 ====
    struct ServerConfig {
        QString host;
        int port;
        int maxConnections;
        int backlog;
        int handshakeTimeout;
        int idleTimeout;
        bool keepAlive;
        bool tcpNoDelay;
    };

    struct RemoteHostConfig {
        QString host;
        int port;
        int connectTimeout;
        bool autoReconnect;
        int heartbeatInterval;
    };
    struct ThreadConfig {
        int poolSize;
        int queueSize;
    };
    struct DatabaseConfig {
        QString type;
        QString host;
        int port;
        QString name;
        QString user;
        QString password;
        int connectionPool;
    };
    struct PathsConfig {
        QString uploadDir;
        QString tempDir;
        QString staticDir;
    };
    struct SecurityConfig {
        bool enableSSL;
        QString sslCertificate;
        QString sslPrivateKey;
        bool clientAuth; };
    struct PerformanceConfig {
        int socketBufferSize;
        int cacheSize;
        bool enableCompression;
    };
    struct CustomConfig {
        bool debugMode;
        double apiVersion;
    };

    // 线程安全访问函数
    ServerConfig getServerConfig();
    RemoteHostConfig getRemoteHostConfig();
    ThreadConfig getThreadConfig();
    DatabaseConfig getDatabaseConfig();
    PathsConfig getPathsConfig();
    SecurityConfig getSecurityConfig();
    PerformanceConfig getPerformanceConfig();
    CustomConfig getCustomConfig();

signals:
    void configReloaded(); // 配置热加载后触发

private slots:
    void onFileChanged(const QString &path);

private:
    explicit ConfigManager(const QString &iniFilePath, QObject *parent = nullptr);
    static std::unique_ptr<ConfigManager> m_instance;

    QSettings m_settings;
    QFileSystemWatcher m_fileWatcher;
    QString m_iniFilePath;

    // 配置实例
    ServerConfig server;
    RemoteHostConfig remoteHost;
    ThreadConfig thread;
    DatabaseConfig database;
    PathsConfig paths;
    SecurityConfig security;
    PerformanceConfig performance;
    CustomConfig custom;

    QReadWriteLock m_lock; // 读写锁

    void loadAll();
    void loadServer();
    void loadRemoteHost();
    void loadThread();
    void loadDatabase();
    void loadPaths();
    void loadSecurity();
    void loadPerformance();
    void loadCustom();
};

#endif // CONFIGMANAGER_H
