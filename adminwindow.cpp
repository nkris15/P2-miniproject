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

void AdminWindow::registerGroup(class MainWindow* p)
{
    group_list.push_back(p); // Add element at the end
    // label_groups updateGroupList();
    ui->lcd_groups->display(QString::number(group_list.size()));
}



void AdminWindow::startQueue(class MainWindow* p)
{
    queue_list.push_back(p);
    updateQueue();
}


void AdminWindow::stopQueue(class MainWindow* p)
{
    std::vector<MainWindow*>::iterator it;

    for(it=queue_list.begin(); it < queue_list.end(); it++)
    {
        if(*it == p) {
            queue_list.erase(it); // Eraese at the iterator position
            break;  // Break out of the for-loop
        }
    }

    updateQueue();
}


void AdminWindow::updateQueue()
{
    ui->listWidget_queue->clear();
    int i = 0;
    // C++11
    for ( const auto &group : queue_list ) {
        group->setQueueNr(++i);
        ui->listWidget_queue->addItem(group->groupID_label); //
    }

    // Update procent bar
    int procent = (queue_list.size()*100)/group_list.size();
    ui->pbar_queue->setValue(procent);
}
