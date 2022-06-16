/********************************************************************************
** Form generated from reading UI file 'fourtoggle.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOURTOGGLE_H
#define UI_FOURTOGGLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fourtoggle
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;

    void setupUi(QDialog *fourtoggle)
    {
        if (fourtoggle->objectName().isEmpty())
            fourtoggle->setObjectName(QString::fromUtf8("fourtoggle"));
        fourtoggle->resize(800, 600);
        widget = new QWidget(fourtoggle);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(260, 70, 93, 140));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setCheckable(true);

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setCheckable(true);

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setCheckable(true);

        verticalLayout->addWidget(pushButton);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setCheckable(true);

        verticalLayout->addWidget(pushButton_4);


        retranslateUi(fourtoggle);

        QMetaObject::connectSlotsByName(fourtoggle);
    } // setupUi

    void retranslateUi(QDialog *fourtoggle)
    {
        fourtoggle->setWindowTitle(QCoreApplication::translate("fourtoggle", "fourtoggle", nullptr));
        pushButton_3->setText(QCoreApplication::translate("fourtoggle", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("fourtoggle", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("fourtoggle", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("fourtoggle", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fourtoggle: public Ui_fourtoggle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOURTOGGLE_H
