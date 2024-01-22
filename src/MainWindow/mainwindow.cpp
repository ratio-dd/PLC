#include "../header/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mainStackWidget(new QStackedWidget(this))
    , expViewWidget(new QWidget())
{
    ui->setupUi(this);
    mainStackWidget->addWidget(dataViewWidget);
    mainStackWidget->addWidget(expViewWidget);

    QLineEdit *lineEdit1 = new QLineEdit(dataViewWidget);
    QLineEdit *lineEdit2 = new QLineEdit(expViewWidget);
    lineEdit1->setText("data");
    lineEdit2->setText("exp");


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(mainStackWidget);
    setLayout(layout);
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
    mainStackWidget->setCurrentIndex(0);
}

void MainWindow::on_enterExpButton_clicked()
{
    mainStackWidget->setCurrentIndex(1);
}
