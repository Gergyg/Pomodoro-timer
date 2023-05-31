#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#include <QDialog>

namespace Ui {
class timerwindow;
}

class timerwindow : public QDialog
{
    Q_OBJECT

public:
    explicit timerwindow(QWidget *parent = nullptr);
    ~timerwindow();

private slots:
    void on_pushButton_clicked();
    void onTimeout();

private:
    Ui::timerwindow *ui;
    QTimer* timer;
    int state;
    int rtime;
    int completedRounds;
    int timeleft;
    void check();
    void stop();
};

#endif // TIMERWINDOW_H
