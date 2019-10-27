/*!
 * \file menue_medien.cpp
 * \brief Header für das Medien Menü
 */
#include "inc/gui/menue_medien.h"
#include "ui_menue_medien.h"

MenueMedien::MenueMedien(QWidget *parent, Jugendraum *j) :
    QDialog(parent),
    ui_(new Ui::MenueMedien)
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

    // slide-in Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(-400,0,400,480));
    animation->setEndValue(QRect(0,0,400,480));
    animation->setEasingCurve(QEasingCurve::InExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

MenueMedien::~MenueMedien()
{
    qDebug() << Q_FUNC_INFO;
    delete ui_;
}

void MenueMedien::on_pushButton_audio_released()
{
    qDebug() << Q_FUNC_INFO;
    
    einstellung_audio_ = new EinstellungAudio(this, jugendraum_);
}

void MenueMedien::on_pushButton_beamer_released()
{
    qDebug() << Q_FUNC_INFO;
}

void MenueMedien::on_pushButton_pc_released()
{
    qDebug() << Q_FUNC_INFO;
}

void MenueMedien::on_pushButton_back_released()
{
    qDebug() << Q_FUNC_INFO;

    // slide-out Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(150);
    animation->setStartValue(QRect(0,0,400,480));
    animation->setEndValue(QRect(-400,0,400,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MenueMedien::updateTime()
{
    // qDebug() << Q_FUNC_INFO;

    ui_->label_clock->setText(QDateTime::currentDateTime().toString("hh:mm"));
}