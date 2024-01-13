#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    int tmpAllScore, tmp6, tmp5, tmp4;
    int resScore;

    void update();

private slots:
    void on_pushButton_tmp6Sub_clicked();

    void on_pushButton_tmp6Add_clicked();

    void on_pushButton_tmp5Sub_clicked();

    void on_pushButton_tmp5Add_clicked();

    void on_pushButton_tmp4Sub_clicked();

    void on_pushButton_tmp4Add_clicked();

    void on_checkBox_1_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
