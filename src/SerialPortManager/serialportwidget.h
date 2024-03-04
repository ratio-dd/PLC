#ifndef SERIALPORTWIDGET_H
#define SERIALPORTWIDGET_H

#include <QWidget>

namespace Ui {
    class SerialPortWidget;
}

class SerialPortWidget : public QWidget {
    Q_OBJECT

  public:
    explicit SerialPortWidget(QWidget *parent = nullptr);
    ~SerialPortWidget();

  signals:
    void backButtonClicked();

  private slots:
    void on_backButton_clicked();

    void on_checkConnectButton_clicked();

  private:
    Ui::SerialPortWidget *ui;
};

#endif // SERIALPORTWIDGET_H
