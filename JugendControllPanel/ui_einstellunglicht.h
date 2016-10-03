/********************************************************************************
** Form generated from reading UI file 'einstellunglicht.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EINSTELLUNGLICHT_H
#define UI_EINSTELLUNGLICHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EinstellungLicht
{
public:
    QPushButton *pushButtonHome;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonRGBWand;
    QPushButton *pushButtonDinner;
    QPushButton *pushButtonPaletten;
    QPushButton *pushButtonTheke;
    QPushButton *pushButtonHauptlicht;
    QPushButton *pushButtonRGBDecke;

    void setupUi(QDialog *EinstellungLicht)
    {
        if (EinstellungLicht->objectName().isEmpty())
            EinstellungLicht->setObjectName(QStringLiteral("EinstellungLicht"));
        EinstellungLicht->resize(800, 480);
        EinstellungLicht->setMinimumSize(QSize(800, 480));
        EinstellungLicht->setMaximumSize(QSize(800, 480));
        EinstellungLicht->setStyleSheet(QLatin1String("QDialog{\n"
"background-color:rgb(255, 255, 255);\n"
"}"));
        pushButtonHome = new QPushButton(EinstellungLicht);
        pushButtonHome->setObjectName(QStringLiteral("pushButtonHome"));
        pushButtonHome->setGeometry(QRect(690, 390, 100, 80));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonHome->sizePolicy().hasHeightForWidth());
        pushButtonHome->setSizePolicy(sizePolicy);
        pushButtonHome->setMinimumSize(QSize(100, 80));
        pushButtonHome->setMaximumSize(QSize(100, 80));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(15);
        pushButtonHome->setFont(font);
        pushButtonHome->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"border-image:url(:/new/bilder/bilder/zurueck.png) 1;\n"
"border-width: 1px;\n"
"}"));
        gridLayoutWidget = new QWidget(EinstellungLicht);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 30, 731, 331));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonRGBWand = new QPushButton(gridLayoutWidget);
        pushButtonRGBWand->setObjectName(QStringLiteral("pushButtonRGBWand"));
        sizePolicy.setHeightForWidth(pushButtonRGBWand->sizePolicy().hasHeightForWidth());
        pushButtonRGBWand->setSizePolicy(sizePolicy);
        pushButtonRGBWand->setMinimumSize(QSize(100, 80));
        pushButtonRGBWand->setMaximumSize(QSize(100, 80));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        pushButtonRGBWand->setFont(font1);

        gridLayout->addWidget(pushButtonRGBWand, 0, 1, 1, 1);

        pushButtonDinner = new QPushButton(gridLayoutWidget);
        pushButtonDinner->setObjectName(QStringLiteral("pushButtonDinner"));
        sizePolicy.setHeightForWidth(pushButtonDinner->sizePolicy().hasHeightForWidth());
        pushButtonDinner->setSizePolicy(sizePolicy);
        pushButtonDinner->setMinimumSize(QSize(100, 80));
        pushButtonDinner->setMaximumSize(QSize(100, 80));
        QFont font2;
        font2.setFamily(QStringLiteral("Comic Sans MS"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        pushButtonDinner->setFont(font2);
        pushButtonDinner->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(pushButtonDinner, 1, 0, 1, 1);

        pushButtonPaletten = new QPushButton(gridLayoutWidget);
        pushButtonPaletten->setObjectName(QStringLiteral("pushButtonPaletten"));
        sizePolicy.setHeightForWidth(pushButtonPaletten->sizePolicy().hasHeightForWidth());
        pushButtonPaletten->setSizePolicy(sizePolicy);
        pushButtonPaletten->setMinimumSize(QSize(100, 80));
        pushButtonPaletten->setMaximumSize(QSize(100, 80));
        pushButtonPaletten->setFont(font2);

        gridLayout->addWidget(pushButtonPaletten, 1, 2, 1, 1);

        pushButtonTheke = new QPushButton(gridLayoutWidget);
        pushButtonTheke->setObjectName(QStringLiteral("pushButtonTheke"));
        sizePolicy.setHeightForWidth(pushButtonTheke->sizePolicy().hasHeightForWidth());
        pushButtonTheke->setSizePolicy(sizePolicy);
        pushButtonTheke->setMinimumSize(QSize(100, 80));
        pushButtonTheke->setMaximumSize(QSize(100, 80));
        pushButtonTheke->setFont(font2);

        gridLayout->addWidget(pushButtonTheke, 1, 1, 1, 1);

        pushButtonHauptlicht = new QPushButton(gridLayoutWidget);
        pushButtonHauptlicht->setObjectName(QStringLiteral("pushButtonHauptlicht"));
        sizePolicy.setHeightForWidth(pushButtonHauptlicht->sizePolicy().hasHeightForWidth());
        pushButtonHauptlicht->setSizePolicy(sizePolicy);
        pushButtonHauptlicht->setMinimumSize(QSize(0, 80));
        pushButtonHauptlicht->setMaximumSize(QSize(100, 80));
        QFont font3;
        font3.setFamily(QStringLiteral("Comic Sans MS"));
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        font3.setKerning(true);
        pushButtonHauptlicht->setFont(font3);
        pushButtonHauptlicht->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(pushButtonHauptlicht, 0, 0, 1, 1);

        pushButtonRGBDecke = new QPushButton(gridLayoutWidget);
        pushButtonRGBDecke->setObjectName(QStringLiteral("pushButtonRGBDecke"));
        sizePolicy.setHeightForWidth(pushButtonRGBDecke->sizePolicy().hasHeightForWidth());
        pushButtonRGBDecke->setSizePolicy(sizePolicy);
        pushButtonRGBDecke->setMinimumSize(QSize(100, 80));
        pushButtonRGBDecke->setMaximumSize(QSize(100, 80));
        pushButtonRGBDecke->setFont(font1);

        gridLayout->addWidget(pushButtonRGBDecke, 0, 2, 1, 1);


        retranslateUi(EinstellungLicht);
        QObject::connect(pushButtonHome, SIGNAL(clicked()), EinstellungLicht, SLOT(close()));

        QMetaObject::connectSlotsByName(EinstellungLicht);
    } // setupUi

    void retranslateUi(QDialog *EinstellungLicht)
    {
        EinstellungLicht->setWindowTitle(QApplication::translate("EinstellungLicht", "Einstellung", 0));
        pushButtonHome->setText(QApplication::translate("EinstellungLicht", "Back", 0));
        pushButtonRGBWand->setText(QApplication::translate("EinstellungLicht", "RGB Wand", 0));
        pushButtonDinner->setText(QApplication::translate("EinstellungLicht", "Diner", 0));
        pushButtonPaletten->setText(QApplication::translate("EinstellungLicht", "Paletten", 0));
        pushButtonTheke->setText(QApplication::translate("EinstellungLicht", "Theke", 0));
        pushButtonHauptlicht->setText(QApplication::translate("EinstellungLicht", "Hauptlicht", 0));
        pushButtonRGBDecke->setText(QApplication::translate("EinstellungLicht", "RGB Decke", 0));
    } // retranslateUi

};

namespace Ui {
    class EinstellungLicht: public Ui_EinstellungLicht {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EINSTELLUNGLICHT_H
