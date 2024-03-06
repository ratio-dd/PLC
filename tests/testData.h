#ifndef TESTDATA_H
#define TESTDATA_H


#include <QtTest/QTest>
#include <QObject>

class TestQString: public QObject {
    Q_OBJECT

  public:
    TestQString();

  private slots:
    void toUpper();
};

#endif // TESTDATA_H
