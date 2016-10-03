/********************************************************************************
** Form generated from reading UI file 'einstellunghauptlicht.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EINSTELLUNGHAUPTLICHT_H
#define UI_EINSTELLUNGHAUPTLICHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_EinstellungHauptlicht
{
public:
    QDialogButtonBox *buttonBox;
    QProgressBar *HelligkeitAnzeige;
    QLabel *label;

    void setupUi(QDialog *EinstellungHauptlicht)
    {
        if (EinstellungHauptlicht->objectName().isEmpty())
            EinstellungHauptlicht->setObjectName(QStringLiteral("EinstellungHauptlicht"));
        EinstellungHauptlicht->resize(400, 300);
        EinstellungHauptlicht->setMaximumSize(QSize(400, 300));
        buttonBox = new QDialogButtonBox(EinstellungHauptlicht);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        HelligkeitAnzeige = new QProgressBar(EinstellungHauptlicht);
        HelligkeitAnzeige->setObjectName(QStringLiteral("HelligkeitAnzeige"));
        HelligkeitAnzeige->setGeometry(QRect(70, 130, 261, 61));
        QFont font;
        font.setPointSize(15);
        HelligkeitAnzeige->setFont(font);
        HelligkeitAnzeige->setLayoutDirection(Qt::LeftToRight);
        HelligkeitAnzeige->setValue(0);
        HelligkeitAnzeige->setOrientation(Qt::Horizontal);
        label = new QLabel(EinstellungHauptlicht);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 20, 271, 61));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        retranslateUi(EinstellungHauptlicht);
        QObject::connect(buttonBox, SIGNAL(accepted()), EinstellungHauptlicht, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EinstellungHauptlicht, SLOT(reject()));

        QMetaObject::connectSlotsByName(EinstellungHauptlicht);
    } // setupUi

    void retranslateUi(QDialog *EinstellungHauptlicht)
    {
        EinstellungHauptlicht->setWindowTitle(QApplication::translate("EinstellungHauptlicht", "Dialog", 0));
        label->setText(QApplication::translate("EinstellungHauptlicht", "Hauptlicht Helligkeit", 0));
    } // retranslateUi

};

namespace Ui {
    class EinstellungHauptlicht: public Ui_EinstellungHauptlicht {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EINSTELLUNGHAUPTLICHT_H
