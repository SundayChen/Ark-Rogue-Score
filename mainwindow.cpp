#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initial variables
    tmpAllScore = tmp4 = tmp5 = tmp6 = 0;
    resScore = 0;

    //basic settings
    resize(1600, 1000);
    setWindowTitle("第二届可汗杯分数计算器");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    //Temp part update
    ui->label_tmp6Num->setNum(tmp6);
    ui->label_tmp5Num->setNum(tmp5);
    ui->label_tmp4Num->setNum(tmp4);

    ui->label_tmp6Score->setNum(tmp6 * 50);
    ui->label_tmp5Score->setNum(tmp5 * 20);
    ui->label_tmp4Score->setNum(tmp4 * 10);

    tmpAllScore = tmp6 * 50 + tmp5 * 20 + tmp4 * 10;
    ui->label_tmpAllScore->setNum(tmpAllScore);

    //Result part update
    ui->label_resScore->setNum(resScore);
}

void MainWindow::on_pushButton_tmp6Sub_clicked()
{
    if (tmp6 > 0) --tmp6;
    update();
}

void MainWindow::on_pushButton_tmp6Add_clicked()
{
    ++tmp6;
    update();
}

void MainWindow::on_pushButton_tmp5Sub_clicked()
{
    if (tmp5 > 0) --tmp5;
    update();
}

void MainWindow::on_pushButton_tmp5Add_clicked()
{
    ++tmp5;
    update();
}

void MainWindow::on_pushButton_tmp4Sub_clicked()
{
    if (tmp4 > 0) --tmp4;
    update();
}

void MainWindow::on_pushButton_tmp4Add_clicked()
{
    ++tmp4;
    update();
}

void MainWindow::on_checkBox_1_stateChanged(int arg1)
{
    if (arg1) resScore += 100;
    else resScore -= 100;
    update();
}
