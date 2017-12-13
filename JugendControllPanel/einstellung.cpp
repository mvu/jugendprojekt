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
    connect(uThread, SIGNAL(TempDeckeChanged(float, int)), this, SLOT(TempRaum_neu(float, int)));
    connect(uThread, SIGNAL(TempNetzteileChanged(float, int)), this, SLOT(TempNetzteil_neu(float, int)));
    connect(uThread, SIGNAL(TempSteuerplatineChanged(float, int)), this, SLOT(TempPlatine_neu(float, int)));
    connect(uThread, SIGNAL(TempPiChanged(float)), this, SLOT(TempPi_neu(float)));
    connect(uThread, SIGNAL(TempPCChanged(float)), this, SLOT(TempPc_neu(float)));
    connect(uThread, SIGNAL(TempVerstaerkerChanged(float, int)), this, SLOT(TempOnkyo_neu(float, int)));

//    emit getLuefterAusgangOben();
//    emit getLuefterController();
//    emit getLuefterNetzteil();

  //initial reading
    float temp_pi = uThread->requestTemp(3);
    float temp_raum = uThread->requestTemp(2);
    float temp_netz = uThread->requestTemp(1);
    float temp_plat = uThread->requestTemp(0);
    float temp_onkyo = uThread->requestTemp(4);
    float temp_pc = uThread->requestTemp(5);
    TempNetzteil_neu(temp_netz, 0);
    TempPlatine_neu(temp_plat, 0);
    TempRaum_neu(temp_raum, 0);
    TempPi_neu(temp_pi);
    TempOnkyo_neu(temp_onkyo, 0);
    TempPc_neu(temp_pc);
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
    password = new Passwort(this);
    connect(password, SIGNAL(PasswortCorrect()), this, SLOT(Shutdown()));
    password->showFullScreen();

    //Shutdown();
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

void Einstellung::TempNetzteil_neu(float val, int pwm)
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

    //set pwm-label
    ui->label_fan_netz->setText((QString::number(pwm, 'i', 0)).append("%"));
}

void Einstellung::TempPlatine_neu(float val, int pwm)
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

    //set pwm-label
    ui->label_fan_plat->setText((QString::number(pwm, 'i', 0)).append("%"));
}

void Einstellung::TempRaum_neu(float val, int pwm)
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
    //set pwm-label
    ui->label_fan_raum->setText((QString::number(pwm, 'i', 0)).append("%"));
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

void Einstellung::TempPc_neu(float val)
{
    ui->label_temp_pc->setText((QString::number(val, 'f', 2 )).append("°C"));

    //set color
    if (val < TempPc_High)
    {
        ui->label_temp_pc->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(0,255,0);"));
    }
    else if (val < TempPc_Crit)
    {
        ui->label_temp_pc->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(255,255,0);"));
    }
    else
    {
        ui->label_temp_pc->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(255,0,0);"));
    }
}

void Einstellung::TempOnkyo_neu(float val, int pwm)
{
    ui->label_temp_onkyo->setText((QString::number(val, 'f', 2 )).append("°C"));

    //set color
    if (val < TempOnkyo_High)
    {
        ui->label_temp_onkyo->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(0,255,0);"));
    }
    else if (val < TempOnkyo_Crit)
    {
        ui->label_temp_onkyo->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(255,255,0);"));
    }
    else
    {
        ui->label_temp_onkyo->setStyleSheet(QString("font: 14pt 'Courier New';color:rgb(255,0,0);"));
    }
    //set pwm-label
    ui->label_fan_raum->setText((QString::number(pwm, 'i', 0)).append("%"));
}
