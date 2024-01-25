#ifndef CUSTOMCHARTVIEW_H
#define CUSTOMCHARTVIEW_H

#include <QWidget>
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE


class CustomChartView : public QChartView {

public:

    CustomChartView(QChart *chart, QWidget *parent = nullptr) : QChartView(chart, parent) {
        setMouseTracking(true);
    }

protected:
    void wheelEvent(QWheelEvent *event) override {
        QList<QAbstractAxis*> axesList = chart()->axes(Qt::Horizontal);

        // 检查是否有水平轴，并确保它是QValueAxis类型
        if (!axesList.isEmpty() && dynamic_cast<QValueAxis*>(axesList.first())) {
            QValueAxis *axisX = static_cast<QValueAxis*>(axesList.first());

            // 计算缩放因子
            double factor = (event->angleDelta().y() > 0) ? 0.9 : 1.1;

            // 计算新的坐标轴范围
            double newMin = axisX->min() * factor;
            double newMax = axisX->max() * factor;

            // 设置新的坐标轴范围
            axisX->setRange(newMin, newMax);

            QChartView::wheelEvent(event);
        }
    }
};

#endif // CUSTOMCHARTVIEW_H
