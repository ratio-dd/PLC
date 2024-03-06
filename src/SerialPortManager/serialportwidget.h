#ifndef SERIALPORTWIDGET_H
#define SERIALPORTWIDGET_H

#include <QWidget>
#include <QtSerialPort>
#include "serialportmanager.h"

namespace Ui {
    class SerialPortWidget;
}

class SerialPortWidget : public QWidget {
    Q_OBJECT

  public:
    explicit SerialPortWidget(QWidget *parent = nullptr);
    bool setupSerialPortManagerConnections(SerialPortManager *manager);
    ~SerialPortWidget();

  signals:
    void backButtonClicked();
    void baudRateChanged(int baudRate);
    void widgetCreated(SerialPortWidget serialPortWidget);

  private:
    void updateConnectionStatus(bool success);

  private slots:
    void on_backButton_clicked();

    void on_checkConnectButton_clicked();

  private:
    Ui::SerialPortWidget *ui;
};

#endif // SERIALPORTWIDGET_H
