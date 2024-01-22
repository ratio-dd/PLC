#include "customchartview.h"
#include "ui_customchartview.h"

CustomChartView::CustomChartView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomChartView)
{
    ui->setupUi(this);
}

CustomChartView::~CustomChartView()
{
    delete ui;
}
