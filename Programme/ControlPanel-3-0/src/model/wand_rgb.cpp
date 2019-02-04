/*!
 * \file wand_rgb.cpp
 * \brief Source-File für die Wand-RGB-Streifen
 */
#include "inc/model/wand_rgb.h"

WandRGB::WandRGB():
    RGBElement()
{
    qDebug() << Q_FUNC_INFO;
    
    // load registers of the colors
    addr_red_ = RGB_WAND_ROT;
    addr_green_ = RGB_WAND_GRUEN;
    addr_blue_ = RGB_WAND_BLAU;
    
    // read initial state from hardware
    red_value_ = hw::readValue(addr_red_);
    green_value_ = hw::readValue(addr_green_);
    blue_value_ = hw::readValue(addr_blue_);
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
