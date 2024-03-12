QT       += core gui
QT       += charts
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport printsupport

CONFIG += sdk_no_version_check

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/DataVisualization/datavisualizationwidget.cpp \
    src/ParameterAdjustment/parameteradjustmentwidget.cpp \
    src/SerialPortManager/serialportwidget.cpp \
    src/main.cpp \
    src/MainWindow/mainwindow.cpp \
    src/ParameterAdjustment/parameteradjustment.cpp \
    src/SerialPortManager/serialportmanager.cpp \
    src/DataVisualization/datamodel.cpp \
    tests/testData.cpp \
    tests/testDataModel.cpp \
    libs/qcustomplot.cpp
    tests/testSerialPort.cpp


HEADERS += \
    src/DataVisualization/datamodel.h \
    src/DataVisualization/datavisualizationwidget.h \
    src/MainWindow/mainwindow.h \
    src/ParameterAdjustment/parameteradjustment.h \
    src/ParameterAdjustment/parameteradjustmentwidget.h \
    src/SerialPortManager/serialportmanager.h \
    src/SerialPortManager/serialportwidget.h \
    libs/qcustomplot.h \
    tests/testData.h


FORMS += \
    forms/mainwindow.ui \
    forms/datavisualizationwidget.ui \
    forms/parameteradjustmentwidget.ui \
    forms/serialportwidget.ui \

RESOURCES +=\
    res/

DISTFILES += \
    docs/structure.md \
    tests/test.cvs

#DEFINES += TEST_MODE

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

