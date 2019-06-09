#include "BCMessagePostingItemWidget.h"
#include <QPainter>

BCMessagePostingItemWidget::BCMessagePostingItemWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
}

void BCMessagePostingItemWidget::initData(const QString& title,const QString& date,const QString& content,const bool isRead)
{
    setTitle(title);
    setDate(date);
    setContent(content);
    setIsRead(isRead);
}

void BCMessagePostingItemWidget::setIsRead(const bool &isRead)
{
    mIsRead = isRead;
    update();
}

void BCMessagePostingItemWidget::paintEvent(QPaintEvent *event)
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

void BCMessagePostingItemWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mMainVLayout->setContentsMargins(40,20,40,20);
    mMainVLayout->setSpacing(20);

    mTitleHLayout->setMargin(0);
    mTitleHLayout->setSpacing(0);

    initStyle();
}

void BCMessagePostingItemWidget::init()
{
    mMainVLayout = new QVBoxLayout(this);

    createTitleWidget();
    mContentLabel = new BCPolymorphicLabel(this);

    mMainVLayout->addWidget(mTitleWidget,1);
    mMainVLayout->addWidget(mContentLabel,6);

    this->setLayout(mMainVLayout);
}

void BCMessagePostingItemWidget::createTitleWidget()
{
    mTitleWidget = new QWidget(this);
    mTitleHLayout = new QHBoxLayout(mTitleWidget);

    mTitleLabel = new BCPolymorphicLabel(mTitleWidget);
    mDateLabel = new BCPolymorphicLabel(mTitleWidget);

    mTitleHLayout->addWidget(mTitleLabel);
    mTitleHLayout->addStretch(0);
    mTitleHLayout->addWidget(mDateLabel);

    mTitleWidget->setLayout(mTitleHLayout);
}

void BCMessagePostingItemWidget::initStyle()
{
    mTitleLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mTitleLabel->setFontStyle(25,63);

    mDateLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignTop);
    mDateLabel->setFontStyle(15,25);

    mContentLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mContentLabel->setFontStyle(20,25);
    mContentLabel->setWordWrap(true);
}

void BCMessagePostingItemWidget::setTitle(const QString &title)
{
    mTitleLabel->setText(title);
    mTitleLabel->adjustSize();
}

void BCMessagePostingItemWidget::setDate(const QString &date)
{
    mDateLabel->setText(date);
    mDateLabel->adjustSize();
}

void BCMessagePostingItemWidget::setContent(const QString &content)
{
    mContentLabel->setText(content);
}
