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
#include <stdexcept>
#include <QString>

/*!
 * \brief Klasse zum Lesen und Schreiben von Konfigurations-Dateien. Besteht nur aus dem Header.
 */
class FileHandler
{
public:
    /*!
     * \brief Konstruktur 
     * \param filename Name der Datei, die behandelt wird. Muss den gesamten absoluten oder relativen Pfad enthalten.
     */
    FileHandler(QString filename){
        filename_ = filename.toStdString();
    }
    
    //! Destructor
    ~FileHandler(){
        if (file_.is_open()){
            file_.close();
        }
    }
    
    /*!
     * \brief Liest einen Wert aus einer Datei
     * \param param Name der Variable, deren Wert gelesen werden soll. Nach exakt diesem String wird in der Datei gesucht.
     * \exception std::invalid_argument Wird geworfen, falls es zu einem Fehler beim Lesen aus der Datei kommt, z.B. wenn die Typen nicht passen
     * \exception std::domain_error Wird geworfen, wenn der Parameter nicht in der Datei gefunden wurde
     * \return Gibt den aus der Datei gelesenen Wert von 'param' zurück.
     */
     //Because this is a template the implementation needs to be in the header
    template<typename T>
    T readFromFile(QString qparam){
        std::string param = qparam.toStdString();
        file_.open(filename_);
        std::string line, equal, p;
        T value = T(); //also initializes 'value'
        size_t pos;
        bool found = false;
    
        while(std::getline(file_, line) && !found){
            //find and erase comments
            pos = line.find("#");
            //std::cout << line << " " << pos <<std::endl;
  
            if (pos != std::string::npos){
                line.erase(pos, std::string::npos);
            }
            if (line.find(param) != std::string::npos){
                //read value of param from file
                std::istringstream inStream(line);
                inStream >> p; //first word is name of parameter
                inStream >> equal; //second word is an '='
                inStream >> value; //third word is needed value
                
                // check if an error occured
                if (inStream.fail()){ 
                    //std::cerr << "[READ-ERROR] An error occured while reading '" << param << "'\n";
                    throw std::invalid_argument("[READ-ERROR] An error occured while reading '" + param + "' from '" + filename_ + "'");
                }
                
                found = true;
            }
        }
        file_.close();
        
        if (!found){
            // if the parameter is not found, an exception will be thrown and the method will terminate
            throw std::domain_error("[READ-ERROR] Parameter '" + param + "' not found in '" + filename_ + "'"); 
        }
        
        // if no value could be read, this won't be reached because of the exceptions
        return value;
    }
    
    /*!
     * \brief Schreibt einen Wert in eine Datei. Alle existierenden Werte werden dabei überschrieben. Ist der Parameter noch nicht vorhanden, wird er am Ende der Datei angefügt. 
     * Es wird nicht überprüft, ob der Wert, der in die Datei geschrieben wird, einen falschen Typ hat und somit beim nächsten Lesen zu einem Fehler führt.
     * \param qparam Name der Variable, deren Wert in die Datei geschrieben werden soll. Exakt dieser String wird in der Datei überschrieben bzw. neu angelegt.
     * \param value Wert von 'param', der in die Datei geschrieben wird.
     * \todo eine Leerzeile wird vor die eigentliche Zeile geschrieben, wenn die Zeile neu geschrieben und nicht nur ersetzt wird
     */
    template<typename T>
    void writeToFile(QString qparam, T value){
        std::string param = qparam.toStdString();
        std::string tmp_filename = "tmp.txt";
        std::ofstream tmp;
        std::string comment, line;
        size_t pos, pos2;
        bool found = false;
    
        file_.open(filename_);
        tmp.open(tmp_filename);
    
        //replace value of 'param' by 'value'
        if (file_.is_open()){
            while(!file_.eof()){
                getline(file_, line);
    
                pos = line.find(param);
                if (pos != std::string::npos){
                    pos2 = line.find("#");
                    comment = "";
                    if (pos2 != std::string::npos){
                        comment = line.substr(pos2);
                    }
                    tmp << param << " = " << value << " " << comment << std::endl;
                    found = true;
                }
                else {
                    tmp << line << std::endl;
                }
            }
        }
        
        // if param was not found, it is added at the end
        if (!found){
            tmp << param << " = " << value << std::endl;
        }
    
        tmp.close();
        file_.close();
    
        // replace old file by new one
        const char * tmp_file_p = tmp_filename.c_str();
        const char * file_p = filename_.c_str();
        remove(file_p);
        rename(tmp_file_p, file_p);
    }
    
private:
    std::string filename_;
    std::fstream file_;
};

#endif // FILE_HANDLER_H
