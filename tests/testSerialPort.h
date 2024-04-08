#ifndef TESTSERIALPORT_H
#define TESTSERIALPORT_H
#include <QtTest/QTest>

class TestSerialPort: public QObject {
    Q_OBJECT
  private slots:
    void changeBurdRate();
    void setBurdRate();
    void spWidgetCreated();
    void checkConnection();
};


#endif // TESTSERIALPORT_H
