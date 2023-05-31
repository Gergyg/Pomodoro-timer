#include "timerwindow.h"
#include "ui_timerwindow.h"
#include "activityrunwindow.h"
#include "globals.h"
#include "Logic/Statistics.h"
#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QMessageBox>

timerwindow::timerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timerwindow)
{
    ui->setupUi(this);
    state = 0;
    completedRounds = 0;
    timeleft = pomodoro->getWorkTime();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start(1000);
    if(timeleft==0) stop();
}

timerwindow::~timerwindow()
{
    delete ui;
}

void timerwindow::on_pushButton_clicked()
{
    stop();
}

void timerwindow::onTimeout()
{
    timeleft--;
    QTime a(0,0,0);
    a = a.addSecs(timeleft);
    ui->label_2->setText(a.toString());
    if(timeleft <= 0){
        timeleft = 100;
        check();
    }
}

void timerwindow::check()
{
    QMessageBox::information(this, "Result", "Session ended");
    state = 1 - state;
    if(state==0){
        QPixmap pix(":/resources/img/WorkPomodoro.jpg");
        int h = ui->image->height();
        int w = ui->image->width();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

        ui->label_4->setText("Work Time!");
        timeleft = pomodoro->getWorkTime();
        Statistics::getInstance()->updateRestTime(user->getUsername(), activity->getTitle(), rtime);
    } else {
        QPixmap pix(":/resources/img/RestPomodoro.jpg");
        int h = ui->image->height();
        int w = ui->image->width();
        ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

        ui->label_4->setText("Rest Time!");
        completedRounds++;
        Statistics::getInstance()->updateCompletedPomodoros(user->getUsername(), activity->getTitle());
        Statistics::getInstance()->updateWorkedTime(user->getUsername(), activity->getTitle(), pomodoro->getWorkTime());
        if(completedRounds == pomodoro->getRounds()) stop();
        timeleft = completedRounds % pomodoro->getRoundsForLongBreak() == 0 ? pomodoro->getLongBreakTime() : pomodoro->getShortBreakTime();
        rtime = timeleft;
    }
}

void timerwindow::stop()
{
    timer->stop();
    close();
    activityrunwindow* nw = new activityrunwindow();
    nw->show();
}

