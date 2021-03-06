﻿#include "BCPostingWidget.h"

#include <QDebug>

#include "BCMainWindow.h"
#include "BCCommonEnumData.h"
#include "../Common/Gui/BCToastTips.h"
#include "BCDataManager.h"
#include "BCMessageManager.h"


BCPostingWidget::BCPostingWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initStyle();
    initConnect();
    setButtonText();

    initData();
}

void BCPostingWidget::receiveOperationResult(bool isSuccess, Page::BCPageEnum pageEnum)
{
    qDebug() << "BCPostingWidget::receiveOperationResult" << "\n";
    switch (pageEnum)
    {
        case Page::Postings:
        {
            if(!isSuccess)
            {
                QString errorMsg = BCDataManager::instance().getErrorMsg();
                BCToastTips::Instance().setToastTip(errorMsg);
                return;
            }
            mPostingListWidget->addListItem(ListItem::Posting);
            break;
        }
        case Page::PostDetail:
        {
            if(!isSuccess)
            {
                QString errorMsg = BCDataManager::instance().getErrorMsg();
                BCToastTips::Instance().setToastTip(errorMsg);
                return;
            }
            BCMainWindow::instance()->showPage(Page::PostDetail);
            break;
        }
    }
}

void BCPostingWidget::initData()
{
    mPostingListWidget->addListItem(ListItem::Posting);
}

void BCPostingWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCPostingWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mAddPostingsButton->setGeometry(75,20,200,50);

    for(auto iter = mSubjectButtonMap.begin(); iter != mSubjectButtonMap.end(); iter++)
    {
        iter.value()->setFixedSize(100,40);
        mSubjectButtonMap.value(iter.key())->move(75 + (iter.key() - 1)*(iter.value()->width() + 5),100);
    }

    mPostingListWidget->setGeometry(75,150,this->width() - 150,this->height() - 150);

    initStyle();
}

void BCPostingWidget::slotSubjectBtnClicked()
{
    for(auto iter = mSubjectButtonMap.begin(); iter != mSubjectButtonMap.end(); iter++)
    {
        if(sender() == iter.value())
        {
            iter.value()->setColorStyle("transparent","transparent","transparent","transparent",
                                        "rgb(247,187,100)",1,"rgb(247,187,100)",20);
//            auto parametes = BCDataManager::instance().getUpLoadPostings();
//            parametes.type = iter.key();
            BCDataManager::instance().setUpLoadPostings(iter.key());
            emit getPostingList(Page::Postings);
        }
        else
        {
            iter.value()->setColorStyle("transparent","transparent","transparent","transparent",
                                        "rgb(51,51,51)",1,"rgb(51,51,51)",20);
        }
    }
}

void BCPostingWidget::init()
{
    mAddPostingsButton = new BCPolymorphicButton(this);

    for(int i = 1; i <= 14; i++)
    {
        BCPolymorphicButton *button = new BCPolymorphicButton(this);
        connect(button,&BCPolymorphicButton::clicked,this,&BCPostingWidget::slotSubjectBtnClicked);
        mSubjectButtonMap[i] = button;
    }

    mPostingListWidget = new BCListWidget(this);
}

void BCPostingWidget::initStyle()
{
    mAddPostingsButton->setColorStyle("rgba(247,187,100,1)",
                                      "rgba(247,187,100,0.8)",
                                      "rgba(247,187,100,1)",
                                      "rgba(247,187,100,1)",
                                      "white",0,"transparent",25);
    mAddPostingsButton->setFontStyle(25);
    mAddPostingsButton->setButtonText(QStringLiteral("发布帖子"));

    for(auto iter = mSubjectButtonMap.begin(); iter != mSubjectButtonMap.end(); iter++)
    {
        if(iter.key() == Subject::All)
        {
            iter.value()->setColorStyle("transparent","transparent","transparent","transparent",
                                        "rgb(247,187,100)",1,"rgb(247,187,100)",20);
        }
        else
        {
            iter.value()->setColorStyle("transparent","transparent","transparent","transparent",
                                        "rgb(51,51,51)",1,"rgb(51,51,51)",20);
        }
        iter.value()->setFontStyle(20);
    }
}

void BCPostingWidget::initConnect()
{
    connect(mAddPostingsButton,&BCPolymorphicButton::clicked,this,[](){
        BCMainWindow::instance()->showPage(Page::PublishPost);
    });
    connect(this,&BCPostingWidget::getPostingList,BCMessageManager::getInstance(),&BCMessageManager::getPageVlaues);
    connect(mPostingListWidget,&BCListWidget::getPageValues,BCMessageManager::getInstance(),&BCMessageManager::getPageVlaues);
    connect(BCMessageManager::getInstance(),&BCMessageManager::sendOperationResultSignal,this,&BCPostingWidget::receiveOperationResult);
}

void BCPostingWidget::setButtonText()
{
    for(auto iter = mSubjectButtonMap.begin(); iter != mSubjectButtonMap.end(); iter++)
    {
        switch(iter.key())
        {
        case Subject::All:
            iter.value()->setText(QStringLiteral("全部"));
            break;
        case Subject::Economics:
            iter.value()->setText(QStringLiteral("经济学"));
            break;
        case Subject::Law:
            iter.value()->setText(QStringLiteral("法学"));
            break;
        case Subject::Engineering:
            iter.value()->setText(QStringLiteral("工学"));
            break;
        case Subject::Pedagogy:
            iter.value()->setText(QStringLiteral("教育学"));
            break;
        case Subject::Literature:
            iter.value()->setText(QStringLiteral("文学"));
            break;
        case Subject::History:
            iter.value()->setText(QStringLiteral("历史学"));
            break;
        case Subject::Philosophy:
            iter.value()->setText(QStringLiteral("哲学"));
            break;
        case Subject::Science:
            iter.value()->setText(QStringLiteral("理学"));
            break;
        case Subject::Agronomy:
            iter.value()->setText(QStringLiteral("农学"));
            break;
        case Subject::ArtTheory:
            iter.value()->setText(QStringLiteral("艺术学"));
            break;
        case Subject::Management:
            iter.value()->setText(QStringLiteral("管理学"));
            break;
        case Subject::MilitaryScience:
            iter.value()->setText(QStringLiteral("军事学"));
            break;
        case Subject::Medicine:
            iter.value()->setText(QStringLiteral("医学"));
            break;
        }
    }
}
