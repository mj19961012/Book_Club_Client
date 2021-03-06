﻿#include "BCActivityWidget.h"
#include <QDateTime>
#include "BCMainWindow.h"
#include "BCMessageManager.h"
#include "BCDataManager.h"
#include "BCToastTips.h"

BCActivityWidget::BCActivityWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
    initStyle();
    initConnect();

    initData();
}

void BCActivityWidget::initData()
{
//    mActivityListWidget->addListItem(ListItem::Activity);
    auto user = BCDataManager::instance().getCurrentLoginUserInfo();
    QString begin = QString::number(QDateTime::currentDateTime().toTime_t() - 24 * 3600 * 3);
    QString end = QString::number(QDateTime::currentDateTime().toTime_t() + 24 * 3600 * 3);
    QString city = QString().fromStdString(user.getCity());
    city = "110000";
    mPageNum = 0;
    mPageSize = 20;
    BCDataManager::instance().setUpLoadActivity(begin,end,city,mPageNum,mPageSize);

    emit getActivitiesList(Page::BCPageEnum::Activity);
}

void BCActivityWidget::receiveOperationResult(bool isSuccess, Page::BCPageEnum pageEnum)
{
    qDebug() << "BCActivityWidget::receiveOperationResult" << "\n";
    switch (pageEnum)
    {
        case Page::Activity:
        {
            if(isSuccess)
            {
                mActivityListWidget->addListItem(ListItem::Activity);
//                BCMainWindow::instance()->showPage(Page::Activity);
            }
            else
            {
                QString errorMsg = BCDataManager::instance().getErrorMsg();
                BCToastTips::Instance().setToastTip(errorMsg);
            }
            break;
        }
        case Page::ActivityDetail:
        {
            if(!isSuccess)
            {
                QString errorMsg = BCDataManager::instance().getErrorMsg();
                BCToastTips::Instance().setToastTip(errorMsg);
                return;
            }
            BCMainWindow::instance()->showPage(Page::ActivityDetail);
            break;
        }
    }
}

void BCActivityWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCActivityWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mAddActivityButton->setGeometry(75,20,200,50);
    mSelectCityButton->setGeometry(75,90,700,50);
    mSelectDateButton->setGeometry(mSelectCityButton->pos().x() + mSelectCityButton->width() + 20,90,700,50);
    mActivityListWidget->setGeometry(75,150,this->width() - 150,this->height() - 150);
}

void BCActivityWidget::init()
{
    mAddActivityButton = new BCPolymorphicButton(this);
    mSelectCityButton = new BCCityButton(this);
    mSelectCityButton->initData(QStringLiteral("所在城市："));
    mSelectDateButton = new BCDateButton(this);
    mSelectDateButton->initData(QStringLiteral("按活动时间筛选："));
    mActivityListWidget = new BCListWidget(this);
}

void BCActivityWidget::initStyle()
{
    mAddActivityButton->setColorStyle("rgba(247,187,100,1)",
                                      "rgba(247,187,100,0.8)",
                                      "rgba(247,187,100,1)",
                                      "rgba(247,187,100,1)",
                                      "white",0,"transparent",25);
    mAddActivityButton->setFontStyle(25);
    mAddActivityButton->setButtonText(QStringLiteral("发布活动"));
}

void BCActivityWidget::initConnect()
{
    connect(mAddActivityButton,&BCPolymorphicButton::clicked,this,[](){
        BCMainWindow::instance()->showPage(Page::PublishActivity);
    });
    connect(this,&BCActivityWidget::getActivitiesList,BCMessageManager::getInstance(),&BCMessageManager::getPageVlaues);
    connect(mActivityListWidget,&BCListWidget::getPageValues,BCMessageManager::getInstance(),&BCMessageManager::getPageVlaues);
    connect(BCMessageManager::getInstance(),&BCMessageManager::sendOperationResultSignal,this,&BCActivityWidget::receiveOperationResult);
}
