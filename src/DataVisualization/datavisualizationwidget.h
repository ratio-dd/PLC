#ifndef DATAVISUALIZATIONWIDGET_H
#define DATAVISUALIZATIONWIDGET_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include "customchartview.h"

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

    // setDefaultChart: return a default chart pointer(temp function)
    void setDefaultChart(){


    }
private:
    Ui::DataVisualizationWidget *ui;
};



#endif // DATAVISUALIZATIONWIDGET_H
