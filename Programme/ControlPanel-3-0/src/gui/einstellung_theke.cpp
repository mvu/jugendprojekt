/*!
 * \file einstellung_theke.cpp
 * \brief Source für die Theke-Einstellung GUI
 */
#include "inc/gui/einstellung_theke.h"
#include "ui_einstellung_theke.h"

EinstellungTheke::EinstellungTheke(QWidget *parent, Jugendraum *j) :
    QDialog(parent),
    ui_(new Ui::EinstellungTheke)
{
    qDebug() << Q_FUNC_INFO;
        
    jugendraum_ = j;

    // erzeuge GUI
    ui_->setupUi(this);
    ui_->horizontalLayoutWidget_2->setStyleSheet("border:none;");
    ui_->horizontalLayoutWidget_3->setStyleSheet("border:none;");
    this->setModal(true);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->show();

    // slide-in Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(-400,0,0,480));
    animation->setEndValue(QRect(0,0,400,480));
    animation->setEasingCurve(QEasingCurve::InExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    // setze Buttons entsprechend dem aktuellen Zustand
    ui_->pushButton_lampen_on_off->setChecked(jugendraum_->theken_licht->topIsOn());
    ui_->pushButton_rgb_on_off->setChecked(jugendraum_->theken_licht->RGBisOn());
    ui_->pushButton_rgb_on_off->setChecked(false);
}

EinstellungTheke::~EinstellungTheke()
{
    qDebug() << Q_FUNC_INFO;
    // delete slider if they exist
    ui_->pushButton_rgb_set->setChecked(false);
    delete ui_;
}

void EinstellungTheke::on_pushButton_back_released()
{
    qDebug() << Q_FUNC_INFO;  
    
    // slide-out Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(150);
    animation->setStartValue(QRect(0,0,400,480));
    animation->setEndValue(QRect(-400,0,0,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);  
}

void EinstellungTheke::on_pushButton_lampen_on_off_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    // invert current state
    jugendraum_->theken_licht->setTopOn(checked);
    ui_->pushButton_lampen_on_off->setText(checked ? "Aus" : "An");
}

void EinstellungTheke::on_pushButton_rgb_set_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;

    if (checked)
    {
        // activate rgb, so that the changes take immediate effect
        ui_->pushButton_rgb_on_off->setChecked(true);

        // create the sliders
        slider_red_ =   new JSlider(this, 2, jugendraum_->theken_licht->getRedValue());
        slider_green_ = new JSlider(this, 3, jugendraum_->theken_licht->getGreenValue());
        slider_blue_ =  new JSlider(this, 4, jugendraum_->theken_licht->getBlueValue());
        connect(slider_red_, SIGNAL(changed(int)), this, SLOT(sliderRedChanged(int)));
        connect(slider_green_, SIGNAL(changed(int)), this, SLOT(sliderGreenChanged(int)));
        connect(slider_blue_, SIGNAL(changed(int)), this, SLOT(sliderBlueChanged(int)));
    }
    else
    {
        // delete the sliders
        disconnect(slider_red_, SIGNAL(changed(int)), this, SLOT(sliderRedChanged(int)));
        disconnect(slider_green_, SIGNAL(changed(int)), this, SLOT(sliderGreenChanged(int)));
        disconnect(slider_blue_, SIGNAL(changed(int)), this, SLOT(sliderBlueChanged(int)));
        delete slider_red_;
        delete slider_green_;
        delete slider_blue_;
    }

}

void EinstellungTheke::on_pushButton_rgb_on_off_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    // invert current state
    jugendraum_->theken_licht->setRGBOn(checked);
    ui_->pushButton_rgb_on_off->setText(checked ? "Aus" : "An");

    // close sliders if rgb gets switched off
    if (not checked) ui_->pushButton_rgb_set->setChecked(false);
}

void EinstellungTheke::sliderRedChanged(int val)
{
    qDebug() << Q_FUNC_INFO;

    ui_->test_label_1->setText(QString("%1").arg(val));
    jugendraum_->theken_licht->setRedValue(val);
}

void EinstellungTheke::sliderGreenChanged(int val)
{
    qDebug() << Q_FUNC_INFO;

    ui_->test_label_2->setText(QString("%1").arg(val));
    jugendraum_->theken_licht->setGreenValue(val);
}

void EinstellungTheke::sliderBlueChanged(int val)
{
    qDebug() << Q_FUNC_INFO;

    ui_->test_label_3->setText(QString("%1").arg(val));
    jugendraum_->theken_licht->setBlueValue(val);
}
