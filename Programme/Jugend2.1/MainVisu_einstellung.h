#ifndef EINSTELLUNG_H
#define EINSTELLUNG_H

#include <QDialog>

#include "mainconfig.h"
#include "MainVisu_passwort.h"


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
    void TempRaum_neu(float val, int pwm);
    void TempNetzteil_neu(float val, int pwm);
    void TempPlatine_neu(float val, int pwm);
    void TempPi_neu(float val);
    void TempPc_neu(float val);
    void TempOnkyo_neu(float val, int pwm);

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
