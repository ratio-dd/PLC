#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class SerialPortWidget;

class SerialPortManager : public QObject {
    Q_OBJECT

  public:
    explicit SerialPortManager(QObject *parent = nullptr);
    void checkConnect();
    void setBaudRate(int baudRate);
    void setDeivce(const QSerialPortInfo);

  signals:
    void connectionResult(bool success);

  public slots:

  private:
    QSerialPort *qsp;

};


#endif // SERIALPORTMANAGER_H
