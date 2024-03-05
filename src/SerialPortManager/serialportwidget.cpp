#include "serialportwidget.h"
#include "ui_serialportwidget.h"
#include "../MainWindow/mainwindow.h"
#include "serialportmanager.h"

SerialPortWidget::SerialPortWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialPortWidget) {
    ui->setupUi(this);

    QStringList baudRate = {"300", "600", "1200", "2400", "4800", "9600", "19200", "38400", "43000", "56000", "57600", "115200"};

    ui->BaudRateBox->addItems(baudRate);
    ui->BaudRateBox->setCurrentIndex(5);

}


SerialPortWidget::~SerialPortWidget() {
    delete ui;
}


void SerialPortWidget::on_backButton_clicked() {
    emit backButtonClicked();
}

void SerialPortWidget::on_checkConnectButton_clicked() {
    if(CheckConnect()) {
        ui->connectFeedBackLabel->setText("成功");
        ui->connectFeedBackLabel->setStyleSheet("QLabel { color : green; }");
    }
    ui->connectFeedBackLabel->setText("失败");
    ui->connectFeedBackLabel->setStyleSheet("QLabel { color : red; }");
}
