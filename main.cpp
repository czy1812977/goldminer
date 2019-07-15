#include "gm.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GM w;
    w.show();


    return a.exec();
}
