#include "MainVisu_config.h"
#include "ui_config.h"

config::config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::config)
{
    ui->setupUi(this);
}

config::~config()
{
    delete ui;
}

void config::on_pushButton_PCA_Config_released()
{

}

void config::on_pushButton_Temperatur_released()
{

}

void config::on_pushButton_Einstellung_released()
{

}

void config::on_pushButton_LuefterConfig_released()
{

}
