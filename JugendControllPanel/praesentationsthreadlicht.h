#ifndef PRAESENTATIONSTHREADLICHT_H
#define PRAESENTATIONSTHREADLICHT_H
#include <QtCore>
#include <QThread>
#include "mainwindow.h"
#include "main.h"

class PraesentationsThreadLicht : public QThread
{
    Q_OBJECT
public:
    explicit PraesentationsThreadLicht(QObject *parent = 0);
    void run();
};

#endif // PRAESENTATIONSTHREADLICHT_H
