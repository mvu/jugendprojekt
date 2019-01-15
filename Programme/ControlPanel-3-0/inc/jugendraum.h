#ifndef JUGENDRAUM_H
#define JUGENDRAUM_H

#include <QObject>
#include <QDebug>

/*!
 * \brief Die Klasse, die alles enthält; das Modell im MVC Pattern
 * \details Die Jugendraum-Klasse speichert alle Parameter zur Kontrolle des
 *      Jugendraum. Diese werden zyklich an die Hardware weitergegeben
 */
class Jugendraum : public QObject
{
    Q_OBJECT
public:
    explicit Jugendraum();  //!< Constructor
    void shutdown(void);    //!< Destructor

private:

signals:

public slots:
};

#endif // JUGENDRAUM_H
