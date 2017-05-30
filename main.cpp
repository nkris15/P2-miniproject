#include "mainwindow.h"
#include "adminwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    AdminWindow admin;
    admin.show();

    MainWindow w;
    w.show();



    return a.exec();
}
