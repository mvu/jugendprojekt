#include "inc/model/theken_licht.h"

ThekenLicht::ThekenLicht() :
    JElement(), RGBElement()
{
    qDebug() << Q_FUNC_INFO;    
    
    // read initial state from hardware
    top_is_on_ = hw::readState(THEKE);
    red_value_ = hw::readValue(RGB_THEKE_ROT);
    green_value_ = hw::readValue(RGB_THEKE_GRUEN);
    blue_value_ = hw::readValue(RGB_THEKE_BLAU);
    
}

void ThekenLicht::saveToFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;
}

void ThekenLicht::loadFromFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;
}

bool ThekenLicht::topIsOn()
{
    qDebug() << Q_FUNC_INFO;
    return top_is_on_;
}

void ThekenLicht::setTopOn(bool state)
{
    qDebug() << Q_FUNC_INFO;
    top_is_on_ = state;
    
    // add update function to list if it isn't already in there
    UpdateFunc updater = [this](){hw::writeState(THEKE, top_is_on_);};
    addToUpdaters(updater);
}

void ThekenLicht::setRedValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    red_value_ = value;
    
    // add update function to list if it isn't already in there
    UpdateFunc updater = [this](){hw::writeValue(RGB_THEKE_ROT, red_value_);};
    addToUpdaters(updater);
}

void ThekenLicht::setGreenValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    green_value_ = value;
    
    // add update function to list if it isn't already in there
    UpdateFunc updater = [this](){hw::writeValue(RGB_THEKE_GRUEN, green_value_);};
    addToUpdaters(updater);
}

void ThekenLicht::setBlueValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    blue_value_ = value;
    
    // add update function to list if it isn't already in there
    UpdateFunc updater = [this](){hw::writeValue(RGB_THEKE_BLAU, blue_value_);};
    addToUpdaters(updater);
}
