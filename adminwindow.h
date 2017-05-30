#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

#include <QUuid>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

    void registerGroup(class MainWindow*);
    void unRegisterGroup(class MainWindow*);
    void startQueue(class MainWindow*);
    void stopQueue(class MainWindow*);

private:
    Ui::AdminWindow *ui;
    void updateQueue();

    std::vector<class MainWindow*> group_list; // All groups
    std::vector<class MainWindow*> queue_list; // Only groups in queue
};

#endif // ADMINWINDOW_H
