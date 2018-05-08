/********************************************************************************
** Form generated from reading UI file 'theke.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEKE_H
#define UI_THEKE_H

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

class Ui_Theke
{
public:
    QLabel *label;
    QFrame *frame;
    QPushButton *pushButton_back;
    QGroupBox *groupBox_RGB;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QPushButton *pushButton_rgb_togge;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_rgb_set;
    QGroupBox *groupBox_lampen;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_3;
    QPushButton *pushButton;

    void setupUi(QDialog *Theke)
    {
        if (Theke->objectName().isEmpty())
            Theke->setObjectName(QStringLiteral("Theke"));
        Theke->resize(400, 480);
        Theke->setMaximumSize(QSize(800, 530));
        Theke->setStyleSheet(QStringLiteral("QGroupBox::title{subcontrol-origin:margin; left:10px; padding: 0 3px 0 3px;color:rgb(10,10,10);}"));
        label = new QLabel(Theke);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 400, 50));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:rgb(10,10,10);"));
        label->setAlignment(Qt::AlignCenter);
        frame = new QFrame(Theke);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 560, 541));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/bilder/Icons/back_green.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton_back = new QPushButton(frame);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setGeometry(QRect(320, 410, 60, 60));
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/bilder/Icons/arrow_left_icon_blk.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_back->setIcon(icon);
        pushButton_back->setIconSize(QSize(50, 50));
        pushButton_back->setFlat(true);
        groupBox_RGB = new QGroupBox(Theke);
        groupBox_RGB->setObjectName(QStringLiteral("groupBox_RGB"));
        groupBox_RGB->setGeometry(QRect(30, 81, 339, 175));
        groupBox_RGB->setStyleSheet(QLatin1String("margin-top:0.5em;\n"
"border:1px solid black;\n"
"border-radius:10px;\n"
"font-size:20px;"));
        horizontalLayoutWidget_2 = new QWidget(groupBox_RGB);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 30, 321, 131));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(horizontalLayoutWidget_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QLatin1String(";margin-top:0;\n"
"border:none;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_rgb_togge = new QPushButton(groupBox);
        pushButton_rgb_togge->setObjectName(QStringLiteral("pushButton_rgb_togge"));
        pushButton_rgb_togge->setGeometry(QRect(10, 10, 131, 111));
        pushButton_rgb_togge->setFocusPolicy(Qt::NoFocus);
        pushButton_rgb_togge->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,0);\n"
"border:none;\n"
"color:rgb(255,255,255);"));
        pushButton_rgb_togge->setFlat(true);

        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(horizontalLayoutWidget_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QLatin1String(";margin-top:0;\n"
"border:none;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton_rgb_set = new QPushButton(groupBox_2);
        pushButton_rgb_set->setObjectName(QStringLiteral("pushButton_rgb_set"));
        pushButton_rgb_set->setGeometry(QRect(10, 10, 131, 111));
        pushButton_rgb_set->setFocusPolicy(Qt::NoFocus);
        pushButton_rgb_set->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,0);\n"
"border:none;\n"
"color:rgb(255,255,255);"));
        pushButton_rgb_set->setFlat(true);

        horizontalLayout_2->addWidget(groupBox_2);

        groupBox_lampen = new QGroupBox(Theke);
        groupBox_lampen->setObjectName(QStringLiteral("groupBox_lampen"));
        groupBox_lampen->setGeometry(QRect(30, 276, 181, 174));
        groupBox_lampen->setStyleSheet(QLatin1String("margin-top:0.5em;\n"
"border:1px solid black;\n"
"border-radius:10px;\n"
"font-size:20px;"));
        horizontalLayoutWidget_3 = new QWidget(groupBox_lampen);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 30, 161, 131));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(horizontalLayoutWidget_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setStyleSheet(QLatin1String(";margin-top:0;\n"
"border:none;\n"
"background-color:rgba(0,0,0,100);"));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 131, 111));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,0);\n"
"border:none;\n"
"color:rgb(255,255,255);"));
        pushButton->setFlat(true);

        horizontalLayout_3->addWidget(groupBox_3);

        frame->raise();
        label->raise();
        groupBox_RGB->raise();
        groupBox_lampen->raise();

        retranslateUi(Theke);

        QMetaObject::connectSlotsByName(Theke);
    } // setupUi

    void retranslateUi(QDialog *Theke)
    {
        Theke->setWindowTitle(QApplication::translate("Theke", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Theke", "Theke Licht", Q_NULLPTR));
        pushButton_back->setText(QString());
        groupBox_RGB->setTitle(QApplication::translate("Theke", "RGB", Q_NULLPTR));
        groupBox->setTitle(QString());
        pushButton_rgb_togge->setText(QApplication::translate("Theke", "An", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        pushButton_rgb_set->setText(QApplication::translate("Theke", "Farbe\n"
"einstellen", Q_NULLPTR));
        groupBox_lampen->setTitle(QApplication::translate("Theke", "Deckenlampen", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        pushButton->setText(QApplication::translate("Theke", "An", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Theke: public Ui_Theke {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEKE_H
