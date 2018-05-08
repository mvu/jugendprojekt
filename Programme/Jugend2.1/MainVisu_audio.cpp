#include "MainVisu_audio.h"
#include "ui_audio.h"

Audio::Audio(QWidget *parent, steuerungThreadLicht *s , ModelThreadLicht *m) :
    QDialog(parent),
    ui(new Ui::Audio)
{
    ui->setupUi(this);
    ui->pushButton_back->setVisible(false);
    ui->verticalLayoutWidget_2->setStyleSheet("border:none;");
    ui->verticalLayoutWidget_3->setStyleSheet("border:none;");

    sThread = s;
    mThread = m;

    //slide in animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(afterAnimation()));
    animation->setDuration(500);
    animation->setStartValue(QRect(-800,0,800,480));
    animation->setEndValue(QRect(0,0,800,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start();

    connect(this,SIGNAL(beamer(bool)),s,SLOT(beamerOnOff(bool)));
    connect(this,SIGNAL(pc()),s,SLOT(pcOn()));
}

Audio::~Audio()
{
    delete ui;
}

void Audio::on_pushButtonAUX_released()
{
    this->setEnabled(false);
    QProcess terminal;
    terminal.start("onkyo main.input-selector=aux1");
    terminal.waitForFinished(10);
    this->setEnabled(true);
}

void Audio::on_pushButtonPlaystation_released()
{
    this->setEnabled(false);
    QProcess terminal;
    terminal.start("onkyo main.input-selector=game");
    terminal.waitForFinished(10);
    this->setEnabled(true);
}

void Audio::on_pushButtonPC_released()
{
    this->setEnabled(false);
    QProcess terminal;
    terminal.start("onkyo main.input-selector=pc");
    terminal.waitForFinished(10);
    this->setEnabled(true);
}

void Audio::on_pushButton_back_released()
{
    emit ParentEnable();
    //slide out animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(300);
    animation->setStartValue(QRect(0,0,400,480));
    animation->setEndValue(QRect(-800,0,400,480));
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->start();
}

void Audio::afterAnimation()
{
    ui->pushButton_back->setVisible(true);
}

void Audio::on_pushButton_OnOff_toggled(bool checked)
{
    ui->central_Widget->setEnabled(false);
    std::cout << "Signals disconnected\n";
    QProcess terminal;
    if (checked){
        terminal.start("onkyo main.system-power=standby");
        terminal.waitForFinished(10);
    }
    else
    {
        terminal.start("onkyo main.system-power=on");
        terminal.waitForFinished(10);
    }
    //this->setEnabled(true);
    ui->central_Widget->setEnabled(true);
    std::cout << "Signals connected\n";
}

void Audio::on_pushButtonLautstaerke_Leise_released()
{
    this->setEnabled(false);
    QProcess terminal;
    terminal.start("onkyo volume:49");
    terminal.waitForFinished(10);
    this->setEnabled(false);
}

void Audio::on_pushButtonLautstaerke_Mittel_released()
{
    this->setEnabled(false);
    QProcess terminal;
    terminal.start("onkyo volume:68");
    terminal.waitForFinished(10);
    this->setEnabled(true);
}

void Audio::on_pushButtonLautstaerke_Laut_released()
{
    this->setEnabled(false);
    QProcess terminal;
    terminal.start("onkyo volume:85");
    terminal.waitForFinished(10);
    this->setEnabled(true);
}
