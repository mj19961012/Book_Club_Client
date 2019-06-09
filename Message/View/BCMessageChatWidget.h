#ifndef BCMESSAGECHATWIDGET_H
#define BCMESSAGECHATWIDGET_H

#include <QWidget>
#include "BCPolymorphicLabel.h"
#include "BCPolymorphicButton.h"
#include "BCCommonEnumData.h"
#include "BCListWidget.h"
#include "BCInputWidget.h"

class BCMessageChatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMessageChatWidget(QWidget *parent = nullptr);
    void initData();
signals:
    void doSendMessage(Page::BCPageEnum);
public slots:
    void receiveOperationResult(bool isSuccess, Page::BCPageEnum pageEnum);
//    void onSubmitButtonClicked();
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
