#ifndef PLAY_SINGLE_VIEW_ITEM_H
#define PLAY_SINGLE_VIEW_ITEM_H
#include<QGraphicsPixmapItem>

class play_single_view_item : public QGraphicsPixmapItem
{
public:
    play_single_view_item();
    void set_picture(QString path);
    void set_size(int x);
    int n;  //序号
    int x, y;
    int state;   //1存在，0消失
    float weight;  //由weight改变speadin/speadout
    int value;   //价值
    int height;
    int width;
    static int value_add;
};

#endif // PLAY_SINGLE_VIEW_ITEM_H
