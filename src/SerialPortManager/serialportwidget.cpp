#include "serialportwidget.h"
#include "ui_serialportwidget.h"
#include "../MainWindow/mainwindow.h"
#include "serialportmanager.h"

SerialPortWidget::SerialPortWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialPortWidget) {
    ui->setupUi(this);
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
