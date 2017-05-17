
#include "praesentationthreadlicht.h"
#include <QtCore>
#include <QDebug>

PraesentationThreadLicht::MyThread()
{

}

void PraesentationThreadLicht::run()
{
    MainWindow w;

    w.showFullScreen();
}
