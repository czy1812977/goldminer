#ifndef MODE_CHOOSE_H
#define MODE_CHOOSE_H

#include <QDialog>
#include"play_single.h"
#include"play_double.h"


namespace Ui {
class mode_choose;
}

class mode_choose : public QDialog
{
    Q_OBJECT

public:
    explicit mode_choose(QDialog *parent = nullptr);
    ~mode_choose();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::mode_choose *ui;
    play_single c;
    play_double d;

signals:
    void start_timer_1();
    void start_timer_2();
};

#endif // MODE_CHOOSE_H
