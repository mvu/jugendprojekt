/*!
 * \file j_element.cpp
 * \brief Source der JElement Basisklasse für alles im Jugendraum
 */
#include "inc/model/j_element.h"

JElement::JElement()
{
    qDebug() << Q_FUNC_INFO;
}

JElement::~JElement()
{
    qDebug() << Q_FUNC_INFO;
}

void JElement::update()
{
    qDebug() << Q_FUNC_INFO;
    
    // execute and show complete list
    foreach (const UpdateFunc &ptr, updaters_)
        ptr();

    // after execution, clear the list
    updaters_.clear();
    updaters_addr_.clear();

}

void JElement::saveToFile( QString filename)
{
    qDebug() << Q_FUNC_INFO;
}

void JElement::loadFromFile(QString filename)
{
    qDebug() << Q_FUNC_INFO;
}

void JElement::addToUpdaters(UpdateFunc updater)
{
    qDebug() << Q_FUNC_INFO; 
    
    // check if updater is already in updaters_ by using QSet of adresses  
    if (not updaters_addr_.contains(&updater))
    {
         updaters_.append(updater);
         updaters_addr_.insert(&updater);
    }
}
