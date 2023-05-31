#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "globals.h"
#include <QMessageBox>

signupwindow::signupwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupwindow)
{
    ui->setupUi(this);
}

signupwindow::~signupwindow()
{
    delete ui;
}

void signupwindow::on_pushButton_clicked()
{
    QString login = ui->login->text();

    if(auth->isExists(login.toStdString())){
        QMessageBox::warning(this, "Result", "This user already exists");
        return;
    }

    QString pass1 = ui->pass1->text();
    QString pass2 = ui->pass2->text();
    if(pass1 != pass2){
        QMessageBox::warning(this, "Result", "Passwords don't match");
        return;
    }

    auth->signup(login.toStdString(), pass1.toStdString());
    close();
}

