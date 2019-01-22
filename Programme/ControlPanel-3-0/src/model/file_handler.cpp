/*!
 * \file file_handler.cpp
 * \brief Source für File-Handler Klasse
 */
#include "../../inc/model/file_handler.h"

FileHandler::FileHandler(std::string filename)
{
    filename_ = filename;
}

FileHandler::~FileHandler(){
    if (file_.is_open()){
        file_.close();
    }
}

template<typename T>
void FileHandler::writeToFile(std::string param, T value){

}
