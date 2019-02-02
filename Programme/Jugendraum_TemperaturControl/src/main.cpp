/*!
 * \authors
 *      + [JonasWitzenrath](https://github.com/JonasWitzenrath)
 * \version 1.0
 *
 * \copyright GNU Public License
 *
 * \mainpage Systemservice, der die Temperaturen überwacht und die Lüfter regelt
 *
 */


#include <QCoreApplication>
#include "inc/temperature_manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // instantiate temperatur manager
    TemperatureManager tm;
    tm.operate();

    return a.exec();
}
