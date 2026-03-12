#include "Configuration.h"
#include "ui_Configuration.h"

Configuration::Configuration(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Configuration)
{
    ui->setupUi(this);
}

Configuration::~Configuration()
{
    delete ui;
}
