/*!
 * \file system_status.h
 * \brief Header für die Systemanzeige GUI
 */
#ifndef SYSTEM_STATUS_H
#define SYSTEM_STATUS_H

#include <QDialog>
#include <QCryptographicHash>
#include <QList>
#include <QTimer>
#include <QJsonDocument>
#include <QDebug>

#include "inc/gui/passwort.h"

#include "inc/model/jugendraum.h"
#include "inc/model/file_handler.h"
#include "inc/model/hardware.h"

namespace Ui {
class SystemStatus;
}

/*!
 * \brief Klasse für die Systemanzeige GUI
 */
class SystemStatus : public QDialog
{
    Q_OBJECT

public:
    explicit SystemStatus(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~SystemStatus();

private slots:
    void on_pushButton_shutdown_released();
    void on_pushButton_back_released();

    void update();  // reads the current temps and fan speeds from temperatur service, writes it to labels
    // void setLabelTemperatur(QString name, double temp);
    QColor makeColor(double val, double high, double crit); // used to determine which color the label should have


private:
    Ui::SystemStatus *ui_;
    Passwort *passwort_;
    Jugendraum *jugendraum_;
    QTimer *update_timer_;
};

#endif // SYSTEM_STATUS_H
