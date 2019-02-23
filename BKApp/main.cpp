#include "BKMainWindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BKMainWindow w;
    w.show();

    return a.exec();
}
