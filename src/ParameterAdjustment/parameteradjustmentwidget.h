#ifndef PARAMETERADJUSTMENTWIDGET_H
#define PARAMETERADJUSTMENTWIDGET_H

#include <QWidget>

namespace Ui {
    class ParameterAdjustmentWidget;
}

class ParameterAdjustmentWidget : public QWidget {
    Q_OBJECT

  public:
    explicit ParameterAdjustmentWidget(QWidget *parent = nullptr);
    ~ParameterAdjustmentWidget();

  signals:
    void backButtonClicked();

  private slots:
    void on_backButton_clicked();

  private:
    Ui::ParameterAdjustmentWidget *ui;
};

#endif // PARAMETERADJUSTMENTWIDGET_H
