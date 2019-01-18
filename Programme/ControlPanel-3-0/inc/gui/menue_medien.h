/*!
 * \file menue_medien.h
 * \brief Header für die Medien-Menü GUI
 */
#ifndef MENUE_MEDIEN_H
#define MENUE_MEDIEN_H

#include <QDialog>
#include <QDebug>

#include "inc/model/jugendraum.h"

namespace Ui {
class MenueMedien;
}

/*!
 * \brief Klasse für die Medien-Menü GUI
 * \todo Verdunklung der Buttons bei Klicken
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
};

#endif // MENUE_MEDIEN_H
