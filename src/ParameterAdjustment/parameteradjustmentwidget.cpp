#include "parameteradjustmentwidget.h"
#include "ui_parameteradjustmentwidget.h"

ParameterAdjustmentWidget::ParameterAdjustmentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParameterAdjustmentWidget) {
    ui->setupUi(this);
    //connect(ui->backButton, &QPushButton::clicked, this, &ParameterAdjustmentWidget::backButtonClicked);
}

ParameterAdjustmentWidget::~ParameterAdjustmentWidget() {
    delete ui;
}

void ParameterAdjustmentWidget::on_backButton_clicked() {
    emit backButtonClicked();
}
