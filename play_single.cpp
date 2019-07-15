#include "play_single.h"
#include "ui_play_single.h"
#include"store.h"
#include"judge.h"


int play_single::sum_money = 0;
int play_single::sum_1=0;
int play_single::sum_2=0;
int play_single::sum_3=0;
int play_single::sum_4=0;
int play_single::level=2;
int play_single::goal_money=1000;




play_single::play_single(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::play_single)
{
    ui->setupUi(this);
    this->sc=new play_single_view;
    this->ui->graphicsView->setSceneRect(0,0,1250,610);
    this->ui->graphicsView->setScene(sc);
    connect(this,SIGNAL(over()),this,SLOT(turn_to_over()));
    connect(&this->v.a,SIGNAL(turn_shop_item_1()),this,SLOT(change_tool_1()));
    connect(&this->v.a,SIGNAL(turn_shop_item_2()),this,SLOT(change_tool_2()));
    connect(&this->v.a,SIGNAL(turn_shop_item_3()),this,SLOT(change_tool_3()));
    connect(&this->v.a,SIGNAL(turn_shop_item_4()),this,SLOT(change_tool_4()));
    connect(this->sc,SIGNAL(change_tool_4_3()),this,SLOT(change_tool_4_2()));
    connect(this,SIGNAL(return_ptr(play_single*)),&this->v.a,SLOT(return_back(play_single*)));
    emit return_ptr(this);
    this->ui->lcdNumber_6->display(1000);
}

play_single::~play_single()
{
    delete ui;
}

void play_single::on_pushButton_2_clicked()
{
    this->close();
}
void play_single::timer(){
    Time_Left--;
    this->ui->timeleft->display(Time_Left);
    if(Time_Left==0)
    {
        this->ptimer5->stop();
        emit this->over();
    }
    this->ui->lcdNumber_5->display(sum_money);
}

void play_single::timer_2() {
    Time_Left = 60;
    connect(this->ptimer5,SIGNAL(timeout()),this,SLOT(timer()));
    this->ptimer5->start(1000);
}

void play_single::turn_to_over(){
    if (sum_money < goal_money)
    {

        this->d.exec();
        this->close();
    }
    else {if(play_single::level<4)
        {this->v.exec();
        judge::mode=1;}
        else {this->f.exec();
            this->close();
        }
    }
}
void play_single::change_tool_1(){
    if(sum_money>200)
    {
    this->sc->hook->speadin++;
    sum_money-=200;
    sum_1++;
    this->ui->tool1->display(sum_1);
    }
}
void play_single::change_tool_2(){
    if(play_single::sum_money>250)
    {
    play_single_view_item:: value_add+=50;
    sum_money-=250;
    sum_2++;
    this->ui->tool2->display(sum_2);
    }
}

void play_single::change_tool_3(){

    if(sum_money>100)
    {this->sc->hook->speadout++;
     sum_money-=100;
    sum_3++;
    this->ui->tool3->display(sum_3);
    }
}

void play_single::change_tool_4(){
    if(sum_money>100)
    {sum_money-=100;
    sum_4++;
    this->ui->tool4->display(play_single::sum_4);
    }
}
void play_single::change_level_1(){

       if(play_single::level==2)
        {
           goal_money+=2000;
           this->ui->lcdNumber_6->display(play_single::goal_money);
           connect(this,SIGNAL(level2()),this->sc,SLOT(level_2()));
           emit this->level2();
       Time_Left = 50;
       this->ptimer5->start(1000);}
          if(play_single::level==3)
            {
              goal_money+=4000;
              this->ui->lcdNumber_6->display(play_single::goal_money);
              connect(this,SIGNAL(level3()),this->sc,SLOT(level_3()));
              emit this->level3();
              Time_Left = 45;
              this->ptimer5->start(1000);
          }
          play_single::level++;
}

void play_single::change_tool_4_2(){
    this->ui->tool4->display(play_single::sum_4);
}
