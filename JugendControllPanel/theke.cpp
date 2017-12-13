#include "theke.h"
#include "ui_theke.h"

#define SliderEnable false //to select between hardware and softwaresliders; false -> softwareslider

Theke::Theke(QWidget *parent, steuerungThreadLicht *s, ModelThreadLicht *m) :
    QDialog(parent),
    ui(new Ui::Theke)
{
    ui->setupUi(this);
    ui->horizontalLayoutWidget_2->setStyleSheet("border:none;");
    ui->horizontalLayoutWidget_3->setStyleSheet("border:none;");
    //ui->horizontalLayout_5->setStyleSheet("border:none;");
    ui->pushButton_back->setVisible(false);
    //ui->horizontalGroupBox_setColor->setEnabled(false);

    if(SliderEnable == true)slider = new thread_Slider(this);


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
    if(SliderEnable == true){
        connect(slider, SIGNAL(Slider1_Changed(int)), this, SLOT(SliderChanged_ROT(int)));
        connect(slider, SIGNAL(Slider2_Changed(int)), this, SLOT(SliderChanged_GRN(int)));
        connect(slider, SIGNAL(Slider3_Changed(int)), this, SLOT(SliderChanged_BLAU(int)));
    }
    //connect(this, SIGNAL(parentEnable()),einstellung,SLOT(EnableMenue()));

  //initialize display to current status
    //Decke-Button
    if (sThread->thekegetDecke())ui->pushButton->setText("Aus");
    else ui->pushButton->setText("An");
    //slider
}

Theke::~Theke()
{
    //emit parentEnable();
    delete ui;
}

void Theke::SliderChanged_ROT(int val)
{
    std::cout << "ROT: " << val << "\n";
    emit thekeRGBrot(RGBTHEKEROT,val*2.55);
    sThread->RGB_Theke_Data[0]=val*2.55;
    //ui->color->setStyleSheet(QString("background-color:rgba(%1,%2,%3,100);").arg(ui->verticalSlider_Rot->value()).arg(ui->verticalSlider_Gruen->value()).arg(ui->verticalSlider_Blau->value()));
}

void Theke::SliderChanged_BLAU(int val)
{
    std::cout << "BLAU: " << val << "\n";
    emit thekeRGBrot(RGBTHEKEBLAU,val*2.55);
    sThread->RGB_Theke_Data[2]=val*2.55;
    //ui->color->setStyleSheet(QString("background-color:rgba(%1,%2,%3,100);").arg(ui->verticalSlider_Rot->value()).arg(ui->verticalSlider_Gruen->value()).arg(ui->verticalSlider_Blau->value()));
}

void Theke::SliderChanged_GRN(int val)
{
    std::cout << "GRUEN: " << val << "\n";
    emit thekeRGBrot(RGBTHEKEGREUN,val*2.55);
    sThread->RGB_Theke_Data[1]=val*2.55;
    //ui->color->setStyleSheet(QString("background-color:rgba(%1,%2,%3,100);").arg(ui->verticalSlider_Rot->value()).arg(ui->verticalSlider_Gruen->value()).arg(ui->verticalSlider_Blau->value()));
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
    ui->pushButton_rgb_togge->setText("Aus");
    if(ui->pushButton_rgb_set->text() == "Farbe\neinstellen"){
        //color->open();
        QColor getColor = color->getColor(Qt::white,this);
        SliderChanged_BLAU(getColor.blue());
        SliderChanged_GRN(getColor.green());
        SliderChanged_ROT(getColor.red());
    }
    else{
        ui->pushButton_rgb_set->setText("Farbe\neinstellen");
    }

    //int gre = getColor.green();
    //int blue = getColor.blue();
    //int red = getColor.red();
    //std::cout << "out put Color:"<<"grün:"<<gre<<" blau:"<<blue<<" rot:"<<red<< "\n";


    /*
    ui->pushButton_rgb_togge->setText("Aus");
    if (ui->pushButton_rgb_set->text() == "Farbe\neinstellen"){
        if(SliderEnable == true){
            slider->start();
            slider->init(sThread->RGB_Theke_Data[0], sThread->RGB_Theke_Data[1], sThread->RGB_Theke_Data[2], 50);
        }
        else{
            ui->horizontalGroupBox_setColor->setEnabled(true);
        }
        ui->pushButton_rgb_set->setText("Einstellung\nbeenden");
    }
    else
    {
        if(SliderEnable == true)slider->close();
        else ui->horizontalGroupBox_setColor->setEnabled(false);
        ui->pushButton_rgb_set->setText("Farbe\neinstellen");
    }
    */
}

void Theke::on_pushButton_back_released()
{
    //slide out animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(150);
    animation->setStartValue(QRect(000,0,400,560));
    animation->setEndValue(QRect(-400,0,400,560));
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->start();
    emit parentEnable();

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
