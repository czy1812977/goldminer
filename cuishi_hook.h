#ifndef CUISHI_HOOK_H
#define CUISHI_HOOK_H
#include<QGraphicsPixmapItem>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<play_single_view_item.h>
#include<play_double_item.h>




class cuishi_hook:public QGraphicsPixmapItem
{
public:
    cuishi_hook();
    int HX, HY; //初始坐标
        float x, y;
        float angle;
        int state;  //0旋转，1延伸或收缩
        int direction;  //0逆 1顺
        float speadout;  //出钩速度
        float speadin; //收钩速度
        float length;
        float temp;
        int style;
        int style2;
        int style3;
        int style4;
        int style5;
        int style6;

        void Setstate(int s);    //设定状态函数
        void Hookinit();         //钩子初始化
        void Rotate();
        void Move();
        int Down();  //按下下键
        void Catched();//是否抓到
        play_single_view_item *catchedA;
        play_double_item *catchedB;


public slots:
        void Get_it();

};


#endif // CUISHI_HOOK_H
