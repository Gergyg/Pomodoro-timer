#ifndef CREATEPOMODOROWINDOW_H
#define CREATEPOMODOROWINDOW_H

#include <QDialog>

namespace Ui {
class createpomodorowindow;
}

class createpomodorowindow : public QDialog
{
    Q_OBJECT

public:
    explicit createpomodorowindow(QWidget *parent = nullptr);
    ~createpomodorowindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::createpomodorowindow *ui;
};

#endif // CREATEPOMODOROWINDOW_H
