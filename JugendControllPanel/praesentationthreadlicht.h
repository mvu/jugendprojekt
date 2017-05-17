#ifndef PRAESENTATIONTHREADLICHT_H
#define PRAESENTATIONTHREADLICHT_H

#include <QObject>
#include <QThread>
#include <QtCore>
#include "mainwindow.h"
#include "main.h"


class PraesentationThreadLicht : public QThread
{
    //Q_OBJECT

public:
    //explicit PraesentationThreadLicht(QObject *parent = 0);
    MyThread();
    void run();


signals:


};

#endif // PRAESENTATIONTHREADLICHT_H
