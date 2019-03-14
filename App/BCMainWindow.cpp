#include "BCMainWindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include "BCLoginWindow.h"

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
    init();
}

void BCMainWindow::init()
{
    setGeometry(QApplication::desktop()->availableGeometry(this));
    setWindowFlags(Qt::FramelessWindowHint);
}

void BCMainWindow::addPage()
{
}

void BCMainWindow::showPage()
{
    setFixedSize(710,420);
}
