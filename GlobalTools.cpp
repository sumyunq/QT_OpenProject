#include "GlobalTools.h"

GlobalTools::GlobalTools(QObject *parent)
    : QObject{parent}
{
    this.jsonHelper =new JsonHelper();

}
