#include "MainVisu_einstellunghauptlicht.h"
#include "ui_einstellunghauptlicht.h"

#define SlinderarduinoEnable false

//QThread cThread;
//Thread cObject;

EinstellungHauptlicht::EinstellungHauptlicht(QWidget *parent, steuerungThreadLicht *s, ModelThreadLicht *m) :
    QDialog(parent),
    ui(new Ui::EinstellungHauptlicht)
{
    ui->setupUi(this);
    ui->pushButton_back->setVisible(false);

    if(SlinderarduinoEnable == true)
    {
        Slider = new thread_Slider(this);
        ui->horizontalSlider->isHidden();   // Disable Slider if Arduino Slider true
    }
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

    //put all PushButtons in Array to be able to loop through them
    ArrayOfPushButtons.append(ui->pushButton_1);
    ArrayOfPushButtons.append(ui->pushButton_2);
    ArrayOfPushButtons.append(ui->pushButton_3);
    ArrayOfPushButtons.append(ui->pushButton_4);
    ArrayOfPushButtons.append(ui->pushButton_5);
    ArrayOfPushButtons.append(ui->pushButton_6);
    ArrayOfPushButtons.append(ui->pushButton_7);
    ArrayOfPushButtons.append(ui->pushButton_8);
    ArrayOfPushButtons.append(ui->pushButton_9);

    //Setup Sliders
    if(SlinderarduinoEnable == true){
        Slider->init(sThread->Hauptlicht_Data[0]/2.55, 0,0,0);
        Slider->start();
    }


    //setup backgrounds, borders
    for (int i = 0; i < ArrayOfPushButtons.length(); i++)
    {
        ArrayOfPushButtons[i]->setStyleSheet("border: 2px solid black; border-radius: 10px;");
        ArrayOfPushButtons[i]->setChecked(false);
    }
    SetAllButtonsColor();
    ui->horizontalSlider->setSliderPosition(sThread->Hauptlicht_Data[0]/2.55);
    //connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(SliderHellChanged(int)));//<----for testing

    //setup button AnAus
    if (sThread->getStatusHauptlicht()) ui->pushButton_AnAus->setText("Aus");
    else ui->pushButton_AnAus->setText("An");
  //Communication between Threads
    //Slider -> UI
    if(SlinderarduinoEnable == true) connect(Slider, SIGNAL(Slider1_Changed(int)), this, SLOT(SliderHellChanged(int)));

    //UI -> steuerungThreadLicht
    connect(this, SIGNAL(HelligkeitChanged(int)), sThread, SLOT(SetHauptlicht(int)));
    connect(this,SIGNAL(toggelhauptlicht()), sThread,SLOT(hauptlichtNetzteilOnOff()));
    //connect(this,SIGNAL(hauptlichtOn(int)),sThread,SLOT(SetHauptlicht(int)));

    //emit hauptlichtOn(1);
}

EinstellungHauptlicht::~EinstellungHauptlicht()
{
    delete ui;
}

void EinstellungHauptlicht::ButtonPressed(int button, bool checked)
{
    sThread->Hauptlicht_Checked[button -1] = checked;
    //std::cout << "Button:" << button<<"Checked:"<< checked<<"\n";
    //std::cout << button-1 << ": " << sThread->RGB_Decke_Checked[button-1] << "\n";
    if (checked)
    {
        ArrayOfPushButtons[button-1]->setStyleSheet(ArrayOfPushButtons[button-1]->styleSheet().replace(0, 45, QString("border: 2px solid white; border-radius: 10px;")));
    }
    else
    {
        ArrayOfPushButtons[button-1]->setStyleSheet(ArrayOfPushButtons[button-1]->styleSheet().replace(0, 45, QString("border: 2px solid black; border-radius: 10px;")));
    }
}

void EinstellungHauptlicht::SliderHellChanged(int value)
{
    if(SlinderarduinoEnable == false){
        int wert = int(value*2.55);
        if(wert >= 120) wert = 120;
        emit HelligkeitChanged(wert);
        SetAllButtonsColor();
    }
}

void EinstellungHauptlicht::SetAllButtonsColor()
{
    for (int i = 0; i < 9; i++)
    {
            //std::cout<<"Hauptlicht Data"<<sThread->Hauptlicht_Data[i] <<","<<i<<"\n";
            ArrayOfPushButtons[i]->setStyleSheet(ArrayOfPushButtons[i]->styleSheet().replace(45, 42, QString("background-color:rgba(%1, %1, %1, 80);").arg(sThread->Hauptlicht_Data[i])));
    }
}

void EinstellungHauptlicht::afterAnimation()
{
    ui->pushButton_back->setVisible(true);
}

void EinstellungHauptlicht::on_pushButton_1_toggled(bool checked)
{
    ButtonPressed(1, checked);
}

void EinstellungHauptlicht::on_pushButton_2_toggled(bool checked)
{
    ButtonPressed(2, checked);
}

void EinstellungHauptlicht::on_pushButton_3_toggled(bool checked)
{
    ButtonPressed(3, checked);
}

void EinstellungHauptlicht::on_pushButton_4_toggled(bool checked)
{
    ButtonPressed(4, checked);
}

void EinstellungHauptlicht::on_pushButton_5_toggled(bool checked)
{
    ButtonPressed(5, checked);
}

void EinstellungHauptlicht::on_pushButton_6_toggled(bool checked)
{
    ButtonPressed(6, checked);
}

void EinstellungHauptlicht::on_pushButton_7_toggled(bool checked)
{
    ButtonPressed(7, checked);
}

void EinstellungHauptlicht::on_pushButton_8_toggled(bool checked)
{
    ButtonPressed(8, checked);
}

void EinstellungHauptlicht::on_pushButton_9_toggled(bool checked)
{
    ButtonPressed(9, checked);
}

void EinstellungHauptlicht::on_pushButton_alle_toggled(bool checked)
{

    for (int i = 0; i < 9; i++)
    {
        ArrayOfPushButtons[i]->setChecked(checked);
        sThread->Hauptlicht_Checked[i] = checked;
    }
}

void EinstellungHauptlicht::on_pushButton_Group1_toggled(bool checked)
{
    ui->pushButton_Group2->setChecked(false);
    ui->pushButton_alle->setChecked(false);
    for (int i = 0; i < 5; i++)
    {
        ArrayOfPushButtons[i]->setChecked(checked);
    }
    for (int i = 5; i < 9; i++)
    {
        ArrayOfPushButtons[i]->setChecked(false);
    }
}

void EinstellungHauptlicht::on_pushButton_Group2_toggled(bool checked)
{
    ui->pushButton_Group1->setChecked(false);
    ui->pushButton_alle->setChecked(false);
    for (int i = 0; i < 5; i++)
    {
        ArrayOfPushButtons[i]->setChecked(false);
    }
    for (int i = 5; i < 9; i++)
    {
        ArrayOfPushButtons[i]->setChecked(checked);
    }
}

void EinstellungHauptlicht::on_pushButton_back_released()
{
    if(SlinderarduinoEnable == true) Slider->close();
    //slide out animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(300);
    animation->setStartValue(QRect(0,0,400,480));
    animation->setEndValue(QRect(-800,0,400,480));
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->start();
    //switch realais off if no light on
    std::cout << "closing Einstellung\n";
    bool anyOn = false;
    for (int i = 0; i < 9; i++){
        if (sThread->Hauptlicht_Data[i] != 0) {
            anyOn = true;
            break;
        }
    }
    if (anyOn) sThread->hauptlichtNetzteilOn();
    else sThread->hauptlichtNetzteilOff();
    if(SlinderarduinoEnable == true) Slider->exit();
    emit EnableParent();
}

void EinstellungHauptlicht::on_pushButton_AnAus_released()
{
    if (ui->pushButton_AnAus->text() == "An") ui->pushButton_AnAus->setText("Aus");
    else ui->pushButton_AnAus->setText("An");
    emit toggelhauptlicht();
}

void EinstellungHauptlicht::on_horizontalSlider_valueChanged(int value)
{
    SliderHellChanged(value);
}
