/*!
 * \file passwort.cpp
 * \brief Source der Passwort GUI
 */
#include "inc/gui/passwort.h"
#include "ui_passwort.h"

Passwort::Passwort(QWidget *parent, QByteArray correct_password_hash) :
    QDialog(parent),
    ui_(new Ui::Passwort)
{
    qDebug() << Q_FUNC_INFO;

    correct_password_hash_ = correct_password_hash;
    tmp_password_raw_ = nullptr;

    // erzeuge GUI
    ui_->setupUi(this);
    ui_->label_password->setText("");
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->showFullScreen();
}

Passwort::~Passwort()
{
    qDebug() << Q_FUNC_INFO;
    delete ui_;
}

void Passwort::ResetEnteredPassword()
{
    tmp_password_raw_.resize(0);
    ui_->label_password->clear();
}

void Passwort::on_pushButton_1_released()
{
    qDebug() << Q_FUNC_INFO;
    tmp_password_raw_.append('1');
    ui_->label_password->setText(ui_->label_password->text().append('*'));
}

void Passwort::on_pushButton_2_released()
{
    qDebug() << Q_FUNC_INFO;
    tmp_password_raw_.append('2');
    ui_->label_password->setText(ui_->label_password->text().append('*'));
}

void Passwort::on_pushButton_3_released()
{
    qDebug() << Q_FUNC_INFO;
    tmp_password_raw_.append('3');
    ui_->label_password->setText(ui_->label_password->text().append('*'));
}

void Passwort::on_pushButton_4_released()
{
    qDebug() << Q_FUNC_INFO;
    tmp_password_raw_.append('4');
    ui_->label_password->setText(ui_->label_password->text().append('*'));
}

void Passwort::on_pushButton_5_released()
{
    qDebug() << Q_FUNC_INFO;
    tmp_password_raw_.append('5');
    ui_->label_password->setText(ui_->label_password->text().append('*'));
}

void Passwort::on_pushButton_6_released()
{
    qDebug() << Q_FUNC_INFO;
    tmp_password_raw_.append('6');
    ui_->label_password->setText(ui_->label_password->text().append('*'));
}

void Passwort::on_pushButton_7_released()
{
    qDebug() << Q_FUNC_INFO;
    tmp_password_raw_.append('7');
    ui_->label_password->setText(ui_->label_password->text().append('*'));
}

void Passwort::on_pushButton_8_released()
{
    qDebug() << Q_FUNC_INFO;
    tmp_password_raw_.append('8');
    ui_->label_password->setText(ui_->label_password->text().append('*'));
}

void Passwort::on_pushButton_9_released()
{
    qDebug() << Q_FUNC_INFO;
    tmp_password_raw_.append('9');
    ui_->label_password->setText(ui_->label_password->text().append('*'));
}

void Passwort::on_pushButton_0_released()
{
    qDebug() << Q_FUNC_INFO;
    tmp_password_raw_.append('0');
    ui_->label_password->setText(ui_->label_password->text().append('*'));
}

void Passwort::on_pushButton_ok_released()
{
    qDebug() << Q_FUNC_INFO;

    if (QCryptographicHash::hash(tmp_password_raw_, QCryptographicHash::Sha256) == correct_password_hash_) {
        emit PasswordCorrect();
        this->close();
    } else {
        // log wrong failed attempt
        log(EVENT_LOG, QString("wrong password entered: %1").arg(tmp_password_raw_.toInt()));

        // shake Animation
        QPropertyAnimation *animation = new QPropertyAnimation(ui_->label_password, "geometry");
        connect(animation, SIGNAL(finished()), this, SLOT(ResetEnteredPassword()));
        animation->setDuration(500);
        animation->setStartValue(QRect(-20,100,800,20));
        animation->setEndValue(QRect(0,100,800,20));
        animation->setEasingCurve(QEasingCurve::InOutElastic);
        animation->start();
    }
}

void Passwort::on_pushButton_back_released()
{
    if (tmp_password_raw_.isEmpty()) {
        this->close();
    } else {
        tmp_password_raw_.chop(1);
        ui_->label_password->setText(ui_->label_password->text().chopped(1));
    }
}
