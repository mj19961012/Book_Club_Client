#ifndef BCLISTWIDGET_H
#define BCLISTWIDGET_H

#include <QListWidget>
#include <QMap>
#include <QScrollBar>
#include <QEvent>
#include <QMouseEvent>
#include <QResizeEvent>
#include "BCMessageEnumData.h"
#include "BCCommonEnumData.h"

class BCListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit BCListWidget(QWidget *parent = nullptr);
    void addListItem(ListItem::BCListWidgetType type);
    void setMessageChatListHasBeenRead();
    void setMessagePostingListHasBeenRead();

signals:
    void sigItemClicked();
//    void getPageValues(Page::BCPageEnum);
public slots:
//    void receiveOperationResult(bool isSuccess,Page::BCPageEnum pageEnum);
protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    void addPostingItem(const QString& id, const QString& name, const QString& content);

    void addPostingDetailItem(const QString &id);

    void addActivityItem(const QString &id, const QString& name, const QString& content,const QString& date,const QString& num);
    void addMinePostingItem(const QString &id,const QString& title,const QString& content,const QString& date);
    void addMineAvtivityItem(const QString &id,const QString& title,const QString& content,const QString& date);
    void addMineInterestItem(const QString &id,const QString& image,const QString& name);
    void addMessageChatItem(const QString &id,const QString& image,const QString& name,const QString& date,const QString& content);
    void addMessagePostingItem(const QString &id,const QString& title,const QString& date,const QString& content);

    void addMessageChatBubbleItem(const QString &id, const MessagePage::BCMessageBubbleEnum& isMe);
private:
    void clearData();
    void setMessageChatItemIsRead(QListWidgetItem* item);
    void setMessagePostingItemIsRead(QListWidgetItem* item);

private:
    QMap<QString,QListWidgetItem*> mListMap{};
    QSet<QString> mListSet{};
    QListWidgetItem *mCurrentItem{};
    ListItem::BCListWidgetType mCurrentItemType{};
};

#endif // BCLISTWIDGET_H
