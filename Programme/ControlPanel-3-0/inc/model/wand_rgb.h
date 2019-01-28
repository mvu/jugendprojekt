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
    
    /*!
     * \brief Setzt den Rot-Wert zwischen 0 und 100 und erzeugt einen Updater, 
     * der beim nächsten Update-Zyklus die Hardware aktualisiert
     * \param value Wert, der gesetzt wird
     */
    void setRedValue(int value) override;
    
    /*!
     * \brief Setzt den Grün-Wert zwischen 0 und 100 und erzeugt einen Updater, 
     * der beim nächsten Update-Zyklus die Hardware aktualisiert
     * \param value Wert, der gesetzt wird
     */
    void setGreenValue(int value) override;
    
    /*!
     * \brief Setzt den Blau-Wert zwischen 0 und 100 und erzeugt einen Updater, 
     * der beim nächsten Update-Zyklus die Hardware aktualisiert
     * \param value Wert, der gesetzt wird
     */
    void setBlueValue(int value) override;
};

#endif // WAND_RGB_H