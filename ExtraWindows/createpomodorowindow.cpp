#include "createpomodorowindow.h"
#include "ui_createpomodorowindow.h"
#include "globals.h"

createpomodorowindow::createpomodorowindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createpomodorowindow)
{
    ui->setupUi(this);
}

createpomodorowindow::~createpomodorowindow()
{
    delete ui;
}

void createpomodorowindow::on_pushButton_clicked()
{
    int workTime = ui->spinBox_1->value();
    int shortBreakTime = ui->spinBox_2->value();
    int longBreakTime = ui->spinBox_3->value();
    int rounds = ui->spinBox_4->value();
    int roundsForLongBreak = ui->spinBox_5->value();

    activity->addTimer(workTime*60, shortBreakTime*60, longBreakTime*60, rounds, roundsForLongBreak, activity->getTitle());
    close();
}

