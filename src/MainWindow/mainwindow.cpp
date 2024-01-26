#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exitButton_clicked()
{
    this->close();
}

void MainWindow::on_viewDataButton_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_enterExpButton_clicked()
{

}
