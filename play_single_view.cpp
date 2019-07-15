#include "play_single_view.h"
#include<QKeyEvent>
#include<math.h>
#include<play_single.h>
int play_single_view_item:: value_add=0;

play_single_view::play_single_view(QGraphicsScene *parent) : QGraphicsScene(parent)
{
    connect(this,SIGNAL(have_catched()),this,SLOT(Get_it()));
    for(int i=0;i<16;i++){
    this->item[i]=new play_single_view_item;
   }
    this->item[0]->set_picture(":/gameitem/img/cuishi.png");
    this->item[0]->x=110;
    this->item[0]->y=400;
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
    this->item[9]->x = 300;
    this->item[9]->y = 400;
    this->item[10]->x = 55;
    this->item[10]->y = 260;
    for(int i=0;i<16;i++){ this->item[i]->setPos(this->item[i]->x,this->item[i]->y);
    this->addItem(this->item[i]);};

    this->hook=new cuishi_hook;
    this->hook->Hookinit();
    this->hook->setPos(this->hook->x,this->hook->y);
    this->hook->Hookinit();
    this->addItem(this->hook);
    this->ptimer2->start(10);
    connect(this->ptimer2,SIGNAL(timeout()),this,SLOT(moveover()));
    this->ptimer->start(1);
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(change()));
}
void play_single_view::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_S:
            this->hook->state = 1;break;
        case Qt::Key_W:
        if(play_single::sum_4>0&&this->hook->style3==1)
        {
        play_single::sum_4--;
        this->hook->style3=0;
        this->hook->style5=1;
        this->hook->catchedA->set_picture(":/gameitem/img/boom.png");
         emit this->change_tool_4_3();
        }
break;

    }
}
void play_single_view::change(){
   this->hook->Move();
   this->Catched();
}
void play_single_view::moveover(){
    this->hook->Rotate();
}
void play_single_view::Catched()
{
    for (int i = 2; i < 16; i++)
    {
        if(item[i])
            if (this->hook->x - this->item[i]->x <= this->item[i]->width-144 && this->hook->y - this->item[i]->y <= this->item[i]->height-80 &&this->hook->x - this->item[i]->x >= -80 &&this->hook->y - this->item[i]->y>=-80)      //判定catch的条件（待修改）
            {
                hook->catchedA =this->item[i];  //指针
                emit this->have_catched();
                item[i] = nullptr;
            }
    }
}
void play_single_view::Get_it(){

       this->hook-> style3=1;
}
void play_single_view::level_2(){
    for(int i=0;i<16;i++){delete item[i];};
    for(int i=0;i<16;i++){
    this->item[i]=new play_single_view_item;
    }
    this->item[0]->set_picture(":/gameitem/img/cuishi.png");
    this->item[0]->x=110;
    this->item[0]->y=400;
    this->item[2]->set_size(1);
    this->item[3]->set_size(1);
    this->item[4]->set_size(2);
    this->item[5]->set_size(2);
    this->item[6]->set_size(3);
    this->item[7]->set_size(4);
    this->item[8]->set_size(4);
    this->item[9]->set_size(5);
    this->item[10]->set_size(6);
    this->item[11]->set_size(7);
    this->item[12]->set_size(8);
    this->item[2]->x = 1100;
    this->item[2]->y = 200;
    this->item[3]->x = 600;
    this->item[3]->y = 350;
    this->item[4]->x = 850;
    this->item[4]->y = 150;
    this->item[5]->x = 350;
    this->item[5]->y = 480;
    this->item[6]->x = 300;
    this->item[6]->y = 280;
    this->item[7]->x = 200;
    this->item[7]->y = 150;
    this->item[8]->x = 900;
    this->item[8]->y = 550;
    this->item[9]->x = 500;
    this->item[9]->y = 160;
    this->item[10]->x = 830;
    this->item[10]->y = 400;
    this->item[11]->x = 310;
    this->item[11]->y = 950;
    this->item[12]->x = 50;
    this->item[12]->y = 220;
    for(int i=0;i<16;i++){
        this->item[i]->setPos(this->item[i]->x,this->item[i]->y);
        this->addItem(this->item[i]);
    };
}
void play_single_view::level_3(){
     for(int i=0;i<16;i++){
         delete item[i];
     }
    for(int i=0;i<16;i++){
    this->item[i]=new play_single_view_item;
   }
    this->item[0]->set_picture(":/gameitem/img/cuishi.png");
    this->item[0]->x=110;
    this->item[0]->y=400;
    this->item[2]->set_size(1);
    this->item[3]->set_size(1);
    this->item[4]->set_size(2);
    this->item[5]->set_size(3);
    this->item[6]->set_size(4);
    this->item[7]->set_size(4);
    this->item[8]->set_size(4);
    this->item[9]->set_size(4);
    this->item[10]->set_size(5);
    this->item[11]->set_size(6);
    this->item[12]->set_size(7);
    this->item[2]->x = 600;
    this->item[2]->y = 300;
    this->item[3]->x = 950;
    this->item[3]->y = 450;
    this->item[4]->x = 150;
    this->item[4]->y = 100;
    this->item[5]->x = 350;
    this->item[5]->y = 460;
    this->item[6]->x = 600;
    this->item[6]->y = 320;
    this->item[7]->x = 850;
    this->item[7]->y = 80;
    this->item[8]->x = 620;
    this->item[8]->y = 540;
    this->item[9]->x = 1080;
    this->item[9]->y = 520;
    this->item[10]->x = 250;
    this->item[10]->y = 200;
    this->item[11]->x = 1000;
    this->item[11]->y = 280;
    this->item[12]->x = 500;
    this->item[10]->y = 100;
    for(int i=0;i<16;i++){
        this->item[i]->setPos(this->item[i]->x,this->item[i]->y);
        this->addItem(this->item[i]);
    }


}


