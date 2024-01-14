#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initial variables
    tmpScore = resScore = animalScore = urgencyScore = propScore = storeScore = pressureScore = spLvScore = 0;
    total = 0;

    tmp4 = tmp5 = tmp6 = 0;

    for (int i = 0; i < 8; ++i) res[i] = 0;

    animalNum = 0;

    urgency = new QList<QPair<QString, int>>();

    spLv = new QList<QPair<QString, int>>();
    sp3Score = 0;

    clctionNum = boardNum = 0;

    //Reset sound
    resetSound = new QMediaPlayer(this);
    resetSoundList = new QMediaPlaylist(this);
    resetSoundList->addMedia(QUrl("qrc:/media/reset.mp3"));
    resetSound->setVolume(35);
    resetSound->setPlaylist(resetSoundList);

    //Basic settings
    setFixedSize(1550, 950);
    setWindowTitle("第二届可汗杯分数计算器");
    setWindowIcon(QPixmap(":/media/icon.jpg"));

    ui->label_total->setFont(QFont("黑体", 20));
    ui->label_totalScore->setFont(QFont("Times New Roman", 20));
    ui->pushButton->setFont(QFont("黑体", 12));

    //Correction score explanation
    ui->label_about->setText("抗压加分规则：\n\n"
                             "藏品≤10，完成三层boss战的编队中，\n"
                             "精二≤1，六星≤3，额外+30分\n\n"
                             "藏品≤15，完成四层任何作战的编队中，\n"
                             "精二≤2，六星≤4，额外+20分\n\n"
                             "藏品≤15，完成五层非boss作战的编队中，\n"
                             "精二≤4，六星≤6，额外+20分\n\n"
                             "藏品≤15，完成五层boss作战的编队中，\n"
                             "精二≤5，六星≤7，额外+60分\n\n"
                             "藏品≤25，完成六层及以上非boss作战，\n"
                             "精二≤6，六星≤8，额外+40分\n\n"
                             "藏品≤25，完成六层及以上boss作战，\n"
                             "精二≤7，六星≤9，额外+80分");

    update();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete urgency;
    delete spLv;
    delete resetSound;
    delete resetSoundList;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //Paint background
    QPainter painter(this);
    QPixmap pix(":/media/Sami.png");
    painter.drawPixmap(1180, 470, 350, 350, pix);
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

    tmpScore = tmp6 * 50 + tmp5 * 20 + tmp4 * 10;
    ui->label_tmpAllScore->setNum(tmpScore);

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
    if (ui->checkBox_retry->isChecked()) resScore -= 50;
    if (ui->checkBox_more->isChecked()) resScore += 100;
    if (ui->checkBox_notree->isChecked()) resScore += 200;
    if (ui->checkBox_special->isChecked()) resScore += 99;
    ui->label_resScore->setNum(resScore);

    //Animal part update
    animalScore = animalNum * 20;
    ui->label_animalScore->setNum(animalScore);
    ui->label_animalNum->setNum(animalNum);

    //Urgency part update
    urgencyScore = urgencyCount = 0;
    ui->textBrowser_urgenNum->setText("编号\n");
    ui->textBrowser_urgenName->setText("关卡名称\n");
    ui->textBrowser_urgenScore->setText("分数\n");
    for (auto it = urgency->begin(); it != urgency->end(); ++it) {
        ++urgencyCount;
        ui->textBrowser_urgenNum->append(QString::number(urgencyCount));
        ui->textBrowser_urgenName->append(it->first);
        ui->textBrowser_urgenScore->append(QString::number(it->second));
        urgencyScore += it->second;
    }
    ui->label_urgencyScore->setNum(urgencyScore);

    //Prop part update
    ui->label_boardNum->setNum(boardNum);
    ui->label_clctionNum->setNum(clctionNum);
    propScore = boardNum * 10 + clctionNum * 10;
    ui->label_propScore->setNum(propScore);

    //Store part update
    storeScore = ui->checkBox_noWithdraw->isChecked() * 66 - ui->spinBox_extraWithdraw->value() * 10;
    ui->label_storeScore->setNum(storeScore);

    //Pressure part update
    ui->label_3bossScore->setNum(ui->spinBox_3boss->value() * 30);
    ui->label_4levelScore->setNum(ui->spinBox_4level->value() * 20);
    ui->label_5levelScore->setNum(ui->spinBox_5level->value() * 20);
    ui->label_6levelScore->setNum(ui->spinBox_6level->value() * 40);

    pressureScore = ui->spinBox_3boss->value() * 30 + ui->spinBox_4level->value() * 20 + ui->spinBox_5level->value() * 30 + ui->spinBox_6level->value() * 40;
    ui->label_pressureScore->setNum(pressureScore);

    //Splv part update
    spLvScore = spLvCount = 0;
    ui->textBrowser_spLvNum->setText("编号\n");
    ui->textBrowser_spLvName->setText("关卡名称\n");
    ui->textBrowser_spLvScore->setText("分数\n");
    for (auto it = spLv->begin(); it != spLv->end(); ++it) {
        ++spLvCount;
        ui->textBrowser_spLvNum->append(QString::number(spLvCount));
        ui->textBrowser_spLvName->append(it->first);
        ui->textBrowser_spLvScore->append(QString::number(it->second));
        spLvScore += it->second;
    }
    sp3Score = ui->checkBox_spLvsp3->isChecked() * 50 + ui->checkBox_spLvsp3_poor->isChecked() * 30;
    if (ui->checkBox_splvsp3_good->isChecked()) sp3Score += sp3Score / 5;
    spLvScore += sp3Score;
    ui->label_spLevelScore->setNum(spLvScore);

    //Total
    total = tmpScore + resScore + animalScore + urgencyScore + propScore + storeScore + pressureScore + spLvScore;
    total += ui->spinBox_final->value() + ui->spinBox_finalCorrect->value();

    ui->label_totalScore->setText(QString::number(total) + "！");
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
    ui->spinBox_animal->setValue(value);
    update();
}

void MainWindow::on_spinBox_animal_valueChanged(int arg1)
{
    ui->horizontalSlider_animal->setValue(arg1);
    animalNum = arg1;
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

void MainWindow::on_pushButton_urgenDel_clicked()
{
    if (urgency->isEmpty()) return;
    urgency->removeLast();
    update();
}

void MainWindow::on_pushButton_urgenAdd_clicked()
{
    UrgenUi *urgen_ui = new UrgenUi();
    urgen_ui->show();
    connect(urgen_ui, &UrgenUi::urgenExit, this, [=](const QString &mainStr, int mainScore){
        urgency->append(QPair<QString, int>(mainStr, mainScore));
        urgen_ui->close();
        update();
    });
    update();
}

void MainWindow::on_pushButton_spLvAdd_clicked()
{
    spLevelUi *spLv_ui = new spLevelUi();
    spLv_ui->show();
    connect(spLv_ui, &spLevelUi::spLvExit, this, [=](const QString &mainStr, int mainScore){
        spLv->append(QPair<QString, int>(mainStr, mainScore));
        spLv_ui->close();
        update();
    });
    update();
}

void MainWindow::on_pushButton_spLvDel_clicked()
{
    if (spLv->isEmpty()) return;
    spLv->removeLast();
    update();
}

void MainWindow::on_pushButton_clicked()
{
    //Variables
    tmp4 = tmp5 = tmp6 = 0;
    urgency->clear();
    spLv->clear();
    update();

    //Checkbox
    ui->checkBox_0->setChecked(false);
    ui->checkBox_1->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_sp1->setChecked(false);
    ui->checkBox_sp2->setChecked(false);
    ui->checkBox_sp3->setChecked(false);
    ui->checkBox_sp4->setChecked(false);
    ui->checkBox_more->setChecked(false);
    ui->checkBox_1good->setChecked(false);
    ui->checkBox_1poor->setChecked(false);
    ui->checkBox_2good->setChecked(false);
    ui->checkBox_2poor->setChecked(false);
    ui->checkBox_3good->setChecked(false);
    ui->checkBox_3poor->setChecked(false);
    ui->checkBox_4good->setChecked(false);
    ui->checkBox_4poor->setChecked(false);
    ui->checkBox_retry->setChecked(false);
    ui->checkBox_notree->setChecked(false);
    ui->checkBox_sp1good->setChecked(false);
    ui->checkBox_sp1poor->setChecked(false);
    ui->checkBox_sp2good->setChecked(false);
    ui->checkBox_sp2poor->setChecked(false);
    ui->checkBox_sp3good->setChecked(false);
    ui->checkBox_sp3poor->setChecked(false);
    ui->checkBox_sp4good->setChecked(false);
    ui->checkBox_sp4poor->setChecked(false);
    ui->checkBox_spLvsp3->setChecked(false);
    ui->checkBox_special->setChecked(false);
    ui->checkBox_noWithdraw->setChecked(false);
    ui->checkBox_spLvsp3_poor->setChecked(false);
    ui->checkBox_splvsp3_good->setChecked(false);

    //Slider
    ui->horizontalSlider_board->setValue(0);
    ui->horizontalSlider_animal->setValue(0);
    ui->horizontalSlider_clction->setValue(0);

    //Spinbox
    ui->spinBox_3boss->setValue(0);
    ui->spinBox_board->setValue(0);
    ui->spinBox_final->setValue(0);
    ui->spinBox_4level->setValue(0);
    ui->spinBox_5level->setValue(0);
    ui->spinBox_6level->setValue(0);
    ui->spinBox_animal->setValue(0);
    ui->spinBox_clction->setValue(0);
    ui->spinBox_finalCorrect->setValue(0);
    ui->spinBox_extraWithdraw->setValue(0);

    resetSound->play();
}
