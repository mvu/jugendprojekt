/*!
 * \file menue_licht.cpp
 * \brief Header für das Licht Menü
 */
#include "inc/gui/menue_licht.h"
#include "ui_menue_licht.h"

MenueLicht::MenueLicht(QWidget *parent, Jugendraum *j) :
    QDialog (parent),
    ui_(new Ui::MenueLicht)
{
    qDebug() << Q_FUNC_INFO;

    jugendraum_ = j;

    // erzeuge GUI
    ui_->setupUi(this);
    this->setModal(true);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->show();

    // initialisiere timer zum updaten der Uhrzeit
    clock_timer_ = new QTimer(this);
    connect(clock_timer_, SIGNAL(timeout()), this, SLOT(updateTime()));
    clock_timer_->start(1000);
    updateTime();

    // Erfrage Status von jugendraum_ und setze Beschriftungen entsprechend
    ui_->pushButton_palette->setText(QString("Paletten ").append(jugendraum_->paletten_licht->isOn() ? "aus": "an"));

    // slide-in Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(800,0,400,480));
    animation->setEndValue(QRect(400,0,400,480));
    animation->setEasingCurve(QEasingCurve::InExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

MenueLicht::~MenueLicht()
{
    qDebug() << Q_FUNC_INFO;
    delete ui_;
}

void MenueLicht::on_pushButton_main_light_released()
{
    qDebug() << Q_FUNC_INFO;

    einstellung_hauptlicht_ = new EinstellungHauptlicht(this, jugendraum_);
}

void MenueLicht::on_pushButton_rgb_ceiling_released()
{
    qDebug() << Q_FUNC_INFO;

    einstellung_rgb_decke_ = new EinstellungRGBDecke(this, jugendraum_);
}

void MenueLicht::on_pushButton_counter_released()
{
    qDebug() << Q_FUNC_INFO;
    
    einstellung_theke_ = new EinstellungTheke(this, jugendraum_);
}

void MenueLicht::on_pushButton_rgb_windows_released()
{
    qDebug() << Q_FUNC_INFO;
    
    einstellung_rgb_wand_ = new EinstellungRGBWand(this, jugendraum_);
}

void MenueLicht::on_pushButton_palette_released()
{
    qDebug() << Q_FUNC_INFO;

    // invert the state of palette
    jugendraum_->paletten_licht->setOn(not jugendraum_->paletten_licht->isOn());
    //display the new value
    ui_->pushButton_palette->setText(QString("Paletten ").append(jugendraum_->paletten_licht->isOn() ? "aus": "an"));
}

void MenueLicht::on_pushButton_save_released()
{
    qDebug() << Q_FUNC_INFO;

    menu_speichern_ = new MenueSpeichern(this, jugendraum_);
}

void MenueLicht::on_pushButton_close_released()
{
    qDebug() << Q_FUNC_INFO;

    // slide-out Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(150);
    animation->setStartValue(QRect(400,0,400,480));
    animation->setEndValue(QRect(800,0,400,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MenueLicht::updateTime()
{
    // qDebug() << Q_FUNC_INFO;

    ui_->label_clock->setText(QDateTime::currentDateTime().toString("hh:mm"));
}
