#include "BCLoginWindow.h"
#include <QApplication>
#include <iostream>
#include "BCMessageManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BCLoginWindow window;
    window.show();

    BCMessageManager::getInstance()->BCSystemInit();

    return a.exec();
//    return 0;
}
