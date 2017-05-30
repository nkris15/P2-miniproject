#include "mainwindow.h"
#include "adminwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    AdminWindow admin;
    admin.show();

    MainWindow w(&admin); // Parent class is admin
    w.show();

    MainWindow w2(&admin);
    w2.show();

    //MainWindow w3(&admin);
    //w3.show();

    return a.exec();
}
