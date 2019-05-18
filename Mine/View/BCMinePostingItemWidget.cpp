#include "BCMinePostingItemWidget.h"
#include <QPainter>

BCMinePostingItemWidget::BCMinePostingItemWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
}

void BCMinePostingItemWidget::initData()
{
    setTitle(u8"人在塔在");
    setDate("2018-05-20");
    setContent(u8"啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦啦");
}

void BCMinePostingItemWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.setOpacity(0.1);
    painter.drawRoundedRect(0,0,this->width(),this->height(),20,20,Qt::AbsoluteSize);
}

void BCMinePostingItemWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    initStyle();
}

void BCMinePostingItemWidget::init()
{
    mMainVLayout = new QVBoxLayout(this);

    createTitleWidget();
    mContentLabel = new BCPolymorphicLabel(this);

    mMainVLayout->addWidget(mTitleWidget,1);
    mMainVLayout->addWidget(mContentLabel,6);

    this->setLayout(mMainVLayout);
}

void BCMinePostingItemWidget::createTitleWidget()
{
    mTitleWidget = new QWidget(this);
    mTitleHLayout = new QHBoxLayout();

    mTitleLabel = new BCPolymorphicLabel(this);
    mDateLabel = new BCPolymorphicLabel(this);

    mTitleHLayout->addWidget(mTitleLabel);
    mTitleHLayout->addStretch(0);
    mTitleHLayout->addWidget(mDateLabel);

    mTitleWidget->setLayout(mTitleHLayout);
}

void BCMinePostingItemWidget::initStyle()
{
    mTitleLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mTitleLabel->setFontStyle(25,63);

    mDateLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignTop);
    mDateLabel->setFontStyle(15,25);

    mContentLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mContentLabel->setFontStyle(20,25);
    mContentLabel->setWordWrap(true);
}

void BCMinePostingItemWidget::setTitle(const QString &title)
{
    mTitleLabel->setText(title);
    mTitleLabel->adjustSize();
}

void BCMinePostingItemWidget::setDate(const QString &date)
{
    mDateLabel->setText(date);
    mDateLabel->adjustSize();
}

void BCMinePostingItemWidget::setContent(const QString &content)
{
    mContentLabel->setText(content);
}
