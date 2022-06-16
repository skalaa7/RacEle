/********************************************************************************
** Form generated from reading UI file 'picture.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTURE_H
#define UI_PICTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_picture
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *picture)
    {
        if (picture->objectName().isEmpty())
            picture->setObjectName(QString::fromUtf8("picture"));
        picture->resize(800, 600);
        pushButton = new QPushButton(picture);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(370, 530, 91, 30));
        pushButton->setCheckable(true);
        label = new QLabel(picture);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, -30, 471, 551));

        retranslateUi(picture);

        QMetaObject::connectSlotsByName(picture);
    } // setupUi

    void retranslateUi(QDialog *picture)
    {
        picture->setWindowTitle(QCoreApplication::translate("picture", "picture", nullptr));
        pushButton->setText(QCoreApplication::translate("picture", "PushButton", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class picture: public Ui_picture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTURE_H
