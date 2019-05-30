#ifndef BCMESSAGECHATWIDGET_H
#define BCMESSAGECHATWIDGET_H

#include <QWidget>
#include "BCPolymorphicLabel.h"
#include "BCPolymorphicButton.h"
#include "BCListWidget.h"
#include "BCInputWidget.h"

class BCMessageChatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMessageChatWidget(QWidget *parent = nullptr);
    void initData();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initStyle();
    void initConnect();
    void setName(const QString& name);

private:
    BCPolymorphicButton *mBackButton{};
    BCPolymorphicLabel *mNameLabel{};
    BCListWidget *mChatListWidget{};
    BCInputWidget *mInputWidget{};
};

#endif // BCMESSAGECHATWIDGET_H
