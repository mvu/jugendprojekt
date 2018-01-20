#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include "sliderarduino.h"
#include "mainconfig.h"
#include "pca_9635.h"

class pca_9635;
class SliderArduino;

class MyThread : public QThread
{
    Q_OBJECT

public:
    explicit MyThread(QObject *parent = 0);
    void run();
    bool Stop;
    SliderArduino *slider;
    pca_9635 *pca;

signals:
    void SliderChanged(int);
    void ValChanged(int);
    void Verbunden(int);
    void Threadrun(int);

public slots:
    void checkBoxChanged(int index, bool value);

};

#endif // MYTHREAD_H

//pca_9635 pca;     erstellt ein Objetct
//pca_9635 *pca2 = new pca_9635();      erstellt ein neune zeiger

