/*!
 * \file wand_rgb.cpp
 * \brief Source-File für die Wand-RGB-Streifen
 */
#include "inc/model/wand_rgb.h"

WandRGB::WandRGB():
    JElement(), RGBElement()
{
    qDebug() << Q_FUNC_INFO;
    
    // read initial state from hardware
    red_value_ = hw::readValue(RGB_WAND_ROT);
    green_value_ = hw::readValue(RGB_WAND_GRUEN);
    blue_value_ = hw::readValue(RGB_WAND_BLAU);
}

void WandRGB::saveToFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;
    
    FileHandler* file_handler_ = new FileHandler(filename);
    file_handler_->writeToFile("WandRGB::red_value_", red_value_);
    file_handler_->writeToFile("WandRGB::green_value_", green_value_);
    file_handler_->writeToFile("WandRGB::blue_value_", blue_value_);
    delete file_handler_;
}

void WandRGB::loadFromFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;
    
    FileHandler* file_handler_ = new FileHandler(filename);
    setRedValue( file_handler_->readFromFile<int>("WandRGB::red_value_") );
    setGreenValue( file_handler_->readFromFile<int>("WandRGB::green_value_") );
    setBlueValue( file_handler_->readFromFile<int>("WandRGB::blue_value_") );
    delete file_handler_;
}

void WandRGB::setRedValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    red_value_ = value;
    
    // add update function to list if it isn't already in there
    UpdateFunc updater = [this](){hw::writeValue(RGB_WAND_ROT, red_value_);};
    addToUpdaters(updater);
}

void WandRGB::setGreenValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    green_value_ = value;
    
    // add update function to list if it isn't already in there
    UpdateFunc updater = [this](){hw::writeValue(RGB_WAND_GRUEN, green_value_);};
    addToUpdaters(updater);
}

void WandRGB::setBlueValue(int value)
{
    qDebug() << Q_FUNC_INFO;
    blue_value_ = value;
    
    // add update function to list if it isn't already in there
    UpdateFunc updater = [this](){hw::writeValue(RGB_WAND_BLAU, blue_value_);};
    addToUpdaters(updater);
}