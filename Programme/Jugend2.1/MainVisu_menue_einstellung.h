#ifndef MENUE_EINSTELLUNG_H
#define MENUE_EINSTELLUNG_H

#include <QDialog>

#include "mainconfig.h"

//fenster
#include "MainVisu_einstellunghauptlicht.h"
#include "MainVisu_rgb_decke.h"
#include "MainVisu_theke.h"
#include "MainVisu_rgbwand.h"
#include "MainVisu_passwort.h"

class steuerungThreadLicht;
class ModelThreadLicht;
class EinstellungHauptlicht;
class RGB_Decke;
class Theke;
class RgbWand;
class Passwort;

namespace Ui {
class Menue_Einstellung;
}

class Menue_Einstellung : public QDialog
{
    Q_OBJECT

public:
    explicit Menue_Einstellung(QWidget *parent = 0, steuerungThreadLicht *s = NULL, ModelThreadLicht *m = NULL);
    ~Menue_Einstellung();

public slots:
    void EnableMenue();

private slots:
    void on_pushButton_hauptlicht_2_released();
    void on_pushButton_RGBdecke_released();
    void on_pushButton_Theke_2_released();
    void on_pushButton_palette_released();
    void on_pushButton_RGBfenster_released();
    void on_pushButton_save_released();
    void on_pushButton_close_released();

    void time_update();

signals:
    void ParentEnable();
    void PaletteToggle(bool);

private:
    Ui::Menue_Einstellung *ui;
    QWidget *Hauptfenster;
    steuerungThreadLicht *sThread;
    ModelThreadLicht *mThread;
    EinstellungHauptlicht *hauptlicht;
    RGB_Decke *rgbDecke;
    Theke *theke;
    RgbWand *rgbWand;
    Passwort *PW;
    QTimer *clock_timer;

};

#endif // MENUE_EINSTELLUNG_H
