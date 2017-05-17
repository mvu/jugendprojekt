#include "rgb_decke.h"
#include "ui_rgb_decke.h"

#include <iostream>//for debugging

using namespace std;

RGB_Decke::RGB_Decke(QWidget *parent, steuerungThreadLicht *s, ModelThreadLicht *m) :
    QDialog(parent),
    ui(new Ui::RGB_Decke)
{
    ui->setupUi(this);
    ui->pushButton_back->setVisible(false);

    Slider = new thread_Slider(this);

    sThread = s;
    mThread = m;

    //slide in animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(afterAnimation()));
    animation->setDuration(500);
    animation->setStartValue(QRect(-800,0,400,480));
    animation->setEndValue(QRect(0,0,400,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start();

    //put all PushButtons in Array to be able to loop through them
    ArrayOfPushBottons.append(ui->pushButton_1);
    ArrayOfPushBottons.append(ui->pushButton_2);
    ArrayOfPushBottons.append(ui->pushButton_3);
    ArrayOfPushBottons.append(ui->pushButton_4);
    ArrayOfPushBottons.append(ui->pushButton_5);
    ArrayOfPushBottons.append(ui->pushButton_6);
    ArrayOfPushBottons.append(ui->pushButton_7);
    ArrayOfPushBottons.append(ui->pushButton_8);
    ArrayOfPushBottons.append(ui->pushButton_9);
    ArrayOfPushBottons.append(ui->pushButton_10);
    ArrayOfPushBottons.append(ui->pushButton_11);
    ArrayOfPushBottons.append(ui->pushButton_12);
    ArrayOfPushBottons.append(ui->pushButton_13);
    ArrayOfPushBottons.append(ui->pushButton_14);
    ArrayOfPushBottons.append(ui->pushButton_15);
    ArrayOfPushBottons.append(ui->pushButton_16);
    ArrayOfPushBottons.append(ui->pushButton_17);
    ArrayOfPushBottons.append(ui->pushButton_18);

    //initalize Buttons (border, color)
//    for (int i = 0; i < ArrayOfPushBottons.length(); i++)
//    {
//        std::cout << i << "-> Checked: " << sThread->RGB_Decke_Checked[i] << ", RGB: " << sThread->RGB_Decke_Data[i][0] << ", " << sThread->RGB_Decke_Data[i][1] << ", " << sThread->RGB_Decke_Data[i][2] << "\n";
//        if (sThread->RGB_Decke_Checked[i])
//        {
//            ArrayOfPushBottons[i]->setStyleSheet("border: 2px solid white; border-radius: 10px;");
//        }
//        else
//        {
//            ArrayOfPushBottons[i]->setStyleSheet("border: 2px solid black; border-radius: 10px;");
//        }
//        ArrayOfPushBottons[i]->setChecked(sThread->RGB_Decke_Checked[i]);
//    }
    for (int i = 0; i < ArrayOfPushBottons.length(); i++)
    {
        ArrayOfPushBottons[i]->setStyleSheet("border: 2px solid black; border-radius: 10px;");
        ArrayOfPushBottons[i]->setChecked(false);
    }
    SetAllButtonsColor();
    ui->horizontalSlider->setSliderPosition(sThread->RGB_Decke_Data[0][0]/1.27);

  //Communication between threads
    //Slider -> UI
    connect(Slider, SIGNAL(Slider1_Changed(int)), this, SLOT(SliderRotChanged(int)));
    connect(Slider, SIGNAL(Slider2_Changed(int)), this, SLOT(SliderGruenChanged(int)));
    connect(Slider, SIGNAL(Slider3_Changed(int)), this, SLOT(SliderBlauChanged(int)));
    connect(Slider, SIGNAL(Slider4_Changed(int)), this, SLOT(SliderHellChanged(int)));
    //UI -> stuerungsThreadLicht
    //connect(this, SIGNAL(CheckBox_changed(int,int)), s, SLOT(RGB_Decke_Checked_Changed(int,int)));
    connect(this, SIGNAL(SliderRot_changed(int)), s, SLOT(RGB_Decke_DataRot_Changed(int)));
    connect(this, SIGNAL(SliderGruen_changed(int)), s, SLOT(RGB_Decke_DataGruen_Changed(int)));
    connect(this, SIGNAL(SliderBlau_changed(int)), s, SLOT(RGB_Decke_DataBlau_Changed(int)));

    Slider->start();
    Slider->init(sThread->RGB_Decke_Data[0][0]/1.27,sThread->RGB_Decke_Data[0][1]/1.27,sThread->RGB_Decke_Data[0][2]/1.27,100);//<----- Eleganterer Startwert, Helligkeit
    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(SliderRotChanged(int)));
}


RGB_Decke::~RGB_Decke()
{
    Slider->close();
    delete ui;
}

//eigene Slots

void RGB_Decke::SliderRotChanged(int val)
{
    int wert = int(val*1.27);
    emit SliderRot_changed(wert);
    SetAllButtonsColor();
}

void RGB_Decke::SliderGruenChanged(int val)
{
    int wert = int(val*1.27);
    emit SliderGruen_changed(wert);
    SetAllButtonsColor();
}

void RGB_Decke::SliderBlauChanged(int val)
{
    int wert = int(val*1.27);
    emit SliderBlau_changed(wert);
    SetAllButtonsColor();
}

void RGB_Decke::SliderHellChanged(int val)
{

}

void RGB_Decke::afterAnimation()
{
    ui->pushButton_back->setVisible(true);
}

void RGB_Decke::ButtonPressed(int button, bool checked)
{
    sThread->RGB_Decke_Checked[button-1] = checked;
    //std::cout << button-1 << ": " << sThread->RGB_Decke_Checked[button-1] << "\n";
    if (checked)
    {
        ArrayOfPushBottons[button-1]->setStyleSheet(ArrayOfPushBottons[button-1]->styleSheet().replace(0, 45, QString("border: 2px solid white; border-radius: 10px;")));
    }
    else
    {
        ArrayOfPushBottons[button-1]->setStyleSheet(ArrayOfPushBottons[button-1]->styleSheet().replace(0, 45, QString("border: 2px solid black; border-radius: 10px;")));
    }
}

void RGB_Decke::SetAllButtonsColor()
{
    std::cout << "StyleSheet before: " << ArrayOfPushBottons[0]->styleSheet().toStdString() << "\n";
    std::cout << "RGB: " << sThread->RGB_Decke_Data[0][0] << ", " << sThread->RGB_Decke_Data[0][1] << ", " << sThread->RGB_Decke_Data[0][2] << "\n";
    for (int i = 0; i < ArrayOfPushBottons.length(); i++)
    {
        ArrayOfPushBottons[i]->setStyleSheet(ArrayOfPushBottons[i]->styleSheet().replace(45, 42, QString("background-color:rgba(%1, %2, %3, 80);").arg(sThread->RGB_Decke_Data[i][0]*2).arg(sThread->RGB_Decke_Data[i][1]*2).arg(sThread->RGB_Decke_Data[i][2]*2)));
    }
    std::cout << "StyleSheet after: " << ArrayOfPushBottons[0]->styleSheet().toStdString() << "\n" << "\n";
}

//UI slots


void RGB_Decke::on_pushButton_1_toggled(bool checked)
{
    ButtonPressed(1, checked);
}

void RGB_Decke::on_pushButton_2_toggled(bool checked)
{
    ButtonPressed(2, checked);
}

void RGB_Decke::on_pushButton_3_toggled(bool checked)
{
    ButtonPressed(3, checked);
}

void RGB_Decke::on_pushButton_4_toggled(bool checked)
{
    ButtonPressed(4, checked);
}

void RGB_Decke::on_pushButton_5_toggled(bool checked)
{
    ButtonPressed(5, checked);
}

void RGB_Decke::on_pushButton_6_toggled(bool checked)
{
    ButtonPressed(6, checked);
}

void RGB_Decke::on_pushButton_7_toggled(bool checked)
{
    ButtonPressed(7, checked);
}

void RGB_Decke::on_pushButton_8_toggled(bool checked)
{
    ButtonPressed(8, checked);
}

void RGB_Decke::on_pushButton_9_toggled(bool checked)
{
    ButtonPressed(9, checked);
}

void RGB_Decke::on_pushButton_10_toggled(bool checked)
{
    ButtonPressed(10, checked);
}

void RGB_Decke::on_pushButton_11_toggled(bool checked)
{
    ButtonPressed(11, checked);
}

void RGB_Decke::on_pushButton_12_toggled(bool checked)
{
    ButtonPressed(12, checked);
}

void RGB_Decke::on_pushButton_13_toggled(bool checked)
{
    ButtonPressed(13, checked);
}

void RGB_Decke::on_pushButton_14_toggled(bool checked)
{
    ButtonPressed(14, checked);
}

void RGB_Decke::on_pushButton_15_toggled(bool checked)
{
    ButtonPressed(15, checked);
}

void RGB_Decke::on_pushButton_16_toggled(bool checked)
{
    ButtonPressed(16, checked);
}

void RGB_Decke::on_pushButton_17_toggled(bool checked)
{
    ButtonPressed(17, checked);
}

void RGB_Decke::on_pushButton_18_toggled(bool checked)
{
    ButtonPressed(18, checked);
}

void RGB_Decke::on_pushButton_back_released()
{
    Slider->close();
    //slide out animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(300);
    animation->setStartValue(QRect(0,0,400,480));
    animation->setEndValue(QRect(-800,0,400,480));
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->start();
}
void RGB_Decke::on_pushButton_all_toggled(bool checked)
{
    for (int i = 0; i < ArrayOfPushBottons.length(); i++)
    {
        ArrayOfPushBottons[i]->setChecked(checked);
    }

}

void RGB_Decke::on_pushButton_Group_1_toggled(bool checked)
{
    ui->pushButton_Group_2->setChecked(false);
    ui->pushButton_all->setChecked(false);
    for (int i = 0; i < 10; i++)
    {
        ArrayOfPushBottons[i]->setChecked(checked);
    }
    for (int i = 10; i < 18; i++)
    {
        ArrayOfPushBottons[i]->setChecked(false);
    }
}

void RGB_Decke::on_pushButton_Group_2_toggled(bool checked)
{
    ui->pushButton_Group_1->setChecked(false);
    ui->pushButton_all->setChecked(false);
    for (int i = 0; i < 10; i++)
    {
        ArrayOfPushBottons[i]->setChecked(false);
    }
    for (int i = 10; i < 18; i++)
    {
        ArrayOfPushBottons[i]->setChecked(checked);
    }
}
