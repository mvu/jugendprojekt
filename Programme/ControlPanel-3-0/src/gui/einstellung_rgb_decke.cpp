/*!
 * \file einstellung_rgb_decke.cpp
 * \brief Source der GUI zur Einstellung der Decken-RGBs
 */
#include "inc/gui/einstellung_rgb_decke.h"
#include "ui_einstellung_rgb_decke.h"

EinstellungRGBDecke::EinstellungRGBDecke(QWidget *parent, Jugendraum *j) :
    QDialog(parent),
    ui_(new Ui::EinstellungRGBDecke)
{
    qDebug() << Q_FUNC_INFO;

    jugendraum_ = j;

    // erzeuge GUI
    ui_->setupUi(this);
    this->setModal(true);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->show();

    InitButtons();

    // slide-in Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(-800,0,0,480));
    animation->setEndValue(QRect(0,0,800,480));
    animation->setEasingCurve(QEasingCurve::InExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    
    // erzeuge Slider
    if (not hw::sliderless())
    {
        slider_red_ = new JSlider(this, 1, 0);
        connect(slider_red_, SIGNAL(changed(int)), this, SLOT(sliderRedChanged(int)));
        slider_green_ = new JSlider(this, 2, 0);
        connect(slider_green_, SIGNAL(changed(int)), this, SLOT(sliderGreenChanged(int)));
        slider_blue_ = new JSlider(this, 3, 0);
        connect(slider_blue_, SIGNAL(changed(int)), this, SLOT(sliderBlueChanged(int)));
    }
}

EinstellungRGBDecke::~EinstellungRGBDecke()
{
    qDebug() << Q_FUNC_INFO;

    delete ui_;
    
    if (not hw::sliderless())
    {
        delete slider_red_;
        delete slider_green_;
        delete slider_blue_;
    }
}

void EinstellungRGBDecke::InitButtons()
{
    // Lade alle QPushButtons der RGBs in eine QList
    push_buttons_rgb_.append(ui_->pushButton_1);
    push_buttons_rgb_.append(ui_->pushButton_2);
    push_buttons_rgb_.append(ui_->pushButton_3);
    push_buttons_rgb_.append(ui_->pushButton_4);
    push_buttons_rgb_.append(ui_->pushButton_5);
    push_buttons_rgb_.append(ui_->pushButton_6);
    push_buttons_rgb_.append(ui_->pushButton_7);
    push_buttons_rgb_.append(ui_->pushButton_8);
    push_buttons_rgb_.append(ui_->pushButton_9);
    push_buttons_rgb_.append(ui_->pushButton_10);
    push_buttons_rgb_.append(ui_->pushButton_11);
    push_buttons_rgb_.append(ui_->pushButton_12);
    push_buttons_rgb_.append(ui_->pushButton_13);
    push_buttons_rgb_.append(ui_->pushButton_14);
    push_buttons_rgb_.append(ui_->pushButton_15);
    push_buttons_rgb_.append(ui_->pushButton_16);
    push_buttons_rgb_.append(ui_->pushButton_17);
    push_buttons_rgb_.append(ui_->pushButton_18);

    // Lade alle QPushButtons der Gruppen in eine QList
    push_buttons_groups_.append(ui_->pushButton_group_all);
    push_buttons_groups_.append(ui_->pushButton_group_1);
    push_buttons_groups_.append(ui_->pushButton_group_2);

    // setze StyleSheets für QPushButtons der RGBs
    for (int i = 0; i < push_buttons_rgb_.length(); i++){
        push_buttons_rgb_[i]->setStyleSheet("QPushButton { \
                                                background-color: rgba(0,0,0,80); \
                                                border: 2px solid black; \
                                                border-radius: 10px; \
                                            } \
                                            QPushButton:checked { \
                                                border: 2px solid white; \
                                                border-radius: 10px;\
                                            }");
    }

    // setzte StyleSheets für QPushButtons der Gruppen
    for (int i = 0; i < push_buttons_groups_.length(); i++){
        push_buttons_groups_[i]->setStyleSheet("QPushButton { \
                                                   background-color: rgba(0,0,0,80); \
                                                   color: white; \
                                                   border: none; \
                                               } \
                                               QPushButton:checked { \
                                                   border: 2px solid white; \
                                               }");
    }
    
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_1_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[0]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_2_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[1]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_3_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[2]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_4_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[3]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_5_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[4]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_6_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[5]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_7_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[6]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_8_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[7]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_9_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[8]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_10_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[9]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_11_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[10]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_12_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[11]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_13_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[12]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_14_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[13]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_15_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[14]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_16_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[15]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_17_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[16]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_18_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    jugendraum_->rgb_deckenlicht[17]->allowChange(checked);
    checkForGroups();
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_group_all_released()
{
    qDebug() << Q_FUNC_INFO;
    
    bool checked = ui_->pushButton_group_all->isChecked();
 
    // will affect all other buttons only if the button itself was hit
    for (auto push_button: push_buttons_rgb_)
    {  
        // don't pass the inverted value of checked because of it is already inverted before the released-method is called
        push_button->setChecked(checked); 
    }
    
    // check which label the on/off-button show show
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_group_1_released()
{
    qDebug() << Q_FUNC_INFO;
    bool checked = ui_->pushButton_group_1->isChecked();
    
    // if group 2 is also checked this will result in checking group all
    if (ui_->pushButton_group_2->isChecked())
    {
        ui_->pushButton_group_all->setChecked(true);
        on_pushButton_group_all_released();
    }
    else
    {
        // will affect all other buttons only if the button itself was hit
        for (int i = 0; i < 10; i++)
            push_buttons_rgb_[i]->setChecked(checked); 
        for (int i = 10; i < 18; i++)
            push_buttons_rgb_[i]->setChecked(false);  
    }
    
    // check which label the on/off-button show show
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_group_2_released()
{
    qDebug() << Q_FUNC_INFO;  
    
     bool checked = ui_->pushButton_group_2->isChecked();
    
    // if group 1 is also checked this will result in checking group all
    if (ui_->pushButton_group_1->isChecked())
    {
        ui_->pushButton_group_all->setChecked(true);
        on_pushButton_group_all_released();
    }
    else
    {
        // will affect all other buttons only if the button itself was hit
        for (int i = 0; i < 10; i++)
            push_buttons_rgb_[i]->setChecked(false); 
        for (int i = 10; i < 18; i++)
            push_buttons_rgb_[i]->setChecked(checked);  
    }
    
    // check which label the on/off-button show show
    checkOnOffState(); 
}

void EinstellungRGBDecke::on_pushButton_on_off_released()
{
    qDebug() << Q_FUNC_INFO;
    
    // will only affect selected ones
    for (int i = 0; i < push_buttons_rgb_.length(); i++)
    {
        RGBStreifen* rgb_streifen = jugendraum_->rgb_deckenlicht[i];
        // set new state by inverting old, does this work??
        rgb_streifen->setRGBOn(not rgb_streifen->RGBisOn());
        setButtonBackground(push_buttons_rgb_[i], 0, 0, 0);
    }
    
    checkOnOffState();
}

void EinstellungRGBDecke::on_pushButton_back_released()
{
    qDebug() << Q_FUNC_INFO;

    // slide-out Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(150);
    animation->setStartValue(QRect(0,0,800,480));
    animation->setEndValue(QRect(-800,0,0,480));
    animation->setEasingCurve(QEasingCurve::OutExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void EinstellungRGBDecke::sliderRedChanged(int value)
{
    qDebug() << Q_FUNC_INFO;

    // will only affect selected ones
    for (auto rgb_streifen: jugendraum_->rgb_deckenlicht)
        rgb_streifen->setRedValue(value);

    checkOnOffState();
    updateButtonBackgrounds();
}

void EinstellungRGBDecke::sliderGreenChanged(int value)
{
    qDebug() << Q_FUNC_INFO;

    // will only affect selected ones
    for (auto rgb_streifen: jugendraum_->rgb_deckenlicht)
        rgb_streifen->setGreenValue(value);

    checkOnOffState();
    updateButtonBackgrounds();
}

void EinstellungRGBDecke::sliderBlueChanged(int value)
{
    qDebug() << Q_FUNC_INFO;

    // will only affect selected ones
    for (auto rgb_streifen: jugendraum_->rgb_deckenlicht)
        rgb_streifen->setBlueValue(value);

    checkOnOffState();
    updateButtonBackgrounds();    
}

void EinstellungRGBDecke::checkForGroups()
{
    qDebug() << Q_FUNC_INFO;
    
    // check if all are selected
    bool all_check = true;
    
    for (auto push_button: push_buttons_rgb_)
    {
        all_check = all_check && push_button->isChecked();
    }
    
    // check if group 1 is selected
    bool group_1_selected = true;
    
    for (int i = 0; i < 10; i++)
    {
        group_1_selected = group_1_selected && push_buttons_rgb_[i]->isChecked();
    }
    for (int i = 10; i < 18; i++)
    {
        group_1_selected = group_1_selected && (not push_buttons_rgb_[i]->isChecked());
    }
    
    // check if group 2 is selected
    bool group_2_selected = true;
    
    for (int i = 0; i < 10; i++)
    {
        group_2_selected = group_2_selected && (not push_buttons_rgb_[i]->isChecked());
    }
    for (int i = 10; i < 18; i++)
    {
        group_2_selected = group_2_selected && push_buttons_rgb_[i]->isChecked();
    }
    
    ui_->pushButton_group_all->setChecked(all_check);
    ui_->pushButton_group_1->setChecked(group_1_selected);
    ui_->pushButton_group_2->setChecked(group_2_selected);
    // overwrite the buttons of the subgroups if group all is selected
    if (all_check)
    {
        ui_->pushButton_group_1->setChecked(false);
        ui_->pushButton_group_2->setChecked(false);    
    }   
}

void EinstellungRGBDecke::updateButtonBackgrounds()
{
    qDebug() << Q_FUNC_INFO;
    
    // will affect only selected ones
    for (int i = 0; i < push_buttons_rgb_.length(); i++)
    {   
        RGBStreifen* streifen = jugendraum_->rgb_deckenlicht[i];
        setButtonBackground(push_buttons_rgb_[i], streifen->getRedValue(), streifen->getGreenValue(), streifen->getBlueValue());
    }
}

void EinstellungRGBDecke::setButtonBackground(QPushButton *button, int red, int green, int blue)
{
    qDebug() << Q_FUNC_INFO;
    
    int red_val = red * 255 / 100;
    int green_val = green * 255 / 100;
    int blue_val = blue * 255 / 100;
    QString stylesheet_text = button->styleSheet();
    int start_pos = stylesheet_text.indexOf("rgba");
    int end_pos = stylesheet_text.indexOf(")", start_pos);
    QString red_str = QString::number(red_val);
    QString green_str = QString::number(green_val);
    QString blue_str = QString::number(blue_val);
    QString new_rgb_text = "rgba(" + red_str + "," + green_str + "," + blue_str + ",80)";
    stylesheet_text.replace(start_pos, end_pos - start_pos + 1, new_rgb_text);
    button->setStyleSheet(stylesheet_text);
}

void EinstellungRGBDecke::checkOnOffState()
{
    qDebug() << Q_FUNC_INFO;
    
    bool is_on = false;
    int active_counter = 0;
    
    for (int i = 0; i < push_buttons_rgb_.length(); i++)
        if (push_buttons_rgb_[i]->isChecked())
            {
                // is true, if one or more of the buttons is on
                is_on = is_on || jugendraum_->rgb_deckenlicht[i]->RGBisOn(); 
                active_counter++;
            }
    
    ui_->pushButton_on_off->setText(is_on ? "Aus" : "An");
    
    // show no label if no button is active
    if (active_counter == 0)
        ui_->pushButton_on_off->setText("");
}

void EinstellungRGBDecke::on_RSlider_valueChanged(int value)
{   
    // for testing purpose only 
    sliderRedChanged(value);
}

void EinstellungRGBDecke::on_GSlider_valueChanged(int value)
{
    // for testing purpose only
    sliderGreenChanged(value);
}

void EinstellungRGBDecke::on_BSlider_valueChanged(int value)
{
    // for testing purpose only
    sliderBlueChanged(value);
}
