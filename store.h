#ifndef STORE_H
#define STORE_H

#include <QDialog>

class play_single;
class play_double;


namespace Ui {
class store;
}

class store : public QDialog
{
    Q_OBJECT
public slots:
    void return_back(play_single*a) {
        back = a;
    }
    void return_back(play_double*b){
        back_2= b;
    }
public:
    explicit store(QWidget *parent = nullptr);
    ~store();
    play_single*back;
    play_double*back_2;
signals:
    void  turn_shop_item_1();
   void  turn_shop_item_2();
   void  turn_shop_item_3();
   void  turn_shop_item_4();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();



    void on_pushButton_clicked();

private:
    Ui::store *ui;
};

#endif // STORE_H
