#include "mytcpserver.h"

MyTCPServer::MyTCPServer(int port,QObject *parent)
    : QObject{parent}
{
    _server = new QTcpServer(this);
    // Khi một client cố gắng kết nối đến server, QTcpServer sẽ phát ra tín hiệu newConnection
    connect(_server,&QTcpServer::newConnection,this,&MyTCPServer::on_client_connecting);
    // Khởi động server và cho phép nó lắng nghe các kết nối đến từ bất kỳ địa chỉ IP nào (QHostAddress::Any) trên cổng 12345
    // Phương thức listen trả về true nếu server bắt đầu lắng nghe thành công, và false nếu không.
    _isStarted = _server->listen(QHostAddress::Any,12345);
    if(!_isStarted)
    {
        qDebug()<<"Server could not Start";
    }
    else
    {
        qDebug()<<"Server started....";
    }
}

void MyTCPServer::on_client_connecting()
{
    qDebug() << "a client connect to server";
    // Hàm nextPendingConnection() của QTcpServer trả về một con trỏ đến một đối tượng QTcpSocket mới.
    //Đối tượng QTcpSocket này được cấu hình để xử lý kết nối đến từ client.

    /*
        Khi client gửi dữ liệu đến server (ví dụ, thông qua phương thức write của QTcpSocket),
        server có thể đọc dữ liệu đó bằng cách sử dụng phương thức readAll của QTcpSocket
    */

    /*
        Nói chung là Server tạo ra 1 socket liên kết với socket client
        Nếu client gửi dữ liệu bằng write() thì socket được tạo ra sẽ phát tín hiệu readyRead
        Nếu client mất kết nối thì socket được tạo ra sẽ phát tín hiệu disconnected
        Nói chung là có 2 đầu QTCPSocket để tương tác với nhau
    */
    QTcpSocket* socket = _server->nextPendingConnection();
    //
    qDebug() << "Client IP: " << socket->peerAddress().toString();
    qDebug() << "Port IP: " << socket->peerPort();

    // Kết nối các tin hiệu của Socket Client vừa kết nối với Server
    connect(socket,&QTcpSocket::readyRead,this,&MyTCPServer::client_DataReady);
    connect(socket,&QTcpSocket::disconnected,this,&MyTCPServer::client_Disconnect);
    //

    // Thêm các socket client kết nối với Server vào list
    _socketList.append(socket);
    //
    socket->write("Welcom to this Server");
    emit newClientConneted();

}

//
void MyTCPServer::client_Disconnect()
{
    emit clientDisconnect();
}

//
void MyTCPServer::client_DataReady()
{
    // Sử dụng qobject_cast<QTcpSocket*>(sender()) để chuyển đổi đối tượng gửi tín hiệu (sender) sang kiểu QTcpSocket*.
    // Biến sender() trả về đối tượng nào đã phát ra tín hiệu readyRead. Trong trường hợp này, chính là socket của client đã gửi dữ liệu.
    auto socket = qobject_cast<QTcpSocket*>(sender());
    QByteArray data = socket->readAll();
    emit dataReceived(data);
}

// get của biến _isStarted
bool MyTCPServer::isStarted() const
{
    return _isStarted;
}

// set của biến _isStarted
void MyTCPServer::setIsStarted(bool newIsStarted)
{
    _isStarted = newIsStarted;
}

// Hàm gửi tín nhắn từ Server đến tất cả các Socket client trong QList _socketList
void MyTCPServer::sendToAll(QString message)
{
    for(QTcpSocket* socket : _socketList)
    {
        socket->write(message.toUtf8());
    }
}
