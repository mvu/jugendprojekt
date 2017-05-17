#ifndef EINSTELLUNG_H
#define EINSTELLUNG_H

#include <QDialog>

#include "mainconfig.h"
#include "passwort.h"

//to match color of labels, green below High, yellow between, red above Crit
#define TempPi_High 50
#define TempPi_Crit 70
#define TempNetz_High 40
#define TempNetz_Crit 60
#define TempPlat_High 40
#define TempPlat_Crit 50
#define TempRaum_High 30
#define TempRaum_Crit 35

class steuerungThreadLicht;
class ModelThreadLicht;
class thread_Ueberwachung;
class Passwort;

namespace Ui {
class einstellung;
}

class Einstellung : public QDialog
{
    Q_OBJECT

public:
    explicit Einstellung(QWidget *parent = 0, steuerungThreadLicht *s = NULL, ModelThreadLicht *m = NULL, thread_Ueberwachung *u = NULL);
    ~Einstellung();

public slots:
    void Shutdown();
    void afterAnimation();

private slots:
    void on_pushButton_back_released();
    void on_pushButton_Off_released();
    void TempRaum_neu(float val);
    void TempNetzteil_neu(float val);
    void TempPlatine_neu(float val);
    void TempPi_neu(float val);

signals:
    void luefterSetNetzteil(int val);
    void luefterSetController(int val);
    void luefterSetAusgangOben(int val);

    void getLuefterNetzteil();
    void getLuefterController();
    void getLuefterAusgangOben();

    void ParentEnable();
private:
    Ui::einstellung *ui;
    steuerungThreadLicht *sThread;
    ModelThreadLicht *mThread;
    thread_Ueberwachung *uThread;
    Passwort *password;
};

#endif // EINSTELLUNG_H
