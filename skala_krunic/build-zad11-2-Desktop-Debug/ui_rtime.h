/********************************************************************************
** Form generated from reading UI file 'rtime.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RTIME_H
#define UI_RTIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_RTime
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox;

    void setupUi(QDialog *RTime)
    {
        if (RTime->objectName().isEmpty())
            RTime->setObjectName(QString::fromUtf8("RTime"));
        RTime->resize(800, 600);
        groupBox = new QGroupBox(RTime);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(120, 40, 311, 211));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 111, 22));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 30, 113, 30));
        lineEdit->setMaxLength(9);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 121, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 100, 68, 22));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 150, 91, 30));
        groupBox_2 = new QGroupBox(RTime);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(120, 250, 311, 231));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 110, 68, 22));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(170, 110, 113, 28));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(170, 150, 113, 28));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 60, 131, 28));

        retranslateUi(RTime);

        QMetaObject::connectSlotsByName(RTime);
    } // setupUi

    void retranslateUi(QDialog *RTime)
    {
        RTime->setWindowTitle(QCoreApplication::translate("RTime", "RTime", nullptr));
        groupBox->setTitle(QCoreApplication::translate("RTime", "vreme", nullptr));
        label->setText(QCoreApplication::translate("RTime", "Podesi vreme :", nullptr));
        lineEdit->setText(QCoreApplication::translate("RTime", "hh:mm:ss", nullptr));
        label_2->setText(QCoreApplication::translate("RTime", "Trenutno vreme :", nullptr));
        label_3->setText(QCoreApplication::translate("RTime", "00:00:00", nullptr));
        pushButton->setText(QCoreApplication::translate("RTime", "PushButton", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("RTime", "LCD", nullptr));
        label_4->setText(QCoreApplication::translate("RTime", "Format", nullptr));
        radioButton->setText(QCoreApplication::translate("RTime", "24h", nullptr));
        radioButton_2->setText(QCoreApplication::translate("RTime", "12h", nullptr));
        checkBox->setText(QCoreApplication::translate("RTime", "Invertuj redove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RTime: public Ui_RTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RTIME_H
