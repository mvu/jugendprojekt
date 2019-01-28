/*!
 * \file rgb_element.h
 * \brief Header für die RGB-Basisklasse
 */
#ifndef RGB_ELEMENT_H
#define RGB_ELEMENT_H

/*!
 * \brief Basisklasse für RGBs, von der alle Objekt, die RGBs enthalten, erben. 
 * \details Speichert den Zustand eines RGB-Lichts und stellt Funktionen zum Auslesen und Verändern von diesem zur Verfügung.
 * \todo Ist nach einer gewissen Zeitspanne keine Slider-Bewegung mehr erfolgt, werden die 
 * Slider deaktiviert. Das ist eigentlich eher eine Gui-Aufgabe, steht aber trotzdem hier weil alle RGB-Lichter von dieser Klasse erben.
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
    
    /*!
     * \brief Liefert den Zustand der RGBs
     * \return true, wenn RGB an ist
     */
    bool RGBisOn();
    
    /*!
     * \brief Schaltet die RGBs an oder aus
     * \param state True heißt an
     */
    virtual void setRGBOn(bool state);
    
protected:
    int red_value_ = 0;
    int green_value_ = 0;
    int blue_value_ = 0;
    bool rgb_is_on_ = false;
};

#endif // RGB_ELEMENT_H