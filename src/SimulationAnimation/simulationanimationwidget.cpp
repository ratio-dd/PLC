#include "simulationanimationwidget.h"
#include "ui_simulationanimationwidget.h"

SimulationAnimationWidget::SimulationAnimationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulationAnimationWidget)
{
    ui->setupUi(this);
}

SimulationAnimationWidget::~SimulationAnimationWidget()
{
    delete ui;
}
