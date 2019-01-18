/*!
 * \file menue_medien.h
 * \brief Header für das Medien Menü
 */
#ifndef MENUE_MEDIEN_H
#define MENUE_MEDIEN_H

#include <QDialog>


#include "inc/model/jugendraum.h"

#include "inc/gui/einstellung_audio.h"


namespace Ui {
class MenueMedien;
}

/*!
 * \brief Klasse für die Medien-Menü GUI
 */
class MenueMedien : public QDialog
{
    Q_OBJECT

public:
    explicit MenueMedien(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~MenueMedien();

private slots:
    void on_pushButton_audio_released();
    void on_pushButton_beamer_released();
    void on_pushButton_pc_released();
    void on_pushButton_back_released();

private:
    Ui::MenueMedien *ui_;
    Jugendraum *jugendraum_;
    EinstellungAudio *einstellung_audio_;
   
};

#endif // MENUE_MEDIEN_H
