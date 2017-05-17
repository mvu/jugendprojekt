/********************************************************************************
** Form generated from reading UI file 'rgbtheke.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGBTHEKE_H
#define UI_RGBTHEKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_RgbTheke
{
public:
    QDialogButtonBox *buttonBox;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QSlider *sliderBlau;
    QSlider *sliderGreun;
    QSlider *sliderRot;
    QLabel *label;

    void setupUi(QDialog *RgbTheke)
    {
        if (RgbTheke->objectName().isEmpty())
            RgbTheke->setObjectName(QStringLiteral("RgbTheke"));
        RgbTheke->resize(800, 480);
        RgbTheke->setMaximumSize(QSize(800, 480));
        RgbTheke->setStyleSheet(QLatin1String("#RgbTheke{\n"
"\n"
"background-color:white;\n"
"}"));
        buttonBox = new QDialogButtonBox(RgbTheke);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(420, 420, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalFrame = new QFrame(RgbTheke);
        horizontalFrame->setObjectName(QStringLiteral("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(110, 80, 431, 301));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sliderBlau = new QSlider(horizontalFrame);
        sliderBlau->setObjectName(QStringLiteral("sliderBlau"));
        sliderBlau->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 255);"));
        sliderBlau->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(sliderBlau);

        sliderGreun = new QSlider(horizontalFrame);
        sliderGreun->setObjectName(QStringLiteral("sliderGreun"));
        sliderGreun->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        sliderGreun->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(sliderGreun);

        sliderRot = new QSlider(horizontalFrame);
        sliderRot->setObjectName(QStringLiteral("sliderRot"));
        sliderRot->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        sliderRot->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(sliderRot);

        label = new QLabel(RgbTheke);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 20, 191, 31));
        label->setStyleSheet(QStringLiteral("font: 75 24pt \"MS Shell Dlg 2\";"));

        retranslateUi(RgbTheke);
        QObject::connect(buttonBox, SIGNAL(accepted()), RgbTheke, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RgbTheke, SLOT(reject()));

        QMetaObject::connectSlotsByName(RgbTheke);
    } // setupUi

    void retranslateUi(QDialog *RgbTheke)
    {
        RgbTheke->setWindowTitle(QApplication::translate("RgbTheke", "Dialog", 0));
        label->setText(QApplication::translate("RgbTheke", "RGB Theke", 0));
    } // retranslateUi

};

namespace Ui {
    class RgbTheke: public Ui_RgbTheke {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGBTHEKE_H
