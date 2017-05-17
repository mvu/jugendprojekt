#ifndef PASSWORT_H
#define PASSWORT_H

#include <QDialog>
#include "mainconfig.h"

#define correctPasswort 12345

namespace Ui {
class Passwort;
}

class Passwort : public QDialog
{
    Q_OBJECT

public:
    explicit Passwort(QWidget *parent = 0);
    ~Passwort();

public slots:
    void resetPassword();

private slots:
    void on_pushButton_back_released();
    void on_pushButton_1_released();
    void on_pushButton_ok_released();
    void on_pushButton_0_released();
    void on_pushButton_2_released();
    void on_pushButton_3_released();
    void on_pushButton_4_released();
    void on_pushButton_5_released();
    void on_pushButton_6_released();
    void on_pushButton_7_released();
    void on_pushButton_8_released();
    void on_pushButton_9_released();

signals:
    void PasswortCorrect();

private:
    Ui::Passwort *ui;
    int inputPasswort;

};

#endif // PASSWORT_H
