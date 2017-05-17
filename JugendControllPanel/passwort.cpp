#include "passwort.h"
#include "ui_passwort.h"

using namespace std;

Passwort::Passwort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Passwort)
{
    ui->setupUi(this);
    inputPasswort = 0;

    //MouseClickEater *mouseClickEater = new MouseClickEater();
    //ui->pushButton_0->installEventFilter(mouseClickEater);

    ui->label_pw->clear();

}

Passwort::~Passwort()
{
    delete ui;
}

void Passwort::resetPassword()
{
    ui->label_pw->setText("");
    inputPasswort = 0;
}

void Passwort::on_pushButton_back_released()
{
    if (inputPasswort == 0)
    {
        this->close();
    }
    else
    {
        inputPasswort = inputPasswort/10;
        QString temp = ui->label_pw->text();
        temp.chop(1);
        ui->label_pw->setText(temp);
    }
}

void Passwort::on_pushButton_ok_released()
{
    if (inputPasswort == correctPasswort)
    {
        emit PasswortCorrect();
        this->close();
    }
    else
    {
        //animation shake
        QPropertyAnimation *animation = new QPropertyAnimation(ui->label_pw, "geometry");
        connect(animation, SIGNAL(finished()), this, SLOT(resetPassword()));
        animation->setDuration(500);
        animation->setStartValue(QRect(-20,100,800,20));
        animation->setEndValue(QRect(0,100,800,20));
        animation->setEasingCurve(QEasingCurve::OutElastic);
        animation->start();
    }
}


void Passwort::on_pushButton_0_released()
{
    inputPasswort *= 10;
    ui->label_pw->setText(ui->label_pw->text().append('*'));
}

void Passwort::on_pushButton_1_released()
{
    inputPasswort *= 10;
    inputPasswort += 1;
    ui->label_pw->setText(ui->label_pw->text().append('*'));
}

void Passwort::on_pushButton_2_released()
{
    inputPasswort *= 10;
    inputPasswort += 2;
    ui->label_pw->setText(ui->label_pw->text().append('*'));
}

void Passwort::on_pushButton_3_released()
{
    inputPasswort *= 10;
    inputPasswort += 3;
    ui->label_pw->setText(ui->label_pw->text().append('*'));
}

void Passwort::on_pushButton_4_released()
{
    inputPasswort *= 10;
    inputPasswort += 4;
    ui->label_pw->setText(ui->label_pw->text().append('*'));
}

void Passwort::on_pushButton_5_released()
{
    inputPasswort *= 10;
    inputPasswort += 5;
    ui->label_pw->setText(ui->label_pw->text().append('*'));
}

void Passwort::on_pushButton_6_released()
{
    inputPasswort *= 10;
    inputPasswort += 6;
    ui->label_pw->setText(ui->label_pw->text().append('*'));
}

void Passwort::on_pushButton_7_released()
{
    inputPasswort *= 10;
    inputPasswort += 7;
    ui->label_pw->setText(ui->label_pw->text().append('*'));
}

void Passwort::on_pushButton_8_released()
{
    inputPasswort *= 10;
    inputPasswort += 8;
    ui->label_pw->setText(ui->label_pw->text().append('*'));
}

void Passwort::on_pushButton_9_released()
{
    inputPasswort *= 10;
    inputPasswort += 9;
    ui->label_pw->setText(ui->label_pw->text().append('*'));
}
