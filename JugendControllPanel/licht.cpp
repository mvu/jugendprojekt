#include "licht.h"
#include "ui_licht.h"
#include "einstellunglicht.h"

Licht::Licht(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Licht)
{
    ui->setupUi(this);

}






Licht::~Licht()
{
    delete ui;
}

void Licht::on_pushButtonJugend_clicked()
{

}

void Licht::on_pushButtonTeenkreis_clicked()
{

}

void Licht::on_pushButtonPraisTime_clicked()
{

}

void Licht::on_pushButtonMovie_clicked()
{

}

void Licht::on_pushButtonEinstellung_clicked()
{
    QString back ="background-image:url(:/new/bilder/bilder/einstelung.png); background-repeat:no-repeat;";
    einstellungLicht = new EinstellungLicht(this);
    einstellungLicht->setStyleSheet(back);
    einstellungLicht->show();

}


