#include "einstellunglicht.h"
#include "ui_einstellunglicht.h"
#include "einstellunghauptlicht.h"
#include "rgbwand.h"

EinstellungLicht::EinstellungLicht(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EinstellungLicht)
{
    ui->setupUi(this);
}

EinstellungLicht::~EinstellungLicht()
{
    delete ui;
}

void EinstellungLicht::on_pushButtonHauptlicht_clicked()

{
    einstellunghauptlicht = new EinstellungHauptlicht(this);
    einstellunghauptlicht->show();

}

void EinstellungLicht::on_pushButtonRGBWand_clicked()
{
    rgbwand = new RgbWand(this);
    rgbwand->show();
}

void EinstellungLicht::on_pushButtonRGBDecke_clicked()
{

}


void EinstellungLicht::on_pushButtonPaletten_clicked()
{

}

void EinstellungLicht::on_pushButtonDinner_clicked()
{

}

void EinstellungLicht::on_pushButtonTheke_clicked()
{

}
