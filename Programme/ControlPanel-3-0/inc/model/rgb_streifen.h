/*!
 * \file rgb_streifen.h
 * \brief Header für die Repräsentation der RGB-Decken-Streifen
 */
#ifndef RGB_STREIFEN_H
#define RGB_STREIFEN_H

#include "inc/model/rgb_element.h"

/*!
 * \brief Die Klasse repräsentiert die RGB-Decken-Streifen
 */
class RGBStreifen : public RGBElement
{
public:
    /*!
     * \brief Konstruktor für RGBStreifen
     * \param address_red Register des Streifens für rot
     * \param address_green Register des Streifens für grün
     * \param address_blue Register des Streifens für blau
     */
    RGBStreifen(uint8_t address_red, uint8_t address_green, uint8_t address_blue);   

};

#endif // RGB_STREIFEN_H