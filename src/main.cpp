#include "MainWindow/mainwindow.h"
#include <QApplication>
#include "../tests/testData.h"
#include "../tests/testSerialPort.h"

#ifndef TEST_MODE
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    qDebug() << "Running main";

    // 检测 "--test" 参数但不将其传递给 QTest
    if(argc > 1 && QString(argv[1]) == "--test") {
        qDebug() << "Running Tests";
        TestSerialPort test;
        // 为了避免 QTest::qExec 解析 "--test" 参数，可以传递减少的 argc 和 argv
        char *newArgv[] = {argv[0]};
        return QTest::qExec(&test, 1, newArgv);
    }

    MainWindow w;
    w.show();

    // 串口枚举测试
    //    qDebug() << "Available ports:";
    //    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
    //        qDebug() << "Name        : " << info.portName();
    //        qDebug() << "Description : " << info.description();
    //        qDebug() << "Manufacturer: " << info.manufacturer();
    //        // 可以添加更多的信息输出
    //    }

    return app.exec();
}
#endif
