#include "testData.h"

TestQString::TestQString() {
    // 构造函数实现，如果为空则什么都不做
}

void TestQString::toUpper() {
    qDebug() << "Running TestQString::toUpper";
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}
