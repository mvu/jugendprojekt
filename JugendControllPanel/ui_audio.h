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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Audio
{
public:
    QLabel *label;

    void setupUi(QDialog *Audio)
    {
        if (Audio->objectName().isEmpty())
            Audio->setObjectName(QStringLiteral("Audio"));
        Audio->resize(400, 480);
        label = new QLabel(Audio);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 30, 400, 50));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Audio);

        QMetaObject::connectSlotsByName(Audio);
    } // setupUi

    void retranslateUi(QDialog *Audio)
    {
        Audio->setWindowTitle(QApplication::translate("Audio", "Dialog", 0));
        label->setText(QApplication::translate("Audio", "Audio", 0));
    } // retranslateUi

};

namespace Ui {
    class Audio: public Ui_Audio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIO_H
