#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "serialportwidget.h"

class SerialPortManager : public QObject {
    Q_OBJECT

  public:
    explicit SerialPortManager(QObject *parent = nullptr);
    void checkConnect();

  signals:
    void connectionResult(bool success);
  private:
    QSerialPort *qsp;
    void connectToWidget(SerialPortWidget *spWidget);
    void setBaudRate(int baudRate);
};


#endif // SERIALPORTMANAGER_H
