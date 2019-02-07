/*!
 * \file j_slider.h
 * \brief Header der JSlider Klasse
 */
#ifndef J_SLIDER_H
#define J_SLIDER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <iostream>
#include <QString>
#include <QDateTime>

#include "inc/model/hardware.h"

/*!
 * \brief Klasse für einen Hardware Slider
 * \todo Verhalten bei nicht antwortendem Arduino implentieren. Denkbar wäre,
 *      dass sich dann ein Fenster mit Software-Slidern öffnet.
 */
class JSlider : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Constructor für einen JSlider
     * \param parent erzegendes QObject
     * \param slider_num Nummer des sliders, von 1 (ganz links) bis 4 (ganz rechts)
     * \param init_position Position auf die der Slider färht, wenn das Objekt
     *      erzeugt wird; von 0 (unten) bis 100 (oben)
     */
    explicit JSlider(QObject *parent = nullptr, int slider_num = 2, int init_position = 0);
    ~JSlider();

    /*!
     * \brief fährt den Slider auf die Position
     * \param value gewünschte Position; von 0 (unten) bis 100 (oben)
     */
    void setPosition(int value);

    /*!
     * \brief Liefter die aktuelle Position des Sliders
     * \return aktuelle Position von 0 (unten) bis 100 (oben)
     */
    int getPosition();

private:
    void activate();
    void deactivate();

    int slider_num_;
    int position_;
    bool active_, standby_;
    long long last_timestamp_;
    QTimer* update_timer_;
    QByteArray reg_setpoint_, reg_analog_, reg_active_;

private slots:
    void update();

signals:
    /*!
     * \brief Wird gesendet, wenn sich die Position des Sliders ändert. Die
     *      neue Position von 0 (unten) bis 100 (oben) wird an den Empfänger
     *      übergeben.
     */
    void changed(int);
};

#endif // J_SLIDER_H
