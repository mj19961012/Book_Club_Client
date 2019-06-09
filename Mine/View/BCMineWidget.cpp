#include "BCMineWidget.h"
#include "BCCommonEnumData.h"
#include "BCToastTips.h"
#include <QPainter>
#include "BCDataManager.h"
#include "BCToastTips.h"
#include "BCMessageManager.h"

BCMineWidget::BCMineWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
    initConnect();
}

void BCMineWidget::showPage(MinePage::BCMinePageEnum page)
{
    switch(page)
    {
    case MinePage::MineInformation:
        mStackedWidget->setCurrentWidget(mMineInfoWidget);
        mMineInfoWidget->initData();
        break;
    case MinePage::EditMineInformation:
        mStackedWidget->setCurrentWidget(mMineUpdateInfoWidget);
        break;
    case MinePage::MinePosting:
        mStackedWidget->setCurrentWidget(mMinePostingListWidget);
        mMinePostingListWidget->addListItem(ListItem::MinePosting);
        break;
    case MinePage::MineActivity:
        mStackedWidget->setCurrentWidget(mMineActivityListWidget);
        mMineActivityListWidget->addListItem(ListItem::MineAvtivity);
        break;
    case MinePage::FollowedList:
        mStackedWidget->setCurrentWidget(mMineFollowedListWidget);
        mMineFollowedListWidget->addListItem(ListItem::MineFollowed);
        break;
    case MinePage::MineFollowedPostingsMaster:
        mStackedWidget->setCurrentWidget(mMineFollowedPostingMasterWidget);
        mMineFollowedPostingMasterWidget->initData();
        break;
    }
}

void BCMineWidget::receiveOperationResult(bool isSuccess, Page::BCPageEnum pageEnum)
{
    qDebug() << "BCMineWidget::receiveOperationResult" << "\n";
    switch (pageEnum)
    {
        case Page::PostMaster:
        {
            if(!isSuccess)
            {
                QString errorMsg = BCDataManager::instance().getErrorMsg();
                BCToastTips::Instance().setToastTip(errorMsg);
                return;
            }
            showPage(MinePage::MineInformation);
            break;
        }
        case Page::Interest:
        {
            if(!isSuccess)
            {
                QString errorMsg = BCDataManager::instance().getErrorMsg();
                BCToastTips::Instance().setToastTip(errorMsg);
                return;
            }
            mMineInterestListWidget->addListItem(ListItem::MineInterest);
            break;
        }
    }
}

void BCMineWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.drawRect(0,108,this->width(),2);
}

void BCMineWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    int buttonWidth = (this->width() - 150)/4;

    mMineInfoButton->setGeometry(75,50,buttonWidth,60);
    mMinePostingButton->setGeometry(mMineInfoButton->pos().x() + mMineInfoButton->width(),50,
                                       buttonWidth,60);
    mMineActivityButton->setGeometry(mMinePostingButton->pos().x() + mMinePostingButton->width(),50,
                                       buttonWidth,60);
    mInterestListButton->setGeometry(mMineActivityButton->pos().x() + mMineActivityButton->width(),50,
                                     buttonWidth,60);

    mStackedWidget->setGeometry(75,110,this->width() - 150,this->height() - 110);

    initStyle();
}

void BCMineWidget::slotMineButtonClicked()
{
    for(auto iter = mButtonMap.begin(); iter != mButtonMap.end(); iter++)
    {
        if(sender() == iter.value())
        {
            iter.value()->setColorStyle("qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                        "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                        "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                        "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                        "#333333",QString("2,2,2,0").split(","),
                                        QString("#F7BB64,#F7BB64,#F7BB64,#F7BB64").split(","),0);
            showPage(iter.key());
        }
        else
        {
            iter.value()->setColorStyle("qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                        "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                        "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                        "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                        "#333333",QString("0,0,0,2").split(","),
                                        QString("transparent,transparent,transparent,#F7BB64").split(","),0);
        }
        iter.value()->setFontStyle(25);
    }
}

void BCMineWidget::init()
{
    mMineInfoButton = new BCPolymorphicButton(this);
    mMinePostingButton = new BCPolymorphicButton(this);
    mMineActivityButton = new BCPolymorphicButton(this);
    mInterestListButton = new BCPolymorphicButton(this);

    mButtonMap[MinePage::MineInformation] = mMineInfoButton;
    mButtonMap[MinePage::MinePosting] = mMinePostingButton;
    mButtonMap[MinePage::MineActivity] = mMineActivityButton;
    mButtonMap[MinePage::FollowedList] = mInterestListButton;

    mMineInfoButton->setText(QStringLiteral("个人信息"));
    mMinePostingButton->setText(QStringLiteral("我的帖子"));
    mMineActivityButton->setText(QStringLiteral("我的活动"));
    mInterestListButton->setText(QStringLiteral("我的关注"));

    mStackedWidget = new QStackedWidget(this);

    addPage(MinePage::MineInformation);
    addPage(MinePage::EditMineInformation);
    addPage(MinePage::MinePosting);
    addPage(MinePage::MineActivity);
    addPage(MinePage::FollowedList);
    addPage(MinePage::MineFollowedPostingsMaster);
}

void BCMineWidget::initStyle()
{
    for(auto iter = mButtonMap.begin(); iter != mButtonMap.end(); iter++)
    {
        if(iter.key() == MinePage::MineInformation)
        {
            iter.value()->setColorStyle("qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                        "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                        "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                        "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                        "#333333",QString("2,2,2,0").split(","),
                                        QString("#F7BB64,#F7BB64,#F7BB64,#F7BB64").split(","),0);
        }
        else
        {
            iter.value()->setColorStyle("qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                        "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                        "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                        "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                        "#333333",QString("0,0,0,2").split(","),
                                        QString("transparent,transparent,transparent,#F7BB64").split(","),0);
        }
        iter.value()->setFontStyle(25);
    }
}

void BCMineWidget::initConnect()
{
    connect(mMinePostingListWidget,&BCListWidget::getPageValues,BCMessageManager::getInstance(),&BCMessageManager::getPageVlaues);
    connect(mMineActivityListWidget,&BCListWidget::getPageValues,BCMessageManager::getInstance(),&BCMessageManager::getPageVlaues);
    connect(mMineInterestListWidget,&BCListWidget::getPageValues,BCMessageManager::getInstance(),&BCMessageManager::getPageVlaues);
    for(auto &iter : mButtonMap)
    {
        connect(iter,&BCPolymorphicButton::clicked,this,&BCMineWidget::slotMineButtonClicked);
    }
    connect(mMineInfoWidget,&BCMineInfoWidget::sigEditInfo,this,[this](){
        showPage(MinePage::EditMineInformation);
    });
    connect(mMineUpdateInfoWidget,&BCMineUpdateInfoWidget::sigEditInfoBack,this,[this](){
        showPage(MinePage::MineInformation);
    });
    connect(mMineUpdateInfoWidget,&BCMineUpdateInfoWidget::sigUpdateInfo,this,[this](){
        showPage(MinePage::MineInformation);
        BCToastTips::Instance().setToastTip(QStringLiteral("修改成功~"));
    });
    connect(mMineFollowedListWidget,&BCListWidget::sigMineFollowedItemClicked,this,[this](){
        showPage(MinePage::MineFollowedPostingsMaster);
    });
    connect(mMineFollowedPostingMasterWidget,&BCMineFollowedPostingMasterWidget::sigMineFollowedPostingMasterBack,this,[this](){
        showPage(MinePage::FollowedList);
    });
}

void BCMineWidget::addPage(MinePage::BCMinePageEnum page)
{
    switch(page)
    {
    case MinePage::MineInformation:
    {
        mMineInfoWidget = new BCMineInfoWidget(this);
        mStackedWidget->addWidget(mMineInfoWidget);
        break;
    }
    case MinePage::EditMineInformation:
    {
        mMineUpdateInfoWidget = new BCMineUpdateInfoWidget(this);
        mStackedWidget->addWidget(mMineUpdateInfoWidget);
        break;
    }
    case MinePage::MinePosting:
    {
        mMinePostingListWidget = new BCListWidget(this);
        mStackedWidget->addWidget(mMinePostingListWidget);
        break;
    }
    case MinePage::MineActivity:
    {
        mMineActivityListWidget = new BCListWidget(this);
        mStackedWidget->addWidget(mMineActivityListWidget);
        break;
    }
    case MinePage::FollowedList:
    {
        mMineFollowedListWidget = new BCListWidget(this);
        mStackedWidget->addWidget(mMineFollowedListWidget);
        break;
    }
    case MinePage::MineFollowedPostingsMaster:
    {
        mMineFollowedPostingMasterWidget = new BCMineFollowedPostingMasterWidget(this);
        mStackedWidget->addWidget(mMineFollowedPostingMasterWidget);
        break;
    }
    }
}
