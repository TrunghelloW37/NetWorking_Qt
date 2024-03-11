#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytcpserver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _server = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonStartServer_clicked()
{
    if(_server == nullptr)
    {
        auto port = ui->spinPort->value();
        // Khởi Tạo Server có giá trị Port
        _server = new MyTCPServer(port);
        connect(_server,&MyTCPServer::newClientConneted, this,&MainWindow::newClient_Connected);
        connect(_server,&MyTCPServer::clientDisconnect, this,&MainWindow::client_Disconnected);
        connect(_server,&MyTCPServer::dataReceived, this,&MainWindow::client_DataReceived);
    }
}

void MainWindow::newClient_Connected()
{
    ui->listConsole->addItem(QString("New Client connected"));
}

void MainWindow::client_Disconnected()
{
    ui->listConsole->addItem("Client Disconnected");
}

void MainWindow::client_DataReceived(QByteArray message)
{
    ui->listConsole->addItem(QString(message));
}


void MainWindow::on_buttonClear_clicked()
{
    ui->listConsole->clear();
}


void MainWindow::on_buttonSendToAll_clicked()
{
    auto message = ui->lineMessageSend->text().trimmed();
    _server->sendToAll(message);
}

