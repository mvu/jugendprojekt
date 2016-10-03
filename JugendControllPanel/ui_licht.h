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

    void setupUi(QDialog *Licht)
    {
        if (Licht->objectName().isEmpty())
            Licht->setObjectName(QStringLiteral("Licht"));
        Licht->resize(800, 480);
        Licht->setMinimumSize(QSize(800, 480));
        Licht->setMaximumSize(QSize(800, 480));
        Licht->setStyleSheet(QStringLiteral(""));
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
        pushButtonJugend->setGeometry(QRect(90, 30, 100, 80));
        sizePolicy.setHeightForWidth(pushButtonJugend->sizePolicy().hasHeightForWidth());
        pushButtonJugend->setSizePolicy(sizePolicy);
        pushButtonJugend->setMinimumSize(QSize(100, 80));
        pushButtonJugend->setMaximumSize(QSize(100, 80));
        pushButtonJugend->setFont(font);
        pushButtonJugend->setCheckable(true);
        pushButtonTeenkreis = new QPushButton(Licht);
        pushButtonTeenkreis->setObjectName(QStringLiteral("pushButtonTeenkreis"));
        pushButtonTeenkreis->setGeometry(QRect(250, 30, 100, 80));
        sizePolicy.setHeightForWidth(pushButtonTeenkreis->sizePolicy().hasHeightForWidth());
        pushButtonTeenkreis->setSizePolicy(sizePolicy);
        pushButtonTeenkreis->setMinimumSize(QSize(100, 80));
        pushButtonTeenkreis->setMaximumSize(QSize(100, 80));
        pushButtonTeenkreis->setFont(font);
        pushButtonTeenkreis->setCheckable(true);
        pushButtonPraisTime = new QPushButton(Licht);
        pushButtonPraisTime->setObjectName(QStringLiteral("pushButtonPraisTime"));
        pushButtonPraisTime->setGeometry(QRect(410, 30, 100, 80));
        sizePolicy.setHeightForWidth(pushButtonPraisTime->sizePolicy().hasHeightForWidth());
        pushButtonPraisTime->setSizePolicy(sizePolicy);
        pushButtonPraisTime->setMinimumSize(QSize(100, 80));
        pushButtonPraisTime->setMaximumSize(QSize(100, 80));
        pushButtonPraisTime->setFont(font);
        pushButtonPraisTime->setCheckable(true);
        pushButtonEinstellung = new QPushButton(Licht);
        pushButtonEinstellung->setObjectName(QStringLiteral("pushButtonEinstellung"));
        pushButtonEinstellung->setGeometry(QRect(80, 390, 150, 80));
        sizePolicy.setHeightForWidth(pushButtonEinstellung->sizePolicy().hasHeightForWidth());
        pushButtonEinstellung->setSizePolicy(sizePolicy);
        pushButtonEinstellung->setMinimumSize(QSize(150, 80));
        pushButtonEinstellung->setMaximumSize(QSize(150, 80));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        pushButtonEinstellung->setFont(font1);
        pushButtonEinstellung->setStyleSheet(QLatin1String("#pushButtonEinstellung{\n"
"color:rgb(51, 61, 148);\n"
"background-color: transparent;\n"
"border-image: url(:/new/bilder/bilder/einstelung.png);\n"
"background: none;\n"
"border: 5px black ;\n"
"border-radius:10px;\n"
"background-repeat: none;\n"
"}"));
        pushButtonMovie = new QPushButton(Licht);
        pushButtonMovie->setObjectName(QStringLiteral("pushButtonMovie"));
        pushButtonMovie->setGeometry(QRect(570, 30, 100, 80));
        sizePolicy.setHeightForWidth(pushButtonMovie->sizePolicy().hasHeightForWidth());
        pushButtonMovie->setSizePolicy(sizePolicy);
        pushButtonMovie->setMinimumSize(QSize(100, 80));
        pushButtonMovie->setMaximumSize(QSize(100, 80));
        pushButtonMovie->setFont(font);
        pushButtonMovie->setCheckable(true);

        retranslateUi(Licht);
        QObject::connect(pushButtonHome, SIGNAL(clicked()), Licht, SLOT(close()));

        QMetaObject::connectSlotsByName(Licht);
    } // setupUi

    void retranslateUi(QDialog *Licht)
    {
        Licht->setWindowTitle(QApplication::translate("Licht", "Dialog", 0));
        pushButtonHome->setText(QApplication::translate("Licht", "Home", 0));
        pushButtonJugend->setText(QApplication::translate("Licht", "Jugend", 0));
        pushButtonTeenkreis->setText(QApplication::translate("Licht", "Teenkreis", 0));
        pushButtonPraisTime->setText(QApplication::translate("Licht", "Prais time", 0));
        pushButtonEinstellung->setText(QApplication::translate("Licht", "Einstellung", 0));
        pushButtonMovie->setText(QApplication::translate("Licht", "Movie", 0));
    } // retranslateUi

};

namespace Ui {
    class Licht: public Ui_Licht {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LICHT_H
