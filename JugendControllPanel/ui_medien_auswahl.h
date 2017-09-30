/********************************************************************************
** Form generated from reading UI file 'medien_auswahl.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIEN_AUSWAHL_H
#define UI_MEDIEN_AUSWAHL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Medien_auswahl
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_Audio;
    QPushButton *pushButton_Beamer;
    QPushButton *pushButton_PC;
    QLabel *label_uhr_2;
    QPushButton *pushButton_back;
    QFrame *frame;

    void setupUi(QDialog *Medien_auswahl)
    {
        if (Medien_auswahl->objectName().isEmpty())
            Medien_auswahl->setObjectName(QStringLiteral("Medien_auswahl"));
        Medien_auswahl->resize(399, 480);
        label = new QLabel(Medien_auswahl);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 30, 400, 50));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:rgb(10,10,10);"));
        label->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_2 = new QWidget(Medien_auswahl);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 110, 361, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_Audio = new QPushButton(verticalLayoutWidget_2);
        pushButton_Audio->setObjectName(QStringLiteral("pushButton_Audio"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Audio->sizePolicy().hasHeightForWidth());
        pushButton_Audio->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(14);
        pushButton_Audio->setFont(font1);
        pushButton_Audio->setStyleSheet(QLatin1String("border: 0px solid white;\n"
"background-color:rgba(0,0,0,100);\n"
"color:white;"));
        pushButton_Audio->setFlat(true);

        verticalLayout_2->addWidget(pushButton_Audio);

        pushButton_Beamer = new QPushButton(verticalLayoutWidget_2);
        pushButton_Beamer->setObjectName(QStringLiteral("pushButton_Beamer"));
        sizePolicy.setHeightForWidth(pushButton_Beamer->sizePolicy().hasHeightForWidth());
        pushButton_Beamer->setSizePolicy(sizePolicy);
        pushButton_Beamer->setFont(font1);
        pushButton_Beamer->setStyleSheet(QLatin1String("border: 0px solid white;\n"
"background-color:rgba(0,0,0,100);\n"
"color:white;"));
        pushButton_Beamer->setCheckable(true);
        pushButton_Beamer->setFlat(true);

        verticalLayout_2->addWidget(pushButton_Beamer);

        pushButton_PC = new QPushButton(verticalLayoutWidget_2);
        pushButton_PC->setObjectName(QStringLiteral("pushButton_PC"));
        sizePolicy.setHeightForWidth(pushButton_PC->sizePolicy().hasHeightForWidth());
        pushButton_PC->setSizePolicy(sizePolicy);
        pushButton_PC->setFont(font1);
        pushButton_PC->setStyleSheet(QLatin1String("border: 0px solid white;\n"
"background-color:rgba(0,0,0,100);\n"
"color:white;"));
        pushButton_PC->setCheckable(true);
        pushButton_PC->setFlat(true);

        verticalLayout_2->addWidget(pushButton_PC);

        label_uhr_2 = new QLabel(Medien_auswahl);
        label_uhr_2->setObjectName(QStringLiteral("label_uhr_2"));
        label_uhr_2->setEnabled(false);
        label_uhr_2->setGeometry(QRect(270, 0, 121, 31));
        QFont font2;
        font2.setPointSize(18);
        label_uhr_2->setFont(font2);
        label_uhr_2->setStyleSheet(QStringLiteral("color:black;"));
        label_uhr_2->setTextFormat(Qt::PlainText);
        label_uhr_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_back = new QPushButton(Medien_auswahl);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setGeometry(QRect(10, 410, 60, 60));
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/bilder/Icons/arrow_left_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_back->setIcon(icon);
        pushButton_back->setIconSize(QSize(50, 50));
        pushButton_back->setFlat(true);
        frame = new QFrame(Medien_auswahl);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 399, 480));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/bilder/Icons/back_green_triang.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        label->raise();
        verticalLayoutWidget_2->raise();
        label_uhr_2->raise();
        pushButton_back->raise();

        retranslateUi(Medien_auswahl);

        QMetaObject::connectSlotsByName(Medien_auswahl);
    } // setupUi

    void retranslateUi(QDialog *Medien_auswahl)
    {
        Medien_auswahl->setWindowTitle(QApplication::translate("Medien_auswahl", "Dialog", 0));
        label->setText(QApplication::translate("Medien_auswahl", "Medien", 0));
        pushButton_Audio->setText(QApplication::translate("Medien_auswahl", "Audio", 0));
        pushButton_Beamer->setText(QApplication::translate("Medien_auswahl", "Beamer an", 0));
        pushButton_PC->setText(QApplication::translate("Medien_auswahl", "PC an", 0));
        label_uhr_2->setText(QApplication::translate("Medien_auswahl", "11:05", 0));
        pushButton_back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Medien_auswahl: public Ui_Medien_auswahl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIEN_AUSWAHL_H
