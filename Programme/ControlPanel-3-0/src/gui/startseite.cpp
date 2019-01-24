/*!
 * \file startseite.cpp
 * \brief Header für das Hauptfenster der GUI
 */
#include "inc/gui/startseite.h"
#include "ui_startseite.h"

Startseite::Startseite(QWidget *parent, Jugendraum *j) :
    QMainWindow(parent),
    ui_(new Ui::Startseite)
{
    qDebug() << Q_FUNC_INFO;
    jugendraum_ = j;

    ui_->setupUi(this);
}

Startseite::~Startseite()
{
    qDebug() << Q_FUNC_INFO;
    jugendraum_->~Jugendraum();
    delete ui_;
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

    // erzeuge Licht Menü
    menu_light_ = new MenueLicht(this, jugendraum_);

}

void Startseite::on_pushButton_media_released()
{
    qDebug() << Q_FUNC_INFO;

    // erzeuge Medien-Menü
    menu_media_ = new MenueMedien(this, jugendraum_);
}

void Startseite::on_pushButton_system_released()
{
    qDebug() << Q_FUNC_INFO;

    // erzeuge Systemanzeige
    system_status_ = new SystemStatus(this, jugendraum_);
}
