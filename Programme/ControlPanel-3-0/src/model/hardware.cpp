#include "inc/model/hardware.h"

namespace hw 
{
    // something like a hack for privacy in namespaces
    namespace 
    {
        // file descriptor
        int mcp23017;
        int WiringPiReadReg8(int fd, uint8_t reg){return 0;}
        int WiringPiWriteReg8(int fd, uint8_t reg, uint8_t val){return 0;}
    }
 
} 

void hw::init()
{
    qDebug() << Q_FUNC_INFO;
}

bool hw::readState(uint8_t bank, uint8_t bit)
{
    qDebug() << Q_FUNC_INFO;
    
    return bit & WiringPiReadReg8(mcp23017, bank);
}

void hw::writeState(uint8_t bank, uint8_t bit, bool state)
{
    qDebug() << Q_FUNC_INFO;
    
    uint8_t val_old = WiringPiReadReg8(mcp23017, bank);
    uint8_t val_new = (val_old & ~bit) | (state << bit);
    int ret = WiringPiWriteReg8(mcp23017, bank, val_new);
    
} 

int hw::readValue(uint8_t reg)
{
    return 0;
}

void hw::writeValue(uint8_t reg, int val)
{ 

}