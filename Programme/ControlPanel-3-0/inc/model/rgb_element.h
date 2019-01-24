/*!
 * \file rgb_element.h
 * \brief Header für die RGB-Basisklasse
 */
#ifndef RGB_ELEMENT_H
#define RGB_ELEMENT_H

/*!
 * \brief Basisklasse für RGBs, von der alle Objekt, die RGBs enthalten, erben. 
 * \details Speichert den Zustand eines RGB-Lichts und stellt Funktionen zum Auslesen und Verändern von diesem zur Verfügung.
 */
class RGBElement
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
     * \brief Setzt den Rot-Wert zwischen 0 und 100
     * \param value Wert, der gesetzt wird
     */
    virtual void setRedValue(int value);
    
    /*!
     * \brief Setzt den Grün-Wert zwischen 0 und 100
     * \param value Wert, der gesetzt wird
     */
    virtual void setGreenValue(int value);
    
    /*!
     * \brief Setzt den Blau-Wert zwischen 0 und 100
     * \param value Wert, der gesetzt wird
     */
    virtual void setBlueValue(int value);
    
protected:
    int red_value_ = 0;
    int green_value_ = 0;
    int blue_value_ = 0;
};

#endif // RGB_ELEMENT_H