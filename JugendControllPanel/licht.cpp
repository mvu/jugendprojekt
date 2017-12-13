#include "licht.h"
#include "ui_licht.h"


Licht::Licht(QWidget *parent, steuerungThreadLicht *s) :
    QDialog(parent),
    ui(new Ui::Licht)
{

    connect(this, SIGNAL(jugendLichtOnOff()),s,SLOT(thekeLichtOn()));
    connect(this, SIGNAL(teenkreisLichtOnOff()),s,SLOT(teenLichtOn()));
    connect(this, SIGNAL(praistimeLichtOnOff()),s,SLOT(praistime()));
    connect(this, SIGNAL(kinoLichtOnOff()),s,SLOT(kinoOnOff()));
    connect(this ,SIGNAL(lichtAus()),s,SLOT(allOFF()));
    ui->setupUi(this);

    sThread = s;

}

Licht::~Licht()
{
    delete ui;
}


void Licht::on_pushButtonEinstellung_clicked()
{
    menue = new Menue_Einstellung(this, sThread);
    menue->show();
}

void Licht::on_pushButtonJugend_toggled(bool checked)
{
    emit jugendLichtOn();
}

void Licht::on_pushButtonTeenkreis_toggled(bool checked)
{
    emit teenkreisLichtOn();
}

void Licht::on_pushButtonMovie_toggled(bool checked)
{
    emit kinoLichtOn();
}

void Licht::on_pushButtonPraisTime_toggled(bool checked)
{
    emit praistimeLichtOn();
}

void Licht::on_pushButtonLichtAus_released()
{
    emit lichtAus();
}
