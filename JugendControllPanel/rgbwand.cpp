#include "rgbwand.h"
#include "ui_rgbwand.h"
#include "pca_9635.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>


RgbWand::RgbWand(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RgbWand)
{
    ui->setupUi(this);
    ui->label_2->setText("<font color= 'red'>Verbunden</font>");
    mThread = new MyThread(this);
    connect(mThread, SIGNAL(ValChanged(float)), this, SLOT(onValChanged(float)));
    connect(mThread, SIGNAL(Verbunden(int)), this, SLOT(onVerbunden(int)));
    connect(mThread, SIGNAL(Threadrun(int)), this, SLOT(onThreadrun(int)));

    pcaInit = pca->pca9635Setup(0x3f);

    //connect(pca,SIGNAL(pca9635Setup(int)),this,SLOT(onPcafd(int)));
    //connect(this,SIGNAL(on_SliderRot_valueChanged(int)),pca,SLOT(pca9635PWMWrite(int,int,int)));
    //pcaInit = pca9635Setup(0x3f);
}

RgbWand::~RgbWand()
{

    delete ui;
}

void RgbWand::on_pushStart_clicked()
{
    mThread->stop = false;
    mThread->start();

}


void RgbWand::onValChanged(float Val)
{
    ui->label->setText(QString::number(Val));
}

void RgbWand::onVerbunden(int Verbunden)
{
    if (Verbunden < 0)ui->label_2->setText("<font color= 'green'>Verbunden</font>");
    else ui->label_2->setText("<font color= 'red'>Verbunden</font>");
    ui->label_3->setText(QString::number(Verbunden));
}

void RgbWand::onThreadrun(int run)
{
    ui->label_4->setText(QString::number(run));
}

void RgbWand::on_pushStop_clicked()
{
     mThread->stop = true;
}

void RgbWand::on_SliderBlau_valueChanged(int value)
{
    value = 255 - value;
    pca->pca9635PWMWrite(pcaInit,0x07,value);
}

void RgbWand::on_SliderGruen_valueChanged(int value)
{
    value = 255 - value;
    pca->pca9635PWMWrite(pcaInit,0x05,value);
}

void RgbWand::on_SliderRot_valueChanged(int value)
{
    value = 255 - value;
    pca->pca9635PWMWrite(pcaInit,0x06,value);
}
