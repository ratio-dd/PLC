#include "serialportmanager.h"

SerialPortManager::SerialPortManager(QObject *parent) : QObject(parent) {
    qsp = new QSerialPort(this);
};



void SerialPortManager::checkConnect() {
    // 设置串行端口的波特率
    // 检查连接...
    bool success = false;

    emit connectionResult(success);
}

void SerialPortManager::connectToWidget(SerialPortWidget *spWidget) {
    connect(spWidget, &SerialPortWidget::baudRateChanged, this, &SerialPortManager::setBaudRate);
}

void SerialPortManager::setBaudRate(int baudRate) {
    qsp->setBaudRate(baudRate, QSerialPort::AllDirections);
}
