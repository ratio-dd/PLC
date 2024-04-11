#ifndef SERIALPORTWIDGET_H
#define SERIALPORTWIDGET_H

#include <QWidget>
#include <QtSerialPort>
#include <QString>
#include <QSerialPortInfo>

Q_DECLARE_METATYPE(QSerialPortInfo)

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

  public slots:
    void on_deviceComboBox_activated(int index);

  signals:
    void backButtonClicked();
    void baudRateChanged(int baudRate);
    void widgetCreated(SerialPortWidget *spWidget);
    void deviceSelected(const QSerialPortInfo);
  private:

  private slots:
    void on_backButton_clicked();

    void on_checkConnectButton_clicked();


  private:
    Ui::SerialPortWidget *ui;
};

#endif // SERIALPORTWIDGET_H
