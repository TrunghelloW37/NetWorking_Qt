#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
#include <QStyle>
#include <QDebug>
#include <QMetaEnum>
#include <QTcpSocket>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setDeviceController();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDeviceController()
{
    // Các tín hiệu trạng thái của Socket gửi đến
    connect(&_controller,&DeviceController::connected,this,&MainWindow::device_connected);
    connect(&_controller,&DeviceController::disconnected,this,&MainWindow::device_disconnected);
    connect(&_controller,&DeviceController::stateChanged,this,&MainWindow::device_stateChanged);
    connect(&_controller,&DeviceController::errorOccurred,this,&MainWindow::device_errorOccurred);
    // Nhận và in  dữ liệu được gửi đến lên ListWidget
    connect(&_controller,&DeviceController::dataReady,this,&MainWindow::device_dataReady);
}


// Khi giá trị nhập Ip thay đổi gọi gọi phương thức này - Signal (textChange - LineEdit)
void MainWindow::on_lineIpAddress_textChanged(const QString &arg1)
{
    QString  state = "0";
    if(arg1 == "...")
    {
        state = "";
    }
    else
    {
        // QHostAddress là một lớp trong Qt được sử dụng để lưu trữ địa chỉ IP
        QHostAddress address(arg1);
        // Kiểm tra xem địa chỉ IP nhập vào có phải là địa chỉ IPv4 hay không ??
        // QAbstractSocket::IPv4Protocol là một hằng số trong lớp QAbstractSocket của Qt, biểu diễn cho giao thức IPv4
        // address.protocol() là phương thức của lớp QHostAddress, trả về giao thức mà địa chỉ IP đang sử dụng. ( IPv4 hoặc IPv6)
        // Nếu địa chỉ IP nhập vào sử dụng giao thức IPv4, thì biểu thức này sẽ trả về true
        if(QAbstractSocket::IPv4Protocol == address.protocol())
        {
            state = "1"; // Cập nhật lại State
        }
    }

    // setProperty : đặt thuộc tính
    ui->lineIpAddress->setProperty("state",state);
    // cập nhật lại giao diện của ui->lineIpAddress để phản ánh các thay đổi vừa được thực hiện.
    style()->polish(ui->lineIpAddress);

}

// Button kết nối , ngắt kết nối
void MainWindow::on_buttonConnect_clicked()
{
    // Kiểm tra xem nếu Socket đã kết nối thì clicked vào button thì nó ngắt kết nối và ngược lại
    // Nếu chưa kết nối thì nó sẽ kết nối
    if(_controller.isConnected())
    {
        _controller.disconnect();
    }
    else
    {
        auto ip = ui->lineIpAddress->text();
        auto port = ui->spinPort->value();
        _controller.connectToDevice(ip,port);
    }

}

// Khi kết nối thành công đến Server thì in lên ListWidget
void MainWindow::device_connected()
{
    ui->listConsole->addItem("Connect to Device");
    ui->buttonConnect->setText("Disconnect");
    // Khi kết nối thành công đến Server thì mới hiện thị Bảng Send Data
    ui->groupSend_Data->setEnabled(true);

}

// Khi ngắt kết nối Server thì in lên ListWidget
void MainWindow::device_disconnected()
{
    ui->listConsole->addItem("Disconnect From Device");
    ui->buttonConnect->setText("Connect");
    // Khi ngắt kết nối đến Server thì ẩn bảng hiện thị Send Data
    ui->groupSend_Data->setEnabled(false);
}

// Khi trạng thái của socket thay đổi thì in lên ListWidget các giá trị Enum QAbstractSocket::SocketState tương ứng
void MainWindow::device_stateChanged(QAbstractSocket::SocketState state)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    ui->listConsole->addItem(metaEnum.valueToKey(state));
}

// Khi trạng thái của socket bị lỗi thì in lên ListWidget các giá trị Enum QAbstractSocket::SocketError tương ứng
void MainWindow::device_errorOccurred(QAbstractSocket::SocketError error)// Bôi đen SocketError nhấn F2
{
    //  Dòng này tạo một đối tượng QMetaEnum từ kiểu QAbstractSocket::SocketState.
    // QMetaEnum là một lớp trong thư viện Qt được sử dụng để biểu diễn thông tin về một kiểu liệt kê (enum).
    // Phương thức này trả về một đối tượng QMetaEnum biểu diễn thông tin về kiểu liệt kê (enum)
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();

    //valueToKey là phương thức chuyển đổi một giá trị số (ở đây là state) thành chuỗi tương ứng
    // Ví dụ, nếu state là QAbstractSocket::ConnectedState (có giá trị là 3), thì metaEnum.valueToKey(state) sẽ trả về chuỗi "ConnectedState"
    ui->listConsole->addItem(metaEnum.valueToKey(error));
}

// In dữ liệu đọc từ Server lên ListWidget
void MainWindow::device_dataReady(QByteArray data)
{
    ui->listConsole->addItem(QString(data));
}

// Làm sạch Widget
void MainWindow::on_buttonClearList_clicked()
{
    ui->listConsole->clear();
}

// Hàm gửi tín nhắn sang Server
void MainWindow::on_buttonSend_Date_clicked()
{
    QString message = ui->lineSendMessage->text().trimmed();
    _controller.send(message);
}

