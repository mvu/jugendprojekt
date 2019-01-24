#include "inc/model/jugendraum.h"

Jugendraum::Jugendraum()
{
    qDebug() << Q_FUNC_INFO;
    hw::init();
    
    // create all the members
    theken_licht = new ThekenLicht();
    wand_rgb = new WandRGB();
}

void Jugendraum::shutdown()
{
    qDebug() << Q_FUNC_INFO;
}
