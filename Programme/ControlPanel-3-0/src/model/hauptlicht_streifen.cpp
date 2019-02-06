#include "inc/model/hauptlicht_streifen.h"

HauptlichtStreifen::HauptlichtStreifen(uint8_t address)
{
    qDebug() << Q_FUNC_INFO;

    address_ = address;
    allow_change_ = false;
    
    // read inital state from hardware
    brightness_ = hw::readValue(address_);
    is_on_ = (brightness_ != 0);
}

void HauptlichtStreifen::saveToFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;
    
    FileHandler* file_handler = new FileHandler(filename);
    std::string name = "HauplichtStreifen" + std::to_string(address_) + "::brightness_";
    file_handler->writeToFile(name, brightness_);
    delete file_handler;
}

void HauptlichtStreifen::loadFromFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;
    
    FileHandler* file_handler = new FileHandler(filename);
    std::string name = "HauplichtStreifen" + std::to_string(address_) + "::brightness_";
    brightness_ = file_handler->readFromFile<int>(name);
    delete file_handler;
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
        is_on_ = (brightness_ != 0);
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
            setBrightness(last_brightness_);
            qDebug() << brightness_ << " " << brightness_;
        }
        else
        {
            /*// write 0 to hardware without changing the software value
            UpdateFunc updater = [this](){hw::writeValue(address_, 0);};
            addToUpdaters(updater);*/
            
            // store current value
            last_brightness_ = brightness_;
            // set brightness to zero
            setBrightness(0);
        }
    }
    
}

bool HauptlichtStreifen::isOn()
{
    qDebug() << Q_FUNC_INFO;
    return is_on_;
}
