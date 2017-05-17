#ifndef EINSTELLUNGHAUPTLICHT_H
#define EINSTELLUNGHAUPTLICHT_H

#include <QDialog>
#include "mainconfig.h"
#include "thread_slider.h"
#include "ui_einstellunghauptlicht.h"

class thread_Slider;
class steuerungThreadLicht;
class ModelThreadLicht;

namespace Ui {
class EinstellungHauptlicht;
}

class EinstellungHauptlicht : public QDialog
{
    Q_OBJECT

public:
    explicit EinstellungHauptlicht(QWidget *parent = 0, steuerungThreadLicht *s = NULL, ModelThreadLicht *m = NULL);
    ~EinstellungHauptlicht();


private:
    Ui::EinstellungHauptlicht *ui;
    thread_Slider *Slider;
    steuerungThreadLicht *sThread;
    ModelThreadLicht *mThread;
    QList<QPushButton *> ArrayOfPushButtons;

signals:
    void HelligkeitChanged(int val);

private slots:
    //personal
    void SliderHellChanged(int value);
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
    void on_pushButton_back_released();
    void on_pushButton_alle_toggled(bool checked);
    void on_pushButton_Group1_toggled(bool checked);
    void on_pushButton_Group2_toggled(bool checked);
};

#endif // EINSTELLUNGHAUPTLICHT_H
