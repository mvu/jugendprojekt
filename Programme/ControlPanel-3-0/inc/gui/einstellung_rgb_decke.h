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
 * \todo checked der Gruppen Buttons entsprechend der checked RGB-Buttons setzen
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
    void on_pushButton_group_all_toggled(bool checked);
    void on_pushButton_group_1_toggled(bool checked);
    void on_pushButton_group_2_toggled(bool checked);
    void on_pushButton_on_off_released();
    void on_pushButton_back_released();

private:
    Ui::EinstellungRGBDecke *ui_;
    Jugendraum *jugendraum_;
    QList<QPushButton *> push_buttons_rgb_, push_buttons_groups_;
};

#endif // EINSTELLUNG_RGB_DECKE_H
