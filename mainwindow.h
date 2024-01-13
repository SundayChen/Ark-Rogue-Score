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
    int animalNum, animalScore;

    void update();

private slots:
    void on_pushButton_tmp6Sub_clicked();

    void on_pushButton_tmp6Add_clicked();

    void on_pushButton_tmp5Sub_clicked();

    void on_pushButton_tmp5Add_clicked();

    void on_pushButton_tmp4Sub_clicked();

    void on_pushButton_tmp4Add_clicked();

    void on_checkBox_1_stateChanged(int arg1);

    void on_checkBox_sp1_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_sp2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_sp3_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_sp4_stateChanged(int arg1);

    void on_checkBox_more_stateChanged(int arg1);

    void on_checkBox_triple_stateChanged(int arg1);

    void on_checkBox_notree_stateChanged(int arg1);

    void on_horizontalSlider_animal_valueChanged(int value);

    void on_spinBox_animal_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
