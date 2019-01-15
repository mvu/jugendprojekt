#include "inc/gui/startseite.h"
#include "ui_startseite.h"

Startseite::Startseite(QWidget *parent, Jugendraum *j) :
    QMainWindow(parent),
    ui(new Ui::Startseite)
{
    qDebug() << Q_FUNC_INFO;
    ui->setupUi(this);
    jugendraum_ = j;
}

Startseite::~Startseite()
{
    qDebug() << Q_FUNC_INFO;
    delete ui;
    jugendraum_->shutdown();
}

void Startseite::on_pushButton_youth_released()
{
    qDebug() << Q_FUNC_INFO;
}

void Startseite::on_pushButton_teen_released()
{
    qDebug() << Q_FUNC_INFO;
}

void Startseite::on_pushButton_light_released()
{
    qDebug() << Q_FUNC_INFO;
}

void Startseite::on_pushButton_media_released()
{
    qDebug() << Q_FUNC_INFO;
}

void Startseite::on_pushButton_system_released()
{
    qDebug() << Q_FUNC_INFO;
}
