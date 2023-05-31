#ifndef ACTIVITYCHOOSINGWINDOW_H
#define ACTIVITYCHOOSINGWINDOW_H

#include <QDialog>

namespace Ui {
class activitychoosingwindow;
}

class activitychoosingwindow : public QDialog
{
    Q_OBJECT

public:
    explicit activitychoosingwindow(QWidget *parent = nullptr);
    ~activitychoosingwindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::activitychoosingwindow *ui;
};

#endif // ACTIVITYCHOOSINGWINDOW_H
