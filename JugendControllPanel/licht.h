#ifndef LICHT_H
#define LICHT_H

#include <QDialog>
#include "einstellunglicht.h"


namespace Ui {
class Licht;
}

class Licht : public QDialog
{
    Q_OBJECT

public:
    explicit Licht(QWidget *parent = 0);
    ~Licht();

private slots:
    void on_pushButtonJugend_clicked();

    void on_pushButtonTeenkreis_clicked();

    void on_pushButtonPraisTime_clicked();

    void on_pushButtonMovie_clicked();

    void on_pushButtonEinstellung_clicked();



private:
    Ui::Licht *ui;

    EinstellungLicht * einstellungLicht;
};

#endif // LICHT_H
