#include "datavisualizationwidget.h"
#include "ui_datavisualizationwidget.h"

DataVisualizationWidget::DataVisualizationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataVisualizationWidget)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::clicked, this, &DataVisualizationWidget::backButtonClicked);

    ui->chartWidget->addGraph();

    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
    ui->chartWidget->xAxis->setTicker(dateTimeTicker);
    dateTimeTicker->setDateTimeFormat("ss.zzz");

    // 添加数据点
    int interval = 100; // 每个数据点之间的间隔，以毫秒为单位

    //生成随机数据
    int pointsCount = 10; // 添加的数据点数量
    for(int i = 0; i < pointsCount; ++i) {
        double key = i * interval; // x轴的值从0开始，每次递增100毫秒
        int value = QRandomGenerator::global()->bounded(5); // 生成0到99之间的随机数
        ui->chartWidget->graph(0)->addData(key / 1000.0, value); // 添加数据点
    }


    // 设置x轴的范围 (根据随机数据量）
    ui->chartWidget->xAxis->setRange(0, pointsCount * interval / 1000.0);

    // 使图表可随着鼠标缩放、移动、选择图像
    ui->chartWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->chartWidget->replot();
}

DataVisualizationWidget::~DataVisualizationWidget()
{
    delete ui;
}

void DataVisualizationWidget::on_resetZoomButton_clicked()
{
    // 设置x轴和y轴回到初始的范围，假设这里使用之前设置的默认范围
    ui->chartWidget->xAxis->setRange(0, 1); // 这里的0和1替换为您的默认范围值
    ui->chartWidget->yAxis->setRange(0, 5); // 同上

    // 重新绘制图表以应用更改
    ui->chartWidget->replot();
}
