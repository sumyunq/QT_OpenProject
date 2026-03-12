#ifndef GLOBALTOOLS_H
#define GLOBALTOOLS_H

#include <QObject>

#include "JsonHelper.h"
#include "FileHelper.h"

class GlobalTools : public QObject
{
    Q_OBJECT
public:
    explicit GlobalTools(QObject *parent = nullptr);

    JsonHelper *jsonHelper;
    FileHelper *fileHelper;
};

#endif // GLOBALTOOLS_H
