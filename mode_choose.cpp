#include "mode_choose.h"
#include "ui_mode_choose.h"
#include"judge.h"
int judge::mode=0;

mode_choose::mode_choose(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::mode_choose)
{
    ui->setupUi(this);
    connect(this,SIGNAL(start_timer_1()),&d,SLOT(timer_1()));
    connect(this,SIGNAL(start_timer_2()),&c,SLOT(timer_2()));
}

mode_choose::~mode_choose()
{
    delete ui;
}


void mode_choose::on_pushButton_clicked()
{
    this->c.show();
    emit this->start_timer_2();
    this->close();
}

void mode_choose::on_pushButton_2_clicked()
{
    this->d.show();
    emit this->start_timer_1();
    this->close();
}

void mode_choose::on_pushButton_3_clicked()
{
    this->close();
}
