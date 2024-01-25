#include "MainWindow/mainwindow.h"

#include <QApplication>


#ifndef TEST_MODE
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

#endif
