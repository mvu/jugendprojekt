/********************************************************************************
** Form generated from reading UI file 'system.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEM_H
#define UI_SYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_System
{
public:
    QLabel *label;
    QGroupBox *groupBox_temp;
    QTabWidget *tabWidget;
    QWidget *tab_raum;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QProgressBar *progressBar;
    QLabel *label_2;
    QFrame *line;
    QGroupBox *groupBox_2;
    QDial *dial;
    QLabel *label_3;
    QWidget *tab_netzteil;
    QWidget *tab_Platine;

    void setupUi(QDialog *System)
    {
        if (System->objectName().isEmpty())
            System->setObjectName(QStringLiteral("System"));
        System->resize(800, 480);
        QFont font;
        font.setPointSize(14);
        System->setFont(font);
        System->setStyleSheet(QStringLiteral("QGroupBox::title {subcontrol-origin: margin; left: 10px; padding: 0 3px 0 3px; } ;"));
        label = new QLabel(System);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 800, 60));
        QFont font1;
        font1.setPointSize(36);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        groupBox_temp = new QGroupBox(System);
        groupBox_temp->setObjectName(QStringLiteral("groupBox_temp"));
        groupBox_temp->setGeometry(QRect(20, 110, 761, 191));
        groupBox_temp->setFocusPolicy(Qt::NoFocus);
        groupBox_temp->setStyleSheet(QLatin1String("border: 1px solid gray;\n"
"border-radius: 9px;\n"
"margin-top: 0.5em;\n"
"font-size: 22px;"));
        groupBox_temp->setFlat(false);
        groupBox_temp->setCheckable(false);
        tabWidget = new QTabWidget(groupBox_temp);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 30, 741, 151));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setStyleSheet(QLatin1String("border:none;\n"
"margin-top: 0;\n"
"font-size:14px;"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(true);
        tab_raum = new QWidget();
        tab_raum->setObjectName(QStringLiteral("tab_raum"));
        horizontalLayoutWidget = new QWidget(tab_raum);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 741, 121));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 5, 0, 0);
        groupBox = new QGroupBox(horizontalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral("font-size: 16px;"));
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(110, 40, 241, 41));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 30, 61, 61));
        QFont font2;
        label_2->setFont(font2);
        label_2->setStyleSheet(QStringLiteral("font-size:30px;"));

        horizontalLayout->addWidget(groupBox);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        groupBox_2 = new QGroupBox(horizontalLayoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QStringLiteral("font-size: 16px;"));
        dial = new QDial(groupBox_2);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(249, 0, 111, 111));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 30, 61, 61));
        label_3->setFont(font2);
        label_3->setStyleSheet(QStringLiteral("font-size:30px;"));

        horizontalLayout->addWidget(groupBox_2);

        tabWidget->addTab(tab_raum, QString());
        tab_netzteil = new QWidget();
        tab_netzteil->setObjectName(QStringLiteral("tab_netzteil"));
        tabWidget->addTab(tab_netzteil, QString());
        tab_Platine = new QWidget();
        tab_Platine->setObjectName(QStringLiteral("tab_Platine"));
        tabWidget->addTab(tab_Platine, QString());

        retranslateUi(System);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(System);
    } // setupUi

    void retranslateUi(QDialog *System)
    {
        System->setWindowTitle(QApplication::translate("System", "Dialog", 0));
        label->setText(QApplication::translate("System", "System", 0));
        groupBox_temp->setTitle(QApplication::translate("System", "Temperatur && L\303\274fter", 0));
        groupBox->setTitle(QApplication::translate("System", "Temperatur", 0));
        label_2->setText(QApplication::translate("System", "32\302\260C", 0));
        groupBox_2->setTitle(QApplication::translate("System", "L\303\274fter", 0));
        label_3->setText(QApplication::translate("System", "25%", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_raum), QApplication::translate("System", "Raum", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_netzteil), QApplication::translate("System", "Netzteile", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Platine), QApplication::translate("System", "Platine", 0));
    } // retranslateUi

};

namespace Ui {
    class System: public Ui_System {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEM_H
