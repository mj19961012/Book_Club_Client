#include "BCLoginWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BCLoginWidget w;
    w.show();

    return a.exec();
}
