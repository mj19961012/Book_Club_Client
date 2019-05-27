#ifndef BCLISTWIDGET_H
#define BCLISTWIDGET_H

#include <QListWidget>
#include <QMap>
#include <QScrollBar>
#include <QEvent>
#include <QMouseEvent>
#include <QResizeEvent>
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

protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    void addPostingItem(const QString& id, const QString& name, const QString& content);
    void addPostingDetailItem(const QString &id);
    void addActivityItem(const QString &id);
    void addMinePostingItem(const QString &id);
    void addMineAvtivityItem(const QString &id);
    void addMineInterestItem(const QString &id);
    void addMessageChatItem(const QString &id);
    void addMessagePostingItem(const QString &id);

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
