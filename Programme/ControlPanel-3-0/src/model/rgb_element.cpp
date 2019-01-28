/*!
 * \file rgb_element.cpp
 * \brief Source für die RGB-Basisklasse
 */

#include "inc/model/rgb_element.h"

RGBElement::RGBElement() :
    JElement ()
{
    
}

RGBElement::~RGBElement()
{

}

int RGBElement::getRedValue()
{
    qDebug() << Q_FUNC_INFO;
    return red_value_;
}

int RGBElement::getGreenValue()
{
    qDebug() << Q_FUNC_INFO;
    return green_value_;
}

int RGBElement::getBlueValue()
{
    qDebug() << Q_FUNC_INFO;
    return blue_value_;
}

void RGBElement::setRedValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    red_value_ = value;
}

void RGBElement::setGreenValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    green_value_ = value;
}

void RGBElement::setBlueValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    blue_value_ = value;
}

bool RGBElement::RGBisOn()
{
    qDebug() << Q_FUNC_INFO;
    return rgb_is_on_;
}

void RGBElement::setRGBOn(bool state)
{
    qDebug() << Q_FUNC_INFO;
    rgb_is_on_ = state;
    // sets the hardware to zero. The software values are left unchanged for later use
    std::function<void(void)> updater_red = [this](){hw::writeValue(addr_red_, 0);};
    addToUpdaters(updater_red);
    std::function<void(void)> updater_green = [this](){hw::writeValue(addr_green_, 0);};
    addToUpdaters(updater_green);
    std::function<void(void)> updater_blue = [this](){hw::writeValue(addr_blue_, 0);};
    addToUpdaters(updater_blue);
}

