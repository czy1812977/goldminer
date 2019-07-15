#ifndef PLAY_DOUBLE_ITEM_H
#define PLAY_DOUBLE_ITEM_H
#include<QGraphicsPixmapItem>
#include<QString>

class play_double_item : public QGraphicsPixmapItem
{
public:
    play_double_item();
    void set_size(int x);
    void set_picture(QString path);
    int n;  //序号
    int x, y;
    int state;   //1存在，0消失
    float weight;  //由weight改变speadin/speadout
    int value;   //价值
    int height;
    int width;
    static int value_add;
};

#endif // PLAY_DOUBLE_ITEM_H
