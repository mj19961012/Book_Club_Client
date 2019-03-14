#include "BCMainWindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BCMainWindow::getInstance()->show();

    return a.exec();
}
