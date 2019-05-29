#include "BCListWidget.h"
#include "BCMainWindow.h"
#include "BCPostingListItemWidget.h"
#include "BCPostingDetailItemWidget.h"
#include "BCPostingCommentItemWidget.h"
#include "BCActivityListItemWidget.h"
#include "BCMinePostingItemWidget.h"
#include "BCMineActivityItemWidget.h"
#include "BCMineInterestItemWidget.h"
#include "BCMessageChatItemWidget.h"
#include "BCMessagePostingItemWidget.h"
#include "BCChatBubbleItemWidget.h"

BCListWidget::BCListWidget(QWidget *parent)
    :QListWidget(parent)
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
    case ListItem::PostingDetail:
    {
        addPostingDetailItem("-1");
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
    case ListItem::MessageChat:
    {
        for(int i = 0; i < 20; i++)
        {
            addMessageChatItem(QString::number(i));
        }
        break;
    }
    case ListItem::MessagePosting:
    {
        for(int i = 0; i < 20; i++)
        {
            addMessagePostingItem(QString::number(i));
        }
        break;
    }
    case ListItem::MessageChatBubble:
    {
        for(int i = 0; i < 20; i++)
        {
            addMessageChatBubbleItem(QString::number(i),MessagePage::Friend);
        }
        break;
    }
    }
}

void BCListWidget::setMessageChatListHasBeenRead()
{
    if(ListItem::MessageChat == mCurrentItemType)
    {
        for(auto &iter : mListMap)
        {
            static_cast<BCMessageChatItemWidget*>(this->itemWidget(iter))->setIsRead(true);
        }
    }
}

void BCListWidget::setMessagePostingListHasBeenRead()
{
    if(ListItem::MessagePosting == mCurrentItemType)
    {
        for(auto &iter : mListMap)
        {
            static_cast<BCMessagePostingItemWidget*>(this->itemWidget(iter))->setIsRead(true);
        }
    }
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
                                             "}");
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
                                             "}");
}

void BCListWidget::mousePressEvent(QMouseEvent *event)
{
    QListWidget::mousePressEvent(event);

    mCurrentItem = this->itemAt(mapFromGlobal(QCursor::pos()));//鼠标位置的Item，不管右键左键都获取

    if(event->button() == Qt::LeftButton && mCurrentItem != nullptr && mListSet.find(mListMap.key(mCurrentItem)) != mListSet.end())//如果点击的左键并且是点击的是主题
    {
        emit sigItemClicked();

        if(ListItem::MessageChat == mCurrentItemType)
        {
            setMessageChatItemIsRead(mCurrentItem);
            BCMainWindow::instance()->showPage(Page::Chat);
        }
        else if(ListItem::MessagePosting == mCurrentItemType)
        {
            setMessagePostingItemIsRead(mCurrentItem);
            BCMainWindow::instance()->showPage(Page::PostDetail);
        }
        else if(ListItem::Posting == mCurrentItemType)
        {
            BCMainWindow::instance()->showPage(Page::PostDetail);
        }
        else if(ListItem::Activity == mCurrentItemType)
        {
            BCMainWindow::instance()->showPage(Page::ActivityDetail);
        }
        else if(ListItem::MessageChatBubble == mCurrentItemType)
        {
            clearData();
            for(int i = 0; i < 20; i++)
            {
                addMessageChatBubbleItem(QString::number(i),MessagePage::Mine);
            }
        }
        else if(ListItem::MinePosting == mCurrentItemType)
        {
            BCMainWindow::instance()->showPage(Page::PostDetail);
        }
        else if(ListItem::MineAvtivity == mCurrentItemType)
        {
            BCMainWindow::instance()->showPage(Page::ActivityDetail);
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

    listItem->setSizeHint(QSize(this->width() - 20,150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addPostingDetailItem(const QString &id)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    //详情item
    BCPostingDetailItemWidget *itemWidget = new BCPostingDetailItemWidget(this);
    int a = itemWidget->height();
    itemWidget->initData(QStringLiteral("Qt内存管理机制：Qt Qt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：Qt"
                                        "Qt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：Qt"
                                        "Qt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：QtQt内存管理机制：Qt"
                                        "在内部能够维护对象的层次结构。对于可视元素，这种层次结构就是子组件与父组件的关系；对于非可视元素，则是一个对象与另一个对象的从属关系。在 Qt 中，在 Qt 中，删除父对象会将其子对象一起删除。"
                                        "C++中delete 和 new 必须配对使用(一 一对应)：delete少了，则内存泄露，多了麻烦更大。Qt中使用了new却很少delete，因为QObject的类及其继承的类，设置了parent（也可在构造时使用setParent函"
                                        "数或parent的addChild）故parent被delete时，这个parent的相关所有child都会自动delete，不用用户手动处理。但parent是不区分它的child是new出来的还是在栈上分配的。这体现delete的强大，可以"
                                        "释放掉任何的对象，而delete栈上对象就会导致内存出错，这需要了解Qt的半自动的内存管理。另一个问题：child不知道它自己是否被delete掉了，故可能会出现野指针。那就要了解Qt的智能指针QPointer。"));
    itemWidget->setMaximumWidth(1400);
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();
    itemWidget->setListWidgetItem(listItem);
    listItem->setSizeHint(QSize(1400,itemWidget->height()));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    //评论item
    for(int i = 0; i < 10; i++)
    {
        QString commentId = QString::number(i);

        if(mListSet.find(commentId) != mListSet.end())
        {
            return;
        }
        mListSet.insert(commentId);

        BCPostingCommentItemWidget *commentItemWidget = new BCPostingCommentItemWidget(this);
        commentItemWidget->initData();
        commentItemWidget->setMaximumWidth(1400);
        commentItemWidget->adjustSize();

        QListWidgetItem *commentListItem = new QListWidgetItem();
        commentListItem->setSizeHint(QSize(1400,commentItemWidget->height()));
        this->insertItem(this->count(),commentListItem);
        this->setItemWidget(commentListItem, commentItemWidget);
        mListMap.insert(commentId,commentListItem);
    }

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

    listItem->setSizeHint(QSize(this->width() - 20,200));
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

    listItem->setSizeHint(QSize(this->width() - 20,150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMineAvtivityItem(const QString &id)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCMineActivityItemWidget *itemWidget = new BCMineActivityItemWidget(this);

    itemWidget->initData();
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width() - 20,150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMineInterestItem(const QString &id)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCMineInterestItemWidget *itemWidget = new BCMineInterestItemWidget(this);

    itemWidget->initData();
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width() - 20,150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMessageChatItem(const QString &id)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCMessageChatItemWidget *itemWidget = new BCMessageChatItemWidget(this);

    itemWidget->initData();
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width() - 20,150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMessagePostingItem(const QString &id)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCMessagePostingItemWidget *itemWidget = new BCMessagePostingItemWidget(this);

    itemWidget->initData();
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width() - 20,150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMessageChatBubbleItem(const QString &id, const MessagePage::BCMessageBubbleEnum &isMe)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCChatBubbleItemWidget *itemWidget = new BCChatBubbleItemWidget(this);

    itemWidget->initData(isMe);
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width() - 20,itemWidget->height()));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::clearData()
{
    this->clear();
    mListMap.clear();
    mListSet.clear();
    mCurrentItem = nullptr;
}

void BCListWidget::setMessageChatItemIsRead(QListWidgetItem *item)
{
    static_cast<BCMessageChatItemWidget*>(this->itemWidget(item))->setIsRead(true);
}

void BCListWidget::setMessagePostingItemIsRead(QListWidgetItem *item)
{
    static_cast<BCMessagePostingItemWidget*>(this->itemWidget(item))->setIsRead(true);
}
