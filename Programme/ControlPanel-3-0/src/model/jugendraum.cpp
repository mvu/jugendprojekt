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
    // update_timer_->start(HW_UPDATE_INTERVAL_MS);

    // create all the members
    theken_licht = new ThekenLicht();
    paletten_licht = new PalettenLicht();
    wand_rgb = new WandRGB();
    hauptlicht.append(new HauptlichtStreifen(HL_STREIFEN_1));
    hauptlicht.append(new HauptlichtStreifen(HL_STREIFEN_2));
    hauptlicht.append(new HauptlichtStreifen(HL_STREIFEN_3));
    hauptlicht.append(new HauptlichtStreifen(HL_STREIFEN_4));
    hauptlicht.append(new HauptlichtStreifen(HL_STREIFEN_5));
    hauptlicht.append(new HauptlichtStreifen(HL_STREIFEN_6));
    hauptlicht.append(new HauptlichtStreifen(HL_STREIFEN_7));
    hauptlicht.append(new HauptlichtStreifen(HL_STREIFEN_8));

}

Jugendraum::~Jugendraum()
{
    qDebug() << Q_FUNC_INFO;
    delete paletten_licht;
    delete theken_licht;
    delete wand_rgb;

    update_timer_->stop();
    delete update_timer_;
}

void Jugendraum::update()
{
    paletten_licht->update();
    theken_licht->update();
    wand_rgb->update();

    for (auto streifen: hauptlicht)
        streifen->update();

}

void Jugendraum::saveAllToFile(QString filename)
{
    paletten_licht->saveToFile(filename);
    theken_licht->saveToFile(filename);
    wand_rgb->saveToFile(filename);

    for (auto streifen: hauptlicht)
        streifen->saveToFile(filename);
}

void Jugendraum::loadAllFromFile(QString filename)
{
    paletten_licht->loadFromFile(filename);
    theken_licht->loadFromFile(filename);
    wand_rgb->loadFromFile(filename);

    for (auto streifen: hauptlicht)
        streifen->loadFromFile(filename);
}
