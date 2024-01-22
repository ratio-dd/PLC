#ifndef DATAVISUALIZATION_H
#define DATAVISUALIZATION_H

#include <QWidget>
#include <QStack>
#include "ui_datavisualizationwidget.h"

class DataVisualization
{
    Q_OBJECT
public:
    DataVisualization();
    QWidget *dataViewWidget;



};

class DataVisualizationWidget: public QWidget{
    Q_OBJECT
public:
    explicit DataVisualizationWidget(QWidget *parent = nullptr);

private:
    Ui::DataVisualizationWidget *ui;

};



#endif // DATAVISUALIZATION_H
