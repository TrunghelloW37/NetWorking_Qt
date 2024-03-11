/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *spinPort;
    QLabel *label;
    QPushButton *buttonConnect;
    QLineEdit *lineIpAddress;
    QPushButton *buttonClearList;
    QGroupBox *groupSend_Data;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *lineSendMessage;
    QPushButton *buttonSend_Date;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *listConsole;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(892, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("#lineIpAddress[state =\"0\"]{\n"
"	background-color : rgb(234,0,0);\n"
"}\n"
"\n"
"#lineIpAddress[state =\"1\"]{\n"
"	background-color: rgb(104, 197, 27);\n"
"}\n"
"\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 40, 401, 161));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinPort = new QSpinBox(groupBox);
        spinPort->setObjectName(QString::fromUtf8("spinPort"));
        spinPort->setMinimum(12345);
        spinPort->setMaximum(65534);

        gridLayout->addWidget(spinPort, 1, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonConnect = new QPushButton(groupBox);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));

        gridLayout->addWidget(buttonConnect, 2, 1, 1, 1);

        lineIpAddress = new QLineEdit(groupBox);
        lineIpAddress->setObjectName(QString::fromUtf8("lineIpAddress"));
        lineIpAddress->setClearButtonEnabled(true);

        gridLayout->addWidget(lineIpAddress, 0, 1, 1, 1);

        buttonClearList = new QPushButton(groupBox);
        buttonClearList->setObjectName(QString::fromUtf8("buttonClearList"));

        gridLayout->addWidget(buttonClearList, 3, 1, 1, 1);

        groupSend_Data = new QGroupBox(centralwidget);
        groupSend_Data->setObjectName(QString::fromUtf8("groupSend_Data"));
        groupSend_Data->setEnabled(false);
        groupSend_Data->setGeometry(QRect(20, 230, 401, 161));
        gridLayout_2 = new QGridLayout(groupSend_Data);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupSend_Data);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label_3->setFont(font);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        lineSendMessage = new QLineEdit(groupSend_Data);
        lineSendMessage->setObjectName(QString::fromUtf8("lineSendMessage"));

        gridLayout_2->addWidget(lineSendMessage, 0, 1, 1, 1);

        buttonSend_Date = new QPushButton(groupSend_Data);
        buttonSend_Date->setObjectName(QString::fromUtf8("buttonSend_Date"));

        gridLayout_2->addWidget(buttonSend_Date, 1, 0, 1, 2);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(470, 10, 411, 511));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listConsole = new QListWidget(widget);
        listConsole->setObjectName(QString::fromUtf8("listConsole"));

        verticalLayout->addWidget(listConsole);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 892, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        MainWindow->setProperty("state", QVariant(QString()));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Connect Infomation", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Ip Address", nullptr));
        buttonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        lineIpAddress->setInputMask(QCoreApplication::translate("MainWindow", "000.000.000.000;_", nullptr));
        lineIpAddress->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        lineIpAddress->setProperty("state", QVariant(QCoreApplication::translate("MainWindow", "0", nullptr)));
        buttonClearList->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        groupSend_Data->setTitle(QCoreApplication::translate("MainWindow", "Send Data", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Message", nullptr));
        buttonSend_Date->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
