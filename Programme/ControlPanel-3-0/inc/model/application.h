#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QDateTime>
#include <QPushButton>
#include <iostream>

/*!
 * \brief Anpassung von QApplication an das Touchpad
  */
class Application final : public QApplication
{
public:
    Application(int& argc, char** argv);
    /*!
     * \brief Blockt zu dicht aufeinanderfolgende Mausklicks
     * \details Die Zeit, die mindestens zwischen den Events liegen muss,
     *      wird über min_time_passed_ms_ festgelegt. Der Standardwert ist 100 ms.
     * \bug Fängt nur MouseButtonRelease Events ab, d.h. MouseButtonPress events
     *      werden immer durch gereicht. Dadurch verbleiben die Buttons bei zu
     *      schnellem Doppelklick im Zustand pressed (sichtbar duch dauerhaft
     *      verringerte Transparenz).
     */
    bool notify(QObject *receiver, QEvent *e);

private:
    qint64 timestamp_;
    const int min_time_passed_ms_ = 100;
};

#endif // APPLICATION_H
