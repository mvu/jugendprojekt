/*!
 * \file theken_licht.h
 * \brief Header-File zur Verwaltung der Lichter der Theke
 */

#ifndef THEKEN_LICHT_H
#define THEKEN_LICHT_H

#include "inc/model/j_element.h"
#include "inc/model/rgb_element.h"
#include "inc/model/hardware.h"

/*!
 * \brief Klasse zur Steuerung der Lichter der Theke: RGB-Streifen und Lichter über der Theke
 */
class ThekenLicht : public JElement, public RGBElement
{
public:
    //! Constructor
    ThekenLicht();
    
    /*!
     * \brief Schreibt den aktuellen Zustand in eine Datei
     * \param filename Datei, in die gespeichert wird
     * \todo implementieren
     */
    void saveToFile(QString filename) override;
    
    /*!
     * \brief Lädt einen Zustand aus einer Datein
     * \param filename Datei, aus der geladen wird
     * \todo implementieren
     */
    void loadFromFile(QString filename) override;
    
    /*!
     * \brief Fragt den Zustand des Lichts über der Theke ab
     * \return Zustand des Lichts: true = an, false = aus
     */
    bool topIsOn();
    
    /*!
     * \brief Ändert den Zustand des Lichts über der Theke
     * \param state Auf diesen Zustand wird das Licht gesetzt
     */
    void setTopOn(bool state);
    
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
    
private:
    bool top_is_on_ = false;
    
};

#endif // THEKEN_LICHT_H
