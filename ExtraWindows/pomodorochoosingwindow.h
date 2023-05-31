#ifndef POMODOROCHOOSINGWINDOW_H
#define POMODOROCHOOSINGWINDOW_H

#include <QDialog>

namespace Ui {
class pomodorochoosingwindow;
}

class pomodorochoosingwindow : public QDialog
{
    Q_OBJECT

public:
    explicit pomodorochoosingwindow(QWidget *parent = nullptr);
    ~pomodorochoosingwindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pomodorochoosingwindow *ui;
};

#endif // POMODOROCHOOSINGWINDOW_H
