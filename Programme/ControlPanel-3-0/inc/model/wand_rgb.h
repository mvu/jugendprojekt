/*!
 * \file wand_rgb.h
 * \brief Header für die Wand-RGB-Streifen
 */
#ifndef WAND_RGB_H
#define WAND_RGB_H

#include "inc/model/rgb_element.h"
#include "inc/model/hardware.h"

/*!
 * \brief Klasse für die Repräsentation und Kontrolle des Wand-RGB-Streifens
 */
class WandRGB : public RGBElement
{
public:
    //! Contructor
    WandRGB();
    
    void saveToFile(QString filename) override;
    
    void loadFromFile(QString filename) override;
};

#endif // WAND_RGB_H