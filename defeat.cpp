#include "defeat.h"
#include "ui_defeat.h"

defeat::defeat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::defeat)
{
    ui->setupUi(this);
}

defeat::~defeat()
{
    delete ui;
}

void defeat::on_pushButton_2_clicked()
{
    this->close();
}
