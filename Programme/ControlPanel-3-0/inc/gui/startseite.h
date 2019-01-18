/*!
 * \file startseite.h
 * \brief Header für das Hauptfenster der GUI
 */
#ifndef STARTSEITE_H
#define STARTSEITE_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>

#include "inc/gui/menue_licht.h"
#include "inc/gui/menue_medien.h"
#include "inc/gui/system_status.h"

#include "inc/model/jugendraum.h"

namespace Ui {
class Startseite;
}

/*!
 * \brief GUI: Startseite
 * \todo Entfernen der borders der GroupBoxes, ohne das sich das stylesheet
 *      auf die Buttons überträgt.
 * \todo Schwärzung der Buttons beim Klicken durch Verdunklung ersetzen.
 */
class Startseite : public QMainWindow
{
    Q_OBJECT

public:
    explicit Startseite(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~Startseite();

private slots:
    void on_pushButton_youth_released();
    void on_pushButton_teen_released();
    void on_pushButton_light_released();
    void on_pushButton_media_released();
    void on_pushButton_system_released();

private:
    Ui::Startseite *ui_;
    MenueLicht *menu_light_;        //!< GUI vom Lichtmenü
    MenueMedien *menu_media_;       //!< GUI vom Medienmenü
    SystemStatus *system_status_;   //!< GUI von der Systemanzeige
    Jugendraum *jugendraum_;        //!< Das model
};

#endif // STARTSEITE_H
