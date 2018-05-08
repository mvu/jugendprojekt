#ifndef THEKE_H
#define THEKE_H

#include <QDialog>
#include <QColorDialog>

#include "mainconfig.h"
#include "MainVisu_menue_einstellung.h"

class steuerungThreadLicht;
class ModelThreadLicht;
class thread_Slider;
class Menue_Einstellung;

namespace Ui {
class Theke;
}

class Theke : public QDialog
{
    Q_OBJECT

public:
    explicit Theke(QWidget *parent = 0, steuerungThreadLicht *s = NULL, ModelThreadLicht *m = NULL);
    ~Theke();

private:
    Ui::Theke *ui;
    steuerungThreadLicht *sThread;
    ModelThreadLicht *mThread;
    thread_Slider *slider;
    Menue_Einstellung *einstellung;
    QColorDialog *color = new QColorDialog(this);

private slots:
    void SliderChanged_ROT(int val);
    void SliderChanged_GRN(int val);
    void SliderChanged_BLAU(int val);
    void afterAnimation();

    void on_pushButton_rgb_togge_released();
    void on_pushButton_rgb_set_released();
    void on_pushButton_back_released();

    void on_pushButton_released();


signals:
    void thekeRGBrot(int r, int val);
    void thekeRGBblau(int b, int val);
    void thekeRGBgruen(int g, int val);
    void thekeRGBall(int, int, int);
    void thekeDeckeToggle(bool);
    void parentEnable();
};

#endif // THEKE_H
