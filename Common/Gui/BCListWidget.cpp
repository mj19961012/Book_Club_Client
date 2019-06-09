#include "BCListWidget.h"
#include <QDateTime>
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
#include "BCDataManager.h"
#include "BCToastTips.h"


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


//void BCListWidget::receiveOperationResult(bool isSuccess, Page::BCPageEnum pageEnum)
//{
//    switch (pageEnum)
//    {
//        case Page::Activity :
//            {
//                if(isSuccess)
//                {
//                    auto values = BCDataManager::instance().getBCActivitiesListMap();
//                    for(auto &value:values)
//                    {
//                        auto time = QDateTime::fromString(QString().fromStdString(value.getreleaseTime()),"yyyy-MM-dd").toString();
//                        addActivityItem(QString().fromStdString(value.getactionId()),QString().fromStdString(value.getactionTitle()),QString().fromStdString(value.getactionContent()),time,QString::number(value.getpageView()));
//                    }
//                }
//                else
//                {
//                    QString errorMsg = BCDataManager::instance().getErrorMsg();
//                    BCToastTips::Instance().setToastTip(errorMsg);
//                }
//                break;
//            }
//        default:
//        {
//            return;
//        }
//    }
//}
void BCListWidget::addListItem(ListItem::BCListWidgetType type)
{
    clearData();
    mCurrentItemType = type;

    switch(type)
    {
    case ListItem::Posting:
    {
        auto values = BCDataManager::instance().getBCPostingListMap();
        for(auto &value:values)
        {
//            addPostingItem(QString::number(i),QStringLiteral("帖子帖子帖子") + QString::number(i),QString::number(i) + QStringLiteral("、帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子帖子"));
            addPostingItem(QString().fromStdString(value.getarticleId()),QString().fromStdString(value.getarticleTitle()),QString().fromStdString(value.getarticleContent()));
        }
        break;
    }
    case ListItem::PostingDetail:
    {
        auto paramers = BCDataManager::instance().getUpLoadPostDetail();
        addPostingDetailItem(paramers.articleid);
        break;
    }
    case ListItem::Activity:
    {
        auto values = BCDataManager::instance().getBCActivitiesListMap();
        for(auto &value:values)
        {
            auto time = QDateTime::fromTime_t(QString::fromStdString(value.getreleaseTime()).toUInt()).toString("yyyy-MM-dd hh:mm:ss");
            addActivityItem(QString().fromStdString(value.getactionId()),QString().fromStdString(value.getactionTitle()),QString().fromStdString(value.getactionContent()),time,QString::number(value.getpageView()));
        }
        break;
    }
    case ListItem::MinePosting:
    {
        auto values = BCDataManager::instance().getCurrentCatchPostingList();
        for(auto &value:values)
        {
            auto time = QDateTime::fromTime_t(QString::fromStdString(value.getreleaseTime()).toUInt()).toString("yyyy-MM-dd hh:mm:ss");
            addMinePostingItem(QString().fromStdString(value.getarticleId()),QString().fromStdString(value.getarticleTitle()),QString().fromStdString(value.getarticleContent()),time);
        }
        break;
    }
    case ListItem::MineAvtivity:
    {
        auto values = BCDataManager::instance().getCurrentCatchActivitiesList();
        for(auto &value:values)
        {
            auto time = QDateTime::fromTime_t(QString::fromStdString(value.getreleaseTime()).toUInt()).toString("yyyy-MM-dd hh:mm:ss");
            addMineAvtivityItem(QString().fromStdString(value.getactionId()),QString().fromStdString(value.getactionTitle()),QString().fromStdString(value.getactionContent()),time);
        }
        break;
    }
    case ListItem::MineInterest:
    {
        auto values = BCDataManager::instance().getBCMineFocusListMap();

        for(auto &value:values)
        {
            auto user = BCDataManager::instance().getPersonalInformationWithId(value.getfollowerId().c_str());
            addMineInterestItem(QString().fromStdString(value.getinterestId()),QString().fromStdString(user.getheadImage()),QString().fromStdString(user.getnickName()));
        }
        break;
    }
    case ListItem::MessageChat:
    {
        auto values = BCDataManager::instance().getBCMessageListMap();
        auto user_mine = BCDataManager::instance().getCurrentLoginUserInfo();
        for(auto &value:values)
        {
            if(user_mine.getuserId() != value.getsenderId() && value.getmessageType() == 1)
            {
                auto user = BCDataManager::instance().getPersonalInformationWithId(value.getsenderId().c_str());
                addMessageChatItem(QString().fromStdString(value.getmessageId()),QString().fromStdString(user.getheadImage()),QString().fromStdString(user.getnickName()),QDateTime::fromString(value.getsendTime().c_str()).toString(),QString().fromStdString(value.getmessgaeBody()),value.getmessageState() == 0);
            }
        }
        break;
    }
    case ListItem::MessagePosting:
    {
        auto values = BCDataManager::instance().getBCMessageListMap();
        auto currentUser = BCDataManager::instance().getCurrentLoginUserInfo();
        for(auto &value:values)
        {
            if(value.getmessageType() != 1 && currentUser.getuserId() != value.getsenderId())
            {
                auto user = BCDataManager::instance().getPersonalInformationWithId(value.getsenderId().c_str());
                addMessagePostingItem(QString().fromStdString(value.getmessageId()),QString().fromStdString(user.getnickName()),QDateTime::fromString(value.getsendTime().c_str()).toString(),QString().fromStdString(value.getmessgaeBody()),value.getmessageState() == 0);
            }
        }
        break;
    }
    case ListItem::MessageChatBubble:
    {
        auto user_mine = BCDataManager::instance().getCurrentLoginUserInfo();
        auto chatInfo = BCDataManager::instance().getUpLoadChat();
        auto sessionUser = BCDataManager::instance().getPersonalInformationWithId(chatInfo.accepterid);
        auto values = BCDataManager::instance().getBCMessageListMap(QString().fromStdString(user_mine.getuserId()));
        qDebug() << "ListItem::MessageChatBubble_count:" << values.count() << "\n";
        for(auto &value:values)
        {
            if(user_mine.getuserId() == value.getsessionId() && user_mine.getuserId() == value.getaccepterId())
            {
                addMessageChatBubbleItem(QString().fromStdString(value.getmessageId()),MessagePage::Friend,QString().fromStdString(sessionUser.getheadImage()),QString().fromStdString(value.getmessgaeBody()));
            }
            if(user_mine.getuserId() == value.getsenderId() && sessionUser.getuserId() == value.getaccepterId())
            {
                addMessageChatBubbleItem(QString().fromStdString(value.getmessageId()),MessagePage::Mine,QString().fromStdString(user_mine.getheadImage()),QString().fromStdString(value.getmessgaeBody()));
            }
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
            auto message = BCDataManager::instance().getBCMessageInfoWithId(mListMap.key(mCurrentItem));
            auto user = BCDataManager::instance().getCurrentLoginUserInfo();
            auto messages = BCDataManager::instance().getBCMessageListMap(QString().fromStdString(message.getsessionId()));
            for(auto&msg : messages)
            {
                msg.setmessageState(0);
            }
            BCDataManager::instance().setBCMessageListMap(messages);
            BCDataManager::instance().setUpLoadChat(QString().fromStdString(user.getuserId()),QString().fromStdString(message.getsenderId()));
            BCDataManager::instance().setUploadChangeMessageStatus(QString().fromStdString(message.getsessionId()),QString().fromStdString(message.getsenderId()),message.getmessageType());
            emit getPageValues(Page::BCPageEnum::ChangeMessageStatus);
            BCMainWindow::instance()->showPage(Page::Chat);
//            emit getPageValues(Page::BCPageEnum::Message);
        }
        else if(ListItem::MessagePosting == mCurrentItemType)
        {
            setMessagePostingItemIsRead(mCurrentItem);
            auto message = BCDataManager::instance().getBCMessageInfoWithId(mListMap.key(mCurrentItem));
            auto messages = BCDataManager::instance().getBCMessageListMap(QString().fromStdString(message.getsessionId()));
            for(auto&msg : messages)
            {
                msg.setmessageState(0);
            }
            BCDataManager::instance().setBCMessageListMap(messages);
            BCDataManager::instance().setUpLoadPostDetail(QString().fromStdString(message.getsessionId()));
            BCDataManager::instance().setUploadChangeMessageStatus(QString().fromStdString(message.getsessionId()),QString().fromStdString(message.getsenderId()),message.getmessageType());
            emit getPageValues(Page::BCPageEnum::ChangeMessageStatus);
            emit getPageValues(Page::BCPageEnum::PostDetail);
        }
        else if(ListItem::Posting == mCurrentItemType)
        {
            BCDataManager::instance().setUpLoadPostDetail(mListMap.key(mCurrentItem));
            emit getPageValues(Page::BCPageEnum::PostDetail);
        }
        else if(ListItem::Activity == mCurrentItemType)
        {
            BCDataManager::instance().setUpLoadActivityDetail(mListMap.key(mCurrentItem));
            BCMainWindow::instance()->showPage(Page::ActivityDetail);
            emit getPageValues(Page::BCPageEnum::ActivityDetail);
        }
//        else if(ListItem::MessageChatBubble == mCurrentItemType)
//        {
//            clearData();
//            for(int i = 0; i < 20; i++)
//            {
//                addMessageChatBubbleItem(QString::number(i),MessagePage::Mine);
//            }
//        }
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
    qDebug()<< "BCListWidget_addPostingDetailItemId:" << id << "\n";
    //详情item
    BCPostingDetailItemWidget *itemWidget = new BCPostingDetailItemWidget(this);
    itemWidget->initData(id);
    itemWidget->setMaximumWidth(1400);
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();
    itemWidget->setListWidgetItem(listItem);
    listItem->setSizeHint(QSize(1400,itemWidget->height()));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);
    auto commentList = BCDataManager::instance().getBCCommentListMap(id);
    //评论item
    for(auto & comment : commentList)
    {
        QString commentId = QString().fromStdString(comment.getmessageId());

        if(mListSet.find(commentId) != mListSet.end())
        {
            return;
        }
        mListSet.insert(commentId);

        BCPostingCommentItemWidget *commentItemWidget = new BCPostingCommentItemWidget(this);

        auto user = BCDataManager::instance().getPersonalInformationWithId(QString().fromStdString(comment.getsenderId()));

        commentItemWidget->initData(QString().fromStdString(user.getheadImage()),QString().fromStdString(user.getnickName()),QString().fromStdString(comment.getmessgaeBody()),QDateTime::fromTime_t(QString().fromStdString(comment.getsendTime()).toUInt()).toString("yyyy-MM-dd hh:mm:ss"));
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

void BCListWidget::addActivityItem(const QString &id, const QString& name, const QString& content,const QString& date,const QString& num)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCActivityListItemWidget *itemWidget = new BCActivityListItemWidget(this);

    itemWidget->initData(name,content,date,num);
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width() - 20,200));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMinePostingItem(const QString &id,const QString& title,const QString& content,const QString& date)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCMinePostingItemWidget *itemWidget = new BCMinePostingItemWidget(this);

    itemWidget->initData(title,content,date);
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width() - 20,150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMineAvtivityItem(const QString &id,const QString& title,const QString& content,const QString& date)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCMineActivityItemWidget *itemWidget = new BCMineActivityItemWidget(this);

    itemWidget->initData(title,content,date);
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width() - 20,150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMineInterestItem(const QString &id,const QString& image,const QString& name)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCMineInterestItemWidget *itemWidget = new BCMineInterestItemWidget(this);

    itemWidget->initData(image,name);
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width() - 20,150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMessageChatItem(const QString &id, const QString& image, const QString& name, const QString& date, const QString& content, const bool isRead)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCMessageChatItemWidget *itemWidget = new BCMessageChatItemWidget(this);

    itemWidget->initData(image,name,date,content,isRead);
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width() - 20,150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMessagePostingItem(const QString &id,const QString& title,const QString& date,const QString& content,const bool isRead)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCMessagePostingItemWidget *itemWidget = new BCMessagePostingItemWidget(this);

    itemWidget->initData(title,date,content,isRead);
    itemWidget->adjustSize();

    QListWidgetItem *listItem = new QListWidgetItem();

    listItem->setSizeHint(QSize(this->width() - 20,150));
    this->insertItem(this->count(),listItem);
    this->setItemWidget(listItem, itemWidget);
    mListMap.insert(id,listItem);

    update();
}

void BCListWidget::addMessageChatBubbleItem(const QString &id, const MessagePage::BCMessageBubbleEnum &isMe,const QString& image,const QString& content)
{
    if(mListSet.find(id) != mListSet.end())
    {
        return;
    }
    mListSet.insert(id);

    BCChatBubbleItemWidget *itemWidget = new BCChatBubbleItemWidget(this);

    itemWidget->initData(isMe,image,content);
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
