/*!
 * \authors
 *      + [CPLMaddin](https://github.com/CPLMaddin)
 *      + [JonasWitzenrath](https://github.com/JonasWitzenrath)
 *      + [ChrisSeibel](https://github.com/ChrisSeibel)
 * \version 3.0
 *
 * \copyright GNU Public License
 *
 * \mainpage Das Hauptprogramm zur Steuerung des Jugendraumes
 *
 */

#include "inc/model/application.h"

#include "inc/model/jugendraum.h"
#include "inc/gui/startseite.h"


int main(int argc, char *argv[])
{
    Application a(argc, argv);
    Jugendraum jugendraum;
    Startseite startseite(nullptr, &jugendraum);
    //startseite.setWindowFlag(Qt::FramelessWindowHint);
    startseite.showFullScreen();

    return a.exec();
}
