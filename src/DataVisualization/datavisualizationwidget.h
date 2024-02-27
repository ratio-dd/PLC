#ifndef DATAVISUALIZATIONWIDGET_H
#define DATAVISUALIZATIONWIDGET_H


#include <QWidget>

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

  private:
    Ui::DataVisualizationWidget *ui;
};

#endif // DATAVISUALIZATIONWIDGET_H
