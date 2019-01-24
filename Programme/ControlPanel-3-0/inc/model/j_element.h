#ifndef J_ELEMENT_H
#define J_ELEMENT_H

#include <vector>
#include <functional>
#include <iostream>
#include <QSet>
#include <QDebug>

typedef std::function<void(void)> UpdateFunc;

/*!
 * \brief The JElement class
 * \todo Doku bauen!!!
 */
class JElement
{
public:
    JElement();
    ~JElement();
    
    void update();
    
    virtual void saveToFile(QString filename); 
    
    virtual void loadFromFile(QString filename);
    

protected:
    /*!
     * \brief addToUpdaters
     * \param updater
     * \todo was eleganteres für die Vermeidung von doppelten Updatern finden
     */
    void addToUpdaters(UpdateFunc updater);
    
    QList<UpdateFunc> updaters_;
    QSet<UpdateFunc*> updaters_addr_;
    
};

#endif // J_ELEMENT_H