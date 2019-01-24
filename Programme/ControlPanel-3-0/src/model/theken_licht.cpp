#include "inc/model/theken_licht.h"

ThekenLicht::ThekenLicht() :
    JElement(), RGBElement()
{
    qDebug() << Q_FUNC_INFO;    
    
    // read initial state from hardware
    top_is_on_ = hw::readState(THEKE);
    red_value_ = hw::readValue(RGB_THEKE_ROT);
    green_value_ = hw::readValue(RGB_THEKE_GRUEN);
    blue_value_ = hw::readValue(RGB_THEKE_BLAU);
    
}

void ThekenLicht::saveToFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;
    FileHandler* file_handler_ = new FileHandler(filename);
    file_handler_->writeToFile("ThekenLicht::top_is_on_", top_is_on_);
    file_handler_->writeToFile("ThekenLicht::red_value_", red_value_);
    file_handler_->writeToFile("ThekenLicht::green_value_", green_value_);
    file_handler_->writeToFile("ThekenLicht::blue_value_", blue_value_);
    delete file_handler_;
}

void ThekenLicht::loadFromFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;
    FileHandler* file_handler_ = new FileHandler(filename);
    setTopOn( file_handler_->readFromFile<bool>("ThekenLicht::top_is_on_") );
    setRedValue( file_handler_->readFromFile<int>("ThekenLicht::red_value_"));
    setRedValue( file_handler_->readFromFile<int>("ThekenLicht::green_value_"));
    setRedValue( file_handler_->readFromFile<int>("ThekenLicht::blue_value_"));
    delete file_handler_;
}

bool ThekenLicht::topIsOn()
{
    qDebug() << Q_FUNC_INFO;
    return top_is_on_;
}

void ThekenLicht::setTopOn(bool state)
{
    qDebug() << Q_FUNC_INFO;
    top_is_on_ = state;
    
    // add update function to list if it isn't already in there
    UpdateFunc updater = [this](){hw::writeState(THEKE, top_is_on_);};
    addToUpdaters(updater);
}

void ThekenLicht::setRedValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    red_value_ = value;
    
    // add update function to list if it isn't already in there
    UpdateFunc updater = [this](){hw::writeValue(RGB_THEKE_ROT, red_value_);};
    addToUpdaters(updater);
}

void ThekenLicht::setGreenValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    green_value_ = value;
    
    // add update function to list if it isn't already in there
    UpdateFunc updater = [this](){hw::writeValue(RGB_THEKE_GRUEN, green_value_);};
    addToUpdaters(updater);
}

void ThekenLicht::setBlueValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    blue_value_ = value;
    
    // add update function to list if it isn't already in there
    UpdateFunc updater = [this](){hw::writeValue(RGB_THEKE_BLAU, blue_value_);};
    addToUpdaters(updater);
}
