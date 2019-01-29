#include "inc/model/hauptlicht_streifen.h"

HauptlichtStreifen::HauptlichtStreifen(uint8_t address)
{
    qDebug() << Q_FUNC_INFO;

    address_ = address;
    allow_change_ = false;
}

void HauptlichtStreifen::allowChange(bool allow)
{
    qDebug() << Q_FUNC_INFO;

    allow_change_ = allow;
}

void HauptlichtStreifen::setBrightness(int val)
{
    qDebug() << Q_FUNC_INFO;

    if (allow_change_)
    {
        brightness_ = val;
        UpdateFunc updater = [this](){hw::writeValue(address_, brightness_);};
        addToUpdaters(updater);
    }
}

int HauptlichtStreifen::getBrightness()
{
    qDebug() << Q_FUNC_INFO;

    return brightness_;
}

void HauptlichtStreifen::setOn(bool state)
{
    qDebug() << Q_FUNC_INFO;
    
    if (allow_change_)
    {
        is_on_ = state;
    
        if (is_on_)
        {
            // restore last value
            setBrightness(brightness_);
        }
        else
        {
            // write 0 to hardware without changing the software value
            UpdateFunc updater = [this](){hw::writeValue(address_, 0);};
        }
    }
    
}

bool HauptlichtStreifen::isOn()
{
    qDebug() << Q_FUNC_INFO;
    return is_on_;
}
