#ifndef MEDIEN_AUSWAHL_H
#define MEDIEN_AUSWAHL_H

#include <QDialog>
#include "audio.h"

class steuerungThreadLicht;
class ModelThreadLicht;
class Audio;

namespace Ui {
class Medien_auswahl;
}

class Medien_auswahl : public QDialog
{
    Q_OBJECT

private slots:
    void time_update();

    void on_pushButton_back_released();

    void on_pushButton_Audio_released();

    void on_pushButton_Beamer_toggled(bool checked);

    void on_pushButton_PC_toggled(bool checked);

public slots:

signals:
    void ParentEnable();
    void beamer(bool);
    void pc_pulse();

public:
    explicit Medien_auswahl(QWidget *parent = 0, steuerungThreadLicht *s = NULL, ModelThreadLicht *m = NULL);
    ~Medien_auswahl();

private:
    Ui::Medien_auswahl *ui;
    QTimer *clock_timer;
    steuerungThreadLicht *sThread;
    ModelThreadLicht *mThread;
    QWidget *Hauptfenster;
    Audio *audio;
};

#endif // MEDIEN_AUSWAHL_H
