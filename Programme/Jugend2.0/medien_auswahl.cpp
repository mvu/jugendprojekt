#include "medien_auswahl.h"
#include "ui_medien_auswahl.h"

Medien_auswahl::Medien_auswahl(QWidget *parent, steuerungThreadLicht *s, ModelThreadLicht *m) :
    QDialog(parent),
    ui(new Ui::Medien_auswahl)
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

    //initialize Clock
    clock_timer = new QTimer(this);
    connect(clock_timer, SIGNAL(timeout()), this, SLOT(time_update()));
    clock_timer->start(1000);//check every second for new time
    //initial reading
    time_update();
	
    //Communication
    connect(this, SIGNAL(beamer(bool)), sThread, SLOT(beamerOnOff(bool)));
    connect(this, SIGNAL(pc_pulse()), sThread, SLOT(pc_pulse()));

    //initialize Beamer-Button
    if (sThread->getStatusBeamer())ui->pushButton_Beamer->setText("Beamer aus");
    else ui->pushButton_Beamer->setText("Beamer an");
}

Medien_auswahl::~Medien_auswahl()
{
    delete ui;
}

void Medien_auswahl::time_update()
{
    QDateTime DateTime = QDateTime::currentDateTime();
    QString time = DateTime.toString("hh:mm");
    ui->label_uhr_2->setText(time);
}


void Medien_auswahl::on_pushButton_back_released()
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

void Medien_auswahl::on_pushButton_Audio_released()
{
	//Audio currently deactivated due to freezing of the window
    /* audio = new Audio(Hauptfenster, sThread, mThread);
    if(audio->isActiveWindow()) return;
    else{
        audio->setModal(true);
        audio->setWindowFlags(Qt::FramelessWindowHint);
        audio->show();
    } */
}

void Medien_auswahl::on_pushButton_Beamer_toggled(bool checked)
{
    emit beamer(checked);
    if (checked){
        ui->pushButton_Beamer->setText("Beamer aus");
    }
    else
    {
        ui->pushButton_Beamer->setText("Beamer an");
    }
}

void Medien_auswahl::on_pushButton_PC_toggled(bool checked)
{
    emit pc_pulse();
}
