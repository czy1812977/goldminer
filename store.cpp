#include "store.h"
#include "ui_store.h"
#include"play_single.h"
#include"play_double.h"
#include"judge.h"
store::store(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::store)
{
    ui->setupUi(this);
}

store::~store()
{
    delete ui;
}

void store::on_pushButton_2_clicked()
{
    emit turn_shop_item_1();
}

void store::on_pushButton_3_clicked()
{
    emit turn_shop_item_2();

}


void store::on_pushButton_4_clicked()
{
     emit turn_shop_item_3();

}

void store::on_pushButton_5_clicked()
{
    emit turn_shop_item_4();
}


void store::on_pushButton_clicked()
{

    if(judge::mode==2){
    back_2->change_level_2();
        this->close();}

    else{
    back->change_level_1();
    this->close();}
}

