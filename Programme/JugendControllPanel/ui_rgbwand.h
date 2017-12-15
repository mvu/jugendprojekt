/********************************************************************************
** Form generated from reading UI file 'rgbwand.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGBWAND_H
#define UI_RGBWAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RgbWand
{
public:
    QLabel *label;
    QPushButton *pushButton_back;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_toggle;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_einst;
    QFrame *frame;

    void setupUi(QDialog *RgbWand)
    {
        if (RgbWand->objectName().isEmpty())
            RgbWand->setObjectName(QStringLiteral("RgbWand"));
        RgbWand->resize(400, 480);
        RgbWand->setStyleSheet(QStringLiteral("border:none;"));
        label = new QLabel(RgbWand);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 30, 400, 50));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:rgb(245,245,245);"));
        label->setAlignment(Qt::AlignCenter);
        pushButton_back = new QPushButton(RgbWand);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setGeometry(QRect(330, 410, 60, 60));
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/bilder/Icons/arrow_left_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_back->setIcon(icon);
        pushButton_back->setIconSize(QSize(50, 50));
        pushButton_back->setFlat(true);
        groupBox = new QGroupBox(RgbWand);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 100, 351, 171));
        groupBox->setStyleSheet(QLatin1String("border: 1px solid white;\n"
"border-radius:10px;"));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 331, 151));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(horizontalLayoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QLatin1String("background-color:rgba(255,255,255,100);\n"
"border:none;"));
        pushButton_toggle = new QPushButton(groupBox_2);
        pushButton_toggle->setObjectName(QStringLiteral("pushButton_toggle"));
        pushButton_toggle->setGeometry(QRect(0, 0, 161, 151));
        QFont font1;
        font1.setPointSize(16);
        pushButton_toggle->setFont(font1);
        pushButton_toggle->setStyleSheet(QLatin1String("border:none;\n"
"background-color:rgba(0,0,0,0);\n"
"color:rgb(0,0,0);"));
        pushButton_toggle->setFlat(true);

        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(horizontalLayoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setStyleSheet(QLatin1String("background-color:rgba(255,255,255,100);\n"
"border:none;"));
        pushButton_einst = new QPushButton(groupBox_3);
        pushButton_einst->setObjectName(QStringLiteral("pushButton_einst"));
        pushButton_einst->setGeometry(QRect(0, 0, 161, 151));
        pushButton_einst->setFont(font1);
        pushButton_einst->setStyleSheet(QLatin1String("border:none;\n"
"background-color:rgba(0,0,0,0);\n"
"color:rgb(0,0,0);"));
        pushButton_einst->setFlat(true);

        horizontalLayout->addWidget(groupBox_3);

        frame = new QFrame(RgbWand);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 400, 480));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/bilder/Icons/back_blue.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        label->raise();
        pushButton_back->raise();
        groupBox->raise();

        retranslateUi(RgbWand);

        QMetaObject::connectSlotsByName(RgbWand);
    } // setupUi

    void retranslateUi(QDialog *RgbWand)
    {
        RgbWand->setWindowTitle(QApplication::translate("RgbWand", "Dialog", 0));
        label->setText(QApplication::translate("RgbWand", "RGB Fenster", 0));
        pushButton_back->setText(QString());
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        pushButton_toggle->setText(QApplication::translate("RgbWand", "An", 0));
        groupBox_3->setTitle(QString());
        pushButton_einst->setText(QApplication::translate("RgbWand", "Farbe\n"
"einstellen", 0));
    } // retranslateUi

};

namespace Ui {
    class RgbWand: public Ui_RgbWand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGBWAND_H
