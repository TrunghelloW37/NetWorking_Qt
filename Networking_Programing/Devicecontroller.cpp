#include "Devicecontroller.h"

DeviceController::DeviceController(QObject *parent)
    : QObject{parent}
{
    // Khi các Signal trong QTcpSocket phát ra gọi đến các Signal trong DeviveController
    connect(&_socket,&QTcpSocket::connected,this,&DeviceController::connected);
    connect(&_socket,&QTcpSocket::disconnected,this,&DeviceController::disconnected);
    connect(&_socket,&QTcpSocket::errorOccurred,this,&DeviceController::errorOccurred);
    connect(&_socket,&QTcpSocket::stateChanged,this,&DeviceController::socket_stateChanged);
    // Đọc dữ liệu từ Server gửi về
    connect(&_socket,&QTcpSocket::readyRead,this,&DeviceController::socket_ReadReady);
}

// Hàm kết nối đến Server thông qua ip và Port chỉ định
void DeviceController::connectToDevice(QString ip, int port)
{
    // Nếu _socket đang mở thì kiểm tra
    // + Nếu ip và port lần trước nhập giống lần sau nhập thì return về
    // + Nếu ip và port lần trước và lần sau khác nhau thì đóng _socket lại và mở lại socket nhập lần mới nhất
    if(_socket.isOpen())
    {
        if(ip == _ip && port == _port)
        {
            return;
        }

        _socket.close();
    }

    _ip = ip;
    _port = port;
    // Được sử dụng để mở một kết nối TCP đến máy chủ với địa chỉ IP và cổng cụ thể
    // Khi kết nối thành công thì _socket phát ra tín hiệu connected
    _socket.connectToHost(_ip,_port);
}

void DeviceController::disconnect()
{
    _socket.close();
}

bool DeviceController::isConnected()
{
    // _socket.state() === QAbstractSocket::ConnectedState; --> Socket đang kết nối trả về True
    return _socket.state() == QAbstractSocket::ConnectedState;
}


// Hàm trả về các trạng thái của Socket
QAbstractSocket::SocketState DeviceController::state()
{
    // _socket.state() trong Qt trả về trạng thái hiện tại của socket
    // Bôi đen SocketState nhấn F2 để xem các giá trị trả về của _socket
    return _socket.state();
}

void DeviceController::socket_stateChanged(QAbstractSocket::SocketState state)
{
    // QAbstractSocket::UnconnectedState: Socket không kết nối.
    if(state == QAbstractSocket::UnconnectedState)
    {
        _socket.close();
    }

    emit stateChanged(state);
}

// Đọc data từ Server gửi đến
void DeviceController::socket_ReadReady()
{
    //_socket.readAll() : đọc các dữ liệu từ Server gửi đến
    QByteArray data = _socket.readAll();
    emit dataReady(data);
}

// Hàm gửi tin nhắn sang Serve
void DeviceController::send(QString message)
{
    // chuyển đổi một QString thành một QByteArray biểu diễn chuỗi đó theo định dạng UTF-8
    // sau đó gửi nó qua socket TCP
    _socket.write(message.toUtf8());
}


