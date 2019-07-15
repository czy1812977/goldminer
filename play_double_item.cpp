#include "play_double_item.h"
#include<QPixmap>

play_double_item::play_double_item()
{
    weight=5;
    value=0;

}
void play_double_item::set_picture(QString path)
{
    this->setPixmap(path);
}
void play_double_item::set_size(int x)
{
    switch (x) {
    case 1:set_picture(":/gameitem/img/lulu.png");width=245;height=195;value=500+value_add;weight=10;break;
    case 2:set_picture(":/gameitem/img/dazui.png");width=105;height=115;value=200+value_add;weight=5;break;
    case 3:set_picture(":/gameitem/img/yasuo.png");width=67;height=71;value=50+value_add;weight=2;break;
    case 4:set_picture(":/gameitem/img/timo.png");width=81;height=95;value=1000+value_add;weight=2;break;
    case 5:set_picture(":/gameitem/img/mengduo.png");width=181;height=215;value=80+value_add;weight=20;break;
    case 6:set_picture(":/gameitem/img/gouxiong.png");width=124;height=125;value=50+value_add;weight=12;break;
    case 7:set_picture(":/gameitem/img/baoshi.png");width=168;height=189;value=30+value_add;weight=8;break;
    case 8:set_picture(":/gameitem/img/bobi.png");width=106;height=101;value=10+value_add;weight=5;break;
    case 9:set_picture(":/gameitem/img/jiqi.png");break;
    }
}
