#include "inc/model/jugendraum.h"

Jugendraum::Jugendraum()
{
    qDebug() << Q_FUNC_INFO;
    hw::init();
    
    PalettenLicht *pal = new PalettenLicht();
    pal->setOn(true);
    pal->setOn(false);
    pal->setOn(true);
    pal->setOn(false);
    pal->setOn(true);
    pal->setOn(false);
    pal->setOn(true);
    pal->setOn(false);
    pal->setOn(true);
    pal->setOn(false);
    //qDebug() << "update von Hand";
    //std::cout << "update von Hand in jugendraum via std\n";
    //std::cout << pal->updaters_[0] << std::endl;
    //(*(pal->updaters_[0]))();    
    pal->update();
}

void Jugendraum::shutdown()
{
    qDebug() << Q_FUNC_INFO;
}
