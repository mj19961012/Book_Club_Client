#include "BCMainWindow.h"
#include "BCLoginWidget.h"
#include "BCMainWidget.h"
#include "BCPolymorphicButton.h"
#include <QApplication>
#include <QDesktopWidget>

BCMainWindow* BCMainWindow::m_BCMainWindow = nullptr;

BCMainWindow* BCMainWindow::instance()
{
    if(nullptr == m_BCMainWindow)
    {
        m_BCMainWindow = new BCMainWindow();
    }
    return m_BCMainWindow;
}

void BCMainWindow::showBasePage(BasePage::BCBasePageEnum pageEnum)
{
    switch(pageEnum)
    {
    case BasePage::Login:
        mStackedWidget->setCurrentWidget(mLoginWidget);
        break;
    case BasePage::MainWindow:
        mStackedWidget->setCurrentWidget(mMainWidget);
        break;
    }
}

void BCMainWindow::showPage(Page::BCPageEnum pageEnum)
{
    mMainWidget->showPage(pageEnum);
}

void BCMainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
}

void BCMainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    mStackedWidget->setFixedSize(this->width(),this->height());

    mMiniSizeButton->setGeometry(this->width() - 94,10,32,32);
    mExitButton->setGeometry(this->width() - 42,10,32,32);

    initStyle();
}

BCMainWindow::BCMainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    init();
    initToolButton();
    initConnect();
}

void BCMainWindow::init()
{    
    setBaseSize(1920,1040);
    setWindowIcon(QIcon(":/res/common/logo.png"));
    setWindowTitle(QStringLiteral("知友"));
    setGeometry(QApplication::desktop()->availableGeometry(this));
    setWindowFlags(Qt::FramelessWindowHint);

    mStackedWidget = new QStackedWidget(this);

    addBasePage(BasePage::Login);
    addBasePage(BasePage::MainWindow);

    QMainWindow::setCentralWidget(mStackedWidget);
}

void BCMainWindow::initToolButton()
{
    mMiniSizeButton = new BCPolymorphicButton(this);

    mExitButton = new BCPolymorphicButton(this);
}

void BCMainWindow::initStyle()
{
    mMiniSizeButton->setImageStyle(":/res/common/minisize.png");
    mExitButton->setImageStyle(":/res/common/exit.png");
}

void BCMainWindow::initConnect()
{
    connect(mMiniSizeButton,&BCPolymorphicButton::clicked,this,[this](){
        this->showMinimized();
    });

    connect(mExitButton,&BCPolymorphicButton::clicked,this,[](){
        qApp->exit();
    });
}

void BCMainWindow::addBasePage(BasePage::BCBasePageEnum pageEnum)
{
    switch(pageEnum)
    {
    case BasePage::Login:
    {
        mLoginWidget = new BCLoginWidget(this);
        mStackedWidget->addWidget(mLoginWidget);
    }
        break;
    case BasePage::MainWindow:
    {
        mMainWidget = new BCMainWidget(this);
        mStackedWidget->addWidget(mMainWidget);
    }
        break;
    }
}
