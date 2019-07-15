#ifndef DEFEAT_H
#define DEFEAT_H

#include <QDialog>

namespace Ui {
class defeat;
}

class defeat : public QDialog
{
    Q_OBJECT

public:
    explicit defeat(QWidget *parent = nullptr);
    ~defeat();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::defeat *ui;
};

#endif // DEFEAT_H
