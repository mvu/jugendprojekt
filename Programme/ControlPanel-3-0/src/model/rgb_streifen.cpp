/*!
 * \file rgb_streifen.cpp
 * \brief Source der Repräsentation der RGB-Decken-Streifen
 */
#include "inc/model/rgb_streifen.h"

RGBStreifen::RGBStreifen(uint8_t address) :
    RGBElement ()
{
    address_ = address;
}
