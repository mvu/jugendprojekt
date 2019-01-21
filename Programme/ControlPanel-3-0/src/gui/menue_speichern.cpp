/*!
 * \file menue_speichern.cpp
 * \brief Source der Speicher-Menü GUI
 */
#include "inc/gui/menue_speichern.h"
#include "ui_menue_speichern.h"

MenueSpeichern::MenueSpeichern(QWidget *parent, Jugendraum *j) :
    QDialog(parent),
    ui_(new Ui::MenueSpeichern)
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
    animation->setStartValue(QRect(110,-150,580,180));
    animation->setEndValue(QRect(110,150,580,180));
    animation->setEasingCurve(QEasingCurve::InExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

MenueSpeichern::~MenueSpeichern()
{
    qDebug() << Q_FUNC_INFO;
    delete ui_;
}

void MenueSpeichern::on_pushButton_youth_released()
{
    qDebug() << Q_FUNC_INFO;
}

void MenueSpeichern::on_pushButton_teen_2_released()
{
    qDebug() << Q_FUNC_INFO;
}

void MenueSpeichern::on_pushButton_back_released()
{
    qDebug() << Q_FUNC_INFO;

    // slide-out Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(150);
    animation->setStartValue(QRect(110,150,580,180));
    animation->setEndValue(QRect(110,-150,580,180));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}
