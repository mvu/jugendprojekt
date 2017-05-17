/********************************************************************************
** Form generated from reading UI file 'menue_einstellung.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUE_EINSTELLUNG_H
#define UI_MENUE_EINSTELLUNG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menue_Einstellung
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_hauptlicht;
    QLabel *label_2;
    QPushButton *pushButton_hauptlicht_2;
    QGroupBox *groupBox_RGBdecke;
    QLabel *label_3;
    QPushButton *pushButton_RGBdecke;
    QGroupBox *groupBox_theke;
    QLabel *label_4;
    QPushButton *pushButton_Theke_2;
    QGroupBox *groupBox_RGBfenster;
    QLabel *label_6;
    QPushButton *pushButton_RGBfenster;
    QGroupBox *groupBox_palette;
    QLabel *label_5;
    QPushButton *pushButton_palette;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_save;
    QLabel *label_7;
    QPushButton *pushButton_save;
    QGroupBox *groupBox_close;
    QLabel *label_8;
    QPushButton *pushButton_close;
    QLabel *label_uhr_2;
    QFrame *background_menue_frame;
    QLabel *label_9;

    void setupUi(QDialog *Menue_Einstellung)
    {
        if (Menue_Einstellung->objectName().isEmpty())
            Menue_Einstellung->setObjectName(QStringLiteral("Menue_Einstellung"));
        Menue_Einstellung->resize(400, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Menue_Einstellung->sizePolicy().hasHeightForWidth());
        Menue_Einstellung->setSizePolicy(sizePolicy);
        Menue_Einstellung->setMinimumSize(QSize(400, 480));
        Menue_Einstellung->setMaximumSize(QSize(400, 480));
        QPalette palette;
        QBrush brush(QColor(243, 243, 245, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        Menue_Einstellung->setPalette(palette);
        Menue_Einstellung->setContextMenuPolicy(Qt::NoContextMenu);
        Menue_Einstellung->setSizeGripEnabled(false);
        verticalLayoutWidget_2 = new QWidget(Menue_Einstellung);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 111, 361, 351));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox_hauptlicht = new QGroupBox(verticalLayoutWidget_2);
        groupBox_hauptlicht->setObjectName(QStringLiteral("groupBox_hauptlicht"));
        groupBox_hauptlicht->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 100);"));
        label_2 = new QLabel(groupBox_hauptlicht);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(false);
        label_2->setGeometry(QRect(0, 0, 359, 50));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush2(QColor(0, 0, 0, 0));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label_2->setPalette(palette1);
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);"));
        label_2->setAlignment(Qt::AlignCenter);
        pushButton_hauptlicht_2 = new QPushButton(groupBox_hauptlicht);
        pushButton_hauptlicht_2->setObjectName(QStringLiteral("pushButton_hauptlicht_2"));
        pushButton_hauptlicht_2->setGeometry(QRect(0, 0, 359, 50));
        pushButton_hauptlicht_2->setFocusPolicy(Qt::NoFocus);
        pushButton_hauptlicht_2->setFlat(true);

        verticalLayout_2->addWidget(groupBox_hauptlicht);

        groupBox_RGBdecke = new QGroupBox(verticalLayoutWidget_2);
        groupBox_RGBdecke->setObjectName(QStringLiteral("groupBox_RGBdecke"));
        groupBox_RGBdecke->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 100);"));
        label_3 = new QLabel(groupBox_RGBdecke);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(false);
        label_3->setGeometry(QRect(0, 0, 359, 50));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label_3->setPalette(palette2);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);"));
        label_3->setAlignment(Qt::AlignCenter);
        pushButton_RGBdecke = new QPushButton(groupBox_RGBdecke);
        pushButton_RGBdecke->setObjectName(QStringLiteral("pushButton_RGBdecke"));
        pushButton_RGBdecke->setGeometry(QRect(0, 0, 359, 50));
        pushButton_RGBdecke->setFocusPolicy(Qt::NoFocus);
        pushButton_RGBdecke->setFlat(true);

        verticalLayout_2->addWidget(groupBox_RGBdecke);

        groupBox_theke = new QGroupBox(verticalLayoutWidget_2);
        groupBox_theke->setObjectName(QStringLiteral("groupBox_theke"));
        groupBox_theke->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 100);"));
        label_4 = new QLabel(groupBox_theke);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(false);
        label_4->setGeometry(QRect(0, 0, 359, 50));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label_4->setPalette(palette3);
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);"));
        label_4->setAlignment(Qt::AlignCenter);
        pushButton_Theke_2 = new QPushButton(groupBox_theke);
        pushButton_Theke_2->setObjectName(QStringLiteral("pushButton_Theke_2"));
        pushButton_Theke_2->setGeometry(QRect(0, 0, 359, 50));
        pushButton_Theke_2->setFocusPolicy(Qt::NoFocus);
        pushButton_Theke_2->setFlat(true);

        verticalLayout_2->addWidget(groupBox_theke);

        groupBox_RGBfenster = new QGroupBox(verticalLayoutWidget_2);
        groupBox_RGBfenster->setObjectName(QStringLiteral("groupBox_RGBfenster"));
        groupBox_RGBfenster->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 100);"));
        label_6 = new QLabel(groupBox_RGBfenster);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(false);
        label_6->setGeometry(QRect(0, 0, 359, 50));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label_6->setPalette(palette4);
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);"));
        label_6->setAlignment(Qt::AlignCenter);
        pushButton_RGBfenster = new QPushButton(groupBox_RGBfenster);
        pushButton_RGBfenster->setObjectName(QStringLiteral("pushButton_RGBfenster"));
        pushButton_RGBfenster->setGeometry(QRect(0, 0, 359, 50));
        pushButton_RGBfenster->setFocusPolicy(Qt::NoFocus);
        pushButton_RGBfenster->setFlat(true);

        verticalLayout_2->addWidget(groupBox_RGBfenster);

        groupBox_palette = new QGroupBox(verticalLayoutWidget_2);
        groupBox_palette->setObjectName(QStringLiteral("groupBox_palette"));
        groupBox_palette->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 100);"));
        label_5 = new QLabel(groupBox_palette);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(false);
        label_5->setGeometry(QRect(0, 0, 359, 50));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label_5->setPalette(palette5);
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);"));
        label_5->setAlignment(Qt::AlignCenter);
        pushButton_palette = new QPushButton(groupBox_palette);
        pushButton_palette->setObjectName(QStringLiteral("pushButton_palette"));
        pushButton_palette->setGeometry(QRect(0, 0, 359, 50));
        pushButton_palette->setFocusPolicy(Qt::NoFocus);
        pushButton_palette->setFlat(true);

        verticalLayout_2->addWidget(groupBox_palette);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_save = new QGroupBox(verticalLayoutWidget_2);
        groupBox_save->setObjectName(QStringLiteral("groupBox_save"));
        groupBox_save->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 100);"));
        label_7 = new QLabel(groupBox_save);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setEnabled(false);
        label_7->setGeometry(QRect(0, 0, 170, 50));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label_7->setPalette(palette6);
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);"));
        label_7->setAlignment(Qt::AlignCenter);
        pushButton_save = new QPushButton(groupBox_save);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setGeometry(QRect(0, 0, 173, 50));
        pushButton_save->setFocusPolicy(Qt::NoFocus);
        pushButton_save->setFlat(true);

        horizontalLayout->addWidget(groupBox_save);

        groupBox_close = new QGroupBox(verticalLayoutWidget_2);
        groupBox_close->setObjectName(QStringLiteral("groupBox_close"));
        groupBox_close->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 100);"));
        label_8 = new QLabel(groupBox_close);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setEnabled(false);
        label_8->setGeometry(QRect(0, 0, 170, 50));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        label_8->setPalette(palette7);
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);"));
        label_8->setAlignment(Qt::AlignCenter);
        pushButton_close = new QPushButton(groupBox_close);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setGeometry(QRect(0, 0, 173, 50));
        pushButton_close->setFocusPolicy(Qt::NoFocus);
        pushButton_close->setContextMenuPolicy(Qt::DefaultContextMenu);
        pushButton_close->setFlat(true);

        horizontalLayout->addWidget(groupBox_close);


        verticalLayout_2->addLayout(horizontalLayout);

        label_uhr_2 = new QLabel(Menue_Einstellung);
        label_uhr_2->setObjectName(QStringLiteral("label_uhr_2"));
        label_uhr_2->setEnabled(false);
        label_uhr_2->setGeometry(QRect(270, 6, 121, 31));
        QFont font1;
        font1.setPointSize(18);
        label_uhr_2->setFont(font1);
        label_uhr_2->setTextFormat(Qt::PlainText);
        label_uhr_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        background_menue_frame = new QFrame(Menue_Einstellung);
        background_menue_frame->setObjectName(QStringLiteral("background_menue_frame"));
        background_menue_frame->setGeometry(QRect(0, 0, 400, 480));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        background_menue_frame->setPalette(palette8);
        background_menue_frame->setStyleSheet(QStringLiteral("background-image: url(:/bilder/Icons/back_rot_half.jpg);"));
        background_menue_frame->setFrameShape(QFrame::StyledPanel);
        background_menue_frame->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(Menue_Einstellung);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setEnabled(false);
        label_9->setGeometry(QRect(20, 50, 361, 41));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        label_9->setPalette(palette9);
        QFont font2;
        font2.setPointSize(36);
        label_9->setFont(font2);
        label_9->setTextFormat(Qt::PlainText);
        label_9->setAlignment(Qt::AlignCenter);
        background_menue_frame->raise();
        verticalLayoutWidget_2->raise();
        label_uhr_2->raise();
        label_9->raise();

        retranslateUi(Menue_Einstellung);

        QMetaObject::connectSlotsByName(Menue_Einstellung);
    } // setupUi

    void retranslateUi(QDialog *Menue_Einstellung)
    {
        Menue_Einstellung->setWindowTitle(QApplication::translate("Menue_Einstellung", "Dialog", 0));
        groupBox_hauptlicht->setTitle(QString());
        label_2->setText(QApplication::translate("Menue_Einstellung", "Hauptlicht", 0));
        pushButton_hauptlicht_2->setText(QString());
        groupBox_RGBdecke->setTitle(QString());
        label_3->setText(QApplication::translate("Menue_Einstellung", "RGB Decke", 0));
        pushButton_RGBdecke->setText(QString());
        groupBox_theke->setTitle(QString());
        label_4->setText(QApplication::translate("Menue_Einstellung", "Theke", 0));
        pushButton_Theke_2->setText(QString());
        groupBox_RGBfenster->setTitle(QString());
        label_6->setText(QApplication::translate("Menue_Einstellung", "RGB Fenster", 0));
        pushButton_RGBfenster->setText(QString());
        groupBox_palette->setTitle(QString());
        label_5->setText(QApplication::translate("Menue_Einstellung", "Paletten an", 0));
        pushButton_palette->setText(QString());
        groupBox_save->setTitle(QString());
        label_7->setText(QApplication::translate("Menue_Einstellung", "Speichern", 0));
        pushButton_save->setText(QString());
        groupBox_close->setTitle(QString());
        label_8->setText(QApplication::translate("Menue_Einstellung", "Schlie\303\237en", 0));
        pushButton_close->setText(QString());
        label_uhr_2->setText(QApplication::translate("Menue_Einstellung", "11:05", 0));
        label_9->setText(QApplication::translate("Menue_Einstellung", "Men\303\274", 0));
    } // retranslateUi

};

namespace Ui {
    class Menue_Einstellung: public Ui_Menue_Einstellung {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUE_EINSTELLUNG_H
