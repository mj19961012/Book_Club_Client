#include "BCLoginWindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BCLoginWindow window;
    window.show();

    return a.exec();
}
