#include "rgbwand.h"
#include "ui_rgbwand.h"


RgbWand::RgbWand(QWidget *parent, steuerungThreadLicht *s, ModelThreadLicht *m) :
    QDialog(parent),
    ui(new Ui::RgbWand)
{
    ui->setupUi(this);
    ui->horizontalLayoutWidget->setStyleSheet("border:none;");

    Slider = new thread_Slider(this);

    sThread = s;
    mThread = m;

    //slide in animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(-400,0,400,480));
    animation->setEndValue(QRect(0,0,400,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start();
  //Communication
    //UI->sThread
    connect(this,SIGNAL(wandRGBblau(int,int)),s,SLOT(fensterRGBSelectVal(int,int)));
    connect(this,SIGNAL(wandRGBrot(int,int)),s,SLOT(fensterRGBSelectVal(int,int)));
    connect(this,SIGNAL(wandRGBgreun(int,int)),s,SLOT(fensterRGBSelectVal(int,int)));
    //Slider->UI
    connect(Slider, SIGNAL(Slider1_Changed(int)), this, SLOT(SliderChanged_ROT(int)));
    connect(Slider, SIGNAL(Slider2_Changed(int)), this, SLOT(SliderChanged_GRN(int)));
    connect(Slider, SIGNAL(Slider3_Changed(int)), this, SLOT(SliderChanged_BLAU(int)));
}

RgbWand::~RgbWand()
{
    delete ui;
}

void RgbWand::SliderChanged_BLAU(int value)
{
    emit wandRGBblau(RGBFENSTERBLAU,value*2.55);
    sThread->RGB_Wand_Data[2] = value*2.55;
}

void RgbWand::SliderChanged_GRN(int value)
{
    emit wandRGBgreun(RGBFENSTERGRUEN,value*2.55);
    sThread->RGB_Wand_Data[1] = value*2.55;
}

void RgbWand::SliderChanged_ROT(int value)
{
    emit wandRGBrot(RGBFENSTERROT,value*2.55);
    sThread->RGB_Wand_Data[0] = value*2.55;
}

void RgbWand::on_pushButton_back_released()
{
    //slide out animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(150);
    animation->setStartValue(QRect(000,0,400,480));
    animation->setEndValue(QRect(-400,0,400,480));
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->start();
}

void RgbWand::on_pushButton_einst_released()
{
    if (ui->pushButton_einst->text() == "Farbe\neinstellen")
    {
        Slider->start();
        Slider->init(sThread->RGB_Wand_Data[0], sThread->RGB_Wand_Data[1], sThread->RGB_Wand_Data[2], 0);
        ui->pushButton_einst->setText("Einstellung\nbeenden");
    }
    else
    {
        Slider->close();
        ui->pushButton_einst->setText("Farbe\neinstellen");
    }
}

void RgbWand::on_pushButton_toggle_released()
{
    if (ui->pushButton_toggle->text() == "An")
    {
        emit wandRGBrot(RGBFENSTERROT, sThread->RGB_Wand_Data[0]);
        emit wandRGBrot(RGBFENSTERGRUEN, sThread->RGB_Wand_Data[1]);
        emit wandRGBrot(RGBFENSTERBLAU, sThread->RGB_Wand_Data[2]);
        ui->pushButton_toggle->setText("Aus");
    }
    else
    {
        emit wandRGBrot(RGBFENSTERROT, 0);
        emit wandRGBrot(RGBFENSTERGRUEN, 0);
        emit wandRGBrot(RGBFENSTERBLAU, 0);
    }
}
