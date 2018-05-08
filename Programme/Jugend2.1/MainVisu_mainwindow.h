#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mainconfig.h"

//fenster
#include "MainVisu_menue_einstellung.h"
#include "MainVisu_einstellung.h"
#include "MainVisu_medien_auswahl.h"
#include "mainvisu_infoboard.h"

class ModelThreadLicht;
class steuerungThreadLicht;
class thread_Ueberwachung;

class Menue_Einstellung;
class Einstellung;
class Medien_auswahl;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //main threads
    steuerungThreadLicht *sThread;
    ModelThreadLicht *mThread;
    thread_Ueberwachung *Ueberwachung;


private slots:
    void on_pushButton_lichteinstellung_released();
    void on_pushButton_teenkreis_released();
    void on_pushButton_jugend_released();
    void on_pushButton_audio_released();
    void on_pushButton_system_released();

    void time_update();
    void MainEnable();

    void on_pushButton_clock_released();

signals:
    void allOff();
    void TeenkreisLichtOn();
    void JugendLichtOn();

private:
    Ui::MainWindow *ui;
    Menue_Einstellung *settings;
    Einstellung *system_2;
    Medien_auswahl *medien;
    QTimer *timer_clock;
    MainVisu_InfoBoard *info;
};

#endif // MAINWINDOW_H
