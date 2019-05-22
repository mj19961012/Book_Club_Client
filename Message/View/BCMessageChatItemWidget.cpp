#include "BCMessageChatItemWidget.h"
#include <QPainter>

BCMessageChatItemWidget::BCMessageChatItemWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
}

void BCMessageChatItemWidget::initData()
{
    setHeadImage(":/res/common/defaultHeadImage.png");
    setName(u8"私信消息");
    setDate(u8"2019-05-20");
    setContent(u8"私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息私信消息");
    setIsRead(false);
}

void BCMessageChatItemWidget::setIsRead(const bool &isRead)
{
    mIsRead = isRead;
    update();
}

void BCMessageChatItemWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.setOpacity(0.1);
    painter.drawRoundedRect(0,0,this->width(),this->height(),20,20,Qt::AbsoluteSize);

    if(mIsRead)
    {
        painter.setBrush(QColor(Qt::transparent));
    }
    else
    {
        painter.setBrush(QColor(232,0,12));
        painter.setOpacity(1);
    }
    painter.drawRoundedRect(15,15,16,16,8,8,Qt::AbsoluteSize);
}

void BCMessageChatItemWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mMainHLayout->setContentsMargins(30,20,30,20);
    mMainHLayout->setSpacing(20);
    mRightVLayout->setMargin(0);
    mRightVLayout->setSpacing(0);
    mRightTopHLayout->setMargin(0);
    mRightTopHLayout->setSpacing(0);

    initStyle();
}

void BCMessageChatItemWidget::init()
{
    mMainHLayout = new QHBoxLayout(this);

    mHeadImageLabel = new BCPolymorphicLabel(this);
    createRightWidget();

    mMainHLayout->addWidget(mHeadImageLabel);
    mMainHLayout->addWidget(mRightWidget);

    setLayout(mMainHLayout);
}

void BCMessageChatItemWidget::createRightWidget()
{
    mRightWidget = new QWidget(this);
    mRightVLayout = new QVBoxLayout(mRightWidget);

    createRightTopWidget();
    mContentLabel = new BCPolymorphicLabel(mRightWidget);

    mRightVLayout->addWidget(mRightTopWidget);
    mRightVLayout->addWidget(mContentLabel);

    mRightWidget->setLayout(mRightVLayout);
}

void BCMessageChatItemWidget::createRightTopWidget()
{
    mRightTopWidget = new QWidget(this);
    mRightTopHLayout = new QHBoxLayout(mRightTopWidget);

    mNameLabel = new BCPolymorphicLabel(mRightTopWidget);
    mDateLabel = new BCPolymorphicLabel(mRightTopWidget);

    mRightTopHLayout->addWidget(mNameLabel);
    mRightTopHLayout->addStretch(0);
    mRightTopHLayout->addWidget(mDateLabel);

    mRightTopWidget->setLayout(mRightTopHLayout);
}

void BCMessageChatItemWidget::initStyle()
{
    mNameLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mNameLabel->setFontStyle(25,63);

    mDateLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignTop);
    mDateLabel->setFontStyle(15,25);

    mContentLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mContentLabel->setFontStyle(20,25);
    mContentLabel->setWordWrap(true);
}

void BCMessageChatItemWidget::setHeadImage(const QString &image)
{
    QPixmap pixmap;
    if(pixmap.load(image))
    {
        mHeadImageLabel->setPixmap(pixmap.scaled(100,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }
}

void BCMessageChatItemWidget::setName(const QString &name)
{
    mNameLabel->setText(name);
    mNameLabel->adjustSize();
}

void BCMessageChatItemWidget::setDate(const QString &date)
{
    mDateLabel->setText(date);
    mDateLabel->adjustSize();
}

void BCMessageChatItemWidget::setContent(const QString &content)
{
    mContentLabel->setText(content);
}
