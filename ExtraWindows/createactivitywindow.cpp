#include "createactivitywindow.h"
#include "ui_createactivitywindow.h"
#include "globals.h"
#include <QMessageBox>

createactivitywindow::createactivitywindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createactivitywindow)
{
    ui->setupUi(this);
}

createactivitywindow::~createactivitywindow()
{
    delete ui;
}

void createactivitywindow::on_pushButton_clicked()
{
    QString act = ui->lineEdit->text();
    bool res = user->addActivity(act.toStdString());
    if(!res){
        QMessageBox::warning(this, "Result", "Activity already exists");
        return;
    }
    close();
}

