/********************************************************************************
** Form generated from reading UI file 'licht.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LICHT_H
#define UI_LICHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Licht
{
public:
    QPushButton *pushButtonHome;
    QPushButton *pushButtonJugend;
    QPushButton *pushButtonTeenkreis;
    QPushButton *pushButtonPraisTime;
    QPushButton *pushButtonEinstellung;
    QPushButton *pushButtonMovie;
    QPushButton *pushButtonLichtAus;

    void setupUi(QDialog *Licht)
    {
        if (Licht->objectName().isEmpty())
            Licht->setObjectName(QStringLiteral("Licht"));
        Licht->resize(800, 480);
        Licht->setMinimumSize(QSize(800, 480));
        Licht->setMaximumSize(QSize(800, 480));
        Licht->setStyleSheet(QLatin1String("#Licht{\n"
"background-image:url(:/new/bilder/bilder/backgroundlich.png);\n"
"background-color: white;\n"
"widthe: 100px; height:80px;\n"
"width:800px; \n"
"height:480px;\n"
"}"));
        pushButtonHome = new QPushButton(Licht);
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
"border-image:url(:/new/bilder/bilder/home.png) 1;\n"
"border-width: 1px;\n"
"}"));
        pushButtonJugend = new QPushButton(Licht);
        pushButtonJugend->setObjectName(QStringLiteral("pushButtonJugend"));
        pushButtonJugend->setGeometry(QRect(80, 50, 150, 80));
        sizePolicy.setHeightForWidth(pushButtonJugend->sizePolicy().hasHeightForWidth());
        pushButtonJugend->setSizePolicy(sizePolicy);
        pushButtonJugend->setMinimumSize(QSize(100, 80));
        pushButtonJugend->setMaximumSize(QSize(150, 80));
        pushButtonJugend->setFont(font);
        pushButtonJugend->setStyleSheet(QLatin1String("#pushButtonJugend{\n"
"background-color: rgb(255, 226, 0);\n"
"border-radius: 18px;\n"
"\n"
"}"));
        pushButtonJugend->setCheckable(true);
        pushButtonTeenkreis = new QPushButton(Licht);
        pushButtonTeenkreis->setObjectName(QStringLiteral("pushButtonTeenkreis"));
        pushButtonTeenkreis->setGeometry(QRect(80, 170, 150, 80));
        sizePolicy.setHeightForWidth(pushButtonTeenkreis->sizePolicy().hasHeightForWidth());
        pushButtonTeenkreis->setSizePolicy(sizePolicy);
        pushButtonTeenkreis->setMinimumSize(QSize(100, 80));
        pushButtonTeenkreis->setMaximumSize(QSize(150, 80));
        pushButtonTeenkreis->setFont(font);
        pushButtonTeenkreis->setStyleSheet(QLatin1String("#pushButtonTeenkreis{\n"
"background-color:rgb(89, 255, 0);\n"
"border-radius: 18px;\n"
"\n"
"}"));
        pushButtonTeenkreis->setCheckable(true);
        pushButtonPraisTime = new QPushButton(Licht);
        pushButtonPraisTime->setObjectName(QStringLiteral("pushButtonPraisTime"));
        pushButtonPraisTime->setGeometry(QRect(590, 150, 191, 141));
        sizePolicy.setHeightForWidth(pushButtonPraisTime->sizePolicy().hasHeightForWidth());
        pushButtonPraisTime->setSizePolicy(sizePolicy);
        pushButtonPraisTime->setMinimumSize(QSize(100, 80));
        pushButtonPraisTime->setMaximumSize(QSize(1000, 800));
        QFont font1;
        pushButtonPraisTime->setFont(font1);
        pushButtonPraisTime->setStyleSheet(QLatin1String("#pushButtonPraisTime{\n"
"	background-image: url(:/new/bilder/bilder/praisedark.png);\n"
"	background-position: right;\n"
"	border-radius: 18px;\n"
"	color:rgb(255, 255, 127);\n"
"	font-size: 18px;\n"
"	padding: 90px 0px 0px 0px ;\n"
"}\n"
"\n"
"#pushButtonPraisTime:hover{\n"
"	background-image: url(:/new/bilder/bilder/praise.png);\n"
"	font-size: 28px;\n"
"}"));
        pushButtonPraisTime->setCheckable(true);
        pushButtonEinstellung = new QPushButton(Licht);
        pushButtonEinstellung->setObjectName(QStringLiteral("pushButtonEinstellung"));
        pushButtonEinstellung->setGeometry(QRect(80, 390, 150, 80));
        sizePolicy.setHeightForWidth(pushButtonEinstellung->sizePolicy().hasHeightForWidth());
        pushButtonEinstellung->setSizePolicy(sizePolicy);
        pushButtonEinstellung->setMinimumSize(QSize(150, 80));
        pushButtonEinstellung->setMaximumSize(QSize(150, 80));
        pushButtonEinstellung->setFont(font1);
        pushButtonEinstellung->setStyleSheet(QLatin1String("#pushButtonEinstellung{\n"
"background-image:url(:/new/bilder/bilder/einstelung.png);\n"
"height:30px; width: 20px;\n"
"color:rgb(51, 61, 148);\n"
"background-color: transparent;\n"
"border: 5px;\n"
"border-radius:10px;\n"
"background-repeat: none;\n"
"font-size: 22px;\n"
"\n"
"}"));
        pushButtonMovie = new QPushButton(Licht);
        pushButtonMovie->setObjectName(QStringLiteral("pushButtonMovie"));
        pushButtonMovie->setGeometry(QRect(600, 50, 151, 111));
        sizePolicy.setHeightForWidth(pushButtonMovie->sizePolicy().hasHeightForWidth());
        pushButtonMovie->setSizePolicy(sizePolicy);
        pushButtonMovie->setMinimumSize(QSize(100, 80));
        pushButtonMovie->setMaximumSize(QSize(1000, 800));
        pushButtonMovie->setFont(font);
        pushButtonMovie->setStyleSheet(QLatin1String("#pushButtonMovie{\n"
"background-image:url(:/new/bilder/bilder/movieback.png);\n"
"background-position: center;\n"
"background-repeat: none;\n"
"background-color:transparent;\n"
"border-radius: 18px;\n"
"color:white;\n"
"\n"
"\n"
"}\n"
"\n"
"#pushButtonMovie:hover{\n"
"color:rgb(71, 80, 255);\n"
"font-size:36px;\n"
"}"));
        pushButtonMovie->setCheckable(true);
        pushButtonLichtAus = new QPushButton(Licht);
        pushButtonLichtAus->setObjectName(QStringLiteral("pushButtonLichtAus"));
        pushButtonLichtAus->setGeometry(QRect(260, 390, 151, 81));
        QFont font2;
        font2.setFamily(QStringLiteral("MS UI Gothic"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        pushButtonLichtAus->setFont(font2);

        retranslateUi(Licht);
        QObject::connect(pushButtonHome, SIGNAL(clicked()), Licht, SLOT(close()));

        QMetaObject::connectSlotsByName(Licht);
    } // setupUi

    void retranslateUi(QDialog *Licht)
    {
        Licht->setWindowTitle(QApplication::translate("Licht", "Dialog", 0));
        pushButtonHome->setText(QApplication::translate("Licht", "Home", 0));
        pushButtonJugend->setText(QApplication::translate("Licht", "Jugend On", 0));
        pushButtonTeenkreis->setText(QApplication::translate("Licht", "Teenkreis On", 0));
        pushButtonPraisTime->setText(QApplication::translate("Licht", "Praise time", 0));
        pushButtonEinstellung->setText(QApplication::translate("Licht", "Einstellung", 0));
        pushButtonMovie->setText(QApplication::translate("Licht", "Movie", 0));
        pushButtonLichtAus->setText(QApplication::translate("Licht", "Licht AUS", 0));
    } // retranslateUi

};

namespace Ui {
    class Licht: public Ui_Licht {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LICHT_H
