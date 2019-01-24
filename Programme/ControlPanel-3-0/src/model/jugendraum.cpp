/*!
 * \file jugendraum.cpp
 * \brief Source der Jugendraum Klasse.
 */
#include "inc/model/jugendraum.h"

Jugendraum::Jugendraum()
{
    qDebug() << Q_FUNC_INFO;
    hw::init();

    update_timer_ = new QTimer();
    connect(update_timer_, SIGNAL(timeout()), this, SLOT(update()));
    update_timer_->start(HW_UPDATE_INTERVAL_MS);

    // create all the members
    theken_licht = new ThekenLicht();
    paletten_licht = new PalettenLicht();
}

Jugendraum::~Jugendraum()
{
    qDebug() << Q_FUNC_INFO;
    paletten_licht->~PalettenLicht();

    update_timer_->stop();
}

void Jugendraum::update()
{
    paletten_licht->update();
}
