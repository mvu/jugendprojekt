#include "einstellung.h"
#include "ui_einstellung.h"

Einstellung::Einstellung(QWidget *parent, steuerungThreadLicht *s, ModelThreadLicht *m, thread_Ueberwachung *u) :
    QDialog(parent),
    ui(new Ui::einstellung)
{
    ui->setupUi(this);
    ui->pushButton_back->setVisible(false);
    sThread = s;
    mThread = m;
    uThread = u;

  //slide in animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(afterAnimation()));
    animation->setDuration(250);
    animation->setStartValue(QRect(-800,0,400,480));
    animation->setEndValue(QRect(0,0,400,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start();
  //Communication
    //UI->sThread
    connect(this, SIGNAL(luefterSetAusgangOben(int)),s,SLOT(luefterAusgangOben(int)));
    connect(this, SIGNAL(luefterSetController(int)),s,SLOT(luefterController(int)));
    connect(this, SIGNAL(luefterSetNetzteil(int)),s,SLOT(luefterNetzteil(int)));
    connect(this, SIGNAL(getLuefterAusgangOben()),s,SLOT(getLuefterAusgangObenslot()));
    connect(this, SIGNAL(getLuefterController()),s,SLOT(getLuefterControllerslot()));
    connect(this, SIGNAL(getLuefterNetzteil()),s,SLOT(getLuefterNetzteilslot()));
    //uThread->UI
    connect(uThread, SIGNAL(TempDeckeChanged(float)), this, SLOT(TempRaum_neu(float)));
    connect(uThread, SIGNAL(TempNetzteileChanged(float)), this, SLOT(TempNetzteil_neu(float)));
    connect(uThread, SIGNAL(TempSteuerplatineChanged(float)), this, SLOT(TempPlatine_neu(float)));
    connect(uThread, SIGNAL(TempPiChanged(float)), this, SLOT(TempPi_neu(float)));

//    emit getLuefterAusgangOben();
//    emit getLuefterController();
//    emit getLuefterNetzteil();

  //initial reading
    float temp_pi = uThread->requestTemp(3);
    float temp_raum = uThread->requestTemp(2);
    float temp_netz = uThread->requestTemp(1);
    float temp_plat = uThread->requestTemp(0);
    TempNetzteil_neu(temp_netz);
    TempPlatine_neu(temp_plat);
    TempRaum_neu(temp_raum);
    TempPi_neu(temp_pi);
}

Einstellung::~Einstellung()
{
    delete ui;
}

void Einstellung::on_pushButton_back_released()
{
    //slide out animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(250);
    animation->setStartValue(QRect(0,0,400,480));
    animation->setEndValue(QRect(-400,0,400,480));
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->start();

    emit ParentEnable();
}

void Einstellung::on_pushButton_Off_released()
{
//    password = new Passwort(this);
//    connect(password, SIGNAL(PasswortCorrect()), this, SLOT(Shutdown()));
//    password->showFullScreen();

    Shutdown();
}

void Einstellung::afterAnimation()
{
    ui->pushButton_back->setVisible(true);
}

void Einstellung::Shutdown()
{
    //emit allOff();
    sThread->exit(true);
    mThread->exit(true);
    uThread->exit(true);
    parentWidget()->close();
    this->close();
}

void Einstellung::TempNetzteil_neu(float val)
{
    ui->label_temp_netz->setText((QString::number(val, 'f', 2 )).append("°C"));

    //set color
    if (val < TempNetz_High)
    {
        ui->label_temp_netz->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(0,255,0);"));
    }
    else if (val < TempNetz_Crit)
    {
        ui->label_temp_netz->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(255,255,0);"));
    }
    else
    {
        ui->label_temp_netz->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(255,0,0);"));
    }
}

void Einstellung::TempPlatine_neu(float val)
{
    ui->label_temp_plat->setText((QString::number(val, 'f', 2 )).append("°C"));

    //set color
    if (val < TempPlat_High)
    {
        ui->label_temp_plat->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(0,255,0);"));
    }
    else if (val < TempPlat_Crit)
    {
        ui->label_temp_plat->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(255,255,0);"));
    }
    else
    {
        ui->label_temp_plat->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(255,0,0);"));
    }
}

void Einstellung::TempRaum_neu(float val)
{
    ui->label_temp_raum->setText((QString::number(val, 'f', 2 )).append("°C"));

    //set color
    if (val < TempRaum_High)
    {
        ui->label_temp_raum->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(0,255,0);"));
    }
    else if (val < TempRaum_Crit)
    {
        ui->label_temp_raum->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(255,255,0);"));
    }
    else
    {
        ui->label_temp_raum->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(255,0,0);"));
    }
}

void Einstellung::TempPi_neu(float val)
{
    ui->label_temp_pi->setText((QString::number(val, 'f', 2 )).append("°C"));

    //set color
    if (val < TempPi_High)
    {
        ui->label_temp_pi->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(0,255,0);"));
    }
    else if (val < TempPi_Crit)
    {
        ui->label_temp_pi->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(255,255,0);"));
    }
    else
    {
        ui->label_temp_pi->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(255,0,0);"));
    }
}
