/*!
 * \file file_handler.cpp
 * \brief Source für File-Handler Klasse
 */
#include "inc/model/file_handler.h"

FileHandler::FileHandler(std::string filename)
{
    filename_ = filename;
}

FileHandler::~FileHandler(){
    file_.close();
}

template<typename T>
T FileHandler::readFromFile(std::string param){
    file_.open(filename_);
    std::string line, equal, p;
    T value = T(); //also initializes 'value'
    unsigned int pos;

    while(std::getline(file_, line)){
        //find and erase comments
        pos = line.find("#");
        if (pos != std::string::npos){
            line.erase(pos, std::string::npos);
        }
        if (line.find(param) != std::string::npos){
            //read value of param from file
            std::istringstream inStream(line);
            inStream >> p; //first word is name of parameter
            inStream >> equal; //second word is an '='
            inStream >> value; //third word is needed value
            return value;
        }
    }
    std::cout << "[READ-ERROR] Parameter '"<<param<<"' not found\n";
    return value;
}

template<typename T>
void FileHandler::writeToFile(std::string param, T value){

}
