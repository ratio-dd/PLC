#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../DataVisualization/datavisualizationwidget.h"
#include "../ParameterAdjustment/parameteradjustmentwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DataVisualizationWidget *dvWidget = qobject_cast<DataVisualizationWidget*>(ui->mainStackedWidget->widget(1));
    if (dvWidget) {
        connect(dvWidget, &DataVisualizationWidget::backButtonClicked, this, &MainWindow::backToDefault);
    }

    ParameterAdjustmentWidget *paWidget = qobject_cast<ParameterAdjustmentWidget*>(ui->mainStackedWidget->widget(2));
    if (paWidget) {
        connect(paWidget, &ParameterAdjustmentWidget::backButtonClicked, this, &MainWindow::backToDefault);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::backToDefault(){

    ui->mainStackedWidget->setCurrentIndex(0);
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

    ui->mainStackedWidget->setCurrentIndex(2);
}
