/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonLight;
    QPushButton *pushButtonAudio;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow{\n"
"border-image;url(:/new/bilder/bilder/crosstimemain.png);\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonLight = new QPushButton(centralWidget);
        pushButtonLight->setObjectName(QStringLiteral("pushButtonLight"));
        pushButtonLight->setGeometry(QRect(166, 140, 250, 120));
        sizePolicy.setHeightForWidth(pushButtonLight->sizePolicy().hasHeightForWidth());
        pushButtonLight->setSizePolicy(sizePolicy);
        pushButtonLight->setMinimumSize(QSize(250, 120));
        pushButtonLight->setMaximumSize(QSize(250, 120));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(30);
        pushButtonLight->setFont(font);
        pushButtonLight->setStyleSheet(QLatin1String("#pushButtonLight{\n"
"color:rgb(255, 255, 0);\n"
"}"));
        pushButtonLight->setIconSize(QSize(16, 16));
        pushButtonAudio = new QPushButton(centralWidget);
        pushButtonAudio->setObjectName(QStringLiteral("pushButtonAudio"));
        pushButtonAudio->setGeometry(QRect(483, 140, 150, 120));
        sizePolicy.setHeightForWidth(pushButtonAudio->sizePolicy().hasHeightForWidth());
        pushButtonAudio->setSizePolicy(sizePolicy);
        pushButtonAudio->setMinimumSize(QSize(150, 120));
        pushButtonAudio->setMaximumSize(QSize(150, 120));
        pushButtonAudio->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButtonLight->setText(QApplication::translate("MainWindow", "Licht", 0));
        pushButtonAudio->setText(QApplication::translate("MainWindow", "Audio", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
