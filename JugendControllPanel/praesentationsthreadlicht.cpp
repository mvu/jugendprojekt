#include "praesentationsthreadlicht.h"
#include <QtCore>
#include <QtDebug>

PraesentationsThreadLicht::PraesentationsThreadLicht(QObject *parent)   :
    QThread(parent)
{

}

void PraesentationsThreadLicht::run(){
    MainWindow w;

    w.showFullScreen();
}
