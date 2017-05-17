/********************************************************************************
** Form generated from reading UI file 'rgb_decke.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGB_DECKE_H
#define UI_RGB_DECKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RGB_Decke
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_all;
    QPushButton *pushButton_Group_1;
    QPushButton *pushButton_Group_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_16;
    QPushButton *pushButton_18;
    QPushButton *pushButton_2;
    QPushButton *pushButton_12;
    QPushButton *pushButton_1;
    QPushButton *pushButton_17;
    QPushButton *pushButton_15;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_11;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_10;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_back;
    QFrame *frame;
    QSlider *horizontalSlider;
    QFrame *frame_2;

    void setupUi(QDialog *RGB_Decke)
    {
        if (RGB_Decke->objectName().isEmpty())
            RGB_Decke->setObjectName(QStringLiteral("RGB_Decke"));
        RGB_Decke->setEnabled(true);
        RGB_Decke->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RGB_Decke->sizePolicy().hasHeightForWidth());
        RGB_Decke->setSizePolicy(sizePolicy);
        RGB_Decke->setMinimumSize(QSize(800, 480));
        RGB_Decke->setMaximumSize(QSize(800, 480));
        RGB_Decke->setStyleSheet(QStringLiteral(""));
        label = new QLabel(RGB_Decke);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 800, 50));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:rgb(250,250,250);"));
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(RGB_Decke);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(700, 100, 101, 21));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color:rgb(250,250,250);"));
        pushButton_all = new QPushButton(RGB_Decke);
        pushButton_all->setObjectName(QStringLiteral("pushButton_all"));
        pushButton_all->setGeometry(QRect(715, 140, 83, 40));
        pushButton_all->setFont(font1);
        pushButton_all->setFocusPolicy(Qt::NoFocus);
        pushButton_all->setStyleSheet(QLatin1String("border:none;\n"
"background-color:rgba(0,0,0,100);\n"
"color:rgb(250,250,250);"));
        pushButton_all->setCheckable(true);
        pushButton_all->setFlat(true);
        pushButton_Group_1 = new QPushButton(RGB_Decke);
        pushButton_Group_1->setObjectName(QStringLiteral("pushButton_Group_1"));
        pushButton_Group_1->setGeometry(QRect(715, 190, 83, 40));
        pushButton_Group_1->setFont(font1);
        pushButton_Group_1->setFocusPolicy(Qt::NoFocus);
        pushButton_Group_1->setStyleSheet(QLatin1String("border:none;\n"
"background-color:rgba(0,0,0,100);\n"
"color:rgb(250,250,250);"));
        pushButton_Group_1->setCheckable(true);
        pushButton_Group_1->setFlat(true);
        pushButton_Group_2 = new QPushButton(RGB_Decke);
        pushButton_Group_2->setObjectName(QStringLiteral("pushButton_Group_2"));
        pushButton_Group_2->setGeometry(QRect(715, 240, 83, 40));
        pushButton_Group_2->setFont(font1);
        pushButton_Group_2->setFocusPolicy(Qt::NoFocus);
        pushButton_Group_2->setStyleSheet(QLatin1String("border:none;\n"
"background-color:rgba(0,0,0,100);\n"
"color:rgb(250,250,250);"));
        pushButton_Group_2->setCheckable(true);
        pushButton_Group_2->setFlat(true);
        gridLayoutWidget = new QWidget(RGB_Decke);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 130, 621, 321));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(8);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_16 = new QPushButton(gridLayoutWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy1);
        pushButton_16->setFocusPolicy(Qt::NoFocus);
        pushButton_16->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_16->setCheckable(true);
        pushButton_16->setChecked(true);
        pushButton_16->setFlat(true);

        gridLayout->addWidget(pushButton_16, 4, 3, 1, 1);

        pushButton_18 = new QPushButton(gridLayoutWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        sizePolicy1.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy1);
        pushButton_18->setFocusPolicy(Qt::NoFocus);
        pushButton_18->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_18->setCheckable(true);
        pushButton_18->setChecked(true);
        pushButton_18->setFlat(true);

        gridLayout->addWidget(pushButton_18, 5, 3, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        pushButton_2->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_2->setCheckable(true);
        pushButton_2->setChecked(true);
        pushButton_2->setFlat(true);

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy1.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy1);
        pushButton_12->setFocusPolicy(Qt::NoFocus);
        pushButton_12->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_12->setCheckable(true);
        pushButton_12->setChecked(true);
        pushButton_12->setFlat(true);

        gridLayout->addWidget(pushButton_12, 1, 3, 1, 1);

        pushButton_1 = new QPushButton(gridLayoutWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        sizePolicy1.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy1);
        pushButton_1->setFocusPolicy(Qt::NoFocus);
        pushButton_1->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_1->setCheckable(true);
        pushButton_1->setChecked(true);
        pushButton_1->setFlat(true);

        gridLayout->addWidget(pushButton_1, 1, 0, 1, 1);

        pushButton_17 = new QPushButton(gridLayoutWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        sizePolicy1.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy1);
        pushButton_17->setFocusPolicy(Qt::NoFocus);
        pushButton_17->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_17->setCheckable(true);
        pushButton_17->setChecked(true);
        pushButton_17->setFlat(true);

        gridLayout->addWidget(pushButton_17, 5, 2, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy1.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy1);
        pushButton_15->setFocusPolicy(Qt::NoFocus);
        pushButton_15->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_15->setCheckable(true);
        pushButton_15->setChecked(true);
        pushButton_15->setFlat(true);

        gridLayout->addWidget(pushButton_15, 4, 2, 1, 1);

        pushButton_13 = new QPushButton(gridLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy1.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy1);
        pushButton_13->setFocusPolicy(Qt::NoFocus);
        pushButton_13->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_13->setCheckable(true);
        pushButton_13->setChecked(true);
        pushButton_13->setFlat(true);

        gridLayout->addWidget(pushButton_13, 3, 2, 1, 1);

        pushButton_14 = new QPushButton(gridLayoutWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy1.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy1);
        pushButton_14->setFocusPolicy(Qt::NoFocus);
        pushButton_14->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_14->setCheckable(true);
        pushButton_14->setChecked(true);
        pushButton_14->setFlat(true);

        gridLayout->addWidget(pushButton_14, 3, 3, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy1.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy1);
        pushButton_11->setFocusPolicy(Qt::NoFocus);
        pushButton_11->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_11->setCheckable(true);
        pushButton_11->setChecked(true);
        pushButton_11->setFlat(true);

        gridLayout->addWidget(pushButton_11, 1, 2, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setFocusPolicy(Qt::NoFocus);
        pushButton_7->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_7->setCheckable(true);
        pushButton_7->setChecked(true);
        pushButton_7->setFlat(true);

        gridLayout->addWidget(pushButton_7, 5, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setFocusPolicy(Qt::NoFocus);
        pushButton_5->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_5->setCheckable(true);
        pushButton_5->setChecked(true);
        pushButton_5->setFlat(true);

        gridLayout->addWidget(pushButton_5, 4, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setFocusPolicy(Qt::NoFocus);
        pushButton_3->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_3->setCheckable(true);
        pushButton_3->setChecked(true);
        pushButton_3->setFlat(true);

        gridLayout->addWidget(pushButton_3, 3, 0, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);
        pushButton_10->setFocusPolicy(Qt::NoFocus);
        pushButton_10->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_10->setCheckable(true);
        pushButton_10->setChecked(true);
        pushButton_10->setFlat(true);

        gridLayout->addWidget(pushButton_10, 6, 1, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setFocusPolicy(Qt::NoFocus);
        pushButton_6->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_6->setCheckable(true);
        pushButton_6->setChecked(true);
        pushButton_6->setFlat(true);

        gridLayout->addWidget(pushButton_6, 4, 1, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setFocusPolicy(Qt::NoFocus);
        pushButton_8->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_8->setCheckable(true);
        pushButton_8->setChecked(true);
        pushButton_8->setFlat(true);

        gridLayout->addWidget(pushButton_8, 5, 1, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        pushButton_9->setFocusPolicy(Qt::NoFocus);
        pushButton_9->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_9->setCheckable(true);
        pushButton_9->setChecked(true);
        pushButton_9->setFlat(true);

        gridLayout->addWidget(pushButton_9, 6, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setFocusPolicy(Qt::NoFocus);
        pushButton_4->setStyleSheet(QLatin1String("border:2px solid white;\n"
"border-radius:10px;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_4->setCheckable(true);
        pushButton_4->setChecked(true);
        pushButton_4->setFlat(true);

        gridLayout->addWidget(pushButton_4, 3, 1, 1, 1);

        pushButton_back = new QPushButton(RGB_Decke);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setGeometry(QRect(730, 410, 60, 60));
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/bilder/Icons/arrow_left_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_back->setIcon(icon);
        pushButton_back->setIconSize(QSize(50, 50));
        pushButton_back->setFlat(true);
        frame = new QFrame(RGB_Decke);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 800, 480));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/bilder/Icons/back_dark.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalSlider = new QSlider(frame);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(630, 80, 160, 21));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        frame_2 = new QFrame(RGB_Decke);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 100, 680, 370));
        frame_2->setStyleSheet(QStringLiteral("background-image: url(:/bilder/Icons/back_grundriss.png);"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Plain);
        frame->raise();
        label->raise();
        label_2->raise();
        pushButton_all->raise();
        pushButton_Group_1->raise();
        pushButton_Group_2->raise();
        gridLayoutWidget->raise();
        pushButton_back->raise();
        frame_2->raise();

        retranslateUi(RGB_Decke);

        QMetaObject::connectSlotsByName(RGB_Decke);
    } // setupUi

    void retranslateUi(QDialog *RGB_Decke)
    {
        RGB_Decke->setWindowTitle(QApplication::translate("RGB_Decke", "Dialog", 0));
        label->setText(QApplication::translate("RGB_Decke", "RGB Decke", 0));
        label_2->setText(QApplication::translate("RGB_Decke", "Gruppe", 0));
        pushButton_all->setText(QApplication::translate("RGB_Decke", "Alle", 0));
        pushButton_Group_1->setText(QApplication::translate("RGB_Decke", "1", 0));
        pushButton_Group_2->setText(QApplication::translate("RGB_Decke", "2", 0));
        pushButton_16->setText(QString());
        pushButton_18->setText(QString());
        pushButton_2->setText(QString());
        pushButton_12->setText(QString());
        pushButton_1->setText(QString());
        pushButton_17->setText(QString());
        pushButton_15->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        pushButton_11->setText(QString());
        pushButton_7->setText(QString());
        pushButton_5->setText(QString());
        pushButton_3->setText(QString());
        pushButton_10->setText(QString());
        pushButton_6->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_4->setText(QString());
        pushButton_back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RGB_Decke: public Ui_RGB_Decke {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGB_DECKE_H
