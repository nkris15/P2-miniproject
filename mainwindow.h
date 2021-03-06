#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QDateTime>
#include "adminwindow.h"

#include "serialportreader.h"
#include <QtSerialPort/QSerialPort>
#include <QTextStream>
#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <QUuid>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString groupID_label;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setQueueNr(int);
    void tiltRegistered();

private slots:
    void on_timer_tick();
    void on_actionExit_triggered();
    void on_pushButton_queue_clicked();
    void on_pushButton_groupID_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer = new QTimer(this);
    int timeStart;
    class MainWindow *groupID;
    class SerialPortReader *serialPortReader;
    QSerialPort serialPort;
    QString serialPortName;

    void start_queue();
    void stop_queue();
};

#endif // MAINWINDOW_H
