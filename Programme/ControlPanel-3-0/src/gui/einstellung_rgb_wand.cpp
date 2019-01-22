/*!
 * \file einstellung_rgb_wand.cpp
 * \brief Source für die Wand-RGB-Einstellung GUI
 */
#include "inc/gui/einstellung_rgb_wand.h"
#include "ui_einstellung_rgb_wand.h"

EinstellungRGBWand::EinstellungRGBWand(QWidget *parent, Jugendraum *j) :
    QDialog(parent),
    ui_(new Ui::EinstellungRGBWand)
{
    qDebug() << Q_FUNC_INFO;
        
    jugendraum_ = j;

    // erzeuge GUI
    ui_->setupUi(this);
    ui_->horizontalLayoutWidget->setStyleSheet("border:none;");
    this->setModal(true);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->show();

    // slide-in Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(-400,0,0,480));
    animation->setEndValue(QRect(0,0,400,480));
    animation->setEasingCurve(QEasingCurve::InExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

EinstellungRGBWand::~EinstellungRGBWand()
{
    qDebug() << Q_FUNC_INFO;
    delete ui_;
}

void EinstellungRGBWand::on_pushButton_back_released()
{
    qDebug() << Q_FUNC_INFO;
    
    // slide-out Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(150);
    animation->setStartValue(QRect(0,0,400,480));
    animation->setEndValue(QRect(-400,0,0,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);  
}

void EinstellungRGBWand::on_pushButton_on_off_released()
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBWand::on_pushButton_set_color_released()
{
    qDebug() << Q_FUNC_INFO;
}
