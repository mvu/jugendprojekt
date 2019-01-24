/*!
 * \file theken_licht.h
 * \brief Header-File zur Verwaltung der Lichter der Theke
 */

#ifndef THEKEN_LICHT_H
#define THEKEN_LICHT_H

#include "j_element.h"

/*!
 * \brief Klasse zur Steuerung der Lichter der Theke: RGB-Streifen und Lichter über der Theke
 */
class ThekenLicht : public JElement
{
public:
    ThekenLicht();
    
    void saveToFile(QString filename) override;
    void loadFromFile(QString filename) override;
    
private:
    bool top_is_on_ = false;
    // RGB-values, from 0 to 100
    int red_value_ = 0;
    int green_value_ = 0;
    int blue_value_ = 0;
    
};

#endif // THEKEN_LICHT_H