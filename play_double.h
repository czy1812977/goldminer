#ifndef PLAY_DOUBLE_H
#define PLAY_DOUBLE_H

#include <QMainWindow>
#include<play_double_view.h>
#include<QTimer>
#include"victory.h"
#include<defeat.h>
#include"finish.h"



namespace Ui {
class play_double;
}

class play_double : public QMainWindow
{
    Q_OBJECT
public slots:
    void change_level_2();
    void timer_1();
    void on_pushButton_clicked();
    void timer();
    void turn_to_over();
    void change_tool_1();
    void change_tool_2();
    void change_tool_3();
    void change_tool_4();
   void change_tool_4_2();

public:
    explicit play_double(QWidget *parent = nullptr);
    ~play_double();
    QTimer*ptimer5=new QTimer;
    int Time_Left;
    victory v;
    defeat d;
    finish f;
    static int sum_money;
    static int sum_1;
    static int sum_2;
    static int sum_3;
    static int sum_4;
    static int level;
    static int goal_money;

private slots:

signals:

    void over();
    void level1();
    void level2();
    void level3();
    void return_ptr(play_double*);

private:
    Ui::play_double *ui;
    play_double_view *sc=new play_double_view;

};

#endif // PLAY_DOUBLE_H
