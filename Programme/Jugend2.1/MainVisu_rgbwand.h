#ifndef RGBWAND_H
#define RGBWAND_H

#include <QDialog>

#include "mainconfig.h"

class steuerungThreadLicht;
class ModelThreadLicht;
class thread_Slider;

namespace Ui {
class RgbWand;
}

class RgbWand : public QDialog
{
    Q_OBJECT

public:
    explicit RgbWand(QWidget *parent = 0, steuerungThreadLicht *s = NULL, ModelThreadLicht *m = NULL);
    ~RgbWand();

private:
    Ui::RgbWand *ui;
    steuerungThreadLicht *sThread;
    ModelThreadLicht *mThread;
    thread_Slider *Slider;

public slots:

signals:
    void wandRGBrot(int, int);
    void wandRGBblau(int, int);
    void wandRGBgreun(int, int);

private slots:
    void SliderChanged_ROT(int value);
    void SliderChanged_GRN(int value);
    void SliderChanged_BLAU(int value);
    void on_pushButton_back_released();
    void on_pushButton_einst_released();
    void on_pushButton_toggle_released();
};

#endif // RGBWAND_H
