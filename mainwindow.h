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

    int res[8];
    int resScore;

    int animalNum, animalScore;

    int clctionNum, boardNum, propScore;

    int storeScore, extraWithdraw;

private slots:
    void update();

    void on_pushButton_tmp6Sub_clicked();

    void on_pushButton_tmp6Add_clicked();

    void on_pushButton_tmp5Sub_clicked();

    void on_pushButton_tmp5Add_clicked();

    void on_pushButton_tmp4Sub_clicked();

    void on_pushButton_tmp4Add_clicked();

    void on_horizontalSlider_animal_valueChanged(int value);

    void on_spinBox_animal_valueChanged(int arg1);

    void on_horizontalSlider_clction_valueChanged(int value);

    void on_spinBox_clction_valueChanged(int arg1);

    void on_horizontalSlider_board_valueChanged(int value);

    void on_spinBox_board_valueChanged(int arg1);

    void on_spinBox_extraWithdraw_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
