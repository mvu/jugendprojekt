/*!
 * \file einstellung_theke.h 
 * \brief Header für die Theke-Einstellung GUI
 */
#ifndef EINSTELLUNG_THEKE_H
#define EINSTELLUNG_THEKE_H

#include <QDialog>

#include "inc/model/jugendraum.h"
#include "inc/model/j_slider.h"

namespace Ui {
class EinstellungTheke;
}

/*!
 * \brief Klasse für die GUI der Thekeneinstellung
 * \todo stylesheets beim Klicken anpassen
 */

class EinstellungTheke : public QDialog
{
    Q_OBJECT
    
public:
    explicit EinstellungTheke(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~EinstellungTheke();
    
private slots:
    void on_pushButton_back_released();
    void on_pushButton_lampen_on_off_released();    
    void on_pushButton_rgb_set_released();    
    void on_pushButton_rgb_on_off_released();
    void sliderRedChanged(int val);
    void sliderGreenChanged(int val);
    void sliderBlueChanged(int val);
    
private:
    Ui::EinstellungTheke *ui_;
    Jugendraum *jugendraum_;
    JSlider* slider_red_, * slider_green_, * slider_blue_;
};

#endif // EINSTELLUNG_THEKE_H
