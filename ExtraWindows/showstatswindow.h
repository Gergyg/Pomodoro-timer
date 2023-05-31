#ifndef SHOWSTATSWINDOW_H
#define SHOWSTATSWINDOW_H

#include <QDialog>

namespace Ui {
class showstatswindow;
}

class showstatswindow : public QDialog
{
    Q_OBJECT

public:
    explicit showstatswindow(QWidget *parent = nullptr);
    ~showstatswindow();

private:
    Ui::showstatswindow *ui;
};

#endif // SHOWSTATSWINDOW_H
