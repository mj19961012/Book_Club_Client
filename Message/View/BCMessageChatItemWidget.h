#ifndef BCMESSAGECHATITEMWIDGET_H
#define BCMESSAGECHATITEMWIDGET_H

#include <QWidget>
#include <QLayout>
#include "BCPolymorphicLabel.h"

class BCMessageChatItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCMessageChatItemWidget(QWidget *parent = nullptr);
    void initData();
    void setIsRead(const bool& isRead);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void createRightWidget();
    void createRightTopWidget();
    void initStyle();
    void setHeadImage(const QString& image);
    void setName(const QString& name);
    void setDate(const QString& date);
    void setContent(const QString& content);

private:
    BCPolymorphicLabel *mHeadImageLabel{};
    QWidget *mRightWidget{};

    QWidget *mRightTopWidget{};
    BCPolymorphicLabel *mContentLabel{};

    BCPolymorphicLabel *mNameLabel{};
    BCPolymorphicLabel *mDateLabel{};

    QHBoxLayout *mMainHLayout{};
    QVBoxLayout *mRightVLayout{};
    QHBoxLayout *mRightTopHLayout{};

private:
    bool mIsRead{true};
};

#endif // BCMESSAGECHATITEMWIDGET_H
