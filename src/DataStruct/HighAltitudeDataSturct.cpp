#include "HighAltitudeDataSturct.h"


void HighAltitudeWeatherDataSturct::Read_AMap_adcode_citycode(QString filePath, QList<AMap_adcode_citycode> &list_adcode)
{
    // 构建完整路径（支持相对路径和绝对路径）
    QString fullPath = filePath;
    if (QDir::isRelativePath(filePath)) {
        fullPath = QCoreApplication::applicationDirPath() + "/" + filePath;
    }

    // 打开 Excel 文件
    QXlsx::Document xlsx(fullPath);
    if (!xlsx.load()) {
        qWarning() << "无法加载 Excel 文件:" << fullPath;
        return;
    }

    // 遍历所有行（假设数据从第1行开始，列从1开始计数）
    int row = 1;
    while (true) {
        // 读取前三列的值
        QVariant val1 = xlsx.read(row, 1); // 第1列：ChineseName
        QVariant val2 = xlsx.read(row, 2); // 第2列：adcode
        QVariant val3 = xlsx.read(row, 3); // 第3列：citycode

        // 如果第一列为空，通常表示该行无数据，结束循环（可根据实际文件调整终止条件）
        if (val1.isNull() || !val1.isValid())
            break;

        // 如果其他列为空，也可以读取空字符串
        AMap_adcode_citycode item;
        item.ChineseName = val1.toString().trimmed();
        item.adcode      = val2.isValid() ? val2.toString().trimmed() : QString();
        item.citycode    = val3.isValid() ? val3.toString().trimmed() : QString();

        list_adcode.append(item);
        ++row;
    }
}
