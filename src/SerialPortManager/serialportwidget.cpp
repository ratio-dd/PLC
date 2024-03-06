#include "serialportwidget.h"
#include "ui_serialportwidget.h"
#include "../MainWindow/mainwindow.h"

SerialPortWidget::SerialPortWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialPortWidget) {
    ui->setupUi(this);

    struct BaudRateItem {
        QString name;
        qint32 value;
    };
    BaudRateItem baudRates[] = {
        {"1200", QSerialPort::Baud1200},
        {"2400", QSerialPort::Baud2400},
        {"4800", QSerialPort::Baud4800},
        {"9600", QSerialPort::Baud9600},
        {"19200", QSerialPort::Baud19200},
        {"38400", QSerialPort::Baud38400},
        {"57600", QSerialPort::Baud57600},
        {"115200", QSerialPort::Baud115200}
    };

    for(const auto &item : baudRates) {
        ui->BaudRateBox->addItem(item.name, item.value);
    }
    ui->BaudRateBox->setCurrentIndex(3);

    emit widgetCreated(this);

}

bool SerialPortWidget::setupSerialPortManagerConnections(SerialPortManager *manager) {
    bool success = true;
    success &= bool(connect(manager, &SerialPortManager::connectionResult,
                            this, &SerialPortWidget::updateConnectionStatus));
    return success;
}


SerialPortWidget::~SerialPortWidget() {
    delete ui;
}


void SerialPortWidget::on_backButton_clicked() {
    emit backButtonClicked();
}

void SerialPortWidget::on_checkConnectButton_clicked() {

    int baudRate = ui->BaudRateBox->currentData().toInt();
    emit baudRateChanged(baudRate);

}

// auto update after receive connectionResult from Serial Port Manager
void SerialPortWidget::updateConnectionStatus(bool success) {
    if(success) {
        ui->connectFeedBackLabel->setText("成功");
        ui->connectFeedBackLabel->setStyleSheet("QLabel { color : green; }");
    } else {
        ui->connectFeedBackLabel->setText("失败");
        ui->connectFeedBackLabel->setStyleSheet("QLabel { color : red; }");
    }
}
