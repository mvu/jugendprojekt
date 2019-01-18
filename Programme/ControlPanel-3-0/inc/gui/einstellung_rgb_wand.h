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
class EinstellungRgbWand;
}

/*!
 * \brief Klasse für GUI der Einstellungen der RGB an der Wand
 */

class EinstellungRgbWand : public QDialog
{
    Q_OBJECT
    
public:
    explicit EinstellungRgbWand(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~EinstellungRgbWand();
    
private slots:
    void on_pushButton_back_released();
    void on_pushButton_on_off_released();
    void on_pushButton_set_color_released();
    
private:
    Ui::EinstellungRgbWand *ui_;
    Jugendraum *jugendraum_;
};

#endif // EINSTELLUNGRGBWAND_H
