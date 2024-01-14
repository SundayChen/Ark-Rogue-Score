#include "splevelui.h"
#include "ui_splevelui.h"

spLevelUi::spLevelUi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::spLevelUi)
{
    ui->setupUi(this);

    //Initiate
    ui->comboBox->addItem("黄沙幻境东南风", 50);
    ui->comboBox->addItem("夙愿将偿", 50);
    ui->comboBox->addItem("天途半道", 50);
    ui->comboBox->addItem("英雄无名", 60);
    ui->comboBox->addItem("“正义使者”", 80);
    ui->comboBox->addItem("其他作战", 30);

    score = 0;

    //Basic settings
    setFixedSize(400, 250);
    setWindowTitle("特殊关卡");
    setWindowIcon(QPixmap(":/media/icon.jpg"));

    update();
}

spLevelUi::~spLevelUi()
{
    delete ui;
}

void spLevelUi::update()
{
    score = ui->comboBox->currentData().toInt() + ui->spinBox->value();
    if (ui->checkBox->isChecked()) score += score / 5;
    ui->label_score->setNum(score);
}

void spLevelUi::on_pushButton_clicked()
{
    emit this->spLvExit(ui->comboBox->currentText(), score);
}
