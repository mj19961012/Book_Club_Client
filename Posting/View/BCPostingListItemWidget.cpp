#include "BCPostingListItemWidget.h"
#include <QPainter>

BCPostingListItemWidget::BCPostingListItemWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
}

void BCPostingListItemWidget::initData(const QString &name, const QString &content)
{
    setName(name);
    setContent(content);
}

void BCPostingListItemWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.setOpacity(0.1);
    painter.drawRoundedRect(0,0,this->width(),this->height(),20,20,Qt::AbsoluteSize);
}

void BCPostingListItemWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mMainVLayout->setContentsMargins(30,20,30,20);
    mMainVLayout->setSpacing(20);

    initStyle();
}

void BCPostingListItemWidget::init()
{
    mMainVLayout = new QVBoxLayout(this);

    mNameLabel = new BCPolymorphicLabel(this);
    mContentLabel = new BCPolymorphicLabel(this);

    mMainVLayout->addWidget(mNameLabel,1);
    mMainVLayout->addWidget(mContentLabel,6);

    this->setLayout(mMainVLayout);
}

void BCPostingListItemWidget::initStyle()
{
    mNameLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mNameLabel->setFontStyle(25,63);

    mContentLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignTop);
    mContentLabel->setFontStyle(20,25);
    mContentLabel->setWordWrap(true);
}

void BCPostingListItemWidget::setName(const QString &name)
{
    mNameLabel->setText(name);
}

void BCPostingListItemWidget::setContent(const QString &content)
{
    mContentLabel->setText(content);
}
