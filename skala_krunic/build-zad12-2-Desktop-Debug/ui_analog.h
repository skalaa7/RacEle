/********************************************************************************
** Form generated from reading UI file 'analog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALOG_H
#define UI_ANALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_analog
{
public:
    QDial *dial;
    QSlider *verticalSlider;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;

    void setupUi(QDialog *analog)
    {
        if (analog->objectName().isEmpty())
            analog->setObjectName(QString::fromUtf8("analog"));
        analog->resize(800, 600);
        dial = new QDial(analog);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(70, 50, 241, 281));
        verticalSlider = new QSlider(analog);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(470, 110, 16, 160));
        verticalSlider->setOrientation(Qt::Vertical);
        lcdNumber = new QLCDNumber(analog);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(340, 350, 181, 81));
        label = new QLabel(analog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 390, 121, 22));
        label_2 = new QLabel(analog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 40, 68, 22));
        label_3 = new QLabel(analog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(410, 30, 68, 22));
        label_4 = new QLabel(analog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 290, 41, 22));
        label_5 = new QLabel(analog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(220, 290, 41, 22));
        label_6 = new QLabel(analog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(500, 250, 41, 22));
        label_7 = new QLabel(analog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(500, 220, 41, 22));
        label_8 = new QLabel(analog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(500, 190, 41, 22));
        label_9 = new QLabel(analog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(500, 160, 41, 22));
        label_10 = new QLabel(analog);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(500, 100, 41, 22));
        label_11 = new QLabel(analog);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(500, 130, 41, 22));

        retranslateUi(analog);

        QMetaObject::connectSlotsByName(analog);
    } // setupUi

    void retranslateUi(QDialog *analog)
    {
        analog->setWindowTitle(QCoreApplication::translate("analog", "analog", nullptr));
        label->setText(QCoreApplication::translate("analog", "Temperatura", nullptr));
        label_2->setText(QCoreApplication::translate("analog", "Napon", nullptr));
        label_3->setText(QCoreApplication::translate("analog", "Osvetljaj", nullptr));
        label_4->setText(QCoreApplication::translate("analog", "0V", nullptr));
        label_5->setText(QCoreApplication::translate("analog", "3.3V", nullptr));
        label_6->setText(QCoreApplication::translate("analog", "0", nullptr));
        label_7->setText(QCoreApplication::translate("analog", "20", nullptr));
        label_8->setText(QCoreApplication::translate("analog", "40", nullptr));
        label_9->setText(QCoreApplication::translate("analog", "60", nullptr));
        label_10->setText(QCoreApplication::translate("analog", "100", nullptr));
        label_11->setText(QCoreApplication::translate("analog", "80", nullptr));
    } // retranslateUi

};

namespace Ui {
    class analog: public Ui_analog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALOG_H
