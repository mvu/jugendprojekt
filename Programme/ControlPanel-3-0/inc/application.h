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
    /*! \brief Blockt zu dicht aufeinanderfolgende Mausklicks
     *  \details Die Zeit, die mindestens zwischen den Events liegen muss,
     *      wird über min_time_passed_ms_ festgelegt. Der Standardwert ist 100 ms.
     */
    bool notify(QObject *receiver /*!< Der Empfänger des Signals */, QEvent *e /*!< Das Event */);

private:
    qint64 timestamp_;
    const int min_time_passed_ms_ = 100;
};

#endif // APPLICATION_H
