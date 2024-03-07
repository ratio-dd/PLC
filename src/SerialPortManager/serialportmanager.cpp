#include "serialportmanager.h"

SerialPortManager::SerialPortManager(QObject *parent) : QObject(parent) {
    qsp = new QSerialPort(this);
};



void SerialPortManager::checkConnect() {
    bool success = false;

    emit connectionResult(success);
}

void SerialPortManager::setBaudRate(int baudRate) {
    qsp->setBaudRate(baudRate, QSerialPort::AllDirections);
    checkConnect();
}
