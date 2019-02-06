/*!
 * \file rgb_streifen.cpp
 * \brief Source der Repräsentation der RGB-Decken-Streifen
 */
#include "inc/model/rgb_streifen.h"

RGBStreifen::RGBStreifen(uint8_t address_red, uint8_t address_green, uint8_t address_blue) :
    RGBElement ()
{
    addr_red_ = address_red;
    addr_green_ = address_green;
    addr_blue_ = address_blue;
}
