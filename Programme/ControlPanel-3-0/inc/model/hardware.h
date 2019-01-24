/*!
 * \file hardware.h
 * \brief definiert den namespace hw
 */

#ifndef HARDWARE_H
#define HARDWARE_H

#include <QDebug>

#include "hardware_config.h"
#include "hardware_register.h"

#include "i2cdevice.h"

/*! \brief Der namespace hw (kurz für Hardware) bietet high level access zur
 *      Hardware wie z. B. I2C oder UART
 */
namespace hw
{
    /*!
    * \brief Initialisiert die Hardware
    */
    void init();
    
    /*!
     * \brief Gibt 'true' zurück, wenn das Gerät an ist
     * \param bank Unterscheidet PORTA und PORTB 
     * \param bit Position des Bits in der Bank
     * \return Zustand
     * \details Liest den Port des MCP23017 und verknüpft diesen mit dem bit
     *      und liefert dadurch den Status des Relais zurück
     */
    bool readState(uint8_t bank, uint8_t bit);
    
    /*!
     * \brief Schaltet Geräte an und aus
     * \param bank Unterscheidet PORTA und PORTB
     * \param bit Position des Bits in der Bank
     * \param state neuer Zustand
     * \todo erneuter Schreibversuch bei Fehlschlag des ersten, wie viele Versuche?, log?
     */
    void writeState(uint8_t bank, uint8_t bit, bool state);
    
    /*!
     * \brief Gibt den Wert des Registers in Prozent zurück 
     * \return Prozentualer Registerwert
     */
    int readValue();
    
    void writeValue();


}

#endif // HARDWARE_H
