#ifndef MODELTHREADLICHT_H
#define MODELTHREADLICHT_H

#include <QObject>
#include <QThread>
#include <QtCore>
#include "mainconfig.h"

class ModelThreadLicht : public QThread
{
    Q_OBJECT

public:
    explicit ModelThreadLicht(QObject *parent = 0);
    void run();

public slots:

signals:


};

#endif // MODELTHREADLICHT_H
