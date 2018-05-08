/********************************************************************************
** Form generated from reading UI file 'palette.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PALETTE_H
#define UI_PALETTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Palette
{
public:
    QLabel *label;

    void setupUi(QDialog *Palette)
    {
        if (Palette->objectName().isEmpty())
            Palette->setObjectName(QStringLiteral("Palette"));
        Palette->resize(400, 480);
        label = new QLabel(Palette);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 400, 50));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Palette);

        QMetaObject::connectSlotsByName(Palette);
    } // setupUi

    void retranslateUi(QDialog *Palette)
    {
        Palette->setWindowTitle(QApplication::translate("Palette", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Palette", "Paletten", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Palette: public Ui_Palette {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PALETTE_H
