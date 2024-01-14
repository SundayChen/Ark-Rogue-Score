#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QPair>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPixmap>
#include <QPainter>
#include "urgenui.h"
#include "splevelui.h"

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
    int tmpScore, resScore, animalScore, urgencyScore, propScore, storeScore, pressureScore, spLvScore;
    int total;

    int tmp6, tmp5, tmp4;

    int res[8];

    int animalNum;

    QList<QPair<QString, int>> *urgency;
    int urgencyCount;

    int clctionNum, boardNum;

    QList<QPair<QString, int>> *spLv;
    int spLvCount, sp3Score;

    QMediaPlayer *resetSound;
    QMediaPlaylist *resetSoundList;

    void paintEvent(QPaintEvent *) override;

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

    void on_pushButton_urgenDel_clicked();

    void on_pushButton_urgenAdd_clicked();

    void on_pushButton_spLvAdd_clicked();

    void on_pushButton_spLvDel_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
