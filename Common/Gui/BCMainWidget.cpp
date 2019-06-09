#include "BCMainWidget.h"
#include <QPainter>
#include "BCMessageEnumData.h"
#include "BCMineEnumData.h"
#include "BCDataManager.h"
#include "BCMessageManager.h"

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
        {
            BCDataManager::instance().setUpLoadPostings(1,0,20);
            emit getPageValuesSignal(pageEnum);
            mStackWidget->setCurrentWidget(mPostingWidget);
            mNavigationBar->setSelectItem(NavigationBar::Postings);
            break;
        }
    case Page::PostDetail:
        mStackWidget->setCurrentWidget(mPostingDetailWidget);
        mPostingDetailWidget->initData();
        break;
    case Page::PostMaster:
        break;
    case Page::PublishPost:
        mStackWidget->setCurrentWidget(mPublishPostWidget);
        break;
    case Page::Activity:
        {
            auto user = BCDataManager::instance().getCurrentLoginUserInfo();
            QString begin = QString::number(QDateTime::currentDateTime().toTime_t() - 24 * 3600 * 3);
            QString end = QString::number(QDateTime::currentDateTime().toTime_t() + 24 * 3600 * 3);
            QString city = QString().fromStdString(user.getCity());
            city = "110000";
            BCDataManager::instance().setUpLoadActivity(begin,end,city,0,20);
            emit getPageValuesSignal(pageEnum);
            mStackWidget->setCurrentWidget(mActivityWidget);
            mNavigationBar->setSelectItem(NavigationBar::Activity);
            break;
        }
    case Page::ActivityDetail:
        {
            mStackWidget->setCurrentWidget(mActivityDetailWidget);
            auto paramer = BCDataManager::instance().getUpLoadActivityDetail();
            mActivityDetailWidget->initData(paramer.actionid);
            break;
        }
    case Page::PublishActivity:
        mStackWidget->setCurrentWidget(mPublishActivityWidget);
        break;
    case Page::Message:
        mStackWidget->setCurrentWidget(mMessageWidget);
        mNavigationBar->setSelectItem(NavigationBar::Message);
        mMessageWidget->showPage(MessagePage::ChatList);
        break;
    case Page::Chat:
        {
            mStackWidget->setCurrentWidget(mMessageChatWidget);
            auto paramer = BCDataManager::instance().getUpLoadChat();
            mMessageChatWidget->initData();
            break;
        }
    case Page::PersonalInformation:
        mStackWidget->setCurrentWidget(mMineWidget);
        mNavigationBar->setSelectItem(NavigationBar::PersonalInformation);
        mMineWidget->showPage(MinePage::MineInformation);
        break;
    case Page::MineFocus:
        break;
    case Page::ChangeMessageStatus:
        break;
    default:
        break;
    }
}

void BCMainWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(255,255,255));
    painter.drawRect(0,0,this->width(),this->height());
}

void BCMainWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mNavigationBar->setGeometry(0,0,300,this->height());

    mStackWidget->setGeometry(300,0,this->width() - 300,this->height());
}

void BCMainWidget::slotNavigationBarSelected(NavigationBar::BCNavigationBarEnum enumData)
{
    switch(enumData)
    {
    case NavigationBar::Postings:
        showPage(Page::Postings);
        break;
    case NavigationBar::Activity:
        showPage(Page::Activity);
        break;
    case NavigationBar::Message:
        showPage(Page::Message);
        break;
    case NavigationBar::Search:
        showPage(Page::Search);
        break;
    case NavigationBar::PersonalInformation:
        showPage(Page::PersonalInformation);
        break;
    }
}

void BCMainWidget::init()
{
    mNavigationBar = new BCNavigationBar(this);

    mStackWidget = new QStackedWidget(this);

    addPage(Page::Postings);
    addPage(Page::PostDetail);
    addPage(Page::PostMaster);
    addPage(Page::PublishPost);
    addPage(Page::Activity);
    addPage(Page::ActivityDetail);
    addPage(Page::PublishActivity);
    addPage(Page::Message);
    addPage(Page::Chat);
    addPage(Page::PersonalInformation);
    addPage(Page::MineFocus);
    addPage(Page::Search);
}

void BCMainWidget::initStyle()
{

}

void BCMainWidget::initConnect()
{
    connect(mNavigationBar,&BCNavigationBar::sigNavigationBarClicked,this,&BCMainWidget::slotNavigationBarSelected);
    connect(this,SIGNAL(getPageValuesSignal(Page::BCPageEnum)),BCMessageManager::getInstance(),SLOT(getPageVlaues(Page::BCPageEnum)));
}

void BCMainWidget::addPage(Page::BCPageEnum pageEnum)
{
    switch(pageEnum)
    {
    case Page::Postings:
    {
        mPostingWidget = new BCPostingWidget(this);
        mStackWidget->addWidget(mPostingWidget);
        break;
    }
    case Page::PostDetail:
    {
        mPostingDetailWidget = new BCPostingDetailWidget(this);
        mStackWidget->addWidget(mPostingDetailWidget);
        break;
    }
    case Page::PostMaster:
    {
        break;
    }
    case Page::PublishPost:
    {
        mPublishPostWidget = new BCPublishPostWidget(this);
        mStackWidget->addWidget(mPublishPostWidget);
        break;
    }
    case Page::Activity:
    {
        mActivityWidget = new BCActivityWidget(this);
        mStackWidget->addWidget(mActivityWidget);
        break;
    }
    case Page::ActivityDetail:
    {
        mActivityDetailWidget = new BCActivityDetailWidget(this);
        mStackWidget->addWidget(mActivityDetailWidget);
        break;
    }
    case Page::PublishActivity:
    {
        mPublishActivityWidget = new BCPublishActivityWidget(this);
        mStackWidget->addWidget(mPublishActivityWidget);
        break;
    }
    case Page::Message:
    {
        mMessageWidget = new BCMessageWidget(this);
        mStackWidget->addWidget(mMessageWidget);
        break;
    }
    case Page::Chat:
    {
        mMessageChatWidget = new BCMessageChatWidget(this);
        mStackWidget->addWidget(mMessageChatWidget);
        break;
    }
    case Page::PersonalInformation:
    {
        mMineWidget = new BCMineWidget(this);
        mStackWidget->addWidget(mMineWidget);
        break;
    }
    case Page::MineFocus:
    {
        break;
    }
    case Page::Search:
    {
        break;
    }
    default:
        break;
    }
}
