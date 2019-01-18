/*!
 * \file einstellung_theke.cpp
 * \brief Source für die Theke-Einstellung GUI
 */
#include "inc/gui/einstellung_theke.h"
#include "ui_einstellung_theke.h"

EinstellungTheke::EinstellungTheke(QWidget *parent, Jugendraum *j) :
    QDialog(parent),
    ui_(new Ui::EinstellungTheke)
{
    qDebug() << Q_FUNC_INFO;
        
    jugendraum_ = j;

    // erzeuge GUI
    ui_->setupUi(this);
    ui_->horizontalLayoutWidget_2->setStyleSheet("border:none;");
    ui_->horizontalLayoutWidget_3->setStyleSheet("border:none;");
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

EinstellungTheke::~EinstellungTheke()
{
    qDebug() << Q_FUNC_INFO;
    delete ui_;
}

void EinstellungTheke::on_pushButton_back_released()
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

void EinstellungTheke::on_pushButton_lampen_on_off_released()
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungTheke::on_pushButton_rgb_set_released()
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungTheke::on_pushButton_rgb_on_off_released()
{
    qDebug() << Q_FUNC_INFO;
}
