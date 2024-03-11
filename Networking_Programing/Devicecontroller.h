#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include <QObject>
#include <QTcpSocket>

class DeviceController : public QObject
{
    Q_OBJECT
public:
    explicit DeviceController(QObject *parent = nullptr);
    void connectToDevice(QString ip , int port); // Kết nối tới Server
    void disconnect();
    bool isConnected();
    void send(QString message);
    // Hàm trả về các giá trị Enum tương ứng của các trạng thái kết nối Socket
    QAbstractSocket::SocketState state();


signals:
    /*
      _socket không liên tục phát ra các tín hiệu.
     Các tín hiệu như connected, disconnected, errorOccurred, và stateChanged và readyRead chỉ được phát khi có sự thay đổi trạng thái hoặc xảy ra lỗi.
    */

    // Tín hiệu này được phát khi một kết nối TCP thành công được thiết lập với máy chủ.
    void connected();
    // Tín hiệu này được phát khi kết nối TCP với máy chủ bị ngắt.
    void disconnected();
    // Tín hiệu này được phát khi trạng thái của socket thay đổi.
    void stateChanged(QAbstractSocket::SocketState);
    // Tín hiệu này được phát khi có lỗi xảy ra với socket
    void errorOccurred(QAbstractSocket::SocketError);
    // Tín hiệu này được phát ra khi data được gửi từ Socket về
    void dataReady(QByteArray data);


private slots:
    // Kiểm tra các trạng thái của Socket
    void socket_stateChanged(QAbstractSocket::SocketState state);

    // Đọc dữ liệu từ Sever gửi đến
    void socket_ReadReady();


private:
    // _socket không liên tục phát ra các tín hiệu.
    //Các tín hiệu như connected, disconnected, errorOccurred, và stateChanged và readyRead chỉ được phát khi có sự thay đổi trạng thái hoặc xảy ra lỗi.
    // Ví dụ khi _socket kết nối thành công với Server thì nó tự phát ra Signal connected
    // khi _socket ngắt kết nối  với Server thì nó tự phát ra Signal disconnected
    // khi _socket nhận được dữ liệu từ Server thì nó tự phát ra tín hiệu readyRead ,v.v...
    // _socket phát ra các tín hiệu tương ứng khi có sự thay đổi trạng thái
    QTcpSocket _socket;
    QString _ip;
    int _port;



};

#endif // DEVICECONTROLLER_H
