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

#include "hardware.h"
#include "j_element.h"

// Klassen der Elemente
#include "inc/model/paletten_licht.h"
#include "inc/model/theken_licht.h"

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

    ThekenLicht* theken_licht;          //!< Kontrolliert die Thekenlichter
    PalettenLicht* paletten_licht;      //!< Kontroliiert die beleuchteten Paletten an der Wand
private:
    QTimer *update_timer_;


signals:

public slots:

private slots:
    void update();
};

#endif // JUGENDRAUM_H
