/********************************************************************************
** Form generated from reading UI file 'audio.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIO_H
#define UI_AUDIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Audio
{
public:
    QFrame *frame;
    QWidget *central_Widget;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonPC;
    QPushButton *pushButtonAUX;
    QPushButton *pushButtonPlaystation;
    QLabel *label;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButtonLautstaerke_Laut;
    QPushButton *pushButtonLautstaerke_Mittel;
    QPushButton *pushButtonLautstaerke_Leise;
    QPushButton *pushButton_OnOff;
    QPushButton *pushButton_back;
    QLabel *label_2;

    void setupUi(QDialog *Audio)
    {
        if (Audio->objectName().isEmpty())
            Audio->setObjectName(QStringLiteral("Audio"));
        Audio->resize(800, 480);
        Audio->setStyleSheet(QStringLiteral("QGroupBox::title{subcontrol-origin:margin; left:10px; padding: 0 3px 0 3px;color:white;}"));
        frame = new QFrame(Audio);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 800, 480));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/bilder/Icons/back_audio.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        central_Widget = new QWidget(Audio);
        central_Widget->setObjectName(QStringLiteral("central_Widget"));
        central_Widget->setGeometry(QRect(0, 0, 800, 480));
        groupBox_2 = new QGroupBox(central_Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(31, 80, 311, 331));
        groupBox_2->setStyleSheet(QLatin1String("margin-top:0.6em;\n"
"border:1px solid white;\n"
"border-radius:10px;\n"
"font-size:20px;\n"
""));
        verticalLayoutWidget_2 = new QWidget(groupBox_2);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 40, 291, 281));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_2->setContentsMargins(1, 0, 0, 0);
        pushButtonPC = new QPushButton(verticalLayoutWidget_2);
        pushButtonPC->setObjectName(QStringLiteral("pushButtonPC"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonPC->sizePolicy().hasHeightForWidth());
        pushButtonPC->setSizePolicy(sizePolicy);
        pushButtonPC->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,100);\n"
"border:1px solid gray;\n"
"margin-top:0;\n"
"border-radius:5px;\n"
"color:rgb(250,250,250);"));
        pushButtonPC->setFlat(true);

        verticalLayout_2->addWidget(pushButtonPC);

        pushButtonAUX = new QPushButton(verticalLayoutWidget_2);
        pushButtonAUX->setObjectName(QStringLiteral("pushButtonAUX"));
        sizePolicy.setHeightForWidth(pushButtonAUX->sizePolicy().hasHeightForWidth());
        pushButtonAUX->setSizePolicy(sizePolicy);
        pushButtonAUX->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,100);\n"
"border:1px solid gray;\n"
"margin-top:0;\n"
"border-radius:5px;\n"
"color:rgb(250,250,250);"));
        pushButtonAUX->setFlat(true);

        verticalLayout_2->addWidget(pushButtonAUX);

        pushButtonPlaystation = new QPushButton(verticalLayoutWidget_2);
        pushButtonPlaystation->setObjectName(QStringLiteral("pushButtonPlaystation"));
        pushButtonPlaystation->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButtonPlaystation->sizePolicy().hasHeightForWidth());
        pushButtonPlaystation->setSizePolicy(sizePolicy);
        pushButtonPlaystation->setMinimumSize(QSize(0, 0));
        pushButtonPlaystation->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,100);\n"
"border:1px solid gray;\n"
"margin-top:0;\n"
"border-radius:5px;\n"
"color:rgb(250,250,250);"));
        pushButtonPlaystation->setIconSize(QSize(16, 16));
        pushButtonPlaystation->setFlat(true);

        verticalLayout_2->addWidget(pushButtonPlaystation);

        label = new QLabel(central_Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 841, 61));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:rgb(250,250,250);"));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        groupBox_3 = new QGroupBox(central_Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(361, 80, 171, 331));
        groupBox_3->setStyleSheet(QLatin1String("margin-top:0.6em;\n"
"border:1px solid white;\n"
"border-radius:10px;\n"
"font-size:20px;\n"
""));
        verticalLayoutWidget_3 = new QWidget(groupBox_3);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 40, 151, 281));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_3->setContentsMargins(1, 0, 0, 0);
        pushButtonLautstaerke_Laut = new QPushButton(verticalLayoutWidget_3);
        pushButtonLautstaerke_Laut->setObjectName(QStringLiteral("pushButtonLautstaerke_Laut"));
        sizePolicy.setHeightForWidth(pushButtonLautstaerke_Laut->sizePolicy().hasHeightForWidth());
        pushButtonLautstaerke_Laut->setSizePolicy(sizePolicy);
        pushButtonLautstaerke_Laut->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,100);\n"
"border:1px solid gray;\n"
"margin-top:0;\n"
"border-radius:5px;\n"
"color:rgb(250,250,250);"));
        pushButtonLautstaerke_Laut->setFlat(true);

        verticalLayout_3->addWidget(pushButtonLautstaerke_Laut);

        pushButtonLautstaerke_Mittel = new QPushButton(verticalLayoutWidget_3);
        pushButtonLautstaerke_Mittel->setObjectName(QStringLiteral("pushButtonLautstaerke_Mittel"));
        sizePolicy.setHeightForWidth(pushButtonLautstaerke_Mittel->sizePolicy().hasHeightForWidth());
        pushButtonLautstaerke_Mittel->setSizePolicy(sizePolicy);
        pushButtonLautstaerke_Mittel->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,100);\n"
"border:1px solid gray;\n"
"margin-top:0;\n"
"border-radius:5px;\n"
"color:rgb(250,250,250);"));
        pushButtonLautstaerke_Mittel->setFlat(true);

        verticalLayout_3->addWidget(pushButtonLautstaerke_Mittel);

        pushButtonLautstaerke_Leise = new QPushButton(verticalLayoutWidget_3);
        pushButtonLautstaerke_Leise->setObjectName(QStringLiteral("pushButtonLautstaerke_Leise"));
        pushButtonLautstaerke_Leise->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButtonLautstaerke_Leise->sizePolicy().hasHeightForWidth());
        pushButtonLautstaerke_Leise->setSizePolicy(sizePolicy);
        pushButtonLautstaerke_Leise->setMinimumSize(QSize(0, 0));
        pushButtonLautstaerke_Leise->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,100);\n"
"border:1px solid gray;\n"
"margin-top:0;\n"
"border-radius:5px;\n"
"color:rgb(250,250,250);"));
        pushButtonLautstaerke_Leise->setIconSize(QSize(16, 16));
        pushButtonLautstaerke_Leise->setFlat(true);

        verticalLayout_3->addWidget(pushButtonLautstaerke_Leise);

        pushButton_OnOff = new QPushButton(central_Widget);
        pushButton_OnOff->setObjectName(QStringLiteral("pushButton_OnOff"));
        pushButton_OnOff->setGeometry(QRect(691, 10, 80, 51));
        pushButton_OnOff->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,100);\n"
"border:1px solid white;\n"
"border-radius:5px;\n"
"color:rgb(250,250,250);"));
        pushButton_OnOff->setCheckable(true);
        pushButton_OnOff->setFlat(true);
        pushButton_back = new QPushButton(central_Widget);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setGeometry(QRect(731, 390, 61, 61));
        QIcon icon;
        icon.addFile(QStringLiteral(":/bilder/Icons/arrow_left_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_back->setIcon(icon);
        pushButton_back->setIconSize(QSize(50, 50));
        pushButton_back->setFlat(true);
        label_2 = new QLabel(central_Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(31, 425, 501, 21));
        label_2->setStyleSheet(QStringLiteral("color:rgb(250,250,250);"));

        retranslateUi(Audio);

        QMetaObject::connectSlotsByName(Audio);
    } // setupUi

    void retranslateUi(QDialog *Audio)
    {
        Audio->setWindowTitle(QApplication::translate("Audio", "Dialog", 0));
        groupBox_2->setTitle(QApplication::translate("Audio", "Eingang", 0));
        pushButtonPC->setText(QApplication::translate("Audio", "PC", 0));
        pushButtonAUX->setText(QApplication::translate("Audio", "AUX", 0));
        pushButtonPlaystation->setText(QApplication::translate("Audio", "PlayStation", 0));
        label->setText(QApplication::translate("Audio", "Audio", 0));
        groupBox_3->setTitle(QApplication::translate("Audio", "Lautst\303\244rke", 0));
        pushButtonLautstaerke_Laut->setText(QApplication::translate("Audio", "Laut", 0));
        pushButtonLautstaerke_Mittel->setText(QApplication::translate("Audio", "Mittel", 0));
        pushButtonLautstaerke_Leise->setText(QApplication::translate("Audio", "Leise", 0));
        pushButton_OnOff->setText(QApplication::translate("Audio", "An/Aus", 0));
        pushButton_back->setText(QString());
        label_2->setText(QApplication::translate("Audio", "<html><head/><body><p><span style=\" font-size:9pt;\">Hinweis:</span><span style=\" font-size:9pt; font-style:italic;\"> Der Verst\303\244rker reagiert tr\303\244ge, bitte dementsprechend geduldig sein....</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Audio: public Ui_Audio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIO_H
