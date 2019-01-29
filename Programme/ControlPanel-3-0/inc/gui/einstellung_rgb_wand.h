/*!
 * \file einstellung_rgb_wand.h 
 * \brief Header für die Wand-RGB-Einstellung GUI
 */
#ifndef EINSTELLUNGRGBWAND_H
#define EINSTELLUNGRGBWAND_H

#include <QDialog>
#include <QDebug>

#include "inc/model/jugendraum.h"

namespace Ui {
class EinstellungRGBWand;
}

/*!
 * \brief Klasse für GUI der Einstellungen der RGB an der Wand
 * \todo irgendwie beim Klicken von "Farbe einstellen" deutlich machen, 
 * dass der Klick erkannt wurde und die Slider jetzt benutzt werden können
 */

class EinstellungRGBWand : public QDialog
{
    Q_OBJECT
    
public:
    explicit EinstellungRGBWand(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~EinstellungRGBWand();
    
private slots:
    void on_pushButton_back_released();
    void on_pushButton_on_off_released();
    void on_pushButton_set_color_released();
    
private:
    Ui::EinstellungRGBWand *ui_;
    Jugendraum *jugendraum_;
};

#endif // EINSTELLUNGRGBWAND_H
