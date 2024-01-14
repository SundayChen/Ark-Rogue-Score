#include "urgenui.h"
#include "ui_urgenui.h"

UrgenUi::UrgenUi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UrgenUi)
{
    ui->setupUi(this);

    //Initiate
    ScoreMap.insert("冰海疑影", 30);
    ScoreMap.insert("狡兽九窟", 30);
    ScoreMap.insert("坍缩体的午后", 40);
    ScoreMap.insert("公司纠葛", 40);
    ScoreMap.insert("生人勿近", 50);
    ScoreMap.insert("混乱的表象", 50);
    ScoreMap.insert("求敌得敌", 50);
    ScoreMap.insert("本能污染", 80);
    ScoreMap.insert("亡者行军", 80);
    ScoreMap.insert("乐理之灾", 80);
    ScoreMap.insert("何处无山海", 80);
    ScoreMap.insert("人造物狂欢节", 100);
    ScoreMap.insert("霜与沙", 80);
    ScoreMap.insert("生灵的终点", 150);

    foreach(const QString &str, ScoreMap.keys()) {
        ui->comboBox->addItem(str, ScoreMap.value(str));
    }

    score = 0;

    //Basic settings
    setFixedSize(480, 300);
    setWindowTitle("紧急关卡");

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
        else if (ui->comboBox->currentData().toInt() == 50) score += 30;
        else if (ui->comboBox->currentData().toInt() == 100) score += 30;
        else if (ui->comboBox->currentData().toInt() == 150) score += 40;
        else if (ui->comboBox->currentData().toInt() == 80) {
            if (ui->comboBox->currentText() == "霜与沙") score += 40;
            else score += 30;
        }
    }
    if (ui->checkBox_good->isChecked()) score += score / 5;
    ui->label_score->setNum(score);
}

void UrgenUi::on_pushButton_clicked()
{
    emit this->urgenExit(ui->comboBox->currentText(), score);
}
