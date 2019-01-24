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
    
    // show complete list
//    foreach (const FuncPtr &ptr, updaters_)
//    {
//        qDebug() << ptr;
//            (*ptr)();
//    }
       
    FuncPtr tmp = updaters_[0];
    qDebug() << tmp;
    (*tmp)();   
    qDebug() << "size: " << updaters_.size();
    //updaters_.clear();
    
    
//    for ( int i = 0; i < updaters_.size(); i++)
//    {
//        qDebug() << updaters_.at(i);
//    }
    
    // execute and remove
//    while (not updaters_.isEmpty())
//    {
//        qDebug() << updaters_.size();
//        (*updaters_[0])();
//        updaters_.removeFirst();
//    }
}

void JElement::saveToFile()
{
    qDebug() << Q_FUNC_INFO;
}

void JElement::loadFromFile()
{
    qDebug() << Q_FUNC_INFO;
}

void JElement::addToUpdaters(FuncPtr updater)
{
    qDebug() << Q_FUNC_INFO;
    //(*updater)();
    updaters_.push_back(updater);
    //(*(updaters_.front()))();
    update();
    qDebug() << updater << " -> " <<  updaters_.back();
}