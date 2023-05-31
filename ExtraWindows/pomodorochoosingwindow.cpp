#include "pomodorochoosingwindow.h"
#include "ui_pomodorochoosingwindow.h"
#include "globals.h"
#include <QMessageBox>

pomodorochoosingwindow::pomodorochoosingwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pomodorochoosingwindow)
{
    ui->setupUi(this);
    ui->tableWidget->clear();
    vector<vector<int>> view = activity->viewTimers();
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(view.size() + 1);

    QTableWidgetItem* item1 = new QTableWidgetItem();
    item1->setText("Work Time");
    QTableWidgetItem* item2 = new QTableWidgetItem();
    item2->setText("Short Break Time");
    QTableWidgetItem* item3 = new QTableWidgetItem();
    item3->setText("Long Break Time");
    QTableWidgetItem* item4 = new QTableWidgetItem();
    item4->setText("Rounds");
    QTableWidgetItem* item5 = new QTableWidgetItem();
    item5->setText("Rounds For Long Break");
    ui->tableWidget->setItem(0, 0, item1);
    ui->tableWidget->setItem(0, 1, item2);
    ui->tableWidget->setItem(0, 2, item3);
    ui->tableWidget->setItem(0, 3, item4);
    ui->tableWidget->setItem(0, 4, item5);

    for(int i=0; i < (int)view.size(); i++){
        for(int j = 0; j < 5; j++){
            QTableWidgetItem* newItem = new QTableWidgetItem();
            int num = view[i][j];
            if(j < 3) num /= 60;
            newItem->setText(QString::number(num));
            ui->tableWidget->setItem(i+1, j, newItem);
        }
    }
}

pomodorochoosingwindow::~pomodorochoosingwindow()
{
    delete ui;
}

void pomodorochoosingwindow::on_pushButton_clicked()
{
    if(!ui->tableWidget->currentItem()){
        QMessageBox::warning(this, "Result", "Select some pomodoro first");
        return;
    }
    int row = ui->tableWidget->currentRow();
    if(row==0){
        QMessageBox::warning(this, "Result", "Select some pomodoro first");
        return;
    }

    pomodoroChosen = true;
    pomodoro = activity->getTimer(row);
    close();
}

