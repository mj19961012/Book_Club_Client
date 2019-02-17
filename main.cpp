#include "bc_start_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BC_Start_Window w;
    w.show();

    return a.exec();
}
