#include "BCMineWidget.h"
#include "BCCommonEnumData.h"
#include <QPainter>

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
    case MinePage::InterestList:
        mStackedWidget->setCurrentWidget(mMineInterestListWidget);
        mMineInterestListWidget->addListItem(ListItem::MineInterest);
        break;
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
    mButtonMap[MinePage::InterestList] = mInterestListButton;

    mMineInfoButton->setText(QStringLiteral("个人信息"));
    mMinePostingButton->setText(QStringLiteral("我的帖子"));
    mMineActivityButton->setText(QStringLiteral("我的活动"));
    mInterestListButton->setText(QStringLiteral("我的关注"));

    mStackedWidget = new QStackedWidget(this);

    addPage(MinePage::MineInformation);
    addPage(MinePage::EditMineInformation);
    addPage(MinePage::MinePosting);
    addPage(MinePage::MineActivity);
    addPage(MinePage::InterestList);
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
    for(auto &iter : mButtonMap)
    {
        connect(iter,&BCPolymorphicButton::clicked,this,&BCMineWidget::slotMineButtonClicked);
    }
    connect(mMineInfoWidget,&BCMineInfoWidget::sigEditInfo,this,[this](){
        showPage(MinePage::EditMineInformation);
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
    case MinePage::InterestList:
    {
        mMineInterestListWidget = new BCListWidget(this);
        mStackedWidget->addWidget(mMineInterestListWidget);
        break;
    }
    }
}
