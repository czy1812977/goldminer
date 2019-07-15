#ifndef JIQI_HOOK_H
#define JIQI_HOOK_H
#include<QGraphicsPixmapItem>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<play_double_item.h>


class jiqi_hook:public QGraphicsPixmapItem
{
public:
    jiqi_hook();
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
        int style5;

        void Setstate(int s);    //设定状态函数
        void Hookinit();         //钩子初始化
        void Rotate();
        void Move();
        int Down();  //按下下键
        void Catched();//是否抓到
        play_double_item *catchedA;
        //是否抓到
};

#endif // JIQI_HOOK_H
