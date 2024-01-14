#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initial variables
    tmpAllScore = tmp4 = tmp5 = tmp6 = 0;

    for (int i = 0; i < 8; ++i) res[i] = 0;
    resScore = 0;

    animalNum = animalScore = 0;

    clctionNum = boardNum = propScore = 0;

    storeScore = extraWithdraw = 0;

    //Basic settings
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
    res[0] = (50 * ui->checkBox_1->isChecked() + 60 * ui->checkBox_1poor->isChecked());
    if (ui->checkBox_1good->isChecked()) res[0] += res[0] / 5;

    res[1] = (150 * ui->checkBox_sp1->isChecked() + 60 * ui->checkBox_sp1poor->isChecked());
    if (ui->checkBox_sp1good->isChecked()) res[1] += res[1] / 5;

    res[2] = (100 * ui->checkBox_2->isChecked() + 60 * ui->checkBox_2poor->isChecked());
    if (ui->checkBox_2good->isChecked()) res[2] += res[2] / 5;

    res[3] = (120 * ui->checkBox_sp2->isChecked() + 60 * ui->checkBox_sp2poor->isChecked());
    if (ui->checkBox_sp2good->isChecked()) res[3] += res[3] / 5;

    res[4] = (80 * ui->checkBox_3->isChecked() + 80 * ui->checkBox_3poor->isChecked());
    if (ui->checkBox_3good->isChecked()) res[4] += res[4] / 5;

    res[5] = (300 * ui->checkBox_sp3->isChecked() + 80 * ui->checkBox_sp3poor->isChecked());
    if (ui->checkBox_sp3good->isChecked()) res[5] += res[5] / 5;

    res[6] = (150 * ui->checkBox_4->isChecked() + 80 * ui->checkBox_4poor->isChecked());
    if (ui->checkBox_4good->isChecked()) res[6] += res[6] / 5;

    res[7] = (250 * ui->checkBox_sp4->isChecked() + 80 * ui->checkBox_sp4poor->isChecked());
    if (ui->checkBox_sp4good->isChecked()) res[7] += res[7] / 5;

    resScore = 0;
    for (int i = 0; i < 8; ++i) resScore += res[i];
    if (ui->checkBox_more->isChecked()) resScore += 100;
    if (ui->checkBox_notree->isChecked()) resScore += 200;
    if (ui->checkBox_special->isChecked()) resScore += 99;
    ui->label_resScore->setNum(resScore);

    //Animal part update
    ui->label_animalScore->setNum(animalScore);
    ui->label_animalNum->setNum(animalNum);

    //Urgency part update

    //Prop part update
    ui->label_boardNum->setNum(boardNum);
    ui->label_clctionNum->setNum(clctionNum);
    propScore = boardNum * 10 + clctionNum * 10;
    ui->label_propScore->setNum(propScore);

    //Store part update
    storeScore = ui->checkBox_noWithdraw->isChecked() * 66 - extraWithdraw * 10;
    ui->label_storeScore->setNum(storeScore);
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

void MainWindow::on_horizontalSlider_clction_valueChanged(int value)
{
    clctionNum = value;
    ui->spinBox_clction->setValue(value);
    update();
}

void MainWindow::on_spinBox_clction_valueChanged(int arg1)
{
    ui->horizontalSlider_clction->setValue(arg1);
    clctionNum = arg1;
    update();
}

void MainWindow::on_horizontalSlider_board_valueChanged(int value)
{
    boardNum = value;
    ui->spinBox_board->setValue(value);
    update();
}

void MainWindow::on_spinBox_board_valueChanged(int arg1)
{
    ui->horizontalSlider_board->setValue(arg1);
    boardNum = arg1;
    update();
}

void MainWindow::on_spinBox_extraWithdraw_valueChanged(int arg1)
{
    extraWithdraw = arg1;
    update();
}
