#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include "windows.h"
#include "globals.h"


int main(int argc, char *argv[])
{
    int res = system("python upload.py");
    cout << res;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QObject::connect(&a, SIGNAL(aboutToQuit()), &w, SLOT(closing()));
    return a.exec();
}

