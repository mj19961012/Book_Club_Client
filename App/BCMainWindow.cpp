#include "BCMainWindow.h"

BCMainWindow* BCMainWindow::m_BCMainWindow = nullptr;

BCMainWindow* BCMainWindow::getInstance()
{
    if(nullptr == m_BCMainWindow)
    {
        m_BCMainWindow = new BCMainWindow();
    }
    return m_BCMainWindow;
}

BCMainWindow::BCMainWindow(QWidget *parent)
    :QMainWindow(parent)
{

}

void BCMainWindow::init()
{

}

void BCMainWindow::initData()
{

}
