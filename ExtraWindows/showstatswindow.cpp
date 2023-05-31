#include "showstatswindow.h"
#include "ui_showstatswindow.h"
#include "Logic/Statistics.h"
#include "globals.h"

showstatswindow::showstatswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showstatswindow)
{
    ui->setupUi(this);

    auto view = Statistics::getInstance()->showStats(user->getUsername());
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(view.size() + 1);

    QTableWidgetItem* item1 = new QTableWidgetItem();
    item1->setText("Activity");
    QTableWidgetItem* item2 = new QTableWidgetItem();
    item2->setText("Work Time");
    QTableWidgetItem* item3 = new QTableWidgetItem();
    item3->setText("Total rounds");
    QTableWidgetItem* item4 = new QTableWidgetItem();
    item4->setText("Rest Time");
    ui->tableWidget->setItem(0, 0, item1);
    ui->tableWidget->setItem(0, 1, item2);
    ui->tableWidget->setItem(0, 2, item3);
    ui->tableWidget->setItem(0, 3, item4);

    for(int i=0; i < (int)view.size(); i++){
        QTableWidgetItem* newItem = new QTableWidgetItem();
        newItem->setText(QString::fromStdString(view[i].first));
        ui->tableWidget->setItem(i+1, 0, newItem);
        for(int j = 0; j < 3; j++){
            QTableWidgetItem* newItem = new QTableWidgetItem();
            double num = (view[i].second)[j];
            if(j != 1) num /= 60;
            newItem->setText(QString::number(num));
            ui->tableWidget->setItem(i+1, j+1, newItem);
        }
    }
}

showstatswindow::~showstatswindow()
{
    delete ui;
}
