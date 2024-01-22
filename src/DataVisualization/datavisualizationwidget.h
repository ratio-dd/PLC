#ifndef DATAVISUALIZATIONWIDGET_H
#define DATAVISUALIZATIONWIDGET_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

namespace Ui {
class DataVisualizationWidget;
}

QT_CHARTS_USE_NAMESPACE

class DataVisualizationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataVisualizationWidget(QWidget *parent = nullptr);
    ~DataVisualizationWidget();

private:
    Ui::DataVisualizationWidget *ui;
};



#endif // DATAVISUALIZATIONWIDGET_H
