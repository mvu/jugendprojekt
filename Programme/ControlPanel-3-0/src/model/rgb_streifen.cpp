/*!
 * \file rgb_streifen.cpp
 * \brief Source der Repräsentation der RGB-Decken-Streifen
 */
#include "inc/model/rgb_streifen.h"

RGBStreifen::RGBStreifen(uint8_t address) :
    RGBElement ()
{
    address_ = address;
    allow_change_ = false;
    
    // read initial values from hardware
    red_value_ = 0; // to be done 
    green_value_ = 0;
    blue_value_ = 0;
    rgb_is_on_ = (red_value_ + green_value_ + blue_value_) != 0;
}

void RGBStreifen::allowChange(bool allow)
{
    qDebug() << Q_FUNC_INFO;
    allow_change_ = allow;
}

void RGBStreifen::setRedValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    
    if (allow_change_)
    {
        red_value_ = value;
    
        // add update function to list if it isn't already in there
        UpdateFunc updater = [this](){};
        addToUpdaters(updater);
    }
}

void RGBStreifen::setGreenValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    
    if (allow_change_)
    {
        green_value_ = value;
    
        // add update function to list if it isn't already in there
        UpdateFunc updater = [this](){};
        addToUpdaters(updater);
    }
    
}

void RGBStreifen::setBlueValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    
    if (allow_change_)
    {
        blue_value_ = value;
    
        // add update function to list if it isn't already in there
        UpdateFunc updater = [this](){};
        addToUpdaters(updater);
    }
    
}

void RGBStreifen::setRGBOn(bool state)
{
    qDebug() << Q_FUNC_INFO;
    
    if (allow_change_)
    {
        rgb_is_on_ = state;
        
        if (rgb_is_on_)
        {
            // write last value to hardware
        }
        else
        {
            // write zero to hardware
        }
    }  
}
