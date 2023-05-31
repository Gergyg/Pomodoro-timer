#ifndef ACTIVITYRUNWINDOW_H
#define ACTIVITYRUNWINDOW_H

#include <QDialog>

namespace Ui {
class activityrunwindow;
}

class activityrunwindow : public QDialog
{
    Q_OBJECT

public:
    explicit activityrunwindow(QWidget *parent = nullptr);
    ~activityrunwindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::activityrunwindow *ui;
};

#endif // ACTIVITYRUNWINDOW_H
