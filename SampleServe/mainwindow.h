#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"mytcpserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonStartServer_clicked();
    void on_buttonClear_clicked();
    void on_buttonSendToAll_clicked();
    //
    void newClient_Connected();
    void client_Disconnected();
    void client_DataReceived(QByteArray message);



private:
    Ui::MainWindow *ui;
    MyTCPServer* _server;
};
#endif // MAINWINDOW_H
