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
        std::function<void(void)> updater = [this](){hw::writeValue(address_, brightness_);};
        addToUpdaters(updater);
    }
}

int HauptlichtStreifen::getBrightness()
{
    qDebug() << Q_FUNC_INFO;

    return brightness_;
}
