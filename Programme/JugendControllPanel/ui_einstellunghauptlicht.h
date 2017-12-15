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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EinstellungHauptlicht
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_alle;
    QPushButton *pushButton_Group1;
    QPushButton *pushButton_Group2;
    QLabel *label_2;
    QPushButton *pushButton_back;
    QFrame *frame;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_1;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QFrame *frame_2;
    QSlider *horizontalSlider;
    QPushButton *pushButton_AnAus;

    void setupUi(QDialog *EinstellungHauptlicht)
    {
        if (EinstellungHauptlicht->objectName().isEmpty())
            EinstellungHauptlicht->setObjectName(QStringLiteral("EinstellungHauptlicht"));
        EinstellungHauptlicht->resize(800, 480);
        EinstellungHauptlicht->setMaximumSize(QSize(800, 480));
        EinstellungHauptlicht->setStyleSheet(QStringLiteral(""));
        label = new QLabel(EinstellungHauptlicht);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 341, 50));
        QFont font;
        font.setPointSize(36);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color:rgb(250,250,250);"));
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(EinstellungHauptlicht);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(709, 160, 91, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_alle = new QPushButton(verticalLayoutWidget);
        pushButton_alle->setObjectName(QStringLiteral("pushButton_alle"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_alle->sizePolicy().hasHeightForWidth());
        pushButton_alle->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(14);
        pushButton_alle->setFont(font1);
        pushButton_alle->setFocusPolicy(Qt::NoFocus);
        pushButton_alle->setStyleSheet(QLatin1String("border:none;\n"
"background-color:rgba(0,0,0,100);\n"
"color:rgb(250,250,250);"));
        pushButton_alle->setCheckable(true);

        verticalLayout->addWidget(pushButton_alle);

        pushButton_Group1 = new QPushButton(verticalLayoutWidget);
        pushButton_Group1->setObjectName(QStringLiteral("pushButton_Group1"));
        sizePolicy.setHeightForWidth(pushButton_Group1->sizePolicy().hasHeightForWidth());
        pushButton_Group1->setSizePolicy(sizePolicy);
        pushButton_Group1->setFont(font1);
        pushButton_Group1->setFocusPolicy(Qt::NoFocus);
        pushButton_Group1->setStyleSheet(QLatin1String("border:none;\n"
"background-color:rgba(0,0,0,100);\n"
"color:rgb(250,250,250);"));
        pushButton_Group1->setCheckable(true);

        verticalLayout->addWidget(pushButton_Group1);

        pushButton_Group2 = new QPushButton(verticalLayoutWidget);
        pushButton_Group2->setObjectName(QStringLiteral("pushButton_Group2"));
        sizePolicy.setHeightForWidth(pushButton_Group2->sizePolicy().hasHeightForWidth());
        pushButton_Group2->setSizePolicy(sizePolicy);
        pushButton_Group2->setFont(font1);
        pushButton_Group2->setFocusPolicy(Qt::NoFocus);
        pushButton_Group2->setStyleSheet(QLatin1String("border:none;\n"
"background-color:rgba(0,0,0,100);\n"
"color:rgb(250,250,250);"));
        pushButton_Group2->setCheckable(true);

        verticalLayout->addWidget(pushButton_Group2);

        label_2 = new QLabel(EinstellungHauptlicht);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(690, 126, 81, 21));
        label_2->setFont(font1);
        pushButton_back = new QPushButton(EinstellungHauptlicht);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setGeometry(QRect(730, 410, 60, 60));
        pushButton_back->setFocusPolicy(Qt::NoFocus);
        pushButton_back->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/bilder/Icons/arrow_left_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_back->setIcon(icon);
        pushButton_back->setIconSize(QSize(50, 50));
        pushButton_back->setFlat(true);
        frame = new QFrame(EinstellungHauptlicht);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 100, 680, 380));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/bilder/Icons/back_grundriss.png);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        gridLayoutWidget = new QWidget(EinstellungHauptlicht);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 130, 621, 321));
        sizePolicy.setHeightForWidth(gridLayoutWidget->sizePolicy().hasHeightForWidth());
        gridLayoutWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(8);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        pushButton_2->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;\n"
"background-color:rgba(0,0,0,80);"));
        pushButton_2->setCheckable(true);
        pushButton_2->setFlat(true);

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_4->setFocusPolicy(Qt::NoFocus);
        pushButton_4->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;\n"
"background-color:rgba(0,0,0,80);"));
        pushButton_4->setCheckable(true);
        pushButton_4->setFlat(true);

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_1 = new QPushButton(gridLayoutWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);
        pushButton_1->setFocusPolicy(Qt::NoFocus);
        pushButton_1->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;\n"
"background-color:rgba(0,0,0,80);"));
        pushButton_1->setCheckable(true);
        pushButton_1->setFlat(true);

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setFocusPolicy(Qt::NoFocus);
        pushButton_5->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;\n"
"background-color:rgba(0,0,0,80);"));
        pushButton_5->setCheckable(true);
        pushButton_5->setFlat(true);

        gridLayout->addWidget(pushButton_5, 4, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFocusPolicy(Qt::NoFocus);
        pushButton_3->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;\n"
"background-color:rgba(0,0,0,80);"));
        pushButton_3->setCheckable(true);
        pushButton_3->setFlat(true);

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFocusPolicy(Qt::NoFocus);
        pushButton_6->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;\n"
"background-color:rgba(0,0,0,80);"));
        pushButton_6->setCheckable(true);
        pushButton_6->setFlat(true);

        gridLayout->addWidget(pushButton_6, 0, 1, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setFocusPolicy(Qt::NoFocus);
        pushButton_7->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;\n"
"background-color:rgba(0,0,0,80);"));
        pushButton_7->setCheckable(true);
        pushButton_7->setFlat(true);

        gridLayout->addWidget(pushButton_7, 1, 1, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setFocusPolicy(Qt::NoFocus);
        pushButton_8->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;\n"
"background-color:rgba(0,0,0,80);"));
        pushButton_8->setCheckable(true);
        pushButton_8->setFlat(true);

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setFocusPolicy(Qt::NoFocus);
        pushButton_9->setStyleSheet(QLatin1String("border: 2px solid black;\n"
"border-radius: 10px;\n"
"background-color:rgba(0,0,0,80);"));
        pushButton_9->setCheckable(true);
        pushButton_9->setFlat(true);

        gridLayout->addWidget(pushButton_9, 3, 1, 1, 1);

        frame_2 = new QFrame(EinstellungHauptlicht);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 800, 480));
        frame_2->setStyleSheet(QStringLiteral("background-image: url(:/bilder/Icons/back_dark.png);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalSlider = new QSlider(frame_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(380, 20, 406, 61));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setPageStep(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton_AnAus = new QPushButton(EinstellungHauptlicht);
        pushButton_AnAus->setObjectName(QStringLiteral("pushButton_AnAus"));
        pushButton_AnAus->setGeometry(QRect(710, 340, 89, 40));
        sizePolicy.setHeightForWidth(pushButton_AnAus->sizePolicy().hasHeightForWidth());
        pushButton_AnAus->setSizePolicy(sizePolicy);
        pushButton_AnAus->setFont(font1);
        pushButton_AnAus->setFocusPolicy(Qt::NoFocus);
        pushButton_AnAus->setStyleSheet(QLatin1String("border:none;\n"
"background-color:rgba(0,0,0,100);\n"
"color:rgb(250,250,250);"));
        pushButton_AnAus->setCheckable(true);
        frame_2->raise();
        frame->raise();
        label->raise();
        verticalLayoutWidget->raise();
        label_2->raise();
        pushButton_back->raise();
        gridLayoutWidget->raise();
        pushButton_AnAus->raise();

        retranslateUi(EinstellungHauptlicht);

        QMetaObject::connectSlotsByName(EinstellungHauptlicht);
    } // setupUi

    void retranslateUi(QDialog *EinstellungHauptlicht)
    {
        EinstellungHauptlicht->setWindowTitle(QApplication::translate("EinstellungHauptlicht", "Dialog", 0));
        label->setText(QApplication::translate("EinstellungHauptlicht", "Hauptlicht", 0));
        pushButton_alle->setText(QApplication::translate("EinstellungHauptlicht", "Alle", 0));
        pushButton_Group1->setText(QApplication::translate("EinstellungHauptlicht", "1", 0));
        pushButton_Group2->setText(QApplication::translate("EinstellungHauptlicht", "2", 0));
        label_2->setText(QApplication::translate("EinstellungHauptlicht", "Gruppen", 0));
        pushButton_back->setText(QString());
        pushButton_2->setText(QString());
        pushButton_4->setText(QString());
        pushButton_1->setText(QString());
        pushButton_5->setText(QString());
        pushButton_3->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_AnAus->setText(QApplication::translate("EinstellungHauptlicht", "An", 0));
    } // retranslateUi

};

namespace Ui {
    class EinstellungHauptlicht: public Ui_EinstellungHauptlicht {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EINSTELLUNGHAUPTLICHT_H
