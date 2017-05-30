#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Qt specific to "setup ui"
    ui->setupUi(this);

    // Initialise the groupID (Does not change)
    groupID = this;

    // Group label changes and defaults to a unique string
    groupID_label = QUuid::createUuid().toString();
    ui->lineEdit_groupID->setPlaceholderText(groupID_label);

    // Register the group to admin class
    ((AdminWindow*)(parent))->registerGroup(groupID);


    // Make sure the client is not in queue when they start the program
    stop_queue();

    // Connects the timer to on_timer_tick() slot
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer_tick()));

    // Setup SerialPort communication
    QSerialPort serialPort;
    QString serialPortName = "/dev/ttyAMC0"; // Change this
    serialPort.setPortName(serialPortName);

    // Initialise the serialPortReader class
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
    ((AdminWindow*)(parent()))->startQueue(groupID);
    ui->pushButton_queue->setText("Cancel Queue");
    timeStart = QDateTime::currentSecsSinceEpoch();
    timer->start();
}

void MainWindow::stop_queue()
{
    ((AdminWindow*)(parent()))->stopQueue(groupID);
    timer->stop();
    ui->lcd_time->display("0:00");
    ui->lcd_qnum->display(0);
    ui->pushButton_queue->setText("Start Queue");

}
void MainWindow::setQueueNr(int queueNumber)
{
    ui->lcd_qnum->display(queueNumber);
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

void MainWindow::on_pushButton_groupID_clicked()
{
    groupID_label = ui->lineEdit_groupID->text();
}
