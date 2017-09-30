#include "menue_einstellung.h"
#include "ui_menue_einstellung.h"

Menue_Einstellung::Menue_Einstellung(QWidget *parent, steuerungThreadLicht *s, ModelThreadLicht *m) :
    QDialog(parent),
    ui(new Ui::Menue_Einstellung)
{
    ui->setupUi(this);
    sThread = s;
    mThread = m;
    Hauptfenster = parent;

    //slide in animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(800,0,400,480));
    animation->setEndValue(QRect(400,0,400,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start();

    connect(this, SIGNAL(ParentEnable()), parent, SLOT(mainEnable()));
    connect(this, SIGNAL(PaletteToggle(bool)), s, SLOT(paletteLichtOnOff(bool)));

    //initialize Clock
    clock_timer = new QTimer(this);
    connect(clock_timer, SIGNAL(timeout()), this, SLOT(time_update()));
    clock_timer->start(1000);//check every second for new time
    //initial reading
    time_update();

    //initialize Palette-Button
    if (sThread->getStatusPalette())ui->label_5->setText("Paletten aus");
    else ui->label_5->setText("Paletten an");
}

Menue_Einstellung::~Menue_Einstellung()
{
    delete ui;
}


void Menue_Einstellung::on_pushButton_hauptlicht_2_released()
{
    hauptlicht = new EinstellungHauptlicht(Hauptfenster, sThread, mThread);
    connect(hauptlicht, SIGNAL(EnableParent()), this, SLOT(EnableMenue()));
    this->setEnabled(false);
    hauptlicht->setModal(true);
    hauptlicht->setWindowFlags(Qt::FramelessWindowHint);
    hauptlicht->show();
}

void Menue_Einstellung::on_pushButton_RGBdecke_released()
{
//    rgbDecke = new RGB_Decke(Hauptfenster, sThread, mThread);
//    rgbDecke->setModal(true);
//    rgbDecke->setWindowFlags(Qt::FramelessWindowHint);
//    rgbDecke->show();
}

void Menue_Einstellung::on_pushButton_Theke_2_released()
{
    theke = new Theke(Hauptfenster, sThread, mThread);
    connect(theke, SIGNAL(parentEnable()), this, SLOT(EnableMenue()));
    this->setEnabled(false);
    theke->setModal(true);
    theke->setWindowFlags(Qt::FramelessWindowHint);
    theke->showFullScreen();

}

void Menue_Einstellung::on_pushButton_palette_released()
{
    if (ui->label_5->text() == "Paletten an")
    {
        emit PaletteToggle(true);
        ui->label_5->setText("Paletten aus");
    }
    else
    {
        emit PaletteToggle(false);
        ui->label_5->setText("Paletten an");
    }
}

void Menue_Einstellung::on_pushButton_RGBfenster_released()
{
//    rgbWand = new RgbWand(this, sThread, mThread);
//    rgbWand->setModal(true);
//    rgbWand->setWindowFlags(Qt::FramelessWindowHint);
//    rgbWand->show();
}

void Menue_Einstellung::on_pushButton_save_released()
{
    PW = new Passwort(Hauptfenster);
    PW->showFullScreen();
    //connect(PW, SIGNAL(PasswortCorrect()), this, SLOT(Save()));
}

void Menue_Einstellung::on_pushButton_close_released()
{
    //slide out animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(150);
    animation->setStartValue(QRect(400,0,400,480));
    animation->setEndValue(QRect(800,0,400,480));
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->start();
    //enable MainWindow
    emit ParentEnable();
}

void Menue_Einstellung::time_update(){
    QDateTime DateTime = QDateTime::currentDateTime();
    QString time = DateTime.toString("hh:mm");

    ui->label_uhr_2->setText(time);
}

void Menue_Einstellung::EnableMenue(){
//    ui->verticalLayout_2->setEnabled(true);
    this->setEnabled(true);
}
