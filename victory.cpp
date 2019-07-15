#include "victory.h"
#include "ui_victory.h"

victory::victory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::victory)
{
    ui->setupUi(this);
}

victory::~victory()
{
    delete ui;
}

void victory::on_pushButton_clicked()
{
    this->a.exec();
    this->close();
}
