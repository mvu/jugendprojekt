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
}

void MenueLicht::on_pushButton_rgb_ceiling_released()
{
    qDebug() << Q_FUNC_INFO;
}

void MenueLicht::on_pushButton_counter_released()
{
    qDebug() << Q_FUNC_INFO;
}

void MenueLicht::on_pushButton_rgb_windows_released()
{
    qDebug() << Q_FUNC_INFO;
}

void MenueLicht::on_pushButton_palette_released()
{
    qDebug() << Q_FUNC_INFO;
}

void MenueLicht::on_pushButton_save_released()
{
    qDebug() << Q_FUNC_INFO;
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
