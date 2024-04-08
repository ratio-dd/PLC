#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../DataVisualization/datavisualizationwidget.h"
#include "../ParameterAdjustment/parameteradjustmentwidget.h"
#include "../DataVisualization/db.h"


enum StackedWidgetPages {
    HomePage = 0,
    SerialPortPage,
    DataPage,
    ExpPage1,
    ExpPage2,
    ExpPage3,
    ExpPage4
};

enum ExpSelectBoxOptions {
    exp_1 = 0,
    exp_2,
    exp_3,
    exp_4
};


void MainWindow::switchStackedWidgetPage(int pageIndex) {
    ui->mainStackedWidget->setCurrentIndex(pageIndex);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , spManager(new SerialPortManager(this))
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Set Default Page
    switchStackedWidgetPage(HomePage);

    // 添加实验（应用于主页选择界面）
    QStringList expName_list = {"实验一", "实验二", "实验三", "实验四"};
    ui->expSelectComboBox->addItems(expName_list);

    DataVisualizationWidget *dvWidget = qobject_cast<DataVisualizationWidget *>(ui->mainStackedWidget->widget(DataPage));
    if(dvWidget) {
        connect(dvWidget, &DataVisualizationWidget::backButtonClicked, this, &MainWindow::backToDefault);
    }

    ParameterAdjustmentWidget *paWidget = qobject_cast<ParameterAdjustmentWidget *>(ui->mainStackedWidget->widget(ExpPage1));
    if(paWidget) {
        connect(paWidget, &ParameterAdjustmentWidget::backButtonClicked, this, &MainWindow::backToDefault);
    }

    SerialPortWidget *spWidget = qobject_cast<SerialPortWidget *>(ui->mainStackedWidget->widget(SerialPortPage));
    if(spWidget) {
        connect(spWidget, &SerialPortWidget::backButtonClicked, this, &MainWindow::backToDefault);
        setupSerialPortWidgetManagerConnection(spWidget, spManager);
    }




}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::backToDefault() {
    switchStackedWidgetPage(HomePage);
}

void MainWindow::on_exitButton_clicked() {
    this->close();
}

void MainWindow::on_viewDataButton_clicked() {
    switchStackedWidgetPage(DataPage);
}

void MainWindow::on_serialPortButton_clicked() {
    switchStackedWidgetPage(SerialPortPage);
}


void MainWindow::on_returnButton2_clicked() {
    backToDefault();
}
void MainWindow::on_returnButton3_clicked() {
    backToDefault();
}
void MainWindow::on_returnButton4_clicked() {
    backToDefault();
}

void MainWindow::on_enterExpButton_clicked() {
    switch(ui->expSelectComboBox->currentIndex()) {
        case exp_1:
            switchStackedWidgetPage(ExpPage1);
            break;
        case exp_2:
            switchStackedWidgetPage(ExpPage2);
            break;
        case exp_3:
            switchStackedWidgetPage(ExpPage3);
            break;
        case exp_4:
            switchStackedWidgetPage(ExpPage4);
            break;
    }


}

bool MainWindow::setupSerialPortWidgetManagerConnection(
                SerialPortWidget *spWidget, SerialPortManager *spManager) {
    bool success = true;

    success &= bool(connect(spWidget, &SerialPortWidget::baudRateChanged,
                            spManager, &SerialPortManager::setBaudRate));

    success &= bool(connect(spManager, &SerialPortManager::connectionResult,
                            spWidget, &SerialPortWidget::updateConnectionStatus));

    return success;
}

void MainWindow::on_databaseButton_clicked() {
    DB *db = new DB();
}







