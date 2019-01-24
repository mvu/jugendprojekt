#ifndef PALETTEN_LICHT_H
#define PALETTEN_LICHT_H

#include "functional"

#include "inc/model/j_element.h"
#include "inc/model/hardware.h"

class PalettenLicht : public JElement
{
public:
    PalettenLicht();
    
    void saveToFile(QString filename) override;
    void loadFromFile(QString filename) override;
    
    
    void setOn(bool state); ///< \todo name anpassen?
    bool isOn();

private:    
    bool is_on_ = false;
    
};

#endif // PALETTEN_LICHT_Hu