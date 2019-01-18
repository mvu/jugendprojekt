/*!
 * \file einstellung_audio.h 
 * \brief Header für die Audio-Einstellung GUI
 */
#ifndef EINSTELLUNG_AUDIO_H
#define EINSTELLUNG_AUDIO_H

#include <QDialog>
#include <QDebug>

#include "inc/model/jugendraum.h"

namespace Ui {
class EinstellungAudio;
}

/*!
 * \brief Klasse für GUI der Audio-Einstellungen
 * \todo Weitere Einstellungen, z.B. Zonen usw.
 * \todo Ein/Aus-Knopf schöner designen und bei "Aus" alle anderen Buttons deaktiviern, vielleicht mit Fehlermeldung
 * \todo Umbenennun in "Anlage", "Onkyo" oder so
 */

class EinstellungAudio : public QDialog
{
    Q_OBJECT
    
public:
    explicit EinstellungAudio(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~EinstellungAudio();
    
private slots:
    void on_pushButton_input_aux_released();   
    void on_pushButton_input_pc_released();
    void on_pushButton_input_playstation_released();    
    void on_pushButton_volume_high_released();    
    void on_pushButton_volume_low_released();    
    void on_pushButton_volume_medium_released();   
    void on_pushButton_back_released();    
    void on_pushButton_on_off_released();
    
private:
    Ui::EinstellungAudio *ui_;
    Jugendraum *jugendraum_;
};

#endif // EINSTELLUNG_AUDIO_H
