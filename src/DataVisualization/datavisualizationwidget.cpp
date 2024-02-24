#include "datavisualizationwidget.h"
#include "ui_datavisualizationwidget.h"
#include "datamodel.h"

int interval = 100; // 每个数据点之间的间隔，以毫秒为单位

DataVisualizationWidget::DataVisualizationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataVisualizationWidget) {
    ui->setupUi(this);

    connect(ui->backButton, &QPushButton::clicked, this, &DataVisualizationWidget::backButtonClicked);
    connect(ui->chartWidget, &QCustomPlot::mouseMove, this, &DataVisualizationWidget::mouse_position_show);

    ui->chartWidget->addGraph();

    // 设置X轴为毫秒时间显示
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
    ui->chartWidget->xAxis->setTicker(dateTimeTicker);
    dateTimeTicker->setDateTimeFormat("ss.zzz");

    // TEST_MODE则生成随机数据
    #ifdef TEST_MODE
    DataModel DM;
    DataPoints = DM.RandomData(50);
    #else
    #endif

    // 添加数据
    QSharedPointer<QCPGraphDataContainer> dataContainer = ui->chartWidget->graph(0)->data();
    dataContainer->add(DataPoints);

    // 设置x轴的范围 (根据随机数据量）
    ui->chartWidget->xAxis->setRange(0, DataPoints.count() * interval / 1000);
    ui->chartWidget->yAxis->setRange(0, 10);
    // 设置图表中点的样式
    ui->chartWidget->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
    // 使图表可随着鼠标缩放、移动、选择图像
    ui->chartWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    //重新绘制图表
    ui->chartWidget->replot();
}

DataVisualizationWidget::~DataVisualizationWidget() {
    delete ui;
}

void DataVisualizationWidget::on_resetZoomButton_clicked() {
    // 设置x轴和y轴回到初始的范围，假设这里使用之前设置的默认范围
    ui->chartWidget->xAxis->setRange(0, DataPoints.count() * interval / 1000);
    ui->chartWidget->yAxis->setRange(0, 10);
    // 重新绘制图表以应用更改
    ui->chartWidget->replot();
}

void DataVisualizationWidget::mouse_position_show(QMouseEvent *event) {
    #ifdef TEST_MODE
    double x = ui->chartWidget->xAxis->pixelToCoord(event->pos().x());
    double y = ui->chartWidget->yAxis->pixelToCoord(event->pos().y());
    ui->xLineEdit->setText(QString::number(x, 'f', 2));
    ui->yLineEdit->setText(QString::number(y, 'f', 2));
    #endif
}
