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
#include <QtWidgets/QFormLayout>
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
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinPort;
    QPushButton *buttonStartServer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineMessageSend;
    QPushButton *buttonSendToAll;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *listConsole;
    QPushButton *buttonClear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(955, 475);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 441, 115));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinPort = new QSpinBox(groupBox);
        spinPort->setObjectName(QString::fromUtf8("spinPort"));
        QFont font;
        font.setPointSize(13);
        spinPort->setFont(font);
        spinPort->setMinimum(12345);
        spinPort->setMaximum(65535);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinPort);

        buttonStartServer = new QPushButton(groupBox);
        buttonStartServer->setObjectName(QString::fromUtf8("buttonStartServer"));

        formLayout->setWidget(1, QFormLayout::FieldRole, buttonStartServer);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 160, 441, 141));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(11);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineMessageSend = new QLineEdit(groupBox_2);
        lineMessageSend->setObjectName(QString::fromUtf8("lineMessageSend"));

        gridLayout->addWidget(lineMessageSend, 0, 1, 1, 1);

        buttonSendToAll = new QPushButton(groupBox_2);
        buttonSendToAll->setObjectName(QString::fromUtf8("buttonSendToAll"));

        gridLayout->addWidget(buttonSendToAll, 1, 1, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(510, 10, 431, 401));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listConsole = new QListWidget(widget);
        listConsole->setObjectName(QString::fromUtf8("listConsole"));

        verticalLayout->addWidget(listConsole);

        buttonClear = new QPushButton(widget);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));

        verticalLayout->addWidget(buttonClear);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 955, 26));
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
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Server information", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "PORT", nullptr));
        buttonStartServer->setText(QCoreApplication::translate("MainWindow", "Start Server", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Send_Data", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Message", nullptr));
        buttonSendToAll->setText(QCoreApplication::translate("MainWindow", "Send To All", nullptr));
        buttonClear->setText(QCoreApplication::translate("MainWindow", "Clean", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
