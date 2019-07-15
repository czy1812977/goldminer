#include "gm.h"
#include "ui_gm.h"

GM::GM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GM)
{
    ui->setupUi(this);
}
GM::~GM()
{
    delete ui;
}



void GM::on_help_clicked()
{
    this->a.exec();

}

void GM::on_quit_clicked()
{
    this->close();
}

void GM::on_start_clicked()
{
    this->b.exec();
}
