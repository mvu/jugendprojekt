/*!
 * \file menue_licht.h
 * \brief Header für das Licht Menü
 */
#ifndef MENUE_LICHT_H
#define MENUE_LICHT_H

#include <QDialog>

#include "inc/gui/einstellung_theke.h"
#include "inc/gui/einstellung_rgb_wand.h"

#include "inc/model/jugendraum.h"

namespace Ui {
class MenueLicht;
}

/*!
 * \brief Klasse die Licht-Menü GUI
 * \todo Schließen button durch Icon ersetzen
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
    EinstellungRgbWand *einstellung_rgb_wand_;
};

#endif // MENUE_LICHT_H
