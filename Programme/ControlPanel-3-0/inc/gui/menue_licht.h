/*!
 * \file menue_licht.h
 * \brief Header für das Licht Menü
 */
#ifndef MENUE_LICHT_H
#define MENUE_LICHT_H

#include <QDialog>
#include <QDebug>

#include "inc/gui/einstellung_theke.h"
#include "inc/gui/einstellung_rgb_wand.h"
#include "inc/gui/einstellung_hauptlicht.h"
#include "inc/gui/einstellung_rgb_decke.h"
#include "inc/gui/menue_speichern.h"

#include "inc/model/jugendraum.h"

namespace Ui {
class MenueLicht;
}

/*!
 * \brief Klasse die Licht-Menü GUI
 * \todo Schließen button durch Icon ersetzen
 * \todo Verdunklung der Butons bei Klick
 * \todo Update der Uhr
 */
class MenueLicht : public QDialog
{
    Q_OBJECT

public:
    explicit MenueLicht(QWidget *parent = nullptr, Jugendraum  *j = nullptr);
    ~MenueLicht();

public slots:


private slots:
    void on_pushButton_main_light_released();
    void on_pushButton_rgb_ceiling_released();
    void on_pushButton_counter_released();
    void on_pushButton_rgb_windows_released();
    void on_pushButton_palette_released();
    void on_pushButton_save_released();
    void on_pushButton_close_released();

private:
    Ui::MenueLicht *ui_;
    Jugendraum *jugendraum_;
    EinstellungTheke *einstellung_theke_;
    EinstellungRGBWand *einstellung_rgb_wand_;
    EinstellungRGBDecke *einstellung_rgb_decke_;
    EinstellungHauptlicht *einstellung_hauptlicht_;
    MenueSpeichern *menu_speichern_;

};

#endif // MENUE_LICHT_H
