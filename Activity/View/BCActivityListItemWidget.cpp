#include "BCActivityListItemWidget.h"
#include <QPainter>

BCActivityListItemWidget::BCActivityListItemWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
}

void BCActivityListItemWidget::initData(const QString& name,const QString& content,const QString& date,const QString& num)
{
    setName(name);
    setContent(content);
    setDate(date);
    setWatchNum(num);
}

void BCActivityListItemWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.setOpacity(0.1);
    painter.drawRoundedRect(0,0,this->width(),this->height(),20,20,Qt::AbsoluteSize);
}

void BCActivityListItemWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mMainVLayout->setContentsMargins(30,20,30,20);
    mMainVLayout->setSpacing(20);

    mTipHLayout->setMargin(0);
    mTipHLayout->setSpacing(0);

    initStyle();
}

void BCActivityListItemWidget::init()
{
    mMainVLayout = new QVBoxLayout(this);

    mNameLabel = new BCPolymorphicLabel(this);
    mContentLabel = new BCPolymorphicLabel(this);
    createTipWidget();

    mMainVLayout->addWidget(mNameLabel,1);
    mMainVLayout->addWidget(mContentLabel,6);
    mMainVLayout->addWidget(mTipWidget,1);

    this->setLayout(mMainVLayout);
}

void BCActivityListItemWidget::initStyle()
{
    mNameLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mNameLabel->setFontStyle(25,63);

    mContentLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignTop);
    mContentLabel->setFontStyle(20,25);
    mContentLabel->setWordWrap(true);

    mDateLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mDateLabel->setFontStyle(15,25);

    mWatchNumLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignTop);
    mWatchNumLabel->setFontStyle(15,25);
}

void BCActivityListItemWidget::createTipWidget()
{
    mTipWidget = new QWidget(this);
    mTipHLayout = new QHBoxLayout();

    mDateLabel = new BCPolymorphicLabel(this);
    mWatchNumLabel = new BCPolymorphicLabel(this);

    mTipHLayout->addWidget(mDateLabel);
    mTipHLayout->addStretch(0);
    mTipHLayout->addWidget(mWatchNumLabel);

    mTipWidget->setLayout(mTipHLayout);
}

void BCActivityListItemWidget::setName(const QString &name)
{
    mNameLabel->setText(name);
}

void BCActivityListItemWidget::setContent(const QString &content)
{
    mContentLabel->setText(content);
}

void BCActivityListItemWidget::setDate(const QString &date)
{
    mDateLabel->setText(date);
    mDateLabel->adjustSize();
}

void BCActivityListItemWidget::setWatchNum(const QString &num)
{
    mWatchNumLabel->setText(num);
    mWatchNumLabel->adjustSize();
}
