#ifndef RGB_DECKE_H
#define RGB_DECKE_H

#include <QDialog>
#include <QList>
#include "mainconfig.h"
#include "thread_slider.h"
#include "ui_rgb_decke.h"

class thread_Slider;
class steuerungThreadLicht;
class ModelThreadLicht;

namespace Ui {
class RGB_Decke;
}

class RGB_Decke : public QDialog
{
    Q_OBJECT

public:
    explicit RGB_Decke(QWidget *parent = 0, steuerungThreadLicht *s = NULL, ModelThreadLicht *m = NULL);
    ~RGB_Decke();

private:
    Ui::RGB_Decke *ui;
    thread_Slider *Slider;
    steuerungThreadLicht *sThread;
    ModelThreadLicht *mThread;
    QList<QPushButton *> ArrayOfPushBottons;

signals:
    void SliderRot_changed(int);
    void SliderGruen_changed(int);
    void SliderBlau_changed(int);

private slots:
    //personal
    void SliderRotChanged(int val);
    void SliderGruenChanged(int val);
    void SliderBlauChanged(int val);
    void SliderHellChanged(int val);
    void afterAnimation();
    void ButtonPressed(int button, bool checked);
    void SetAllButtonsColor();
    //ui

    void on_pushButton_1_toggled(bool checked);
    void on_pushButton_2_toggled(bool checked);
    void on_pushButton_3_toggled(bool checked);
    void on_pushButton_4_toggled(bool checked);
    void on_pushButton_5_toggled(bool checked);
    void on_pushButton_6_toggled(bool checked);
    void on_pushButton_7_toggled(bool checked);
    void on_pushButton_8_toggled(bool checked);
    void on_pushButton_9_toggled(bool checked);
    void on_pushButton_10_toggled(bool checked);
    void on_pushButton_11_toggled(bool checked);
    void on_pushButton_12_toggled(bool checked);
    void on_pushButton_13_toggled(bool checked);
    void on_pushButton_14_toggled(bool checked);
    void on_pushButton_15_toggled(bool checked);
    void on_pushButton_16_toggled(bool checked);
    void on_pushButton_17_toggled(bool checked);
    void on_pushButton_18_toggled(bool checked);
    void on_pushButton_back_released();
    void on_pushButton_all_toggled(bool checked);
    void on_pushButton_Group_1_toggled(bool checked);
    void on_pushButton_Group_2_toggled(bool checked);
};

#endif // RGB_DECKE_H
