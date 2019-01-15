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
 */

#include "inc/application.h"

#include "inc/jugendraum.h"
#include "inc/startseite.h"


int main(int argc, char *argv[])
{
    Application a(argc, argv);
    Jugendraum jugendraum;
    Startseite startseite(nullptr, &jugendraum);
    startseite.show();

    return a.exec();
}
