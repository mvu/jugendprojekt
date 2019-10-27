/*!
 * \file theken_licht.h
 * \brief Header-File zur Verwaltung der Lichter der Theke
 */

#ifndef THEKEN_LICHT_H
#define THEKEN_LICHT_H

#include "inc/model/rgb_element.h"
#include "inc/model/hardware.h"

/*!
 * \brief Klasse zur Steuerung der Lichter der Theke: RGB-Streifen und Lichter über der Theke
 */
class ThekenLicht : public RGBElement
{
public:
    /*!
     * \brief Constructor
     * \todo Was passiert, wenn hardware beim erzeugen des Objects nicht antwortet?
     */
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
    
    
private:
    bool top_is_on_ = false;
    
};

#endif // THEKEN_LICHT_H
