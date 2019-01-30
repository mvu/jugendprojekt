/*!
 * \file j_slider.h
 * \brief Header der JSlider Klasse
 */
#ifndef J_SLIDER_H
#define J_SLIDER_H

#include <QObject>
#include <QTimer>
#include <QtNetwork/QUdpSocket>
#include <QDebug>

#include "inc/model/hardware.h"

class JSlider : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Constructor für einen JSlider
     * \param parent erzegendes QObject
     * \param slider_id Nummer des sliders, von 1 (ganz links) bis 4 (ganz rechts)
     */
    explicit JSlider(QObject *parent = nullptr, int slider_id = 0);
    ~JSlider();

    void setValue(int value);
    int getValue();

private slots:
    void update();

signals:
    void changed(int);
};

#endif // J_SLIDER_H
