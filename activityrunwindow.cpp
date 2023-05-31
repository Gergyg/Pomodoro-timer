#include "activityrunwindow.h"
#include "ui_activityrunwindow.h"
#include "ExtraWindows/createpomodorowindow.h"
#include "ExtraWindows/pomodorochoosingwindow.h"
#include "loggedinwindow.h"
#include "timerwindow.h"
#include "globals.h"

activityrunwindow::activityrunwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::activityrunwindow)
{
    ui->setupUi(this);
    QString title = "Activity - ";
    title += QString::fromStdString(activity->getTitle());
    ui->label->setText(title);
}

activityrunwindow::~activityrunwindow()
{
    delete ui;
}

void activityrunwindow::on_pushButton_4_clicked()
{
    createpomodorowindow window(this);
    window.setModal(true);
    window.exec();
}


void activityrunwindow::on_pushButton_6_clicked()
{
    pomodorochoosingwindow window;
    window.setModal(true);
    window.exec();
    if(pomodoroChosen){
        hide();

        timerwindow nxt;
        nxt.setModal(true);
        nxt.exec();

        pomodoroChosen = false;
    }
}


void activityrunwindow::on_pushButton_5_clicked()
{
    activityChosen = false;
    close();
    loggedinwindow* nw = new loggedinwindow();
    nw->show();
}

