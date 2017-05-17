#ifndef PCA_9635_H
#define PCA_9635_H

#include <QObject>
#include <QThread>
#include <QtCore>
#include <QDebug>
#include "mainconfig.h"



class pca_9635 : public QObject
{
    Q_OBJECT
public:
    explicit pca_9635(QObject *parent = 0);

private:
    QMutex mutex;
signals:

public slots:
    void pca9635PWMWrite(int fd, int pin, int pwm);
    void pca9635PWMReset(int fd);
    int pca9635PWMRead(int fd, int reg);
    int pca9635Setup(int i2cAddress);
    int pcaInit(int i2c);


};

#endif // PCA_9635_H
