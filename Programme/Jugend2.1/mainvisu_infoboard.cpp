#include "mainvisu_infoboard.h"
#include "ui_mainvisu_infoboard.h"

MainVisu_InfoBoard::MainVisu_InfoBoard(QWidget *parent, ModelThreadLicht *m) :
    QDialog(parent),
    ui(new Ui::MainVisu_InfoBoard)
{
    ui->setupUi(this);
    mThread = m;


    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(afterAnimation()));
    animation->setDuration(500);
    animation->setStartValue(QRect(50,-480,0,480));
    animation->setEndValue(QRect(50,0,400,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start();

    ui->gridLayout->setColumnMinimumWidth(1,1);
}

MainVisu_InfoBoard::~MainVisu_InfoBoard()
{
    delete ui;
}

void MainVisu_InfoBoard::on_pushButton_Back_released()
{
    //slide out animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(150);
    animation->setStartValue(QRect(50,0,400,480));
    animation->setEndValue(QRect(50,-480,0,480));
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->start();
    //enable MainWindow
    emit ParentEnable();
}



void MainVisu_InfoBoard::on_pushButton_Relais_released()
{

    if(merker != 3){
        while( ui->gridLayout->count() ) {
            QWidget* widget = ui->gridLayout->itemAt(0)->widget();
            if( widget ) {
            ui->gridLayout->removeWidget(widget);
            delete widget;
            //ui->gridLayout->removeWidget();
            }
        }

        QLabel *LabNet48 = new QLabel(this);
        QLabel *LabInNet48 = new QLabel(this);

        QLabel *LabNet12 = new QLabel(this);
        QLabel *LabInNet12 = new QLabel(this);

        QLabel *LabTheke = new QLabel(this);
        QLabel *LabInTheke = new QLabel(this);

        QLabel *LabBeamer = new QLabel(this);
        QLabel *LabInBeamer = new QLabel(this);

        QLabel *LabPC = new QLabel(this);
        QLabel *LabInPC = new QLabel(this);

        QLabel *LabPalette = new QLabel(this);
        QLabel *LabInPalette = new QLabel(this);

        LabNet48->setText("Netzteil 48V:");
        LabNet12->setText("Netzteil 12V:");
        LabTheke->setText("Theke");
        LabBeamer->setText("Beamer");
        LabPalette->setText("Palette");
        LabPC->setText("PC");


        if(mThread->arrayRelais[NETZTEIL48V]){
            LabInNet48->setText("ON");
            LabInNet48->setStyleSheet("color: green");
        }
        else {
            LabInNet48->setText("OFF");
            LabInNet48->setStyleSheet("color: red");
        }

        if(mThread->arrayRelais[NETZTEIL12V]){
            LabInNet12->setText("ON");
            LabInNet12->setStyleSheet("color: green");
        }
        else {
            LabInNet12->setText("OFF");
            LabInNet12->setStyleSheet("color: red");
        }

        if(mThread->arrayRelais[PC]){
            LabInPC->setText("ON");
            LabInPC->setStyleSheet("color: green");
        }
        else {
            LabInPC->setText("OFF");
            LabInPC->setStyleSheet("color: red");
        }
        if(mThread->arrayRelais[PALETTE]){
            LabInPalette->setText("ON");
            LabInPalette->setStyleSheet("color: green");
        }
        else {
            LabInPalette->setText("OFF");
            LabInPalette->setStyleSheet("color: red");
        }
        if(mThread->arrayRelais[BEAMER]){
            LabInBeamer->setText("ON");
            LabInBeamer->setStyleSheet("color: green");
        }
        else {
            LabInBeamer->setText("OFF");
            LabInBeamer->setStyleSheet("color: red");
        }
        if(mThread->arrayRelais[THEKE]){
            LabInTheke->setText("ON");
            LabInTheke->setStyleSheet("color: green");
        }
        else {
            LabInTheke->setText("OFF");
            LabInTheke->setStyleSheet("color: red");
        }





        ui->gridLayout->addWidget(LabNet48);
        ui->gridLayout->addWidget(LabInNet48);
        ui->gridLayout->addWidget(LabNet12);
        ui->gridLayout->addWidget(LabInNet12);
        ui->gridLayout->addWidget(LabBeamer);
        ui->gridLayout->addWidget(LabInBeamer);
        ui->gridLayout->addWidget(LabPC);
        ui->gridLayout->addWidget(LabInPC);
        ui->gridLayout->addWidget(LabPalette);
        ui->gridLayout->addWidget(LabInPalette);
        ui->gridLayout->addWidget(LabTheke);
        ui->gridLayout->addWidget(LabInTheke);

        merker = 3;
    }

}

void MainVisu_InfoBoard::on_pushButton_Hauptlicht_released()
{
    if(merker != 4){
        while( ui->gridLayout->count() ) {
            QWidget* widget = ui->gridLayout->itemAt(0)->widget();
            if( widget ) {
            ui->gridLayout->removeWidget(widget);
            delete widget;
            //ui->gridLayout->removeWidget();
            }
        }
        QLabel *HL1 = new QLabel(this);
        QLabel *HL1val = new QLabel(this);

        QLabel *HL2 = new QLabel(this);
        QLabel *HL2val = new QLabel(this);

        QLabel *HL3 = new QLabel(this);
        QLabel *HL3val = new QLabel(this);

        QLabel *HL4 = new QLabel(this);
        QLabel *HL4val = new QLabel(this);

        QLabel *HL5 = new QLabel(this);
        QLabel *HL5val = new QLabel(this);

        QLabel *HL6 = new QLabel(this);
        QLabel *HL6val = new QLabel(this);

        QLabel *HL7 = new QLabel(this);
        QLabel *HL7val = new QLabel(this);

        QLabel *HL8 = new QLabel(this);
        QLabel *HL8val = new QLabel(this);

        HL1->setText("Hauptlicht 1:");
        HL2->setText("Hauptlicht 2:");
        HL3->setText("Hauptlicht 3:");
        HL4->setText("Hauptlicht 4:");
        HL5->setText("Hauptlicht 5:");
        HL6->setText("Hauptlicht 6:");
        HL7->setText("Hauptlicht 7:");
        HL8->setText("Hauptlicht 8:");

        HL1val->setText(QString::number((mThread->arrayPWMHL[0]/ 2.55),'f',2).append("%"));
        HL2val->setText(QString::number((mThread->arrayPWMHL[2]/ 2.55),'f',2).append("%"));
        HL3val->setText(QString::number((mThread->arrayPWMHL[3]/ 2.55),'f',2).append("%"));
        HL4val->setText(QString::number((mThread->arrayPWMHL[4]/ 2.55),'f',2).append("%"));
        HL5val->setText(QString::number((mThread->arrayPWMHL[5]/ 2.55),'f',2).append("%"));
        HL6val->setText(QString::number((mThread->arrayPWMHL[6]/ 2.55),'f',2).append("%"));
        HL7val->setText(QString::number((mThread->arrayPWMHL[7]/ 2.55),'f',2).append("%"));
        HL8val->setText(QString::number((mThread->arrayPWMHL[8]/ 2.55),'f',2).append("%"));


        ui->gridLayout->addWidget(HL1);
        ui->gridLayout->addWidget(HL1val);
        ui->gridLayout->addWidget(HL2);
        ui->gridLayout->addWidget(HL2val);
        ui->gridLayout->addWidget(HL3);
        ui->gridLayout->addWidget(HL3val);
        ui->gridLayout->addWidget(HL4);
        ui->gridLayout->addWidget(HL4val);
        ui->gridLayout->addWidget(HL5);
        ui->gridLayout->addWidget(HL5val);
        ui->gridLayout->addWidget(HL6);
        ui->gridLayout->addWidget(HL6val);
        ui->gridLayout->addWidget(HL7);
        ui->gridLayout->addWidget(HL7val);
        ui->gridLayout->addWidget(HL8);
        ui->gridLayout->addWidget(HL8val);

        merker = 4;
    }
}

void MainVisu_InfoBoard::afterAnimation()
{
    ui->pushButton_Back->setVisible(true);
}



void MainVisu_InfoBoard::on_pushButton_Temperatur_released()
{

//    QLabel *controller = new QLabel(this);
//    QLabel *decke = new QLabel(this);
//    QLabel *pc = new QLabel(this);
//    QLabel *onkyo = new QLabel(this);
//    QLabel *pi = new QLabel(this);



//    ui->gridLayout->addWidget(controller);
//    ui->gridLayout->addWidget(decke);
//    ui->gridLayout->addWidget(pc);
//    ui->gridLayout->addWidget(onkyo);
//    ui->gridLayout->addWidget(pi);
}

void MainVisu_InfoBoard::on_pushButton_Main_released()
{
    if(merker != 5){
        while( ui->gridLayout->count() ) {
            QWidget* widget = ui->gridLayout->itemAt(0)->widget();
            if( widget ) {
            ui->gridLayout->removeWidget(widget);
            delete widget;
            //ui->gridLayout->removeWidget();
            }
        }
        QLabel *ComSlider = new QLabel(this);
        QLabel *ComSliderval = new QLabel(this);

        QLabel *ComTemp = new QLabel(this);
        QLabel *ComTempval = new QLabel(this);

        QLabel *ic = new QLabel(this);              // i2c verbindung
        QLabel *icval = new QLabel(this);

        QLabel *Temp = new QLabel(this);
        QLabel *Tempval = new QLabel(this);

        QLabel *Uart = new QLabel(this);
        QLabel *Uartval = new QLabel(this);

        ComSlider->setText("Verbindung Slider:");
        ComTemp->setText("Verbindung Temperatur:");
        ic->setText("I2C Verbindung:");
        Temp->setText("Temperatur Okay:");
        Uart->setText("Uart Verbindung:");

        if(mThread->arryStatus[arStComSlider]){
            ComSliderval->setText("Connect");
            ComSliderval->setStyleSheet("color: green");
        }
        else {
            ComSliderval->setText("disconnect");
            ComSliderval->setStyleSheet("color: red");
        }
        if(mThread->arryStatus[arStComTemp]){
            ComTempval->setText("Connect");
            ComTempval->setStyleSheet("color: green");
        }
        else {
            ComTempval->setText("disconnect");
            ComTempval->setStyleSheet("color: red");
        }
        if(mThread->arryStatus[arStI2c]){
            icval->setText("Connect");
            icval->setStyleSheet("color: green");
        }
        else {
            icval->setText("disconnect");
            icval->setStyleSheet("color: red");
        }
        if(mThread->arryStatus[arStTemp]){
            Tempval->setText("Cool");
            Tempval->setStyleSheet("color: green");
        }
        else {
            Tempval->setText("Alarm");
            Tempval->setStyleSheet("color: red");
        }
        if(mThread->arryStatus[arStUart]){
            Uartval->setText("Connect");
            Uartval->setStyleSheet("color: green");
        }
        else {
            Uartval->setText("disconnect");
            Uartval->setStyleSheet("color: red");
        }

        ui->gridLayout->addWidget(ComSlider);
        ui->gridLayout->addWidget(ComSliderval);
        ui->gridLayout->addWidget(ComTemp);
        ui->gridLayout->addWidget(ComTempval);
        ui->gridLayout->addWidget(ic);
        ui->gridLayout->addWidget(icval);
        ui->gridLayout->addWidget(Temp);
        ui->gridLayout->addWidget(Tempval);
        ui->gridLayout->addWidget(Uart);
        ui->gridLayout->addWidget(Uartval);

        merker = 5;
    }

}
