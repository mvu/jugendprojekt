/*!
 * \file einstellung_rgb_decke.cpp
 * \brief Source der GUI zur Einstellung der Decken-RGBs
 */
#include "inc/gui/einstellung_rgb_decke.h"
#include "ui_einstellung_rgb_decke.h"

EinstellungRGBDecke::EinstellungRGBDecke(QWidget *parent, Jugendraum *j) :
    QDialog(parent),
    ui_(new Ui::EinstellungRGBDecke)
{
    qDebug() << Q_FUNC_INFO;

    jugendraum_ = j;

    // erzeuge GUI
    ui_->setupUi(this);
    this->setModal(true);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->show();

    InitButtons();

    // slide-in Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(-800,0,0,480));
    animation->setEndValue(QRect(0,0,800,480));
    animation->setEasingCurve(QEasingCurve::InExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

EinstellungRGBDecke::~EinstellungRGBDecke()
{
    qDebug() << Q_FUNC_INFO;

    delete ui_;
}

void EinstellungRGBDecke::InitButtons()
{
    // Lade alle QPushButtons der RGBs in eine QList
    push_buttons_rgb_.append(ui_->pushButton_1);
    push_buttons_rgb_.append(ui_->pushButton_2);
    push_buttons_rgb_.append(ui_->pushButton_3);
    push_buttons_rgb_.append(ui_->pushButton_4);
    push_buttons_rgb_.append(ui_->pushButton_5);
    push_buttons_rgb_.append(ui_->pushButton_6);
    push_buttons_rgb_.append(ui_->pushButton_7);
    push_buttons_rgb_.append(ui_->pushButton_8);
    push_buttons_rgb_.append(ui_->pushButton_9);
    push_buttons_rgb_.append(ui_->pushButton_10);
    push_buttons_rgb_.append(ui_->pushButton_11);
    push_buttons_rgb_.append(ui_->pushButton_12);
    push_buttons_rgb_.append(ui_->pushButton_13);
    push_buttons_rgb_.append(ui_->pushButton_14);
    push_buttons_rgb_.append(ui_->pushButton_15);
    push_buttons_rgb_.append(ui_->pushButton_16);
    push_buttons_rgb_.append(ui_->pushButton_17);
    push_buttons_rgb_.append(ui_->pushButton_18);

    // Lade alle QPushButtons der Gruppen in eine QList
    push_buttons_groups_.append(ui_->pushButton_group_all);
    push_buttons_groups_.append(ui_->pushButton_group_1);
    push_buttons_groups_.append(ui_->pushButton_group_2);

    // setze StyleSheets für QPushButtons der RGBs
    for (int i = 0; i < push_buttons_rgb_.length(); i++){
        push_buttons_rgb_[i]->setStyleSheet("QPushButton { \
                                                border: 2px solid black; \
                                                border-radius: 10px; \
                                            } \
                                            QPushButton:checked { \
                                                border: 2px solid white; \
                                                border-radius: 10px;\
                                            }");
    }

    // setzte StyleSheets für QPushButtons der Gruppen
    for (int i = 0; i < push_buttons_groups_.length(); i++){
        push_buttons_groups_[i]->setStyleSheet("QPushButton { \
                                                   background-color: rgba(0,0,0,80); \
                                                   color: white; \
                                                   border: none; \
                                               } \
                                               QPushButton:checked { \
                                                   border: 2px solid white; \
                                               }");
    }
}

void EinstellungRGBDecke::on_pushButton_1_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_2_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_3_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_4_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_5_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_6_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_7_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_8_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_9_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_10_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_11_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_12_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_13_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_14_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_15_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_16_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_17_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_18_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_group_all_toggled(bool checked)
{
        qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_group_1_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_group_2_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_on_off_released()
{
    qDebug() << Q_FUNC_INFO;
}

void EinstellungRGBDecke::on_pushButton_back_released()
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
