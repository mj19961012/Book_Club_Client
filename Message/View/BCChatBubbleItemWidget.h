#ifndef BCCHATBUBBLEITEMWIDGET_H
#define BCCHATBUBBLEITEMWIDGET_H

#include <QWidget>
#include <QLayout>
#include "BCImageView.h"
#include "BCPolymorphicLabel.h"
#include "BCMessageEnumData.h"

class BCChatBubbleItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BCChatBubbleItemWidget(QWidget *parent = nullptr);
    void initData(const MessagePage::BCMessageBubbleEnum& isMeEnum,const QString& headImg,const QString &msg);
    int getMessageHeight() const;

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void init();
    void initStyle();
    void initGeometry();
    void createFriendImageWidget();
    void createMyImageWidget();
    void createMessageWidget();
    void setFriendImageView(const QString& image);
    void setMyImageView(const QString& image);
    void setMessage(const QString& message);

private:
    QWidget *mFriendImageWidget{};
    QWidget *mMyImageWidget{};
    QWidget *mMessageWidget{};

    BCImageView *mFriendImageView{};
    BCImageView *mMyImageView{};
    BCPolymorphicLabel *mMessageLabel{};

    QHBoxLayout *mMainHLayout{};
    QVBoxLayout *mFriendImageVLayout{};
    QVBoxLayout *mMyImageVLayout{};
    QHBoxLayout *mMessageHLayout{};
};

#endif // BCCHATBUBBLEITEMWIDGET_H
