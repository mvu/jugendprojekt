/*!
 * \file einstellung_rgb_wand.cpp
 * \brief Source für die Wand-RGB-Einstellung GUI
 */
#include "inc/gui/einstellung_rgb_wand.h"
#include "ui_einstellung_rgb_wand.h"

EinstellungRGBWand::EinstellungRGBWand(QWidget *parent, Jugendraum *j) :
    QDialog(parent),
    ui_(new Ui::EinstellungRGBWand)
{
    qDebug() << Q_FUNC_INFO;
        
    jugendraum_ = j;

    // erzeuge GUI
    ui_->setupUi(this);
    ui_->horizontalLayoutWidget->setStyleSheet("border:none;");
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
    ui_->pushButton_on_off->setChecked(jugendraum_->wand_rgb->RGBisOn());
    ui_->pushButton_set_color->setChecked(false);
}

EinstellungRGBWand::~EinstellungRGBWand()
{
    qDebug() << Q_FUNC_INFO;
    // delete slider if they exist
    ui_->pushButton_set_color->setChecked(false);
    delete ui_;
}

void EinstellungRGBWand::on_pushButton_back_released()
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

void EinstellungRGBWand::on_pushButton_on_off_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;

    jugendraum_->wand_rgb->setRGBOn(checked);
    ui_->pushButton_on_off->setText(checked ? "Aus" : "An");

    // close sliders if rgb gets switched off
    if (not checked) ui_->pushButton_set_color->setChecked(false);
}

void EinstellungRGBWand::on_pushButton_set_color_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;

    if (checked)
    {
        // activate rgb, so that the changes take immediate effect
        ui_->pushButton_on_off->setChecked(true);

        if (not hw::sliderless())
        {
            // create the sliders
            slider_red_ =   new JSlider(this, 2, jugendraum_->wand_rgb->getRedValue());
            slider_green_ = new JSlider(this, 3, jugendraum_->wand_rgb->getGreenValue());
            slider_blue_ =  new JSlider(this, 4, jugendraum_->wand_rgb->getBlueValue());
            connect(slider_red_, SIGNAL(changed(int)), this, SLOT(sliderRedChanged(int)));
            connect(slider_green_, SIGNAL(changed(int)), this, SLOT(sliderGreenChanged(int)));
            connect(slider_blue_, SIGNAL(changed(int)), this, SLOT(sliderBlueChanged(int)));
        }
    }
    else
    {
        if (not hw::sliderless())
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
}

void EinstellungRGBWand::sliderRedChanged(int val)
{
    qDebug() << Q_FUNC_INFO;

    ui_->test_label_1->setText(QString("%1").arg(val));
    jugendraum_->wand_rgb->setRedValue(val);
}

void EinstellungRGBWand::sliderGreenChanged(int val)
{
    qDebug() << Q_FUNC_INFO;

    ui_->test_label_2->setText(QString("%1").arg(val));
    jugendraum_->wand_rgb->setGreenValue(val);
}

void EinstellungRGBWand::sliderBlueChanged(int val)
{
    qDebug() << Q_FUNC_INFO;

    ui_->test_label_3->setText(QString("%1").arg(val));
    jugendraum_->wand_rgb->setBlueValue(val);
}
