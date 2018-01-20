#include "einstellunglicht.h"
#include "ui_einstellunglicht.h"


EinstellungLicht::EinstellungLicht(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EinstellungLicht)
{
    connect(this, SIGNAL(theke_toggled(bool)),s,SLOT(thekeLichtOnOff(bool)));
    connect(this, SIGNAL(beamer_toggled(bool)),s,SLOT(beamerOnOff(bool)));
    connect(this, SIGNAL(palette_toggled(bool)),s,SLOT(paletteLichtOnOff(bool)));

    ui->setupUi(this);
}

EinstellungLicht::~EinstellungLicht()
{
    delete ui;
}

void EinstellungLicht::on_pushButtonHauptlicht_clicked()

{
    //einstellunghauptlicht = new EinstellungHauptlicht(this);
    //einstellunghauptlicht->showFullScreen();
}

void EinstellungLicht::on_pushButtonRGBWand_clicked()
{
    rgbwand = new RgbWand(this);
    rgbwand->showFullScreen();
}

void EinstellungLicht::on_pushButtonRGBTheke_clicked()
{
    rgbtheke = new RgbTheke(this);
    rgbtheke->showFullScreen();

}

void EinstellungLicht::on_pushButtonEinstellung_clicked()
{
    option = new Einstellung(this);
    option->showFullScreen();
}


void EinstellungLicht::on_pushButtonTheke_toggled(bool checked)
{
    emit theke_toggled(checked);
}

void EinstellungLicht::on_pushButtonPaletten_toggled(bool checked)
{
    emit palette_toggled(checked);
}

void EinstellungLicht::on_pushButtonBeamer_toggled(bool checked)
{
    emit beamer_toggled(checked);
}
