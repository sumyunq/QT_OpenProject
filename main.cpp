#include "MainWindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <Q3DBars>

#include "./src/Tools/ConfigManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Servers_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    a.setWindowIcon(QIcon(":/img/resources/images/wbliu.png"));
    ConfigManager& config = ConfigManager::instance(QCoreApplication::applicationDirPath()+"/configuration/config.ini");

    QObject::connect(&config, &ConfigManager::configReloaded, [](){
        qDebug() << "[ConfigManager] 配置已热加载!";
    });

    auto serverConfig = config.getServerConfig();
    qDebug() << "Server Host:" << serverConfig.host;
    qDebug() << "Server Port:" << serverConfig.port;
    MainWindow w;
    w.show();


    // qputenv("QSG_RHI_BACKEND", "opengl");
    // QGuiApplication app(argc, argv);

    // Q3DBars bars;
    // bars.setFlags(bars.flags() ^ Qt::FramelessWindowHint);
    // bars.rowAxis()->setRange(0, 4);
    // bars.columnAxis()->setRange(0, 4);
    // QBar3DSeries *series = new QBar3DSeries;
    // QBarDataRow *data = new QBarDataRow;
    // *data << 1.0f << 3.0f << 7.5f << 5.0f << 2.2f;
    // series->dataProxy()->addRow(data);
    // bars.addSeries(series);
    // bars.show();

    return a.exec();
}
