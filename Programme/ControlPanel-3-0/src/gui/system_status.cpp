/*!
 * \file system_status.cpp
 * \brief Source für die Systemanzeige GUI
 */
#include "inc/gui/system_status.h"
#include "ui_system_status.h"

SystemStatus::SystemStatus(QWidget *parent, Jugendraum *j) :
    QDialog(parent),
    ui_(new Ui::SystemStatus)
{
    qDebug() << Q_FUNC_INFO;

    jugendraum_ = j;

    // erzeuge GUI
    ui_->setupUi(this);
    this->setModal(true);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->show();

    // slide-in Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(-400,0,400,480));
    animation->setEndValue(QRect(0,0,400,480));
    animation->setEasingCurve(QEasingCurve::InExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

SystemStatus::~SystemStatus()
{
    qDebug() << Q_FUNC_INFO;
    delete ui_;
}

void SystemStatus::on_pushButton_shutdown_released()
{
    qDebug() << Q_FUNC_INFO;
}

void SystemStatus::on_pushButton_back_released()
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
