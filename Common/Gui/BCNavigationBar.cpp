#include "BCNavigationBar.h"
#include "BCPolymorphicLabel.h"
#include "BCPolymorphicButton.h"
#include "BCNavigationBarItem.h"
#include <QPainter>

BCNavigationBar::BCNavigationBar(QWidget *parent)
    :QWidget(parent)
{
    init();
    initStyle();
    initConnect();
}

void BCNavigationBar::setSelectItem(NavigationBar::BCNavigationBarEnum barEnum)
{
    switch(barEnum)
    {
    case NavigationBar::Postings:
        mPostingsItem->setIsSelected(true);
        mActivityItem->setIsSelected(false);
        mMessageItem->setIsSelected(false);
//        mSearchItem->setIsSelected(false);
        mMineInfoItem->setIsSelected(false);
        break;
    case NavigationBar::Activity:
        mPostingsItem->setIsSelected(false);
        mActivityItem->setIsSelected(true);
        mMessageItem->setIsSelected(false);
//        mSearchItem->setIsSelected(false);
        mMineInfoItem->setIsSelected(false);
        break;
    case NavigationBar::Message:
        mPostingsItem->setIsSelected(false);
        mActivityItem->setIsSelected(false);
        mMessageItem->setIsSelected(true);
//        mSearchItem->setIsSelected(false);
        mMineInfoItem->setIsSelected(false);
        break;
//    case NavigationBar::Search:
//        mPostingsItem->setIsSelected(false);
//        mActivityItem->setIsSelected(false);
//        mMessageItem->setIsSelected(false);
//        mSearchItem->setIsSelected(true);
//        mMineInfoItem->setIsSelected(false);
//        break;
    case NavigationBar::PersonalInformation:
        mPostingsItem->setIsSelected(false);
        mActivityItem->setIsSelected(false);
        mMessageItem->setIsSelected(false);
//        mSearchItem->setIsSelected(false);
        mMineInfoItem->setIsSelected(true);
        break;
    }
}

void BCNavigationBar::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.drawRect(0,0,this->width(),this->height());

    QPixmap pixmap;
    pixmap.load(":/res/common/start_logo.png");
    painter.drawPixmap(this->width()/2 - 100/2,50,100,100,pixmap.scaled(100,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}

void BCNavigationBar::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mBookClubLabel->setGeometry(0,150,this->width(),50);

    mPostingsItem->setGeometry(0,300,this->width(),100);
    mActivityItem->setGeometry(0,430,this->width(),100);
    mMessageItem->setGeometry(0,560,this->width(),100);
//    mSearchItem->setGeometry(0,690,this->width(),100);
    mMineInfoItem->setGeometry(0,690,this->width(),100);
//    mMineInfoItem->setGeometry(0,820,this->width(),100);
}

void BCNavigationBar::init()
{
    mBookClubLabel = new BCPolymorphicLabel(this);

    mPostingsItem = new BCNavigationBarItem(this);
    mPostingsItem->setType(NavigationBar::Postings);

    mActivityItem = new BCNavigationBarItem(this);
    mActivityItem->setType(NavigationBar::Activity);

    mMessageItem = new BCNavigationBarItem(this);
    mMessageItem->setType(NavigationBar::Message);

//    mSearchItem = new BCNavigationBarItem(this);
//    mSearchItem->setType(NavigationBar::Search);

    mMineInfoItem = new BCNavigationBarItem(this);
    mMineInfoItem->setType(NavigationBar::PersonalInformation);

    setSelectItem(NavigationBar::Postings);
}

void BCNavigationBar::initStyle()
{
    mBookClubLabel->setStyle("transparent","rgb(255,255,255)",Qt::AlignCenter);
    mBookClubLabel->setFontStyle(30,25);
    mBookClubLabel->setText(QStringLiteral("知友"));
}

void BCNavigationBar::initConnect()
{
    connect(mPostingsItem,&BCNavigationBarItem::clicked,this,[this](){
        setSelectItem(NavigationBar::Postings);
        emit sigNavigationBarClicked(NavigationBar::Postings);
    });

    connect(mActivityItem,&BCNavigationBarItem::clicked,this,[this](){
        setSelectItem(NavigationBar::Activity);
        emit sigNavigationBarClicked(NavigationBar::Activity);
    });

    connect(mMessageItem,&BCNavigationBarItem::clicked,this,[this](){
        setSelectItem(NavigationBar::Message);
        emit sigNavigationBarClicked(NavigationBar::Message);
    });

//    connect(mSearchItem,&BCNavigationBarItem::clicked,this,[this](){
//        setSelectItem(NavigationBar::Search);
//        emit sigNavigationBarClicked(NavigationBar::Search);
//    });

    connect(mMineInfoItem,&BCNavigationBarItem::clicked,this,[this](){
        setSelectItem(NavigationBar::PersonalInformation);
        emit sigNavigationBarClicked(NavigationBar::PersonalInformation);
    });
}
