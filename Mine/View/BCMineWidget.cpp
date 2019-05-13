#include "BCMineWidget.h"

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
        break;
    case MinePage::EditMineInformation:
        break;
    case MinePage::MinePosting:
        break;
    case MinePage::MineActivity:
        break;
    case MinePage::InterestList:
        break;
    }
}

void BCMineWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCMineWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mMineInfoButton->setGeometry(0,50,this->width()/4,60);
    mMinePostingButton->setGeometry(mMineInfoButton->pos().x() + mMineInfoButton->width(),50,
                                       this->width()/4,60);
    mMineActivityButton->setGeometry(mMinePostingButton->pos().x() + mMinePostingButton->width(),50,
                                       this->width()/4,60);
    mInterestListButton->setGeometry(mMineActivityButton->pos().x() + mMineActivityButton->width(),50,
                                     this->width()/4,60);

    mStackedWidget->setGeometry(0,110,this->width(),this->height() - 110);

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
}

void BCMineWidget::addPage(MinePage::BCMinePageEnum page)
{
    switch(page)
    {
    case MinePage::MineInformation:
    {

//        mStackedWidget->addWidget(mLoginWidget);
        break;
    }
    case MinePage::EditMineInformation:
    {

//        mStackedWidget->addWidget(mMainWidget);
        break;
    }
    case MinePage::MinePosting:
    {

//        mStackedWidget->addWidget(mMainWidget);
        break;
    }
    case MinePage::MineActivity:
    {

//        mStackedWidget->addWidget(mMainWidget);
        break;
    }
    case MinePage::InterestList:
    {

//        mStackedWidget->addWidget(mMainWidget);
        break;
    }
    }
}
