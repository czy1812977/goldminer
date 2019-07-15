#ifndef VICTORY_H
#define VICTORY_H

#include <QDialog>
#include"store.h"

namespace Ui {
class victory;
}

class victory : public QDialog
{
    Q_OBJECT

public:
    explicit victory(QWidget *parent = nullptr);
    ~victory();

    store a;

private slots:
    void on_pushButton_clicked();


private:
    Ui::victory *ui;
};

#endif // VICTORY_H
