#include "inc/model/jugendraum.h"

Jugendraum::Jugendraum()
{
    hw::init();
    
    PalettenLicht *pal = new PalettenLicht();
    pal->setOn(true);
    pal->setOn(false);
    
    pal->update();
}

void Jugendraum::shutdown()
{
    qDebug() << Q_FUNC_INFO;
}
