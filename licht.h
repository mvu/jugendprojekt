#ifndef LICHT_H
#define LICHT_H

#include <QDialog>
#include "menue_einstellung.h"
#include "mainconfig.h"

class steuerungThreadLicht;
class Menue_Einstellung;

namespace Ui {
class Licht;
}

class Licht : public QDialog
{
    Q_OBJECT

public:
    explicit Licht(QWidget *parent = 0, steuerungThreadLicht *s = NULL);
    ~Licht();

private slots:
    void on_pushButtonEinstellung_clicked();
    void on_pushButtonJugend_toggled(bool checked);
    void on_pushButtonTeenkreis_toggled(bool checked);
    void on_pushButtonMovie_toggled(bool checked);
    void on_pushButtonPraisTime_toggled(bool checked);
    void on_pushButtonLichtAus_released();

signals:
    void jugendLichtOn();
    void teenkreisLichtOn();
    void praistimeLichtOn();
    void kinoLichtOn();
    void lichtAus();

private:
    Ui::Licht *ui;
    Menue_Einstellung *menue;
    steuerungThreadLicht *sThread;
};

#endif // LICHT_H
