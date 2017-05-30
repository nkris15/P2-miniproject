#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer_tick()));

    currentScore = 0;
    timer_val = 60;

    // Set fixed size and disable the border arrows
    this->setFixedSize(630,430);
    this->statusBar()->setSizeGripEnabled(false);

    ui->lcd_timer->display(timer_val);


}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_pushButton_start_clicked()
{
    if(ui->pushButton_start->text() == "Start"){
        ui->pushButton_start->setText("Stop");
        timer->start(1000);
    } else if(ui->pushButton_start->text() == "Stop") {
        timer->stop();
        ui->pushButton_start->setText("Reset");
    } else if(ui->pushButton_start->text() == "Reset") {
        currentScore = 0;
        timer_val = 60;
        ui->pushButton_start->setText("Start");
        ui->lcd_score->display(currentScore);
        ui->lcd_timer->display(timer_val);
    }
}

void GameWindow::on_timer_tick()
{
    if(timer_val > 0){
        ui->lcd_timer->display(--timer_val);
    } else {
        timer->stop();
        ui->pushButton_start->setText("Reset");
    }
}

void GameWindow::on_pushButton_hit_clicked()
{
    ui->lcd_score->display(++currentScore);
}
