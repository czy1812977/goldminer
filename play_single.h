#ifndef PLAY_SINGLE_H
#define PLAY_SINGLE_H

#include <QMainWindow>
#include <play_single_view.h>
#include"victory.h"
#include<defeat.h>
#include"finish.h"



namespace Ui {
class play_single;
}

class play_single : public QMainWindow
{
    Q_OBJECT
public slots:
    void change_level_1();
    void timer_2();
    void change_tool_4_2();
signals:void over();
    void level1();
    void level2();
    void level3();
    void return_ptr(play_single*);

public:
    explicit play_single(QWidget *parent = nullptr);
    ~play_single();
    QTimer*ptimer5=new QTimer;
    int Time_Left;
    victory v;
    defeat d;
    finish f;
    static int sum_1;
    static int sum_2;
    static int sum_3;
    static int sum_4;
    static int sum_money;
    static int level;
    static int goal_money;


private slots:
    void on_pushButton_2_clicked();
    void timer();
    void turn_to_over();
    void change_tool_1();
    void change_tool_2();
    void change_tool_3();
    void change_tool_4();


private:
    Ui::play_single *ui;
    play_single_view *sc=new play_single_view;

};

#endif // PLAY_SINGLE_H
