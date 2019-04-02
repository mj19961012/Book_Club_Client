#include "BCMainWindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BCMainWindow::instance()->show();
    BCMainWindow::instance()->showBasePage(BasePage::Login);

    return a.exec();
}
