﻿#include "BCListWidget.h"
#include "BCPostingListItemWidget.h"
#include "BCActivityListItemWidget.h"
#include "BCMinePostingItemWidget.h"

BCListWidget::BCListWidget(QWidget *parent)
    :QListWidget (parent)
{
    this->setFocusPolicy(Qt::NoFocus);       // 去除item选中时的虚线边框
    this->setFrameShape(QListWidget::NoFrame);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//水平滚动条关闭
    this->setVerticalScrollMode(QListWidget::ScrollPerPixel);
    this->setViewMode(QListView::ListMode);
    this->setResizeMode(QListView::Adjust);
    this->setMovement(QListView::Static);
    this->setSpacing(5);
    this->setStyleSheet("QListWidget{"
                        "background-color: transparent;"
                        "padding:0px;"
                        "}"
                        "QListWidget:Item{"
                        "background-color: transparent;"
                        "}"
                        "QListWidget:Item:hover{"
                        "background-color: transparent;"
                        "}");

    this->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"
                                             "width:8px;"
                                             "background:rgba(0,0,0,0%);"
                                             "margin:0px,0px,0px,0px;"
                                             "padding-top:0px;"
                                             "padding-bottom:0px;"
                                             "}"
                                             "QScrollBar::handle:vertical{"
                                                 "width:8px;"
                                                 "background:rgba(0,0,0,0%);"
                                                 "border-radius:4px;"
                                                 "min-height:20;"
                                             "}"
                                             "QScrollBar::add-line:vertical{"
                                                                         "height:0px;width:0px;"
                                                                         "subcontrol-position:bottom;"
                                                                         "}"
                                             "QScrollBar::sub-line:vertical{"
                                                                         "height:0px;width:0px;"
                                                                         "subcontrol-position:top;"
                                                                         "}"
                                             );

    this->verticalScrollBar()->setRange(0,100);
    this->verticalScrollBar()->setSingleStep(15);
    this->verticalScrollBar()->setPageStep(15);
}

void BCListWidget::addListItem(ListItem::BCListWidgetType type)
{
    clearData();
    mCurrentItemType = type;

    switch(type)
    {
    case ListItem::Posting:
    {
        for(int i = 0; i < 20; i++)
        {
            addPostingItem(QString::number(i),QStringLiteral("帖子帖子帖子") + QString::number(i),QString::number(i) + QStringLiteral("、帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子"));
        }
        break;
    }
    case ListItem::Activity:
    {
        for(int i = 0; i < 20; i++)
        {
            addActivityItem(QString::number(i));
        }
        break;
    }
    case ListItem::MinePosting:
    {
        for(int i = 0; i < 20; i++)
        {
            addMinePostingItem(QString::number(i));
        }
        break;
    }
    case ListItem::MineAvtivity:
    {
        for(int i = 0; i < 20; i++)
        {
            addMineAvtivityItem(QString::number(i));
        }
        break;
    }
    case ListItem::MineInterest:
    {
        for(int i = 0; i < 20; i++)
        {
            addMineInterestItem(QString::number(i));
        }
        break;
    }
    }
}

void BCListWidget::addPostingItem(const QString &id, const QString &name, const QString &content)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCPostingListItemWidget *itemWidget = new BCPostingListItemWidget(this);

    itemWidget->initData(name,content);
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width(),150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addActivityItem(const QString &id)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCActivityListItemWidget *itemWidget = new BCActivityListItemWidget(this);

    itemWidget->initData();
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width(),200));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMinePostingItem(const QString &id)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCMinePostingItemWidget *itemWidget = new BCMinePostingItemWidget(this);

    itemWidget->initData();
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width(),150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMineAvtivityItem(const QString &id)
{

}

void BCListWidget::addMineInterestItem(const QString &id)
{

}

void BCListWidget::enterEvent(QEvent *event)
{
    QListWidget::enterEvent(event);
    this->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"
                                             "width:8px;"
                                             "background:rgba(0,0,0,0%);"
                                             "margin:0px,0px,0px,0px;"
                                             "padding-top:0px;"
                                             "padding-bottom:0px;"
                                             "}"
                                             "QScrollBar::handle:vertical{"
                                                 "width:8px;"
                                                 "background:rgba(0,0,0,50%);"
                                                 "border-radius:4px;"
                                                 "min-height:20;"
                                             "}"
                                             "QScrollBar::add-line:vertical{"
                                                                         "height:0px;width:0px;"
                                                                         "subcontrol-position:bottom;"
                                                                         "}"
                                             "QScrollBar::sub-line:vertical{"
                                                                         "height:0px;width:0px;"
                                                                         "subcontrol-position:top;"
                                                                         "}"
                                             );
}

void BCListWidget::leaveEvent(QEvent *event)
{
    QListWidget::leaveEvent(event);
    this->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"
                                             "width:8px;"
                                             "background:rgba(0,0,0,0%);"
                                             "margin:0px,0px,0px,0px;"
                                             "padding-top:0px;"
                                             "padding-bottom:0px;"
                                             "}"
                                             "QScrollBar::handle:vertical{"
                                                 "width:8px;"
                                                 "background:rgba(0,0,0,0%);"
                                                 "border-radius:4px;"
                                                 "min-height:20;"
                                             "}"
                                             "QScrollBar::add-line:vertical{"
                                                                         "height:0px;width:0px;"
                                                                         "subcontrol-position:bottom;"
                                                                         "}"
                                             "QScrollBar::sub-line:vertical{"
                                                                         "height:0px;width:0px;"
                                                                         "subcontrol-position:top;"
                                                                         "}"
                                             );
}

void BCListWidget::mousePressEvent(QMouseEvent *event)
{
    QListWidget::mousePressEvent(event);

    mCurrentItem = this->itemAt(mapFromGlobal(QCursor::pos()));//鼠标位置的Item，不管右键左键都获取

    if(event->button() == Qt::LeftButton && mCurrentItem != nullptr && mListSet.find(mListMap.key(mCurrentItem)) != mListSet.end())//如果点击的左键并且是点击的是主题
    {
        emit sigItemClicked();
    }
}

void BCListWidget::clearData()
{
    this->clear();
    mListMap.clear();
    mListSet.clear();
    mCurrentItem = nullptr;
}