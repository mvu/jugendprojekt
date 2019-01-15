#ifndef I2CDEVICE_H
#define I2CDEVICE_H

#include <QtCore>

/*!
 * \brief Basisklasse für alle Geräte am I2C Bus
 */
class I2CDevice
{
public:
    /*!
     * \brief Constructor
     * \details Holt sich den filehandle von der wiringPi library und
     *      initialisiert dann die Register des Slaves
     * \param address Adresse des Slaves
     * \note Prüfe Rückgabewert der wiringPi-init Funktion
     */
    I2CDevice(uint8_t address);
    /*!
     * \brief Setzt das Register auf den Wert
     * \param reg Das zu setzende Register
     * \param val Der zu schreibende Wert
     * \return Code der wiringPi library, d.h. 0 für Erfolg, ansonsten -1
     */
    int WriteReg(uint8_t reg, int val);
    /*!
     * \brief Auslesen des Registers
     * \param reg Das zu lesende Register
     * \return Inhalt des Registers oder -1, wenn Lesefehler
     * \note Evtl. erst erneuten Leseversuch starten, wenn der auch fehlschlägt,
     *      den Fehlercode zurück geben
     */
    int ReadReg(uint8_t reg);
private:
    /// Der filehandle für den Bus
    int filehandle_;
    /*!
     * \brief Initialierungsfunktion für einen PCA9635
     * \return 0, wenn erfolgreich, sonst -1
     */
    int InitPCA();
    /*!
     * \brief Initialierungsfunktion für einen MCP23017
     * \return 0, wenn erfolgreich, sonst -1
     */
    int InitMCP();
};

#endif // I2CDEVICE_H
