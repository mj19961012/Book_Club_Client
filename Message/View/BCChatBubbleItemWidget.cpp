#include "BCChatBubbleItemWidget.h"

BCChatBubbleItemWidget::BCChatBubbleItemWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
}

void BCChatBubbleItemWidget::initData(const MessagePage::BCMessageBubbleEnum &isMeEnum)
{
    setFriendImageView("http://192.168.1.3:8123/./static/1558976068.jpeg");
    setMyImageView("http://192.168.1.3:8123/./static/1558976068.jpeg");
    setMessage(QStringLiteral("啦啦啦"));

    if(MessagePage::Friend == isMeEnum)
    {
        if(mMessageWidget->isVisible())
            mMainHLayout->removeWidget(mMessageWidget);
        if(mMyImageWidget->isVisible())
            mMainHLayout->removeWidget(mMyImageWidget);

        mFriendImageWidget->setVisible(true);
        mMyImageWidget->setVisible(false);

        mMainHLayout->addWidget(mFriendImageWidget);
        mMainHLayout->addWidget(mMessageWidget);
        mMainHLayout->addStretch(0);
    }
    else if (MessagePage::Mine == isMeEnum)
    {
        if(mMessageWidget->isVisible())
            mMainHLayout->removeWidget(mMessageWidget);
        if(mFriendImageWidget->isVisible())
            mMainHLayout->removeWidget(mFriendImageWidget);

        mFriendImageWidget->setVisible(false);
        mMyImageWidget->setVisible(true);

        mMainHLayout->addStretch(0);
        mMainHLayout->addWidget(mMessageWidget);
        mMainHLayout->addWidget(mMyImageWidget);
    }

    initGeometry();
}

int BCChatBubbleItemWidget::getMessageHeight() const
{
    return mMessageLabel->height();
}

void BCChatBubbleItemWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCChatBubbleItemWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    initGeometry();
}

void BCChatBubbleItemWidget::init()
{
    mMainHLayout = new QHBoxLayout(this);

    createFriendImageWidget();
    createMyImageWidget();
    createMessageWidget();

    this->setLayout(mMainHLayout);
}

void BCChatBubbleItemWidget::initStyle()
{
    mMessageLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter,25);
    mMessageLabel->setFontStyle(20);

    mMessageWidget->setObjectName("mMessageWidget");
    mMessageWidget->setStyleSheet("QWidget#mMessageWidget{"
                                  "background-color:rgba(247,187,100,50);"
                                  "border-radius:25px;"
                                  "}");
}

void BCChatBubbleItemWidget::initGeometry()
{
    mMainHLayout->setMargin(20);
    mMainHLayout->setSpacing(10);

    mMessageHLayout->setMargin(20);
    mMessageHLayout->setSpacing(0);

    mFriendImageVLayout->setMargin(0);
    mFriendImageVLayout->setSpacing(0);

    mMyImageVLayout->setMargin(0);
    mMyImageVLayout->setSpacing(0);

    mFriendImageWidget->setFixedWidth(60);
    mMyImageWidget->setFixedWidth(60);
    mMessageWidget->setMinimumSize(mMessageLabel->width() + 40,mMessageLabel->height() + 20);

    mFriendImageView->setFixedSize(60,60);
    mMyImageView->setFixedSize(60,60);

    initStyle();
}

void BCChatBubbleItemWidget::createFriendImageWidget()
{
    mFriendImageWidget = new QWidget(this);
    mFriendImageVLayout = new QVBoxLayout(mFriendImageWidget);

    mFriendImageView = new BCImageView(mFriendImageWidget);

    mFriendImageVLayout->addWidget(mFriendImageView);
    mFriendImageVLayout->addStretch(0);

    mFriendImageWidget->setLayout(mFriendImageVLayout);
}

void BCChatBubbleItemWidget::createMyImageWidget()
{
    mMyImageWidget = new QWidget(this);
    mMyImageVLayout = new QVBoxLayout(mMyImageWidget);

    mMyImageView = new BCImageView(mMyImageWidget);

    mMyImageVLayout->addWidget(mMyImageView);
    mMyImageVLayout->addStretch(0);

    mMyImageWidget->setLayout(mMyImageVLayout);
}

void BCChatBubbleItemWidget::createMessageWidget()
{
    mMessageWidget = new QWidget(this);
    mMessageHLayout = new QHBoxLayout(mMessageWidget);

    mMessageLabel = new BCPolymorphicLabel(mMessageWidget);

    mMessageHLayout->addWidget(mMessageLabel);

    mMessageWidget->setLayout(mMessageHLayout);
}

void BCChatBubbleItemWidget::setFriendImageView(const QString &image)
{
    mFriendImageView->setImage(image);
}

void BCChatBubbleItemWidget::setMyImageView(const QString &image)
{
    mMyImageView->setImage(image);
}

void BCChatBubbleItemWidget::setMessage(const QString &message)
{
    mMessageLabel->setWordWrap(true);
    mMessageLabel->setText(message);
    mMessageLabel->adjustSize();
}
