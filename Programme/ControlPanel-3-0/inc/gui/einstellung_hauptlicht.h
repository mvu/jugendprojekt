/*!
 * \file einstellung_hauptlicht.h
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
 * \details Bei der Wahl der Gruppen von Gruppen gilt immer, dass sich kleinere Einheiten
 * zu größeren addieren, d.h. einzelne Streifen zu den Gruppen 1,2 oder alle und Gruppe 1 und 2 zu alle.
 * Gruppe 1 und 2 sind jeweils nur ausgewählt, wenn genau ihre Streifen ausgewählt sind und schalten beim 
 * Drücken des jeweiligen Gruppen-Buttons alle nicht zur Gruppe gehörigen Streifen aus, außer wenn dadurch 
 * alle ausgewählt werden.
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
    void on_pushButton_all_released();
    void on_pushButton_group_1_released();
    void on_pushButton_group_2_released();
    void on_pushButton_on_off_released();
    void on_pushButton_back_released();


private:
    /*!
     * \brief Überprüft die Einzelbuttons, ob sie eine der drei Gruppen 
     * all, group_1 oder group_2 bilden. Je nach dem werden die entsprechenden 
     * Buttons umgeschaltet.
     */
    void checkForGroups();
    
    Ui::EinstellungHauptlicht *ui_;
    Jugendraum *jugendraum_;
    QList<QPushButton *> push_buttons_HL_, push_buttons_groups_;
};

#endif // EINSTELLUNG_HAUPTLICHT_H
