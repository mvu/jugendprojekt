#include "MainVisu_mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  //setup hardware
    init(); // setzen der varibalen für bus in mainconfig

  //create UI
    ui->setupUi(this);
    //timer for clock
    timer_clock = new QTimer(this);
    connect(timer_clock, SIGNAL(timeout()), this, SLOT(time_update()));
    timer_clock->start(1000);//check every second for new time
    //initial reading
    time_update();

  //start main threads
    sThread = new steuerungThreadLicht(this, mThread);
    mThread = new ModelThreadLicht(this, sThread);
    Ueberwachung = new thread_Ueberwachung(this, sThread, mThread);
    sThread->start();
    mThread->start();
    Ueberwachung->start();
    //communication ui->sThread
    connect(this, SIGNAL(allOff()), sThread, SLOT(allOFF()));
    connect(this, SIGNAL(TeenkreisLichtOn()), sThread, SLOT(teenLichtOn()));
    connect(this, SIGNAL(JugendLichtOn()), sThread, SLOT(jugendLichtON()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_lichteinstellung_released()
{
    //disable mainWindow
    ui->centralWidget->setEnabled(false);

    //create menue
    settings = new Menue_Einstellung(this, sThread);
    connect(settings, SIGNAL(ParentEnable()), this, SLOT(MainEnable()));//to enable MainWindow if Menue closed
    settings->setModal(true);
    settings->setWindowFlags(Qt::FramelessWindowHint);
    settings->show();
}

void MainWindow::on_pushButton_teenkreis_released()
{
    if (ui->label_teenkreis_2->text() == "Licht an"){
        //emit TeenkreisLichtOn();//  <--------not completely implementet yet, set all registers so that jugend is off automatically
        ui->label_teenkreis_2->setText("Licht aus");
        ui->label_lugend_2->setText("Licht an");
    }
    else {
        //emit allOff();
        ui->label_teenkreis_2->setText("Licht an");
    }
}

void MainWindow::on_pushButton_jugend_released()
{
    if (ui->label_lugend_2->text() == "Licht an"){
        //emit JugendLichtOn();//  <--------not completely implementet yet, set all registers so that teenkreis is off automatically
        ui->label_lugend_2->setText("Licht aus");
        ui->label_teenkreis_2->setText("Licht an");
    }
    else {
        //emit allOff();
        ui->label_lugend_2->setText("Licht an");
    }
}

void MainWindow::on_pushButton_audio_released()
{
    centralWidget()->setEnabled(false);
    medien = new Medien_auswahl(this, sThread, mThread);
    connect(medien, SIGNAL(ParentEnable()), this, SLOT(MainEnable()));
    medien->setModal(true);
    medien->setWindowFlags(Qt::FramelessWindowHint);
    medien->show();
}

void MainWindow::on_pushButton_system_released()
{
    centralWidget()->setEnabled(false);
    system_2 = new Einstellung(this, sThread, mThread, Ueberwachung);
    connect(system_2, SIGNAL(ParentEnable()), this, SLOT(MainEnable()));
    system_2->setModal(true);
    system_2->setWindowFlags(Qt::FramelessWindowHint);
    system_2->show();
}

void MainWindow::time_update()
{
    QDateTime DateTime = QDateTime::currentDateTime();
    QString time = DateTime.toString("hh:mm");
    QString date = DateTime.toString("dd. MMMM");

    ui->label_datum->setText(date);
    ui->label_uhrzeit->setText(time);
}

void MainWindow::MainEnable()
{
    ui->centralWidget->setEnabled(true);
}

void MainWindow::on_pushButton_clock_released()
{
    centralWidget()->setEnabled(false);
    info = new MainVisu_InfoBoard(this,mThread);
    connect(info, SIGNAL(ParentEnable()),this,SLOT(MainEnable()));
    info->setModal(true);
    info->setWindowFlags(Qt::FramelessWindowHint);
    info->show();
}
