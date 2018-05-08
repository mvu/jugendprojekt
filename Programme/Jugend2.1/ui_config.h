/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_config
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_PCA_Config;
    QPushButton *pushButton_Temperatur;
    QPushButton *pushButton_Einstellung;
    QPushButton *pushButton_LuefterConfig;

    void setupUi(QDialog *config)
    {
        if (config->objectName().isEmpty())
            config->setObjectName(QStringLiteral("config"));
        config->resize(800, 480);
        config->setMinimumSize(QSize(800, 480));
        config->setMaximumSize(QSize(800, 480));
        verticalLayoutWidget = new QWidget(config);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 70, 251, 331));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_PCA_Config = new QPushButton(verticalLayoutWidget);
        pushButton_PCA_Config->setObjectName(QStringLiteral("pushButton_PCA_Config"));

        verticalLayout->addWidget(pushButton_PCA_Config);

        pushButton_Temperatur = new QPushButton(verticalLayoutWidget);
        pushButton_Temperatur->setObjectName(QStringLiteral("pushButton_Temperatur"));

        verticalLayout->addWidget(pushButton_Temperatur);

        pushButton_Einstellung = new QPushButton(verticalLayoutWidget);
        pushButton_Einstellung->setObjectName(QStringLiteral("pushButton_Einstellung"));

        verticalLayout->addWidget(pushButton_Einstellung);

        pushButton_LuefterConfig = new QPushButton(verticalLayoutWidget);
        pushButton_LuefterConfig->setObjectName(QStringLiteral("pushButton_LuefterConfig"));

        verticalLayout->addWidget(pushButton_LuefterConfig);


        retranslateUi(config);

        QMetaObject::connectSlotsByName(config);
    } // setupUi

    void retranslateUi(QDialog *config)
    {
        config->setWindowTitle(QApplication::translate("config", "Config", Q_NULLPTR));
        pushButton_PCA_Config->setText(QApplication::translate("config", "PCA Config HL", Q_NULLPTR));
        pushButton_Temperatur->setText(QApplication::translate("config", "Temperaturen", Q_NULLPTR));
        pushButton_Einstellung->setText(QApplication::translate("config", "Einstellung", Q_NULLPTR));
        pushButton_LuefterConfig->setText(QApplication::translate("config", "L\303\274fter Config", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class config: public Ui_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
