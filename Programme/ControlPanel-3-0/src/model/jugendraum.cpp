#include "inc/model/jugendraum.h"

Jugendraum::Jugendraum()
{
    hw::Init();
    // init Klassen
}

void Jugendraum::shutdown()
{
    qDebug() << Q_FUNC_INFO;
}
