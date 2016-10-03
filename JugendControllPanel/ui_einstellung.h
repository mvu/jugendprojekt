/********************************************************************************
** Form generated from reading UI file 'einstellung.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EINSTELLUNG_H
#define UI_EINSTELLUNG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_einstellung
{
public:

    void setupUi(QDialog *einstellung)
    {
        if (einstellung->objectName().isEmpty())
            einstellung->setObjectName(QStringLiteral("einstellung"));
        einstellung->resize(400, 300);

        retranslateUi(einstellung);

        QMetaObject::connectSlotsByName(einstellung);
    } // setupUi

    void retranslateUi(QDialog *einstellung)
    {
        einstellung->setWindowTitle(QApplication::translate("einstellung", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class einstellung: public Ui_einstellung {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EINSTELLUNG_H
