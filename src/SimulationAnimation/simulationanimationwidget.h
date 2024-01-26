#ifndef SIMULATIONANIMATIONWIDGET_H
#define SIMULATIONANIMATIONWIDGET_H

#include <QWidget>

namespace Ui {
class SimulationAnimationWidget;
}

class SimulationAnimationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SimulationAnimationWidget(QWidget *parent = nullptr);
    ~SimulationAnimationWidget();

private:
    Ui::SimulationAnimationWidget *ui;
};

#endif // SIMULATIONANIMATIONWIDGET_H
