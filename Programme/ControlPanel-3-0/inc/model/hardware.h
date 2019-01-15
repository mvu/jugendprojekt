#ifndef HARDWARE_H
#define HARDWARE_H

#include <QDebug>

#include "hardware_config.h"
#include "hardware_register.h"

#include "i2cdevice.h"

/*! \brief Der namespace hw (kurz für Hardware) bietet high level access zur
 *      Hardware wie z. B. I2C oder UART
 */
namespace hw
{
    /*!
    * \brief Initialisiert die Hardware
    */
void Init();
}

#endif // HARDWARE_H
