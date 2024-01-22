#include "datavisualizationwidget.h"
#include "ui_datavisualizationwidget.h"

DataVisualizationWidget::DataVisualizationWidget(QWidget *parent) :

    ui(new Ui::DataVisualizationWidget)
{
    ui->setupUi(this);
}

DataVisualizationWidget::~DataVisualizationWidget()
{
    delete ui;
}
