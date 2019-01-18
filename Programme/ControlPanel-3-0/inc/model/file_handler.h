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
     */
    FileHandler(std::string filename);
    
    //! Destructor
    ~FileHandler();
    
    /*!
     * \brief Liest einen Wert aus einer Datei
     * \param param Name der Variable, deren Wert gelesen werden soll. Nach exakt diesem String wird in der Datei gesucht.
     * \return Gibt den aus der Datei gelesenen Wert von 'param' zurück.
     */
    template<typename T>
    T readFromFile(std::string param);
    
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