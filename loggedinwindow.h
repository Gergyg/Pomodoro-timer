#ifndef LOGGEDINWINDOW_H
#define LOGGEDINWINDOW_H

#include <QDialog>

namespace Ui {
class loggedinwindow;
}

class loggedinwindow : public QDialog
{
    Q_OBJECT

public:
    explicit loggedinwindow(QWidget *parent = nullptr);
    ~loggedinwindow();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_statistics_clicked();

private:
    Ui::loggedinwindow *ui;
};

#endif // LOGGEDINWINDOW_H
