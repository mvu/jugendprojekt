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

    clock_timer_ = new QTimer(this);
    connect(clock_timer_, SIGNAL(timeout()), this, SLOT(updateDateTime()));
    clock_timer_->start(1000);

    ui_->setupUi(this);
}

Startseite::~Startseite()
{
    qDebug() << Q_FUNC_INFO;
    delete jugendraum_;
    delete clock_timer_;
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

void Startseite::updateDateTime()
{
    qDebug() << Q_FUNC_INFO;

    QDateTime DateTime = QDateTime::currentDateTime();
    QString time = DateTime.toString("hh:mm");
    QString date = DateTime.toString("d. MMMM");

    ui_->label_date->setText(date);
    ui_->label_time->setText(time);
}
