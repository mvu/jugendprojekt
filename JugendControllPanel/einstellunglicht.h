#ifndef EINSTELLUNGLICHT_H
#define EINSTELLUNGLICHT_H

#include <QDialog>
//#include "einstellunghauptlicht.h"
#include "rgbwand.h"
#include "einstellung.h"
#include "theke.h"
#include "einstellung.h"
#include "mainconfig.h"
#include "steuerungthreadlicht.h"

class Einstellung;
class RgbTheke;
class RgbWand;
//class EinstellungHauptlicht;

namespace Ui {
class EinstellungLicht;
}

class EinstellungLicht : public QDialog
{
    Q_OBJECT


public:
    explicit EinstellungLicht(QWidget *parent = 0);
    ~EinstellungLicht();


private slots:
    void on_pushButtonHauptlicht_clicked();

    void on_pushButtonRGBWand_clicked();

    void on_pushButtonRGBTheke_clicked();

    void on_pushButtonEinstellung_clicked();

    void on_pushButtonTheke_toggled(bool checked);

    void on_pushButtonPaletten_toggled(bool checked);

    void on_pushButtonBeamer_toggled(bool checked);

signals:
    void theke_toggled(bool);
    void palette_toggled(bool);
    void beamer_toggled(bool);

private:
    Ui::EinstellungLicht *ui;
    Einstellung *option;
    //EinstellungHauptlicht *einstellunghauptlicht;
    RgbWand *rgbwand;
    RgbTheke *rgbtheke;
    steuerungThreadLicht * s;


};

#endif // EINSTELLUNGLICHT_H
