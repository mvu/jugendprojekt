/*!
 * \file file_handler.h
 * \brief Header für File-Handler Klasse
 */
#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

/*!
 * \brief Klasse zum Lesen und Schreiben von Konfigurations-Dateien
 */
class FileHandler
{
public:
    /*!
     * \brief Konstruktur 
     * \param filename Name der Datei, die behandelt wird. Muss den gesamten absoluten oder relativen Pfad enthalten.
     * \bug Wenn eine Zahlenvaribale gelesen werden soll, aber der Wert in der Datei ein string ist, kommt kein Fehler, sondern irgendein Rückgabewert, meistens 0
     */
    FileHandler(std::string filename);
    
    //! Destructor
    ~FileHandler();
    
    /*!
     * \brief Liest einen Wert aus einer Datei
     * \param param Name der Variable, deren Wert gelesen werden soll. Nach exakt diesem String wird in der Datei gesucht.
     * \return Gibt den aus der Datei gelesenen Wert von 'param' zurück.
     */
     //Because this is a template the implementation needs to be in the header
    template<typename T>
    T readFromFile(std::string param){
        file_.open(filename_);
        std::string line, equal, p;
        T value = T(); //also initializes 'value'
        size_t pos;
    
        while(std::getline(file_, line)){
            //find and erase comments
            pos = line.find("#");
            std::cout << line << " " << pos <<std::endl;
  
            if (pos != std::string::npos){
                line.erase(pos, std::string::npos);
            }
            if (line.find(param) != std::string::npos){
                //read value of param from file
                std::istringstream inStream(line);
                inStream >> p; //first word is name of parameter
                inStream >> equal; //second word is an '='
                inStream >> value; //third word is needed value
                file_.close();
                return value;
            }
        }
        std::cout << "[READ-ERROR] Parameter '"<<param<<"' not found\n";
        file_.close();
        return value;
    }
    
    /*!
     * \brief Schreibt einen Wert in eine Datei
     * \param param Name der Variable, deren Wert in die Datei geschrieben werden soll. Exakt dieser String wird in der Datei überschrieben bzw. neu angelegt.
     * \param value Wert von 'param', der in die Datei geschrieben wird.
     */
    template<typename T>
    void writeToFile(std::string param, T value);
    
private:
    std::string filename_;
    std::fstream file_;
};

#endif // FILE_HANDLER_H