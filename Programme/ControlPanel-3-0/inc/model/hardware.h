/*!
 * \file hardware.h
 * \brief definiert den namespace hw
 */

#ifndef HARDWARE_H
#define HARDWARE_H

#include <QDebug>
#include <QByteArray>
#include <QList>
#include <QtNetwork>

#include "inc/model/hardware_config.h"
#include "inc/model/hardware_register.h"

#include "i2cdevice.h"

/*! \brief Der namespace hw (kurz für Hardware) bietet high level access zur
 *      Hardware wie z. B. I2C oder UART
 */
namespace hw
{

    /*!
    * \brief Initialisiert die Hardware
    * \todo Verhalten bei Lesefehler der Register ausdenken und implementieren
    */
    void init();

    /*!
     * \brief Gibt 'true' zurück, wenn das Gerät an ist
     * \param bank Unterscheidet PORTA und PORTB
     * \param bit Position des Bits in der Bank
     * \return Zustand
     * \details Liest den Port des MCP23017 und verknüpft diesen mit dem bit
     *      und liefert dadurch den Status des Relais zurück
     * \todo erneuter Leseversuch bei Fehlschlag des ersten, wie viele Versuche?, log?
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
     * \brief Gibt den Wert des Registers repräsentiert durch einen Wert zwischen 0 und 100 zurück
     * \return Prozentualer Registerwert
     * \param reg Registen, dessen Wert ausgelesen wird
     * \todo erneuter Leseversuch bei Fehlschlag des ersten, wie viele Versuche?, log?
     */
    int readValue(uint8_t reg);

    /*!
     * \brief Schreibt einen Wert, der aus dem übergebenen Wert zwischen 0 und 100 errechnet wird, in ein Register
     * \param reg Register, in das geschrieben wird
     * \param int Wert, der gesetzt werden soll
     * \todo erneuter Schreibversuch bei Fehlschlag des ersten, wie viele Versuche?, log?
     */
    void writeValue(uint8_t reg, int val);

    /*!
     * \brief Liefert Adressen der Slider-Register
     * \param slider_num Nummer des Sliders; von 1 (links) bis 4 (rechts)
     * \return [reg_setpoint, reg_analog, reg_active]
     * \details Die Register-Adressen werden in init() vom Arduino geholt und
     *      gespeichert. Hier werden die gespeicherten Werte geliefert.
     *      Im Normalfall sollten sich die Adressen nie ändern, da der Arduino
     *      immer die selben Adressen verwendet.
     */
    QList<QByteArray> getSliderConfig(int slider_num);

    /*!
     * \brief Sendet ein Datenpaket über UDP
     * \param data Daten zum Versenden
     * \param ip IP des Empfängers, verwende zusammen mit port im Macro
     * \param port Port des Empfängers, verwende zusammen mit ip im Macro
     * \todo Verhalten bei Schreibfehler
     */
    void writeUDP(QByteArray data, QHostAddress ip, quint16 port);

    /*!
     * \brief Liest einen uint16_t über UDP aus einem entfernten Register
     * \param reg Das zu lesende Register
     * \param ip IP des Empfängers, verwende zusammen mit port im Macro
     * \param port Port des Empfängers, verwende zusammen mit ip im Macro
     * \return Wert des Registers als int
     * \note Der Client muss den Wert als high- und low-byte senden, nicht
     *      in utf8-encoding
     * \details Wenn der udp_socket bekannt (d.h. als interne Variable existiert)
     *      ist, wird dieser verwendet und damit sichergestellt, dass das die
     *      empfangenen Daten vom gewünschten Sender stammen
     * \todo Verhalten bei Lesefehler
     */
    int readUDP(QByteArray reg, QHostAddress ip, quint16 port);

    /*!
     * \brief Liefert ein QJsonDocument über UDP
     * \param ip IP des Clients
     * \param port Port des Clients
     * \return Das empfangene json file
     */
    QJsonDocument readUDP(QHostAddress ip, quint16 port);

    /*!
     * \brief Temporäre Lösung; Liefert True wenn die Slider nicht geantwortet haben
     * \return True = keine Slider verfügbar
     * \details quick'n'dirty: kann verwndet werden, um auf der GUI Knöpfe zu deaktivieren
     */
   bool sliderless();

    /*!
     * \brief Temporäre Lösung; Liefert True wenn jTemperature nicht geantwortet hat
     * \return True = keine Temperatursensoren verfügbar
     */
   bool sensorless();
}

#endif // HARDWARE_H
