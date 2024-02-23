#ifndef DATAVISUALIZATIONWIDGET_H
#define DATAVISUALIZATIONWIDGET_H


#include <QWidget>
#include "../../libs/qcustomplot.h"

namespace Ui {
    class DataVisualizationWidget;
}

class  DataVisualizationWidget: public QWidget {
    Q_OBJECT

  public:
    explicit DataVisualizationWidget(QWidget *parent = nullptr);
    ~DataVisualizationWidget();

  signals:
    void backButtonClicked();

  private slots:
    void on_resetZoomButton_clicked();
    void mouse_position_show(QMouseEvent *event);

  private:
    Ui::DataVisualizationWidget *ui;
    QVector<QCPGraphData> DataPoints;

};

#endif // DATAVISUALIZATIONWIDGET_H
