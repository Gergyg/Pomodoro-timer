#ifndef CREATEACTIVITYWINDOW_H
#define CREATEACTIVITYWINDOW_H

#include <QDialog>

namespace Ui {
class createactivitywindow;
}

class createactivitywindow : public QDialog
{
    Q_OBJECT

public:
    explicit createactivitywindow(QWidget *parent = nullptr);
    ~createactivitywindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::createactivitywindow *ui;
};

#endif // CREATEACTIVITYWINDOW_H
