/*!
 * \file system_status.h
 * \brief Header für die Systemanzeige GUI
 */
#ifndef SYSTEM_STATUS_H
#define SYSTEM_STATUS_H

#include <QDialog>
#include <QCryptographicHash>
#include <QDebug>

#include "inc/gui/passwort.h"

#include "inc/model/jugendraum.h"

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

private:
    Ui::SystemStatus *ui_;
    Passwort *passwort_;
    Jugendraum *jugendraum_;
};

#endif // SYSTEM_STATUS_H
