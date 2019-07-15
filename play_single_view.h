#ifndef PLAY_SINGLE_VIEW_H
#define PLAY_SINGLE_VIEW_H

#include <QObject>
#include<QGraphicsScene>
#include<play_single_view_item.h>

#include<cuishi_hook.h>
#include<QTimer>


class play_single_view : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit play_single_view(QGraphicsScene *parent = nullptr);
    void Catched();
    play_single_view_item *item[16];
    cuishi_hook *hook=new cuishi_hook;
    QTimer*ptimer=new QTimer;
    QTimer*ptimer2=new QTimer;


signals:void have_catched();
        void change_level_1();
        void change_tool_4_3();








private slots:void change();
              void moveover();
              void Get_it();
              void level_2();
              void level_3();


protected:void keyPressEvent(QKeyEvent *event);
};

#endif // PLAY_SINGLE_VIEW_H
