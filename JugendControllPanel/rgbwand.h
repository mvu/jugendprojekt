#ifndef RGBWAND_H
#define RGBWAND_H

#include <QDialog>
#include "mythread.h"
#include "pca_9635.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>


#define pca9635_rot 3

namespace Ui {
class RgbWand;
}

class RgbWand : public QDialog
{
    Q_OBJECT

public:
    explicit RgbWand(QWidget *parent = 0);
    ~RgbWand();

    MyThread * mThread;
    pca_9635 *pca;


private slots:
    void on_pushStart_clicked();

    void on_pushStop_clicked();

    void on_SliderRot_valueChanged(int value);

    void on_SliderGruen_valueChanged(int value);

    void on_SliderBlau_valueChanged(int value);
signals:


public slots:
    void onValChanged(float);
    void onVerbunden(int);
    void onThreadrun(int);
    //void onPcafd(int);

private:
    Ui::RgbWand *ui;
    int pcaInit;
};

#endif // RGBWAND_H
