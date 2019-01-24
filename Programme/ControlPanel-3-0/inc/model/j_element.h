/*!
 * \file j_element.h
 * \brief Header der JElement Basisklasse für alles im Jugendraum
 */
#ifndef J_ELEMENT_H
#define J_ELEMENT_H

#include <vector>
#include <functional>
#include <iostream>
#include <QList>
#include <QSet>
#include <QDebug>

#include "file_handler.h"

/*!
 * \brief Der Typ für alle update-Funktionen
 */
typedef std::function<void(void)> UpdateFunc;

/*!
 * \brief Basisklasse für alles im Jugendraum
 * \details Stellt die Standardfunkionalitäten zu Verfügung, die alle Elemente
 *      brauchen, so wie die update- oder speichern
 */
class JElement
{
public:
    JElement();
    virtual ~JElement();

    /*!
     * \brief Leitet gänderte Parameter an die Hardware weiter.
     * \details Die Funktion addToUpdaters() füllt eine QList
     *      mit den Funktionen, die zum aktualisieren der Hardware benötigt werden.
     *      update() führt diese dann aus und leert anschließend die Liste. In der Regel ruft die Jugendraumklasse
     *      während ihres update-Zyklus die update()-funktionen aller ihrer Member-
     *      Klassen auf.
     */
    void update();

    /*!
     * \brief Speichert die aktuellen Einstellungen in einer Datei. Muss in der
     *      abgeleiteten Klasse gefüllt werden.
     * \param filename Der Speicherort als relativer oder absoluter Pfad.
     */
    virtual void saveToFile(QString filename);

    /*!
     * \brief Lädt die Einstellungen aus einer Datei. Beim nächsten update()
     *      werden sie an die Hardware gesendet. Muss in der abgeleiteten Klasse
     *      gefüllt werden.
     * \param filename Der Speicherort als relativer oder absoluter Pfad.
     */
    virtual void loadFromFile(QString filename);


protected:
    /*!
     * \brief Fügt eine Funktion in eine QList ein, die mit der Funktion update()
     *      aufgerufen wird. Wenn die Funktion schon enthalten ist, wird sie **nicht**
     *      erneut aufgenommen. Aufruf nach jedem Mutator einer Systemvariable in der
     *      abgeleiteten Klasse.
     * \param updater Eine Funktion ohne Rückgabewert, welche die Funktionen des
     *      namespaces hw verwendet, um einen Parameter an die Hardware zu senden.
     * \details Beispiel für die Benutzung aus paletten_licht.cpp
     *      \code{.cpp}
     *          void PalettenLicht::setOn(bool state)
     *          {
     *              is_on_ = state;
     *              std::function<void(void)> updater = [this](){hw::writeState(PALETTE, is_on_);};
     *              addToUpdaters(updater);
     *          }
     *      \endcode
     * \todo was eleganteres für die Vermeidung von doppelten Updatern finden
     */
    void addToUpdaters(UpdateFunc updater);

    QList<UpdateFunc> updaters_;
    QSet<UpdateFunc*> updaters_addr_;
};

#endif // J_ELEMENT_H
