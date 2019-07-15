#include "cuishi_hook.h"
#include<QPixmap>
#include<QTimer>
#include"play_single.h"
#include"play_double.h"
cuishi_hook::cuishi_hook()
{
    HX = 110;
    HY = 400;
    state = 1;
    this->setPixmap(QPixmap(":/hook/img/cuishi_hook.png"));
}


void cuishi_hook::Setstate(int s)
{
    switch (s) {
    case 0:state = s; 	break;
    case 1:state = s;	break;
    }
}
void cuishi_hook::Hookinit()
{
    x = HX;
    y = HY;
    angle = 0;
    state = 0;    //初始状态为旋转
    length = 0;
    direction = 1;
    speadout = 1;  //初始出收钩速度为1
    speadin = 1;
    style=0;
    style2=0;
    style3=0;
    style4=0;
    style5=0;
    style6=0;
    catchedA=nullptr;
    catchedB=nullptr;

}
void cuishi_hook::Rotate()  //调用Rotate函数后，angle一直在0~90变化
{ if(state==0)
    {if(style2==0)
    {angle++;
        x+=30*cos((angle / 90)*(1.57));
        y-=30*sin((angle / 90)*(1.57));
        setPos(x,y);
        x=HX;
        y=HY;
    }
    else{angle--;
        x += 30*cos((angle / 90)*(1.57));
        y -= 30*sin((angle / 90)*(1.57));
        setPos(x,y);
        x=HX;
        y=HY;


    }
    if(angle==120)
        style2=1;
    if(angle==-30)
        style2=0;
    }
}
void cuishi_hook::Move()
{
    if(state==1){
    if(x <= 1256 && y <= 800 && x>=0 && y>=-100 && style==0 && style3==0&&style4==0)
    {

        x += speadout*cos((angle / 90)*(1.57));
        y -= speadout*sin((angle / 90)*(1.57));
        length+=speadout;
        setPos(x,y);
    }


        else //出界
        {
        style=1;
        temp=speadin;
                if(style3==1)
                {
                   speadin=speadin/catchedA->weight;
                    catchedA->setPos(x+144-0.5*catchedA->width,y);
                x -= speadin*cos((angle / 90)*(1.57));
                y += speadin*sin((angle / 90)*(1.57));
                length-=speadin;
                setPos(x,y);
                speadin=temp;
                }
                if(style4==1)
                {
                    speadin=speadin/catchedB->weight;
                    catchedB->setPos(x+144-0.5*catchedB->width,y);
                x -= speadin*cos((angle / 90)*(1.57));
                y += speadin*sin((angle / 90)*(1.57));
                length-=speadin;
                setPos(x,y);
                speadin=temp;
                }
                if(style3!=1 && style4!=1)
                {
                    x -= speadin*cos((angle / 90)*(1.57));
                    y += speadin*sin((angle / 90)*(1.57));
                    length-=speadin;
                    setPos(x,y);

                }


    if(length<0) {style=0; state = 0;style3=0;style4=0;
        if(catchedA){
            if(style5==0)
            play_single::sum_money += catchedA->value;
            delete catchedA;
            catchedA = nullptr;
            style5=0;
        }if(catchedB){
             if(style6==0)
            play_double::sum_money += catchedB->value;
            delete catchedB;catchedB = nullptr;style6=0;};}
    }
    }
}


