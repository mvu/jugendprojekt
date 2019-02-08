/*!
 * \file einstellung_rgb_decke.h
 * \brief Header der GUI zur Einstellung der Decken-RGBs
 */
#ifndef EINSTELLUNG_RGB_DECKE_H
#define EINSTELLUNG_RGB_DECKE_H

#include <QDialog>
#include <QList>
#include <QtDebug>

#include "inc/model/jugendraum.h"

namespace Ui {
class EinstellungRGBDecke;
}

/*!
 * \brief Klasse der GUI zur Einstellung der Decken-RGBs
 * \details
 * \todo Slider einbauen: Erst Software zum Testen, später Hardware
 */
class EinstellungRGBDecke : public QDialog
{
    Q_OBJECT

public:
    explicit EinstellungRGBDecke(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~EinstellungRGBDecke();

private slots:
    void InitButtons();

    void on_pushButton_1_toggled(bool checked);
    void on_pushButton_2_toggled(bool checked);
    void on_pushButton_3_toggled(bool checked);
    void on_pushButton_4_toggled(bool checked);
    void on_pushButton_5_toggled(bool checked);
    void on_pushButton_6_toggled(bool checked);
    void on_pushButton_7_toggled(bool checked);
    void on_pushButton_8_toggled(bool checked);
    void on_pushButton_9_toggled(bool checked);
    void on_pushButton_10_toggled(bool checked);
    void on_pushButton_11_toggled(bool checked);
    void on_pushButton_12_toggled(bool checked);
    void on_pushButton_13_toggled(bool checked);
    void on_pushButton_14_toggled(bool checked);
    void on_pushButton_15_toggled(bool checked);
    void on_pushButton_16_toggled(bool checked);
    void on_pushButton_17_toggled(bool checked);
    void on_pushButton_18_toggled(bool checked);
    void on_pushButton_group_all_released();
    void on_pushButton_group_1_released();
    void on_pushButton_group_2_released();
    
    void on_pushButton_on_off_released();
    void on_pushButton_back_released();

    
    
private:
    // Überprüft, ob eine Gruppe ausgewählt ist
    void checkForGroups();
    // setzt den Hintergrund aller Buttons auf die Werte ihrer Repräsentationen im Jugendraum
    void updateButtonBackgrounds();
    // setzt den Hintergrund eines Buttons auf die entsprechenden Werte
    void setButtonBackground(QPushButton* button, int red, int green, int blue); // red, blue, green from 0 to 100
    // Überprüft, was der An-/Aus-Button gerade anzeigt
    void checkOnOffState();
    
    Ui::EinstellungRGBDecke *ui_;
    Jugendraum *jugendraum_;
    QList<QPushButton *> push_buttons_rgb_, push_buttons_groups_;
};

#endif // EINSTELLUNG_RGB_DECKE_H
