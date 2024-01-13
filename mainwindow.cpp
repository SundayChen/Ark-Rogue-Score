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
    animalNum = animalScore = 0;

    //basic settings
    setFixedSize(1600, 950);
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

    //Animal part update
    ui->label_animalScore->setNum(animalScore);
    ui->label_animalNum->setNum(animalNum);
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
    if (arg1) resScore += 50;
    else resScore -= 50;
    update();
}

void MainWindow::on_checkBox_sp1_stateChanged(int arg1)
{
    if (arg1) resScore += 150;
    else resScore -= 150;
    update();
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if (arg1) resScore += 100;
    else resScore -= 100;
    update();
}

void MainWindow::on_checkBox_sp2_stateChanged(int arg1)
{
    if (arg1) resScore += 120;
    else resScore -= 120;
    update();
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    if (arg1) resScore += 80;
    else resScore -= 80;
    update();
}

void MainWindow::on_checkBox_sp3_stateChanged(int arg1)
{
    if (arg1) resScore += 300;
    else resScore -= 300;
    update();
}

void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    if (arg1) resScore += 150;
    else resScore -= 150;
    update();
}

void MainWindow::on_checkBox_sp4_stateChanged(int arg1)
{
    if (arg1) resScore += 250;
    else resScore -= 250;
    update();
}

void MainWindow::on_checkBox_more_stateChanged(int arg1)
{
    if (arg1) resScore += 100;
    else resScore -= 100;
    update();
}

void MainWindow::on_checkBox_triple_stateChanged(int arg1)
{
    if (arg1) resScore += 99;
    else resScore -= 99;
    update();
}

void MainWindow::on_checkBox_notree_stateChanged(int arg1)
{
    if (arg1) resScore += 200;
    else resScore -= 200;
    update();
}

void MainWindow::on_horizontalSlider_animal_valueChanged(int value)
{
    animalNum = value;
    animalScore = value * 20;
    ui->spinBox_animal->setValue(value);
    update();
}

void MainWindow::on_spinBox_animal_valueChanged(int arg1)
{
    ui->horizontalSlider_animal->setValue(arg1);
    animalNum = arg1;
    animalScore = arg1 * 20;
    update();
}
