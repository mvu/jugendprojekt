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
     * \param address Register des Streifens; verwende Macro aus hardware_config.h
     */
    RGBStreifen(uint8_t address);
};

#endif // RGB_STREIFEN_H