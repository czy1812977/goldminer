#ifndef PLAY_DOUBLE_VIEW_H
#define PLAY_DOUBLE_VIEW_H

#include <QObject>
#include<QGraphicsScene>
#include<play_double_item.h>
#include<jiqi_hook.h>
#include<cuishi_hook.h>
#include<QTimer>

class play_double_view : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit play_double_view(QGraphicsScene *parent = nullptr);
    cuishi_hook *hook1=new cuishi_hook;
    jiqi_hook *hook2=new jiqi_hook;

signals:void have_catched_1();
        void have_catched_2();
        void change_level_2();
        void change_tool_4_3();


public slots:void change();
    void moveover();
    void change2();
    void moveover2();
    void Get_it_1();
    void Get_it_2();
    void level_2();
    void level_3();



private:play_double_item *item[16];

    QTimer*ptimer=new QTimer;
    QTimer*ptimer2=new QTimer;
    QTimer*ptimer3=new QTimer;
    QTimer*ptimer4=new QTimer;
    void Catched_1();
    void Catched_2();


protected:void keyPressEvent(QKeyEvent *event);
};

#endif // PLAY_DOUBLE_VIEW_H
