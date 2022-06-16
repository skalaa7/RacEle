/********************************************************************************
** Form generated from reading UI file 'temp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMP_H
#define UI_TEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>

QT_BEGIN_NAMESPACE

class Ui_temp
{
public:
    QLCDNumber *lcdNumber;

    void setupUi(QDialog *temp)
    {
        if (temp->objectName().isEmpty())
            temp->setObjectName(QString::fromUtf8("temp"));
        temp->resize(800, 600);
        lcdNumber = new QLCDNumber(temp);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(310, 150, 231, 131));

        retranslateUi(temp);

        QMetaObject::connectSlotsByName(temp);
    } // setupUi

    void retranslateUi(QDialog *temp)
    {
        temp->setWindowTitle(QCoreApplication::translate("temp", "temp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class temp: public Ui_temp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMP_H
