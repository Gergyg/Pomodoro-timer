#include "activitychoosingwindow.h"
#include "ui_activitychoosingwindow.h"
#include "globals.h"
#include <QMessageBox>


activitychoosingwindow::activitychoosingwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::activitychoosingwindow)
{
    ui->setupUi(this);
    vector<string> view = user->viewActivities();
    for(int i=0; i < (int)view.size(); i++){
        ui->listWidget->addItem(QString::fromStdString(view[i]));
    }
}

activitychoosingwindow::~activitychoosingwindow()
{
    delete ui;
}

void activitychoosingwindow::on_pushButton_clicked()
{
    if(!ui->listWidget->currentItem()){
        QMessageBox::warning(this, "Result", "Select some activity first");
        return;
    }
    int index = ui->listWidget->currentRow();
    activityChosen = true;
    activity = user->getActivity(index+1);
    //QMessageBox::warning(this, "Result", QString::number(index));
    close();
}

