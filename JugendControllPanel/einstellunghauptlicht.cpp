#include "einstellunghauptlicht.h"
#include "ui_einstellunghauptlicht.h"
#include <QThread>
#include "thread.h"

QThread cThread;
Thread cObject;

EinstellungHauptlicht::EinstellungHauptlicht(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EinstellungHauptlicht)
{




    ui->setupUi(this);





}

EinstellungHauptlicht::~EinstellungHauptlicht()
{
    cObject.Stop = true;
    delete ui;
}

void EinstellungHauptlicht::onValSliderChanged(int Val)
{
    ui->label->setText(QString::number(Val));
}


//void EinstellungHauptlicht::on_start_clicked()
//{
//    cObject.threadInit(cThread);
//    cObject.moveToThread(&cThread);
//    cThread.start();
//}

void EinstellungHauptlicht::on_pushButton_clicked()
{
    connect(mThread,SIGNAL(ValSlider(int)), this, SLOT(onValSliderChanged(int)));
}
