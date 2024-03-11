#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer> //  Nó được sử dụng để lắng nghe các kết nối đến từ các client
#include <QTcpSocket> // được sử dụng để thiết lập một kết nối TCP và truyền tải dữ liệu qua lại giữa client và server
class MyTCPServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTCPServer(int port, QObject *parent = nullptr);

    // get và set của biến isStarted;
    bool isStarted() const;
    void setIsStarted(bool newIsStarted);
    //
    void sendToAll(QString message);

signals:
    void isServerStarted();
    // Gửi tín hiệu khi có 1 Client mới kết nối đến
    void newClientConneted();
    // Gửi tín hiệu khi có 1 Client ngắt kết nối
    void clientDisconnect();
    // Gửi tín hiệu để đi để đọc dữ liệu từ client gửi đến
    void dataReceived(QByteArray Message);


private slots:
    void on_client_connecting();
    void client_Disconnect();
    void client_DataReady();


private:
    QTcpServer* _server;
    QList<QTcpSocket*> _socketList; // List chứa các client kết nối đến Server
    bool _isStarted;



};

#endif // MYTCPSERVER_H
