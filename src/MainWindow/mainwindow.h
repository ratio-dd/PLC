#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void switchStackedWidgetPage(int pageIndex);

  private slots:
    void backToDefault();

    void on_exitButton_clicked();

    void on_viewDataButton_clicked();

    void on_enterExpButton_clicked();


    void on_returnButton2_clicked();

    void on_returnButton3_clicked();

    void on_returnButton4_clicked();

    void on_serialPortButton_clicked();

  private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
