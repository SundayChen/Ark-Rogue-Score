#include "urgenui.h"
#include "ui_urgenui.h"

UrgenUi::UrgenUi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UrgenUi)
{
    ui->setupUi(this);

    //Initiate
    ui->comboBox->addItem("冰海疑影", 30);
    ui->comboBox->addItem("狡兽九窟", 30);
    ui->comboBox->addItem("坍缩体的午后", 40);
    ui->comboBox->addItem("公司纠葛", 40);
    ui->comboBox->addItem("生人勿近", 50);
    ui->comboBox->addItem("混乱的表象", 50);
    ui->comboBox->addItem("求敌得敌", 50);
    ui->comboBox->addItem("本能污染", 80);
    ui->comboBox->addItem("亡者行军", 80);
    ui->comboBox->addItem("乐理之灾", 80);
    ui->comboBox->addItem("何处无山海", 80);
    ui->comboBox->addItem("人造物狂欢节", 100);
    ui->comboBox->addItem("霜与沙", 80);
    ui->comboBox->addItem("生灵的终点", 150);

    score = 0;

    //Basic settings
    setFixedSize(480, 300);
    setWindowTitle("紧急关卡");
    setWindowIcon(QPixmap(":/media/icon.jpg"));

    update();
}

UrgenUi::~UrgenUi()
{
    delete ui;
}

void UrgenUi::update()
{
    score = ui->comboBox->currentData().toInt() + ui->checkBox_extra->isChecked() * 20 + ui->spinBox->value();
    if (ui->checkBox_press->isChecked()) {
        if (ui->comboBox->currentData().toInt() == 40) score += 20;
        else if (ui->comboBox->currentData().toInt() == 50) score += 20;
        else if (ui->comboBox->currentData().toInt() == 100) score += 20;
        else if (ui->comboBox->currentData().toInt() == 150) score += 40;
        else if (ui->comboBox->currentData().toInt() == 80) {
            if (ui->comboBox->currentText() == "霜与沙") score += 40;
            else score += 20;
        }
    }
    if (ui->checkBox_good->isChecked()) score += score / 5;
    ui->label_score->setNum(score);
}

void UrgenUi::on_pushButton_clicked()
{
    emit this->urgenExit(ui->comboBox->currentText(), score);
}
