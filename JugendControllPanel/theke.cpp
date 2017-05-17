#include "theke.h"
#include "ui_theke.h"

Theke::Theke(QWidget *parent, steuerungThreadLicht *s, ModelThreadLicht *m) :
    QDialog(parent),
    ui(new Ui::Theke)
{
    ui->setupUi(this);
    ui->horizontalLayoutWidget_2->setStyleSheet("border:none;");
    ui->horizontalLayoutWidget_3->setStyleSheet("border:none;");
    ui->pushButton_back->setVisible(false);

    slider = new thread_Slider(this);

    sThread = s;
    mThread = m;

    //slide in animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(afterAnimation()));
    animation->setDuration(250);
    animation->setStartValue(QRect(-400,0,400,480));
    animation->setEndValue(QRect(0,0,400,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start();

  //Communication
    //UI->sThread=s
    connect(this, SIGNAL(thekeRGBblau(int,int)), s, SLOT(thekeRGBSelectVal(int,int)));
    connect(this, SIGNAL(thekeRGBgruen(int,int)), s, SLOT(thekeRGBSelectVal(int,int)));
    connect(this, SIGNAL(thekeRGBrot(int,int)), s, SLOT(thekeRGBSelectVal(int,int)));
    connect(this, SIGNAL(thekeRGBall(int, int, int)), s, SLOT(thekeRGBAllVal(int,int,int)));
    connect(this, SIGNAL(thekeDeckeToggle(bool)), s, SLOT(thekeLichtOnOff(bool)));
    //Slider->UI
    connect(slider, SIGNAL(Slider1_Changed(int)), this, SLOT(SliderChanged_ROT(int)));
    connect(slider, SIGNAL(Slider2_Changed(int)), this, SLOT(SliderChanged_GRN(int)));
    connect(slider, SIGNAL(Slider3_Changed(int)), this, SLOT(SliderChanged_BLAU(int)));
}

Theke::~Theke()
{
    delete ui;
}

void Theke::SliderChanged_ROT(int val)
{
    std::cout << "ROT: " << val << "\n";
    emit thekeRGBrot(RGBTHEKEROT,val*2.55);
    sThread->RGB_Theke_Data[0]=val*2.55;
}

void Theke::SliderChanged_BLAU(int val)
{
    std::cout << "BLAU: " << val << "\n";
    emit thekeRGBrot(RGBTHEKEBLAU,val*2.55);
    sThread->RGB_Theke_Data[2]=val*2.55;
}

void Theke::SliderChanged_GRN(int val)
{
    std::cout << "GRUEN: " << val << "\n";
    emit thekeRGBrot(RGBTHEKEGREUN,val*2.55);
    sThread->RGB_Theke_Data[1]=val*2.55;
}

void Theke::on_pushButton_rgb_togge_released()
{
    if (ui->pushButton_rgb_togge->text() == "An")//d.h. licht ist aus
    {
        //power für rgb an??
        emit thekeRGBrot(RGBTHEKEROT, sThread->RGB_Theke_Data[0]);
        emit thekeRGBgruen(RGBTHEKEGREUN, sThread->RGB_Theke_Data[1]);
        emit thekeRGBblau(RGBTHEKEBLAU, sThread->RGB_Theke_Data[2]);
        ui->pushButton_rgb_togge->setText("Aus");
    }
    else
    {
        //power für rgb aus??
        emit thekeRGBall(0,0,0); //in source register RGBTHEKEROT ??!!
        ui->pushButton_rgb_togge->setText("An");
    }
}

void Theke::on_pushButton_rgb_set_released()
{
    if (ui->pushButton_rgb_set->text() == "Farbe\neinstellen"){
        slider->start();
        slider->init(sThread->RGB_Theke_Data[0], sThread->RGB_Theke_Data[1], sThread->RGB_Theke_Data[2], 50);
        ui->pushButton_rgb_set->setText("Einstellung\nbeenden");
    }
    else
    {
        slider->close();
        ui->pushButton_rgb_set->setText("Farbe\neinstellen");
    }
}

void Theke::on_pushButton_back_released()
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

void Theke::afterAnimation()
{
    ui->pushButton_back->setVisible(true);
}

void Theke::on_pushButton_released()
{
    if (ui->pushButton->text() == "An")//d.h. licht ist aus
    {
        emit thekeDeckeToggle(true);
        ui->pushButton->setText("Aus");
    }
    else
    {
        emit thekeDeckeToggle(false);
        ui->pushButton->setText("An");
    }
}
