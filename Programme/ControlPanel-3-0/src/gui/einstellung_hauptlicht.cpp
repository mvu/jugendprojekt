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
    
    all_selected_last_ = false;
    group_1_selected_last_ = false;
    group_2_selected_last_ = false;

    // slide-in Animation
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(250);
    animation->setStartValue(QRect(-800,0,0,480));
    animation->setEndValue(QRect(0,0,800,480));
    animation->setEasingCurve(QEasingCurve::InExpo);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

EinstellungHauptlicht::~EinstellungHauptlicht()
{
    qDebug() << Q_FUNC_INFO;

    // uncheck all buttons

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

void EinstellungHauptlicht::on_pushButton_all_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    // will affect all other buttons only if the button itself was hit
    if (all_selected_last_ != checked)
    {
        all_selected_last_ = checked;
        
        for (auto push_button: push_buttons_HL_)
        push_button->setChecked(checked); 
    }
    
   
}

void EinstellungHauptlicht::on_pushButton_group_1_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    // will affect all other buttons only if the button itself was hit
    if (group_1_selected_last_ != checked)
    {
        group_1_selected_last_ = checked;
        
        for (int i = 0; i < 4; i++)
        {
            push_buttons_HL_[i]->setChecked(checked); 
        }
    }
    
    // check if by toggeling the button another group is selected
    checkForGroups();
}

void EinstellungHauptlicht::on_pushButton_group_2_toggled(bool checked)
{
    qDebug() << Q_FUNC_INFO;
    
    // will affect all other buttons only if the button itself was hit
    if (group_2_selected_last_ != checked)
    {
        group_2_selected_last_ = checked;
        
        for (int i = 4; i < 8; i++)
        {
            push_buttons_HL_[i]->setChecked(checked); 
        }
    }
    
    // check if by toggeling the button another group is selected
    checkForGroups();
}

void EinstellungHauptlicht::on_pushButton_on_off_released()
{
    qDebug() << Q_FUNC_INFO;
    
    // welchen Zustand zeigt der Knopf wenn mehrere Streifen mit unterschiedlichem Status ausgewählt werden??
    
    // will only affect selected ones
    for (auto streifen: jugendraum_->hauptlicht)
    {
        // invert current state    
        streifen->setOn(not streifen->isOn());
    }
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
    
    // check if all-group is selected
    bool all_selected = true;
   
    for (auto push_button: push_buttons_HL_)
    {
        all_selected = all_selected && push_button->isChecked();
    }
    
    // check if group 1 is selected
    bool group_1_selected = true;
    
    for (int i = 0; i < 4; i++)
    {
        group_1_selected = group_1_selected && push_buttons_HL_[i]->isChecked();
    }
    
    // check if group 2 is selected
    bool group_2_selected = true;
    
    for (int i = 4; i < 8; i++)
    {
        group_2_selected = group_2_selected && push_buttons_HL_[i]->isChecked();
    }
    
    ui_->pushButton_all->setChecked(all_selected);
    
    // if the group buttons have the same state like the all_button, then the 
    // actions of the smaller groups aren't needed because the all_button 
    // does it all alone
    if (all_selected != group_1_selected)
        ui_->pushButton_group_1->setChecked(group_1_selected);
    if (all_selected != group_2_selected)
        ui_->pushButton_group_2->setChecked(group_2_selected); 
}

