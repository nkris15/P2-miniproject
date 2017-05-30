#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private slots:
    void on_pushButton_start_clicked();
    void on_pushButton_hit_clicked();
    void on_timer_tick();

private:
    Ui::GameWindow *ui;
    QTimer *timer = new QTimer(this);
    int currentScore;
    int timer_val;
};

#endif // GAMEWINDOW_H
