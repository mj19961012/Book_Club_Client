#include "bc_start_window.h"
#include "ui_bc_start_window.h"

BC_Start_Window::BC_Start_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BC_Start_Window)
{
    ui->setupUi(this);
}

BC_Start_Window::~BC_Start_Window()
{
    delete ui;
}
