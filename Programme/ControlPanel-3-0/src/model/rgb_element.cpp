/*!
 * \file rgb_element.cpp
 * \brief Source für die RGB-Basisklasse
 */

#include "inc/model/rgb_element.h"

RGBElement::RGBElement()
{
    
}

RGBElement::~RGBElement()
{

}

int RGBElement::getRedValue()
{
    return red_value_;
}

int RGBElement::getGreenValue()
{
    return green_value_;
}

int RGBElement::getBlueValue()
{
    return blue_value_;
}

void RGBElement::setRedValue(int value)
{
    red_value_ = value;
}

void RGBElement::setGreenValue(int value)
{
    green_value_ = value;
}

void RGBElement::setBlueValue(int value)
{
    blue_value_ = value;
}
