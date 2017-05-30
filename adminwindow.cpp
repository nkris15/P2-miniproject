#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Admin panel");
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::startQueue()
{

    //ui->progressBar->setValue(id);
}
