/*!
 * \file einstellung_audio.cpp
 * \brief Source für die Audio-Einstellung GUI
 */
#include "inc/gui/einstellung_audio.h"
#include "ui_einstellung_audio.h"

EinstellungAudio::EinstellungAudio(QWidget *parent, Jugendraum *j) :
    QDialog(parent),
    ui_(new Ui::EinstellungAudio)
{
    qDebug() << Q_FUNC_INFO;
        
    jugendraum_ = j;

    // erzeuge GUI
    ui_->setupUi(this);
    ui_->verticalLayoutWidget_2->setStyleSheet("border:none;");
    ui_->verticalLayoutWidget_3->setStyleSheet("border:none;");
    this->setModal(true);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->show();

    // slide-in Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(-800,0,0,480));
    animation->setEndValue(QRect(0,0,800,480));
    animation->setEasingCurve(QEasingCurve::InExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

EinstellungAudio::~EinstellungAudio()
{
    qDebug() << Q_FUNC_INFO;
    delete ui_;
}

void EinstellungAudio::on_pushButton_input_aux_released()
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungAudio::on_pushButton_input_pc_released()
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungAudio::on_pushButton_input_playstation_released()
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungAudio::on_pushButton_volume_high_released()
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungAudio::on_pushButton_volume_low_released()
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungAudio::on_pushButton_volume_medium_released()
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungAudio::on_pushButton_back_released()
{
    qDebug() << Q_FUNC_INFO;
    
    // slide-out Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(150);
    animation->setStartValue(QRect(0,0,800,480));
    animation->setEndValue(QRect(-800,0,0,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);  
}

void EinstellungAudio::on_pushButton_on_off_released()
{
    qDebug() << Q_FUNC_INFO;
}
