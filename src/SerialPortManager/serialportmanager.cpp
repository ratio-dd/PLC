#include "serialportmanager.h"

SerialPortManager::SerialPortManager(QObject *parent) : QObject(parent) {
    qsp = new QSerialPort(this);
};

void SerialPortManager::checkConnect() {
    bool success = false;
    if(!qsp->open(QIODevice::ReadWrite)) {
        qDebug() << "Error: " << qsp->errorString();
    }
    emit connectionResult(success);
    QString testData = "@Test for connection";
    //    QString dataToSend = "Hello, Serial Port";
    qsp->write(testData.toUtf8());

    //    // Optionally wait until data is written
    qsp->waitForBytesWritten(-1);

    qsp->readLine();

    qsp->close();
}

void SerialPortManager::setBaudRate(int baudRate) {
    qsp->setBaudRate(baudRate, QSerialPort::AllDirections);
    checkConnect();
}

void SerialPortManager::setDeivce(const QSerialPortInfo info) {
    qDebug() << "SerialPortName:" << info.systemLocation();
    //    qsp->setPortName("/dev/ttys003";
    qsp->setPortName(info.systemLocation());
}

