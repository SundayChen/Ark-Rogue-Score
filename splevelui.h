#ifndef SPLEVELUI_H
#define SPLEVELUI_H

#include <QMainWindow>

namespace Ui {
class spLevelUi;
}

class spLevelUi : public QMainWindow
{
    Q_OBJECT

public:
    explicit spLevelUi(QWidget *parent = nullptr);
    ~spLevelUi();

protected:
    int score;

private slots:
    void update();

    void on_pushButton_clicked();

private:
    Ui::spLevelUi *ui;

signals:
    void spLvExit(const QString &str, int score);
};

#endif // SPLEVELUI_H
