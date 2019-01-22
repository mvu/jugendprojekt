/*!
 * \file einstellung_hauptlicht.cpp
 * \brief Header der Hauptlicht-Einstellungs GUI
 */
#ifndef EINSTELLUNG_HAUPTLICHT_H
#define EINSTELLUNG_HAUPTLICHT_H

#include <QDialog>
#include <QList>
#include <QDebug>

#include "inc/model/jugendraum.h"

namespace Ui {
class EinstellungHauptlicht;
}

/*!
 * \brief Klasse der Hauptlicht-Einstellungs GUI
 */
class EinstellungHauptlicht : public QDialog
{
    Q_OBJECT

public:
    explicit EinstellungHauptlicht(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~EinstellungHauptlicht();

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
    void on_pushButton_all_toggled(bool checked);
    void on_pushButton_group_1_toggled(bool checked);
    void on_pushButton_group_2_toggled(bool checked);
    void on_pushButton_on_off_released();
    void on_pushButton_back_released();


private:
    Ui::EinstellungHauptlicht *ui_;
    Jugendraum *jugendraum_;
    QList<QPushButton *> push_buttons_HL_, push_buttons_groups_;
};

#endif // EINSTELLUNG_HAUPTLICHT_H
