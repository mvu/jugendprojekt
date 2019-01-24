#include "inc/model/paletten_licht.h"

PalettenLicht::PalettenLicht():
    JElement()
{
    qDebug() << Q_FUNC_INFO;
    // reads inital state of the hardware
    is_on_ = hw::readState(PALETTE);
}

void PalettenLicht::saveToFile()
{
    qDebug() << Q_FUNC_INFO;
}

void PalettenLicht::loadFromFile()
{
    qDebug() << Q_FUNC_INFO;      
}

void PalettenLicht::setOn(bool state)
{
    qDebug() << Q_FUNC_INFO;
    
    is_on_ = state;
    
    // add update function to list if it isn't already in there
    std::function<void(void)> updater = [this](){hw::writeState(PALETTE, is_on_);};
    std::function<void(void)>* fptr = &updater;
    //(*fptr)();
    addToUpdaters(&updater);
}

bool PalettenLicht::isOn()
{
    qDebug() << Q_FUNC_INFO;
    return is_on_;   
}

