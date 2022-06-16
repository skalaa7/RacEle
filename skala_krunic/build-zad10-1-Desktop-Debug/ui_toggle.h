/********************************************************************************
** Form generated from reading UI file 'toggle.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOGGLE_H
#define UI_TOGGLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_toggle
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *toggle)
    {
        if (toggle->objectName().isEmpty())
            toggle->setObjectName(QString::fromUtf8("toggle"));
        toggle->resize(800, 600);
        pushButton = new QPushButton(toggle);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 150, 91, 30));

        retranslateUi(toggle);

        QMetaObject::connectSlotsByName(toggle);
    } // setupUi

    void retranslateUi(QDialog *toggle)
    {
        toggle->setWindowTitle(QCoreApplication::translate("toggle", "toggle", nullptr));
        pushButton->setText(QCoreApplication::translate("toggle", "Toggle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class toggle: public Ui_toggle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOGGLE_H
