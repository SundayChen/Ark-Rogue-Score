#ifndef URGENUI_H
#define URGENUI_H

#include <QMainWindow>

namespace Ui {
class UrgenUi;
}

class UrgenUi : public QMainWindow
{
    Q_OBJECT

public:
    explicit UrgenUi(QWidget *parent = nullptr);
    ~UrgenUi();

protected:
    int score;

private slots:
    void update();

    void on_pushButton_clicked();

private:
    Ui::UrgenUi *ui;

signals:
    void urgenExit(const QString &str, int score);
};

#endif // URGENUI_H
