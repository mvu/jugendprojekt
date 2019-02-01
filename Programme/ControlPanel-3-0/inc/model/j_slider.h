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

#include "inc/model/hardware.h"

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
     * \bug Bei zweimaligem Funktionsaufruf mit dem selben Wert ohne Deaktiviertung
     *      dazwischen, erkennt der Arduino nicht, wenn der Slider zwischenzeitlich
     *      bewegt wurde und macht dementsprechend nichts.
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
    bool active_;
    QTimer* update_timer_;
    QByteArray reg_setpoint_, reg_analog_, reg_active_;

private slots:
    void update();

signals:
    void changed(int);
};

#endif // J_SLIDER_H
