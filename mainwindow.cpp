#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stop_queue();

    // Connects the timer to on_timer_tick() slot
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer_tick()));



    // Setup SerialPort communication
    QSerialPort serialPort;
    QString serialPortName = "/dev/ttyAMC0";
    serialPort.setPortName(serialPortName);

    SerialPortReader serialPortReader(&serialPort);

    // Set fixed size and disable the border arrows
    this->setFixedSize(630,430);
    this->statusBar()->setSizeGripEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::start_queue()
{
    ui->pushButton_queue->setText("Cancel Queue");
    timeStart = QDateTime::currentSecsSinceEpoch();
    timer->start();

}

void MainWindow::stop_queue()
{
    timer->stop();
    ui->lcd_time->display("0:00");
    ui->pushButton_queue->setText("Start Queue");

}



/* -------------------------------- Events -------------------------------- */

void MainWindow::on_timer_tick()
{
    int timeDiff = QDateTime::currentSecsSinceEpoch() - timeStart; // Time difference between start and now in secounds

    QString text = QString::number(timeDiff/60) + ":" + QString::number(timeDiff%60).rightJustified(2, '0'); // Forces 2 digits, puts a zero if the number is only 1 digit
    ui->lcd_time->display(text);
}

void MainWindow::on_pushButton_queue_clicked()
{
    if(ui->pushButton_queue->text() == "Start Queue")
    {
        start_queue();
    }else{
        stop_queue();
    }
}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit(); // Quits the application
}

