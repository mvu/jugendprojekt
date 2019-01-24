/*!
 * \file paletten_licht.h
 * \brief Header der PalettenLicht Klasse
 */
#ifndef PALETTEN_LICHT_H
#define PALETTEN_LICHT_H

#include "functional"

#include "inc/model/j_element.h"
#include "inc/model/hardware.h"

/*!
 * \brief Klasse zur Verwaltung der beleuchteten Paletten hinter der Bühne
 */
class PalettenLicht : public JElement
{
public:
    PalettenLicht();
    
    void saveToFile(QString filename) override;
    void loadFromFile(QString filename) override;
    
    /*!
     * \brief Schaltet die Palettenbeleuchtung an oder aus
     * \param state true -> anschalten, false -> ausschalten
     */
    void setOn(bool state);
    /*!
     * \brief liefert den Zustand der Palettenbeleuchtung
     * \return true wenn an, sonst aus
     */
    bool isOn();

private:    
    bool is_on_ = false;
    
};

#endif // PALETTEN_LICHT_Hu
