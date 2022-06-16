/********************************************************************************
** Form generated from reading UI file 'qmessagebox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMESSAGEBOX_H
#define UI_QMESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMessageBox
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *QMessageBox)
    {
        if (QMessageBox->objectName().isEmpty())
            QMessageBox->setObjectName(QString::fromUtf8("QMessageBox"));
        QMessageBox->resize(800, 600);
        pushButton = new QPushButton(QMessageBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 280, 91, 30));
        label = new QLabel(QMessageBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 180, 68, 50));
        label_2 = new QLabel(QMessageBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 230, 68, 22));
        widget = new QWidget(QMessageBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(330, 190, 144, 68));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(16);

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMaxLength(16);

        verticalLayout->addWidget(lineEdit_2);


        retranslateUi(QMessageBox);

        QMetaObject::connectSlotsByName(QMessageBox);
    } // setupUi

    void retranslateUi(QDialog *QMessageBox)
    {
        QMessageBox->setWindowTitle(QCoreApplication::translate("QMessageBox", "QMessageBox", nullptr));
        pushButton->setText(QCoreApplication::translate("QMessageBox", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("QMessageBox", "Red1:", nullptr));
        label_2->setText(QCoreApplication::translate("QMessageBox", "Red2:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QMessageBox: public Ui_QMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMESSAGEBOX_H
