#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "globals.h"
#include <QMessageBox>
loginwindow::loginwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginwindow)
{
    ui->setupUi(this);
}

loginwindow::~loginwindow()
{
    delete ui;
}

void loginwindow::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString pass = ui->pass->text();

    bool res = auth->login(login.toStdString(), pass.toStdString());
    if(!res){
        QMessageBox::warning(this, "Result", "Wrong password or username");
        return;
    }
    isLogged = true;
    close();
}

