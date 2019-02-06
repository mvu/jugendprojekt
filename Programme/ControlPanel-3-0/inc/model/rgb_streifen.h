/*!
 * \file rgb_streifen.h
 * \brief Header für die Repräsentation der RGB-Decken-Streifen
 */
#ifndef RGB_STREIFEN_H
#define RGB_STREIFEN_H

#include "inc/model/rgb_element.h"

/*!
 * \brief Die Klasse repräsentiert die RGB-Decken-Streifen
 * \todo Die Set-Funktionen für die Farben mit der einen Adresse überschreiben. Dazu müssen die in RGBElement erstmal
 * virtual gemacht werden...
 */
class RGBStreifen : public RGBElement
{
public:
    /*!
     * \brief Konstruktor für RGBStreifen
     * \param address Adresse des Streifens
     */
    RGBStreifen(uint8_t address);   
    
private:
    uint8_t address_;   //!< Adresse des Streifens

};

#endif // RGB_STREIFEN_H