#include "fmrankcalc.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FMRankCalc w;
    w.show();
    return a.exec();
}
