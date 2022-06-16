/********************************************************************************
** Form generated from reading UI file 'dimer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIMER_H
#define UI_DIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_dimer
{
public:
    QSlider *horizontalSlider;

    void setupUi(QDialog *dimer)
    {
        if (dimer->objectName().isEmpty())
            dimer->setObjectName(QString::fromUtf8("dimer"));
        dimer->resize(800, 600);
        horizontalSlider = new QSlider(dimer);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(260, 150, 160, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(dimer);

        QMetaObject::connectSlotsByName(dimer);
    } // setupUi

    void retranslateUi(QDialog *dimer)
    {
        dimer->setWindowTitle(QCoreApplication::translate("dimer", "dimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dimer: public Ui_dimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIMER_H
