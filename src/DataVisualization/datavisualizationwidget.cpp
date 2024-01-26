#include "datavisualizationwidget.h"
#include "ui_datavisualizationwidget.h"

DataVisualizationWidget::DataVisualizationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataVisualizationWidget)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::clicked, this, &DataVisualizationWidget::backButtonClicked);
}

DataVisualizationWidget::~DataVisualizationWidget()
{
    delete ui;
}
