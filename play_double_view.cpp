#include "play_double_view.h"
#include<QKeyEvent>
#include<play_double.h>
int play_double_item:: value_add=0;


play_double_view::play_double_view(QGraphicsScene *parent) :QGraphicsScene (parent)
{
    connect(this,SIGNAL(have_catched_1()),this,SLOT(Get_it_1()));
    connect(this,SIGNAL(have_catched_2()),this,SLOT(Get_it_2()));

    for(int i=0;i<16;i++){
    this->item[i]=new play_double_item;
   }
    this->item[0]->set_picture(":/gameitem/img/cuishi.png");
    this->item[0]->x=110;
    this->item[0]->y=400;
    this->item[1]->set_size(9);
    this->item[1]->x=320;
    this->item[1]->y=450;
    this->item[2]->set_size(1);
    this->item[3]->set_size(1);
    this->item[4]->set_size(1);
    this->item[5]->set_size(2);
    this->item[6]->set_size(3);
    this->item[7]->set_size(3);
    this->item[8]->set_size(6);
    this->item[9]->set_size(6);
    this->item[10]->set_size(8);
    this->item[2]->x = 130;
    this->item[2]->y = 100;
    this->item[3]->x = 1000;
    this->item[3]->y = 200;
    this->item[4]->x = 1100;
    this->item[4]->y = 450;
    this->item[5]->x = 650;
    this->item[5]->y = 300;
    this->item[6]->x = 205;
    this->item[6]->y = 300;
    this->item[7]->x = 250;
    this->item[7]->y = 1100;
    this->item[8]->x = 700;
    this->item[8]->y = 100;
    this->item[9]->x = 600;
    this->item[9]->y = 400;
    this->item[10]->x = 55;
    this->item[10]->y = 260;


    for(int i=0;i<16;i++){ this->item[i]->setPos(this->item[i]->x,this->item[i]->y);
    this->addItem(this->item[i]);};

    this->hook1=new cuishi_hook;
    this->hook1->setPos(110,400);
    this->addItem(this->hook1);
    this->hook2=new jiqi_hook;
    this->hook2->setPos(320,450);
    this->addItem(this->hook2);
    this->hook1->Hookinit();
    this->hook2->Hookinit();
    connect(this->ptimer2,SIGNAL(timeout()),this,SLOT(moveover()));
    this->ptimer2->start(10);
    connect(this->ptimer4,SIGNAL(timeout()),this,SLOT(moveover2()));
    this->ptimer4->start(10);
    connect(this->ptimer3,SIGNAL(timeout()),this,SLOT(change2()));
    this->ptimer3->start(1);
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(change()));
    this->ptimer->start(1);
}
void play_double_view::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){

    case Qt::Key_S:
        this->hook1->state=1;
        break;

    case Qt::Key_Down:
        this->hook2->state=1;
        break;
    case Qt::Key_W:
    if(play_double::sum_4>0 && this->hook1->style4==1)
    {
    play_double::sum_4--;
    this->hook1->style4=0;
    this->hook1->style6=1;
    this->hook1->catchedB->set_picture(":/gameitem/img/boom.png");
    emit this->change_tool_4_3();
    };break;
    case Qt::Key_Up:
    if(play_double::sum_4>0 && this->hook2->style3==1)
    {
    play_double::sum_4--;
    this->hook2->style3=0;
    this->hook2->style5=1;
    this->hook2->catchedA->set_picture(":/gameitem/img/boom.png");
    emit this->change_tool_4_3();
    };break;
        }

}
void play_double_view::change(){
   this->hook1->Move();
    this->Catched_1();
}
void play_double_view::moveover(){
    this->hook1->Rotate();
}
void play_double_view::change2(){
   this->hook2->Move();
    this->Catched_2();
}
void play_double_view::moveover2(){
    this->hook2->Rotate();
}
void play_double_view::Catched_1()
{
    for (int i = 2; i < 16; i++)
    {
        if(item[i])
            if (this->hook1->x - this->item[i]->x <= this->item[i]->width-144 &&
                    this->hook1->y - this->item[i]->y <= this->item[i]->height-80 &&
                    this->hook1->x - this->item[i]->x >= -80 &&
                    this->hook1->y - this->item[i]->y>=-80)      //判定catch的条件（待修改）
            {
                hook1->catchedB =this->item[i];  //指针
                emit this->have_catched_1();
                item[i] = nullptr;
            }
    }
}
void play_double_view::Get_it_1(){

       this->hook1-> style4=1;
    }
void play_double_view::Catched_2()
{
    for (int i = 2; i < 16; i++)
    {
        if(item[i])
            if (this->hook2->x - this->item[i]->x <= this->item[i]->width-144 && this->hook2->y - this->item[i]->y <= this->item[i]->height-80 &&this->hook2->x - this->item[i]->x >= -80 &&this->hook2->y - this->item[i]->y>=-80)      //判定catch的条件（待修改）
            {
                hook2->catchedA =this->item[i];  //指针
                emit this->have_catched_2();
                item[i] = nullptr;
            }
    }
}
void play_double_view::Get_it_2(){

       this->hook2-> style3=1;
}
void play_double_view::level_2(){
    for(int i=0;i<16;i++){delete item[i];};
    for(int i=0;i<16;i++){
    this->item[i]=new play_double_item;
    }
    this->item[0]->set_picture(":/gameitem/img/cuishi.png");
    this->item[0]->x=110;
    this->item[0]->y=400;
    this->item[1]->set_size(9);
    this->item[1]->x=320;
    this->item[1]->y=450;
    this->item[2]->set_size(1);
    this->item[3]->set_size(2);
    this->item[4]->set_size(2);
    this->item[5]->set_size(2);
    this->item[6]->set_size(3);
    this->item[7]->set_size(4);
    this->item[8]->set_size(4);
    this->item[9]->set_size(5);
    this->item[10]->set_size(5);
    this->item[11]->set_size(6);
    this->item[2]->x = 1050;
    this->item[2]->y = 500;
    this->item[3]->x = 1100;
    this->item[3]->y = 200;
    this->item[4]->x = 500;
    this->item[4]->y = 100;
    this->item[5]->x = 800;
    this->item[5]->y = 400;
    this->item[6]->x = 130;
    this->item[6]->y = 100;
    this->item[7]->x = 200;
    this->item[7]->y = 50;
    this->item[8]->x = 450;
    this->item[8]->y = 200;
    this->item[9]->x = 300;
    this->item[9]->y = 210;
    this->item[10]->x = 1000;
    this->item[10]->y = 320;
    this->item[11]->x = 750;
    this->item[11]->y = 100;
    for(int i=0;i<16;i++){
        this->item[i]->setPos(this->item[i]->x,this->item[i]->y);
        this->addItem(this->item[i]);
    };
}
void play_double_view::level_3(){
     for(int i=0;i<16;i++){
         delete item[i];
     }
    for(int i=0;i<16;i++){
    this->item[i]=new play_double_item;
   }
    this->item[0]->set_picture(":/gameitem/img/cuishi.png");
    this->item[0]->x=110;
    this->item[0]->y=400;
    this->item[1]->set_size(9);
    this->item[1]->x=320;
    this->item[1]->y=450;
    this->item[2]->set_size(1);
    this->item[3]->set_size(2);
    this->item[4]->set_size(3);
    this->item[5]->set_size(3);
    this->item[6]->set_size(4);
    this->item[7]->set_size(4);
    this->item[8]->set_size(4);
    this->item[9]->set_size(4);
    this->item[10]->set_size(5);
    this->item[11]->set_size(6);
    this->item[12]->set_size(6);
    this->item[13]->set_size(7);
    this->item[14]->set_size(7);
    this->item[15]->set_size(8);
    this->item[2]->x = 500;
    this->item[2]->y = 600;
    this->item[3]->x = 1000;
    this->item[3]->y = 450;
    this->item[4]->x = 550;
    this->item[4]->y = 550;
    this->item[5]->x = 1180;
    this->item[5]->y = 510;
    this->item[6]->x = 50;
    this->item[6]->y = 80;
    this->item[7]->x = 600;
    this->item[7]->y = 70;
    this->item[8]->x = 1100;
    this->item[8]->y = 280;
    this->item[9]->x = 720;
    this->item[9]->y = 500;
    this->item[10]->x = 1000;
    this->item[10]->y = 150;
    this->item[11]->x = 350;
    this->item[11]->y = 250;
    this->item[12]->x = 800;
    this->item[12]->y = 350;
    this->item[13]->x = 50;
    this->item[13]->y = 230;
    this->item[14]->x = 380;
    this->item[14]->y = 490;
    this->item[15]->x = 200;
    this->item[15]->y = 350;
    for(int i=0;i<16;i++){
        this->item[i]->setPos(this->item[i]->x,this->item[i]->y);
        this->addItem(this->item[i]);
    }


}







