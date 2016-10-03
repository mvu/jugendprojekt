#ifndef PCA_9635_H
#define PCA_9635_H

#include <QObject>

#define PCA9635_MODE1 0x0
#define PCA9635_MDOE2 0x01
#define PCA9635_SUBADR1 0x18
#define PCA9635_SUBADR2 0x19
#define PCA9635_SUBADR3 0x1A
#define PCA9635_ALLCALLADR 0x1B
#define PCA9635_LEDOUT0 0x14
#define PCA9635_LEDOUT1 0x15
#define PCA9635_LEDOUT2 0x16
#define PCA9635_LEDOUT3 0x17
#define PCA9635_GRPPWM 0x12
#define PCA9635_GRPFREQ 0x13
#define PCA9635_PWM0 0x02
#define PCA9635_PWM1 0x03
#define PCA9635_PWM2 0x04
#define PCA9635_PWM3 0x05
#define PCA9635_PWM4 0x06
#define PCA9635_PWM5 0x07
#define PCA9635_PWM6 0x08
#define PCA9635_PWM7 0x09
#define PCA9635_PWM8 0x0A
#define PCA9635_PWM9 0x0B
#define PCA9635_PWM10 0x0C
#define PCA9635_PWM11 0x0D
#define PCA9635_PWM12 0x0E
#define PCA9635_PWM13 0x0F
#define PCA9635_PWM14 0x10
#define PCA9635_PWM15 0x11

#define PCA9635_PRESCALE 0xFE
#define LED0_ON_L 0x6
#define LEDALL_ON_L 0xFA
#define PIN_ALL 16



class pca_9635 : public QObject
{
    Q_OBJECT
public:
    explicit pca_9635(QObject *parent = 0);


signals:

public slots:
    void pca9635FullOn(int fd, int pin, int tf);
    void pca9635FullOff(int fd, int pin, int tf);
    void pca9635PWMWrite(int fd, int pin, int pwm);
    void pca9635PWMFreq(int fd, float freq);
    void pca9635PWMReset(int fd);
    int pca9635PWMRead(int fd, int reg);
    int pca9635Setup(int i2cAddress);


};

#endif // PCA_9635_H
