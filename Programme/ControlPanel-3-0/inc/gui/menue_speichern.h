/*!
 * \file menue_speichern.h
 * \brief Header der Speicher-Menü GUI
 */
#ifndef MENUE_SPEICHERN_H
#define MENUE_SPEICHERN_H

#include <QDialog>
#include <QCryptographicHash>
#include <QDebug>

#include "inc/gui/passwort.h"

#include "inc/model/jugendraum.h"

namespace Ui {
class MenueSpeichern;
}

/*!
 * \brief Klasse der Speicher-Menü GUI
 * \details Fragt nach, ob die aktuelle Einstellung als default für die Jugend
 *      oder den Teenkreis gespeichert werden soll. Zum Speichern wird nach dem
 *      Passwort gefragt.
 * \todo Fensterposition eher linke Hälfte für mehr Ruhe in der Ansicht?
 * \todo Reale Passwörter für Jugend und Teenkreis verwenden
 * \todo wirklich speichern
 */
class MenueSpeichern : public QDialog
{
    Q_OBJECT

public:
    explicit MenueSpeichern(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~MenueSpeichern();

private slots:
    void on_pushButton_youth_released();
    void on_pushButton_teen_released();
    void on_pushButton_back_released();

    void SaveAllForYouth();
    void SaveAllForTeens();

private:
    Ui::MenueSpeichern *ui_;
    Jugendraum *jugendraum_;
    Passwort *password_;
};

#endif // MENUE_SPEICHERN_H
