#ifndef EINSTELLUNGLICHT_H
#define EINSTELLUNGLICHT_H

#include <QDialog>
#include "einstellunghauptlicht.h"
#include "rgbwand.h"

namespace Ui {
class EinstellungLicht;
}

class EinstellungLicht : public QDialog
{
    Q_OBJECT

public:
    explicit EinstellungLicht(QWidget *parent = 0);
    ~EinstellungLicht();

private slots:
    void on_pushButtonHauptlicht_clicked();

    void on_pushButtonRGBWand_clicked();

    void on_pushButtonRGBDecke_clicked();

    void on_pushButtonTheke_clicked();

    void on_pushButtonPaletten_clicked();

    void on_pushButtonDinner_clicked();


private:
    Ui::EinstellungLicht *ui;

    EinstellungHauptlicht * einstellunghauptlicht;
    RgbWand * rgbwand;
};

#endif // EINSTELLUNGLICHT_H
