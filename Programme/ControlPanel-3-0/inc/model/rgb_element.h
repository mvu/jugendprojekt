/*!
 * \file rgb_element.h
 * \brief Header für die RGB-Basisklasse
 */
#ifndef RGB_ELEMENT_H
#define RGB_ELEMENT_H

#include <QDebug>
#include <functional>

#include "inc/model/j_element.h"
#include "inc/model/hardware.h"

/*!
 * \brief Basisklasse für RGBs, von der alle Objekt, die RGBs enthalten, erben. 
 * \details Speichert den Zustand eines RGB-Lichts und stellt Funktionen zum Auslesen und Verändern von diesem zur Verfügung.
 * \todo Darüber nachdenken, ob bei rgb_is_on_ == false die mutators der Farben was machen oder nicht
 */
class RGBElement : public JElement
{
public:
    /// Constructor
    RGBElement();
    /// Destructor
    virtual ~RGBElement();
    
    /*!
     * \brief lieftert den Rot-Wert zwischen 0 und 100
     * \return Rot-Wert
     */
    int getRedValue();
    
    /*!
     * \brief lieftert den Grün-Wert zwischen 0 und 100
     * \return Grün-Wert
     */
    int getGreenValue();
    
    /*!
     * \brief lieftert den Blau-Wert zwischen 0 und 100
     * \return Blau-Wert
     */
    int getBlueValue();
    
    /*!
     * \brief Setzt den Rot-Wert zwischen 0 und 100 und 
     * erzeugt einen Updater, der die Änderung im nächsten Update-Zyklus ausführt
     * \param value Wert, der gesetzt wird
     */
    void setRedValue(int value);
    
    /*!
     * \brief Setzt den Grün-Wert zwischen 0 und 100 und 
     * erzeugt einen Updater, der die Änderung im nächsten Update-Zyklus ausführt
     * \param value Wert, der gesetzt wird
     */
    void setGreenValue(int value);
    
    /*!
     * \brief Setzt den Blau-Wert zwischen 0 und 100 und 
     * erzeugt einen Updater, der die Änderung im nächsten Update-Zyklus ausführt
     * \param value Wert, der gesetzt wird
     */
    void setBlueValue(int value);
    
    /*!
     * \brief Liefert den Zustand der RGBs
     * \return true, wenn RGB an ist
     */
    bool RGBisOn();
    
    /*!
     * \brief Schaltet die RGBs an oder aus ohne jedoch die Software-Werte 
     * der Farben zu ändern
     * \param state true heißt an
     */
    void setRGBOn(bool state);
    
protected:
    int red_value_ = 0;
    int green_value_ = 0;
    int blue_value_ = 0;
    uint8_t addr_red_;
    uint8_t addr_green_;
    uint8_t addr_blue_;
    bool rgb_is_on_ = false;
};

#endif // RGB_ELEMENT_H
