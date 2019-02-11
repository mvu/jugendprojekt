/*!
 * \file system_status.cpp
 * \brief Source für die Systemanzeige GUI
 */
#include "inc/gui/system_status.h"
#include "ui_system_status.h"

SystemStatus::SystemStatus(QWidget *parent, Jugendraum *j) :
    QDialog(parent),
    ui_(new Ui::SystemStatus)
{
    qDebug() << Q_FUNC_INFO;

    jugendraum_ = j;

    // erzeuge GUI
    ui_->setupUi(this);
    this->setModal(true);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->show();

    // insert labels into an array
    rows[0].t_label = ui_->label_pcb_temp;
    rows[0].f_label = ui_->label_pcb_fan;
    rows[1].t_label = ui_->label_pwr_supply_temp;
    rows[1].f_label = ui_->label_pwr_supply_fan;
    rows[2].t_label = ui_->label_box_temp;
    rows[2].f_label = ui_->label_box_fan;
    rows[3].t_label = ui_->label_pi_temp;
    rows[3].f_label = ui_->label_pi_fan;
    rows[4].t_label = ui_->label_pc_temp;
    rows[4].f_label = ui_->label_pc_fan;
    rows[5].t_label = ui_->label_onkyo_temp;
    rows[5].f_label = ui_->label_onkyo_fan;

    // update timer
    update_timer_ = new QTimer(this);
    connect(update_timer_, SIGNAL(timeout()), this, SLOT(update()));
    update_timer_->start(1000);
    update();

    // slide-in Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(-400,0,400,480));
    animation->setEndValue(QRect(0,0,400,480));
    animation->setEasingCurve(QEasingCurve::InExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

SystemStatus::~SystemStatus()
{
    qDebug() << Q_FUNC_INFO;
    delete update_timer_;
    delete ui_;
}

void SystemStatus::on_pushButton_shutdown_released()
{
    qDebug() << Q_FUNC_INFO;
    passwort_ = new Passwort(this, QCryptographicHash::hash(QByteArray(QString("123").toUtf8()), QCryptographicHash::Sha256));
}

void SystemStatus::on_pushButton_back_released()
{
    qDebug() << Q_FUNC_INFO;

    // slide-out Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(150);
    animation->setStartValue(QRect(0,0,400,480));
    animation->setEndValue(QRect(-400,0,400,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

QColor SystemStatus::makeColor(double val, double high, double crit)
{
    qDebug() << Q_FUNC_INFO;

    return QColor((val > high) ? 255 : 0,
                  (val > crit) ? 0 : 255,
                  0);
}

void SystemStatus::update()
{
    qDebug() << Q_FUNC_INFO;

    // get the current state
    QJsonDocument curr = hw::readUDP(QHostAddress::LocalHost, TEMPERATUR_SERVICE_PORT);

    // move info to labels
    if (not curr.isNull())
    {
        updateRow(rows[0], curr.object().value("PCB"));
        updateRow(rows[1], curr.object().value("Netzteile"));
        updateRow(rows[2], curr.object().value("Schaltschrank"));
        updateRow(rows[3], curr.object().value("Pi"));
        updateRow(rows[4], curr.object().value("PC"));
        updateRow(rows[5], curr.object().value("Onkyo"));
    }
}

void SystemStatus::updateRow(row r, QJsonValue json_params)
{
    // extract the parameters from the json
    double temp = json_params.toObject()["Temperature"].toDouble();
    double t_high = json_params.toObject()["TempHigh"].toDouble();
    double t_crit = json_params.toObject()["TempCritical"].toDouble();
    int fan_speed = json_params.toObject()["FanSpeed"].toInt();

    // setup temperature label
    if (temp > 0)
    {
        QColor col = makeColor(temp, t_high, t_crit);
        r.t_label->setStyleSheet(QString("font: 14pt 'Courier New'; \ncolor: rgb(%1, %2, %3);").arg(col.red()).arg(col.green()).arg(col.blue()));
        r.t_label->setText(QString("%1 °C").arg(temp));
    }
    else
    {
        r.t_label->setStyleSheet("font: 14pt 'Courier New'; \ncolor: white;");
        r.t_label->setText("error");
    }

    // setup fan label
    if (fan_speed == -1)
        r.f_label->setText("-");
    else
        r.f_label->setText(QString("%1 %").arg(fan_speed));


    // qDebug() << "fan = " << fan_speed << "temp = " << temp << ", t_high = " << t_high << ", t_crit = " << t_crit;
}
