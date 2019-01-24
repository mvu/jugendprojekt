#ifndef J_ELEMENT_H
#define J_ELEMENT_H

#include <vector>
#include <functional>
#include <QSet>
#include <QDebug>

typedef std::function<void(void)>* FuncPtr;

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
    /// \todo muss irgendwie noch unterscheiden, wohin gespeichert wird
    virtual void saveToFile(); 
    /// \todo muss irgendwie noch unterscheiden, woher geladen wird
    virtual void loadFromFile();

protected:
    /*!
     * \brief addToUpdaters
     * \param updater
     * \todo doppelte Updater aus der Liste entfernen
     */
    void addToUpdaters(FuncPtr updater);
    std::vector<FuncPtr> updaters_;    
};

#endif // J_ELEMENT_H