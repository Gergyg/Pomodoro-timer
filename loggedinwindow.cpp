#include "loggedinwindow.h"
#include "ui_loggedinwindow.h"
#include "ExtraWindows/activitychoosingwindow.h"
#include "activityrunwindow.h"
#include "mainwindow.h"
#include "ExtraWindows/createactivitywindow.h"
#include "ExtraWindows/showstatswindow.h"
#include "globals.h"

extern bool activityChosen;

loggedinwindow::loggedinwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loggedinwindow)
{
    ui->setupUi(this);
    user = auth->getUser();
}

loggedinwindow::~loggedinwindow()
{
    delete ui;
}

void loggedinwindow::on_pushButton_5_clicked()
{
    activitychoosingwindow window(this);
    window.setModal(true);
    window.exec();

    if(activityChosen){
        hide();
        activityrunwindow nxt(this);
        nxt.setModal(true);
        nxt.exec();
        activityChosen = false;
    }
}


void loggedinwindow::on_pushButton_4_clicked()
{
    createactivitywindow window(this);
    window.setModal(true);
    window.exec();
}


void loggedinwindow::on_pushButton_6_clicked()
{

    isLogged = false;
    close();
    MainWindow* nw = new MainWindow();
    nw->show();

}


void loggedinwindow::on_statistics_clicked()
{
    showstatswindow window(this);
    window.setModal(true);
    window.exec();
}

