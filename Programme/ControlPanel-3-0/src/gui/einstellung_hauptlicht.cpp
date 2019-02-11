/*!
 * \file einstellung_hauptlicht.cpp
 * \brief Source der Hauptlicht-Einstellungs GUI
 */
#include "inc/gui/einstellung_hauptlicht.h"
#include "ui_einstellung_hauptlicht.h"

EinstellungHauptlicht::EinstellungHauptlicht(QWidget *parent, Jugendraum *j) :
    QDialog(parent),
    ui_(new Ui::EinstellungHauptlicht)
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
        slider_ = new JSlider(this, 2, 0);
        connect(slider_, SIGNAL(changed(int)), this, SLOT(sliderChanged(int)));
    }
}

EinstellungHauptlicht::~EinstellungHauptlicht()
{
    qDebug() << Q_FUNC_INFO;

    // uncheck all buttons
    for (auto push_button: push_buttons_HL_)
        push_button->setChecked(false);

    if (not hw::sliderless()) delete slider_;
    delete ui_;
}

void EinstellungHauptlicht::InitButtons()
{
    qDebug() << Q_FUNC_INFO;

    // lade alle QPushButtons der Hauptlichter in eine QList
    push_buttons_HL_.append(ui_->pushButton_1);
    push_buttons_HL_.append(ui_->pushButton_2);
    push_buttons_HL_.append(ui_->pushButton_3);
    push_buttons_HL_.append(ui_->pushButton_4);
    push_buttons_HL_.append(ui_->pushButton_5);
    push_buttons_HL_.append(ui_->pushButton_6);
    push_buttons_HL_.append(ui_->pushButton_7);
    push_buttons_HL_.append(ui_->pushButton_8);

    // lade alle QPushButtons der Gruppen in eine QList
    push_buttons_groups_.append(ui_->pushButton_all);
    push_buttons_groups_.append(ui_->pushButton_group_1);
    push_buttons_groups_.append(ui_->pushButton_group_2);

    // setze StyleSheets für QPushButtons der Hauptlichter
    for (int i = 0; i < push_buttons_HL_.length(); i++){
        push_buttons_HL_[i]->setStyleSheet("QPushButton { \
                                                background-color: rgba(0,0,0,80); \
                                                border: 2px solid black; \
                                                border-radius: 10px; \
                                            } \
                                            QPushButton:checked { \
                                                border: 2px solid white; \
                                                border-radius: 10px;\
                                            }");
    }

    // set backgrounds to real values
    updateButtonBackgrounds();

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

    ui_->pushButton_on_off->setStyleSheet("QPushButton { \
                                                   background-color: rgba(0,0,0,80); \
                                                   color: white; \
                                                   border: none; \
                                               } \
                                               QPushButton:checked { \
                                                   border: 2px solid white; \
                                               }");

    checkOnOffState();
}

void EinstellungHauptlicht::on_pushButton_1_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    jugendraum_->hauptlicht[0]->allowChange(checked);
    checkForGroups();
}

void EinstellungHauptlicht::on_pushButton_2_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    jugendraum_->hauptlicht[1]->allowChange(checked);
    checkForGroups();
}

void EinstellungHauptlicht::on_pushButton_3_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    jugendraum_->hauptlicht[2]->allowChange(checked);
    checkForGroups();
}

void EinstellungHauptlicht::on_pushButton_4_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    jugendraum_->hauptlicht[3]->allowChange(checked);
    checkForGroups();
}

void EinstellungHauptlicht::on_pushButton_5_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    jugendraum_->hauptlicht[4]->allowChange(checked);
    checkForGroups();
}

void EinstellungHauptlicht::on_pushButton_6_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    jugendraum_->hauptlicht[5]->allowChange(checked);
    checkForGroups();
}

void EinstellungHauptlicht::on_pushButton_7_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    jugendraum_->hauptlicht[6]->allowChange(checked);
    checkForGroups();
}

void EinstellungHauptlicht::on_pushButton_8_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    jugendraum_->hauptlicht[7]->allowChange(checked);
    checkForGroups();
}

void EinstellungHauptlicht::on_pushButton_all_released()
{
    qDebug() << Q_FUNC_INFO;
    bool checked = ui_->pushButton_all->isChecked();

    // will affect all other buttons only if the button itself was hit
    for (auto push_button: push_buttons_HL_)
    {
        // don't pass the inverted value of checked because of it is already inverted before the released-method is called
        push_button->setChecked(checked);
    }

    // check which label the on/off-button show show
    checkOnOffState();
}

void EinstellungHauptlicht::on_pushButton_group_1_released()
{
    qDebug() << Q_FUNC_INFO;
    bool checked = ui_->pushButton_group_1->isChecked();

    // if group 2 is also checked this will result in checking group all
    if (ui_->pushButton_group_2->isChecked())
    {
        ui_->pushButton_all->setChecked(true);
        on_pushButton_all_released();
    }
    else
    {
        // will affect all other buttons only if the button itself was hit
        for (int i = 0; i < 4; i++)
        {
            push_buttons_HL_[i]->setChecked(checked);
            push_buttons_HL_[i+4]->setChecked(false);
        }
    }

    // check which label the on/off-button show show
    checkOnOffState();
}

void EinstellungHauptlicht::on_pushButton_group_2_released()
{
    qDebug() << Q_FUNC_INFO;
    bool checked = ui_->pushButton_group_2->isChecked();

    // if group 1 is also checked this will result in checking group all
    if (ui_->pushButton_group_1->isChecked())
    {
        ui_->pushButton_all->setChecked(true);
        on_pushButton_all_released();
    }
    else
    {
        // will affect all other buttons only if the button itself was hit
        for (int i = 4; i < 8; i++)
        {
            push_buttons_HL_[i]->setChecked(checked);
            push_buttons_HL_[i-4]->setChecked(false);
        }
    }

    // check which label the on/off-button show show
    checkOnOffState();
}

void EinstellungHauptlicht::on_pushButton_on_off_released()
{
    qDebug() << Q_FUNC_INFO;

    // will only affect selected ones
    for (auto streifen: jugendraum_->hauptlicht)
    {
        // set new state (super ugly, uses gui to transport information)
        streifen->setOn(ui_->pushButton_on_off->text() != "Aus" );
    }

    checkOnOffState();
    updateButtonBackgrounds();
}

void EinstellungHauptlicht::on_pushButton_back_released()
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

void EinstellungHauptlicht::checkForGroups()
{
    qDebug() << Q_FUNC_INFO;

    // check if all are selected
    bool all_check = true;

    for (auto push_button: push_buttons_HL_)
    {
        all_check = all_check && push_button->isChecked();
    }

    // check if group 1 is selected
    bool group_1_selected = true;

    for (int i = 0; i < 4; i++)
    {
        group_1_selected = group_1_selected && push_buttons_HL_[i]->isChecked() && (not push_buttons_HL_[4+i]->isChecked());
    }

    // check if group 2 is selected
    bool group_2_selected = true;

    for (int i = 4; i < 8; i++)
    {
        group_2_selected = group_2_selected && push_buttons_HL_[i]->isChecked() && (not push_buttons_HL_[i-4]->isChecked());
    }

    ui_->pushButton_all->setChecked(all_check);
    ui_->pushButton_group_1->setChecked(group_1_selected);
    ui_->pushButton_group_2->setChecked(group_2_selected);
    // overwrite the buttons of the subgroups if group all is selected
    if (all_check)
    {
        ui_->pushButton_group_1->setChecked(false);
        ui_->pushButton_group_2->setChecked(false);
    }

    // check which label the on/off-button show show
    checkOnOffState();
}

void EinstellungHauptlicht::updateButtonBackgrounds()
{
    qDebug() << Q_FUNC_INFO;

    for (int i = 0; i < push_buttons_HL_.length(); i++)
    {
        int brightness = jugendraum_->hauptlicht[i]->getBrightness() * 255 / 100;
        QString stylesheet_text = push_buttons_HL_[i]->styleSheet();
        int start_pos = stylesheet_text.indexOf("rgba");
        int end_pos = stylesheet_text.indexOf(")", start_pos);
        QString val = QString::number(brightness);
        QString new_rgb_text = "rgba(" + val + "," + val + "," + val + ",80)";
        stylesheet_text.replace(start_pos, end_pos - start_pos + 1, new_rgb_text);
        //qDebug() << stylesheet_text;
        push_buttons_HL_[i]->setStyleSheet(stylesheet_text);
    }
}

void EinstellungHauptlicht::checkOnOffState()
{
    bool is_on = false;
    int active_counter = 0;

    for (int i = 0; i < push_buttons_HL_.length(); i++)
        if (push_buttons_HL_[i]->isChecked())
            {
                // is true, if only one of the buttons is on
                is_on = is_on || jugendraum_->hauptlicht[i]->isOn();
                active_counter++;
            }

    ui_->pushButton_on_off->setText(is_on ? "Aus" : "An");

    // hide button if no button is active
    if (active_counter == 0)
        ui_->pushButton_on_off->hide();
    else
        ui_->pushButton_on_off->show();
}

void EinstellungHauptlicht::sliderChanged(int value)
{
    qDebug() << Q_FUNC_INFO;

    // will only affect selected ones
    for (auto streifen: jugendraum_->hauptlicht)
        streifen->setBrightness(value);

    checkOnOffState();
    updateButtonBackgrounds();
}
