/*!
 * \file jugendraum.h
 * \brief Header der Jugendraum Klasse.
 */
#ifndef JUGENDRAUM_H
#define JUGENDRAUM_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <iostream>
#include <QString>


#include "inc/model/log.h"
#include "inc/model/hardware.h"
#include "inc/model/j_element.h"

// Klassen der Elemente
#include "inc/model/paletten_licht.h"
#include "inc/model/theken_licht.h"
#include "inc/model/wand_rgb.h"
#include "inc/model/hauptlicht_streifen.h"
#include "inc/model/rgb_streifen.h"

/*!
 * \brief Die Klasse, die alles enthält; das Modell im MVC Pattern
 * \details Die Jugendraum-Klasse speichert alle Parameter zur Kontrolle des
 *      Jugendraum. Diese werden zyklich an die Hardware weitergegeben
 */
class Jugendraum : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Constructor, initialisiert alles
     * \details Es werden nach einander alle Bestandteile initialisert. Zunächst
     *      die Hardware über den namespace hw, dann die high level Klassen
     */
    explicit Jugendraum();
    ~Jugendraum();

    /*!
     * \brief Speichert den aktuellen Zustand aller Elemente des Jugendraums in eine Datei
     * \param filename Datei, in die gespeichert wird
     */
    void saveAllToFile(QString filename);

    /*!
     * \brief Lädt den Zustand aller Elemente des Jugendraums aus einer Datei
     * \param filename Datei, aus der geladen wird
     */
    void loadAllFromFile(QString filename);

    ThekenLicht* theken_licht;              //!< Kontrolliert die Lichter an der Theke, d.h. die Hängelampen und die RGBs
    PalettenLicht* paletten_licht;          //!< Kontroliiert die beleuchteten Paletten an der Wand
    WandRGB* wand_rgb;                      //!< Kontrolliert die RGB Streifen an den Giebelfenstern
    /*!
     * \brief Kontrolliert die Hauptlichtstreifen an der Decke
     * \details Die Reihenfolge der einzelnen Streifen im Array ist durch die Nummerierung der Streifen fest vorgegeben.
     * Bezogen auf die Darstellung in der GUI beginnt die Zählung oben links in der Ecke (bei der Tür und der Theke) bei 1
     * und geht dann gegen den Uhrzeigersinn bis 8. Dieser Nummerierung folgt auch die Belegung der Adressen in der hardware_config.h .
     * Die Benennung der Buttons in der GUI folgt ebenfalls dieser Nummerierung.
     */
    QList<HauptlichtStreifen*> hauptlicht;

    /*!
     * \brief Kontrolliert die RGB-Streifen an der Decke
     * \details Die Reihenfolge der einzelnen Streifen im Array ist durch die Nummerierung der Streifen fest vorgegeben.
     * Bezogen auf die Darstellung in der GUI beginnt die Zählung oben links in der Ecke (bei der Tür und der Theke) bei 1.
     * Der Streifen direkt rechts daneben erhält die 2. In diesem Muster von immer zwei Streifen geht es dann gegen den
     * Uhrzeigersinn bis 18. Dieser Nummerierung folgt auch die Belegung der Adressen.
     * Die Benennung der Buttons in der GUI folgt ebenfalls dieser Nummerierung.
     */
    QList<RGBStreifen*> rgb_deckenlicht;

private:
    QTimer *update_timer_;  //!< Kontrolliert den update-Zyklus der Hardware

signals:

public slots:

private slots:
    void update();
};

#endif // JUGENDRAUM_H
