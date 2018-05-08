#include "modelthreadlicht.h"
#include <QtCore>
#include <QtDebug>

ModelThreadLicht::ModelThreadLicht(QObject *parent) :
    QThread(parent)
{

}

void ModelThreadLicht::run()
{
    timer_SLiderCheck = new QTimer(this);
    timer_mainInfo = new QTimer(this);

    connect(timer_mainInfo,SIGNAL(timeout()),this,SLOT(mainInfoCheck()));

}

void ModelThreadLicht::mainInfoCheck(){

}

