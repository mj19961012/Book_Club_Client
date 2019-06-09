#include "BCPostingCommentItemWidget.h"
#include <QPainter>

BCPostingCommentItemWidget::BCPostingCommentItemWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
}

void BCPostingCommentItemWidget::initData(const QString &headImage, const QString &name, const QString &content, const QString &date)
{
    setHeadImage(headImage);
    setName(name);
    setDateTime(date);
    setContent(content);

    initGeometry();
}

void BCPostingCommentItemWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.setOpacity(0.1);
    painter.drawRoundedRect(0,0,this->width(),this->height(),20,20,Qt::AbsoluteSize);
}

void BCPostingCommentItemWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    initGeometry();
}

void BCPostingCommentItemWidget::init()
{
    mMainVLayout = new QVBoxLayout(this);

    mMainVLayout->setContentsMargins(30,20,30,20);
    mMainVLayout->setSpacing(15);

    createPropertyWidget();
    mContentLabel = new BCPolymorphicLabel(this);
    mContentLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignTop);

    mMainVLayout->addWidget(mPropertyWidget);
    mMainVLayout->addWidget(mContentLabel);

    this->setLayout(mMainVLayout);
}

void BCPostingCommentItemWidget::initGeometry()
{
    mPropertyWidget->setFixedHeight(40);
    mHeadImageLabel->setFixedSize(40,40);

    mNameLabel->setFixedHeight(40);
    mNameLabel->setFontStyle(25,63);
    mNameLabel->adjustSize();

    mDateTimeLabel->setFixedHeight(40);
    mDateTimeLabel->setFontStyle(15,25);

    mContentLabel->setFontStyle(15,25);
    mContentLabel->setWordWrap(true);
    mContentLabel->adjustSize();
}

void BCPostingCommentItemWidget::createPropertyWidget()
{
    mPropertyWidget = new QWidget(this);
    mPropertyHLayout = new QHBoxLayout(mPropertyWidget);

    mPropertyHLayout->setMargin(0);
    mPropertyHLayout->setSpacing(0);

    mHeadImageLabel = new BCPolymorphicLabel(mPropertyWidget);
    mNameLabel = new BCPolymorphicLabel(mPropertyWidget);
    mNameLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mDateTimeLabel = new BCPolymorphicLabel(mPropertyWidget);
    mDateTimeLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);

    mPropertyHLayout->addWidget(mHeadImageLabel);
    mPropertyHLayout->addWidget(mNameLabel);
    mPropertyHLayout->addStretch(0);
    mPropertyHLayout->addWidget(mDateTimeLabel);

    mPropertyWidget->setLayout(mPropertyHLayout);
}

void BCPostingCommentItemWidget::setHeadImage(const QString &image)
{
    mHeadImageLabel->setPixmap(QPixmap(image));
    mHeadImageLabel->setScaledContents(true);
}

void BCPostingCommentItemWidget::setName(const QString &name)
{
    mNameLabel->setText(name);
}

void BCPostingCommentItemWidget::setDateTime(const QString &dateTime)
{
    mDateTimeLabel->setText(dateTime);
}

void BCPostingCommentItemWidget::setContent(const QString &content)
{
    mContentLabel->setText(content);
}
