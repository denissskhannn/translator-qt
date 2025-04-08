/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *txtInput;
    QPushButton *btnTranslate;
    QLineEdit *txtResult;
    QLabel *label_3;
    QLabel *lblTranslatorUsed;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(720, 381);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 90, 71, 41));
        txtInput = new QLineEdit(centralwidget);
        txtInput->setObjectName("txtInput");
        txtInput->setGeometry(QRect(160, 100, 421, 26));
        btnTranslate = new QPushButton(centralwidget);
        btnTranslate->setObjectName("btnTranslate");
        btnTranslate->setGeometry(QRect(320, 170, 88, 26));
        txtResult = new QLineEdit(centralwidget);
        txtResult->setObjectName("txtResult");
        txtResult->setGeometry(QRect(160, 250, 421, 26));
        txtResult->setReadOnly(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 240, 51, 41));
        lblTranslatorUsed = new QLabel(centralwidget);
        lblTranslatorUsed->setObjectName("lblTranslatorUsed");
        lblTranslatorUsed->setGeometry(QRect(490, 310, 181, 41));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sentence", nullptr));
        btnTranslate->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
        lblTranslatorUsed->setText(QCoreApplication::translate("MainWindow", "Class Used:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
