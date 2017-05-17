#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mainconfig.h"

//fenster
#include "menue_einstellung.h"
#include "einstellung.h"

class ModelThreadLicht;
class steuerungThreadLicht;
class thread_Ueberwachung;

class Menue_Einstellung;
class Einstellung;

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

signals:
    void allOff();
    void TeenkreisLichtOn();
    void JugendLichtOn();

private:
    Ui::MainWindow *ui;
    Menue_Einstellung *settings;
    Einstellung *system_2;
    QTimer *timer_clock;
};

#endif // MAINWINDOW_H
