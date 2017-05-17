/********************************************************************************
** Form generated from reading UI file 'einstellung.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EINSTELLUNG_H
#define UI_EINSTELLUNG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_einstellung
{
public:
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_fan_netz;
    QLabel *label_9;
    QLabel *label_fan_raum;
    QLabel *label_3;
    QLabel *label_fan_plat;
    QLabel *label_temp_plat;
    QLabel *label_4;
    QLabel *label_temp_raum;
    QLabel *label_temp_netz;
    QLabel *label_13;
    QLabel *label_temp_pi;
    QLabel *label_15;
    QPushButton *pushButton_back;
    QPushButton *pushButton_Off;

    void setupUi(QDialog *einstellung)
    {
        if (einstellung->objectName().isEmpty())
            einstellung->setObjectName(QStringLiteral("einstellung"));
        einstellung->resize(400, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(einstellung->sizePolicy().hasHeightForWidth());
        einstellung->setSizePolicy(sizePolicy);
        einstellung->setMaximumSize(QSize(800, 480));
        einstellung->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"font: \"Courier New\";"));
        label = new QLabel(einstellung);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 15, 396, 50));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(36);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("font: 36pt \"Courier New\";\n"
"color: rgb(240, 240, 240);"));
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(einstellung);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 100, 331, 221));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setFamily(QStringLiteral("Courier New"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_5->setFont(font1);
        label_5->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color: rgb(240, 240, 240);"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        label_fan_netz = new QLabel(gridLayoutWidget);
        label_fan_netz->setObjectName(QStringLiteral("label_fan_netz"));
        label_fan_netz->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color: rgb(240, 240, 240);"));
        label_fan_netz->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_fan_netz, 3, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color: rgb(240, 240, 240);"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 1, 1, 1, 1);

        label_fan_raum = new QLabel(gridLayoutWidget);
        label_fan_raum->setObjectName(QStringLiteral("label_fan_raum"));
        label_fan_raum->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color: rgb(240, 240, 240);"));
        label_fan_raum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_fan_raum, 4, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_fan_plat = new QLabel(gridLayoutWidget);
        label_fan_plat->setObjectName(QStringLiteral("label_fan_plat"));
        label_fan_plat->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color: rgb(240, 240, 240);"));
        label_fan_plat->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_fan_plat, 2, 2, 1, 1);

        label_temp_plat = new QLabel(gridLayoutWidget);
        label_temp_plat->setObjectName(QStringLiteral("label_temp_plat"));
        label_temp_plat->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color:rgb(255,255,0);"));
        label_temp_plat->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_temp_plat, 2, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_temp_raum = new QLabel(gridLayoutWidget);
        label_temp_raum->setObjectName(QStringLiteral("label_temp_raum"));
        label_temp_raum->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color:rgb(255,127,0);"));
        label_temp_raum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_temp_raum, 4, 1, 1, 1);

        label_temp_netz = new QLabel(gridLayoutWidget);
        label_temp_netz->setObjectName(QStringLiteral("label_temp_netz"));
        label_temp_netz->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color:rgb(0,255,0);"));
        label_temp_netz->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_temp_netz, 3, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);
        label_13->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color: rgb(240, 240, 240);"));

        gridLayout->addWidget(label_13, 5, 0, 1, 1);

        label_temp_pi = new QLabel(gridLayoutWidget);
        label_temp_pi->setObjectName(QStringLiteral("label_temp_pi"));
        label_temp_pi->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color:rgb(0,255,0);"));
        label_temp_pi->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_temp_pi, 5, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setStyleSheet(QLatin1String("font: 14pt \"Courier New\";\n"
"color: rgb(240, 240, 240);"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_15, 5, 2, 1, 1);

        pushButton_back = new QPushButton(einstellung);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setGeometry(QRect(320, 400, 71, 70));
        QIcon icon;
        icon.addFile(QStringLiteral(":/bilder/Icons/arrow_left_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_back->setIcon(icon);
        pushButton_back->setIconSize(QSize(50, 50));
        pushButton_back->setFlat(true);
        pushButton_Off = new QPushButton(einstellung);
        pushButton_Off->setObjectName(QStringLiteral("pushButton_Off"));
        pushButton_Off->setGeometry(QRect(10, 400, 70, 70));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/bilder/Icons/shutdown-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Off->setIcon(icon1);
        pushButton_Off->setIconSize(QSize(70, 70));
        pushButton_Off->setFlat(true);

        retranslateUi(einstellung);

        QMetaObject::connectSlotsByName(einstellung);
    } // setupUi

    void retranslateUi(QDialog *einstellung)
    {
        einstellung->setWindowTitle(QApplication::translate("einstellung", "Dialog", 0));
        label->setText(QApplication::translate("einstellung", "System", 0));
        label_5->setText(QApplication::translate("einstellung", "<html><head/><body><p><span style=\" font-weight:600;\">Raum</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("einstellung", "L\303\274fter:", 0));
        label_fan_netz->setText(QApplication::translate("einstellung", "45%", 0));
        label_9->setText(QApplication::translate("einstellung", "Temp.:", 0));
        label_fan_raum->setText(QApplication::translate("einstellung", "20%", 0));
        label_3->setText(QApplication::translate("einstellung", "<html><head/><body><p><span style=\" font-weight:600;\">Platine</span></p></body></html>", 0));
        label_fan_plat->setText(QApplication::translate("einstellung", "66%", 0));
        label_temp_plat->setText(QApplication::translate("einstellung", "35\302\260C", 0));
        label_4->setText(QApplication::translate("einstellung", "<html><head/><body><p><span style=\" font-weight:600;\">Netzteile</span></p></body></html>", 0));
        label_temp_raum->setText(QApplication::translate("einstellung", "27\302\260C", 0));
        label_temp_netz->setText(QApplication::translate("einstellung", "30\302\260C", 0));
        label_13->setText(QApplication::translate("einstellung", "<html><head/><body><p><span style=\" font-weight:600;\">Pi CPU</span></p></body></html>", 0));
        label_temp_pi->setText(QApplication::translate("einstellung", "43.2\302\260C", 0));
        label_15->setText(QApplication::translate("einstellung", "-", 0));
        pushButton_back->setText(QString());
        pushButton_Off->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class einstellung: public Ui_einstellung {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EINSTELLUNG_H
