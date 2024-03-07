#ifndef SERIALPORTWIDGET_H
#define SERIALPORTWIDGET_H

#include <QWidget>
#include <QtSerialPort>

namespace Ui {
    class SerialPortWidget;
}

// Forward Declaration
class SerialPortManager;

class SerialPortWidget : public QWidget {
    Q_OBJECT

  public:
    explicit SerialPortWidget(QWidget *parent = nullptr);
    ~SerialPortWidget();
    void updateConnectionStatus(bool success);

  signals:
    void backButtonClicked();
    void baudRateChanged(int baudRate);
    void widgetCreated(SerialPortWidget *spWidget);

  private:

  private slots:
    void on_backButton_clicked();

    void on_checkConnectButton_clicked();

  private:
    Ui::SerialPortWidget *ui;
};

#endif // SERIALPORTWIDGET_H
