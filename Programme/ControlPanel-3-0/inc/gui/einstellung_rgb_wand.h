/*!
 * \file einstellung_rgb_wand.h 
 * \brief Header für die Wand-RGB-Einstellung GUI
 */
#ifndef EINSTELLUNGRGBWAND_H
#define EINSTELLUNGRGBWAND_H

#include <QDialog>
#include <QDebug>

#include "inc/model/jugendraum.h"
#include "inc/model/j_slider.h"

namespace Ui {
class EinstellungRGBWand;
}

/*!
 * \brief Klasse für GUI der Einstellungen der RGB an der Wand
 * \todo debug-labels in der GUI entfernen
 */

class EinstellungRGBWand : public QDialog
{
    Q_OBJECT
    
public:
    explicit EinstellungRGBWand(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~EinstellungRGBWand();
    
private slots:
    void on_pushButton_back_released();
    void on_pushButton_on_off_toggled(bool checked);
    void on_pushButton_set_color_toggled(bool checked);
    void sliderRedChanged(int val);
    void sliderGreenChanged(int val);
    void sliderBlueChanged(int val);
    
private:
    Ui::EinstellungRGBWand *ui_;
    Jugendraum *jugendraum_;
    JSlider* slider_red_, * slider_green_, * slider_blue_;
};

#endif // EINSTELLUNGRGBWAND_H
