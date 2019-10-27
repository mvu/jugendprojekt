/*!
 * \file rgb_streifen.h
 * \brief Header für die Repräsentation der RGB-Decken-Streifen
 */
#ifndef RGB_STREIFEN_H
#define RGB_STREIFEN_H

#include "inc/model/rgb_element.h"

/*!
 * \brief Die Klasse repräsentiert die RGB-Decken-Streifen
 * \todo die richtigen Updater schreiben, dazu muss hw::writeUART(...) noch gebaut werden
 */
class RGBStreifen : public RGBElement
{
public:
    /*!
     * \brief Konstruktor für RGBStreifen
     * \param address Adresse des Streifens
     */
    RGBStreifen(uint8_t address);   
    
    /*!
     * \brief (De-)Aktiviert den Streifen, nur wenn der Streifen aktiv ist werden 
     * Änderungen durchgeführt
     * \param allow true = aktiv
     */
    void allowChange(bool allow);
    
    void setRedValue(int value) override;
    
    void setGreenValue(int value) override;
    
    void setBlueValue(int value) override;
    
    void setRGBOn(bool state) override;
    
private:
    uint8_t address_;   //!< Adresse des Streifens
    bool allow_change_; //!< Nur wenn true werden Änderungen durchgeführt

};

#endif // RGB_STREIFEN_H