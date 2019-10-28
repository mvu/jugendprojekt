/*!
 * \file hauptlicht_streifen.h
 * \brief Header für die Repräsentation der Hauptlicht-Streifen
 */
#ifndef HAUPTLICHT_STREIFEN_H
#define HAUPTLICHT_STREIFEN_H

#include <QDebug>
#include <QString>
// #include <string>

#include "inc/model/j_element.h"
#include "inc/model/hardware.h"

class HauptlichtStreifen : public JElement
{
public:
    /*!
     * \brief HauptlichtStreifen
     * \param address Register des Streifens; verwende Macro aus hardware_config.h
     * \todo Wenn SetOn() mit true aufgerufen wird und der interne Wert 0 ist, einen Default-Wert aus 
     * einer Datei lesen
     */
    HauptlichtStreifen(uint8_t address);
    
    void saveToFile(QString filename) override;
    
    void loadFromFile(QString filename) override;

    /*!
     * \brief (De-)Aktiviert den Streifen, nur wenn der Streifen aktiv ist werden 
     * Änderungen durchgeführt
     * \param allow true = aktiv
     */
    void allowChange(bool allow);

    /*!
     * \brief Setzt den Helligkeitswert, wenn der Streifen aktiviert ist
     * \param val Helligkeitswert zwischen 0 und 100
     */
    void setBrightness(int val);

    /*!
     * \brief getValue
     * \return Helligkeitswert zwischen 0 und 100
     */
    int getBrightness();
    
    /*!
     * \brief Schaltet den Streifen an und aus, wenn der Streifen aktiviert ist
     * \param state true = an
     */
    void setOn(bool state);
    
    /*!
     * \brief liefert den aktuellen Zustand des Streifens
     * \return Zustand
     */
    bool isOn();

private:
    int brightness_;        //!< aktueller Helligkeitswert
    uint8_t address_;       //!< Register des Streifens, verwende Macro aus hardware_config.h
    bool allow_change_;     //!< Wenn true, dann reagiert der Streifen auf Slider
    bool is_on_;            //!< Speichert den Zustand des Streifens

};

#endif // HAUPTLICHT_STREIFEN_H
