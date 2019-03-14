#include "BCMainWindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BCMainWindow w;
    w.show();

    return a.exec();
}
