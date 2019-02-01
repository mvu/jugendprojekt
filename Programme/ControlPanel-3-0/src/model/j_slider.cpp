/*!
 * \file j_slider.cpp
 * \brief Source der JSlider Klasse
 */
#include "inc/model/j_slider.h"

JSlider::JSlider(QObject *parent, int slider_num, int init_position) : QObject(parent)
{
    qDebug() << Q_FUNC_INFO;

    qDebug() << "slider_num = " << slider_num;
    slider_num_ = slider_num;
    qDebug() << "slider_num_ = " << slider_num_;
    reg_setpoint_ = hw::getSliderConfig(slider_num_).at(0);
    reg_analog_ = hw::getSliderConfig(slider_num_).at(1);
    reg_active_ = hw::getSliderConfig(slider_num_).at(2);

    update_timer_ = new QTimer(this);
    connect(update_timer_, SIGNAL(timeout()), this, SLOT(update()));

    activate();
    setPosition(init_position);
    // wait a little bit for the sliders to finish their movement
    update_timer_->start(SLIDER_UPDATE_CYCLE_MS);
}

JSlider::~JSlider()
{
    qDebug() << Q_FUNC_INFO;

    update_timer_->stop();
    delete update_timer_;
    setPosition(0);
    deactivate();
}

void JSlider::setPosition(int value)
{
    qDebug() << Q_FUNC_INFO;

    // range check
    if (value > 100) value = 100;
    if (value < 0)   value = 0;
    // calculate actual setpoint for slider
    // whose ADC range is 10 bit with the maximum beeing at the bottom
    uint16_t hw_pos = (100 - value) * 1023/ 100;

    // prepare the datagram
    QByteArray datagram = reg_setpoint_; // address
    datagram.append(static_cast<uint8_t>(hw_pos >> 8)); // high byte of val
    datagram.append(static_cast<uint8_t>(hw_pos));      // low byte of val

    // ugly workaround for bad arduino programming :(
    if (active_) deactivate();
    hw::writeUDP(datagram, SLIDER_UDP);
    if (not active_) activate();
}

int JSlider::getPosition()
{
    qDebug() << Q_FUNC_INFO;

    return position_;
}

void JSlider::activate()
{
    qDebug() << Q_FUNC_INFO;

    QByteArray datagram = reg_active_;
    datagram.append(uint8_t(1));
    hw::writeUDP(datagram, SLIDER_UDP);
    active_ = true;
}

void JSlider::deactivate()
{
    qDebug() << Q_FUNC_INFO;

    QByteArray datagram = reg_active_;
    datagram.append(uint8_t(1));datagram[2] = 0;
    hw::writeUDP(datagram, SLIDER_UDP);
    active_ = false;
}

void JSlider::update()
{
    qDebug() << Q_FUNC_INFO;

    int pos_new = int((1023. - hw::readUDP(reg_analog_, SLIDER_UDP))/1023. * 100.);
    if (abs(pos_new - position_) > SLIDER_NOISE_THRESHOLD)
    {
        position_ = pos_new;
        emit changed(position_);
    }
}
