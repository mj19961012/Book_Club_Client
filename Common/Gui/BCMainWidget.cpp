#include "BCMainWidget.h"
#include "BCNavigationBar.h"

BCMainWidget::BCMainWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initStyle();
    initConnect();
}

void BCMainWidget::showPage(Page::BCPageEnum pageEnum)
{
    switch(pageEnum)
    {
    case Page::Postings:
        break;
    case Page::PostDetail:
        break;
    case Page::PostMaster:
        break;
    case Page::PublishPost:
        break;
    case Page::Activity:
        break;
    case Page::ActivityDetail:
        break;
    case Page::PublishActivity:
        break;
    case Page::Message:
        break;
    case Page::Chat:
        break;
    case Page::PersonalInformation:
        break;
    case Page::MineFocus:
        break;
    case Page::Search:
        break;
    }
}

void BCMainWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCMainWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mNavigationBar->setGeometry(0,0,300,this->height());

    mStackWidget->setGeometry(300,0,this->width() - 300,this->height());
}

void BCMainWidget::init()
{
    mNavigationBar = new BCNavigationBar(this);

    mStackWidget = new QStackedWidget(this);
}

void BCMainWidget::initStyle()
{

}

void BCMainWidget::initConnect()
{

}

void BCMainWidget::addPage(Page::BCPageEnum pageEnum)
{
    switch(pageEnum)
    {
    case Page::Postings:
        break;
    case Page::PostDetail:
        break;
    case Page::PostMaster:
        break;
    case Page::PublishPost:
        break;
    case Page::Activity:
        break;
    case Page::ActivityDetail:
        break;
    case Page::PublishActivity:
        break;
    case Page::Message:
        break;
    case Page::Chat:
        break;
    case Page::PersonalInformation:
        break;
    case Page::MineFocus:
        break;
    case Page::Search:
        break;
    }
}
