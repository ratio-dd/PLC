#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextBrowser>

#include "../src/DataVisualization/datamodel.h"



#ifdef TEST_MODE
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建一个窗口
    QWidget window;
    window.setWindowTitle("Simple Text Browser Widget");

    // 创建一个 QVBoxLayout
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 创建一个 QTextBrowser
    QTextBrowser *textBrowser = new QTextBrowser();

    //debug model
    DataModel DM;
    DM.loadDataFromFile("/Users/ratio/Coding/Qt/PLC/tests/test.cvs");
    textBrowser->setText(DM.getDataAsText());

    // 将 QTextBrowser 添加到布局中
    layout->addWidget(textBrowser);

    // 设置布局到窗口
    window.setLayout(layout);
    window.show();

    return app.exec();
}
#endif
