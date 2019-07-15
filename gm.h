#ifndef GM_H
#define GM_H

#include <QMainWindow>
#include"help.h"
#include"mode_choose.h"

namespace Ui {
class GM;
}

class GM : public QMainWindow
{
    Q_OBJECT

public:
    explicit GM(QWidget *parent = nullptr);
    ~GM();

private slots:
    void on_help_clicked();

    void on_quit_clicked();

    void on_start_clicked();

private:
    Ui::GM *ui;
    help a;
    mode_choose b;
};

#endif // GM_H
