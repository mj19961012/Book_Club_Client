#include "BCMineInterestItemWidget.h"
#include <QPainter>

BCMineInterestItemWidget::BCMineInterestItemWidget(QWidget *parent)
{
    init();
}

void BCMineInterestItemWidget::initData()
{
    setHeadImage(":/res/common/defaultHeadImage.png");
    setName(u8"我的关注");
}

void BCMineInterestItemWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.setOpacity(0.1);
    painter.drawRoundedRect(0,0,this->width(),this->height(),20,20,Qt::AbsoluteSize);
}

void BCMineInterestItemWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mMainHLayout->setContentsMargins(20,10,20,10);
    mMainHLayout->setSpacing(50);

    mHeadImageLabel->setFixedSize(100,100);
    mNameLabel->setFixedHeight(this->height() - 20);
    mEnterLabel->setFixedSize(100,100);

    initStyle();
}

void BCMineInterestItemWidget::init()
{
    mMainHLayout = new QHBoxLayout(this);

    mHeadImageLabel = new BCPolymorphicLabel(this);
    mNameLabel = new BCPolymorphicLabel(this);
    mEnterLabel = new BCPolymorphicLabel(this);

    mMainHLayout->addWidget(mHeadImageLabel);
    mMainHLayout->addWidget(mNameLabel);
    mMainHLayout->addStretch(0);
    mMainHLayout->addWidget(mEnterLabel);

    setLayout(mMainHLayout);
}

void BCMineInterestItemWidget::initStyle()
{
    mNameLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mNameLabel->setFontStyle(25,63);

    QPixmap pixmap;
    if(pixmap.load(":/res/Mine/enter.png"))
    {
        mEnterLabel->setPixmap(pixmap.scaled(64,64,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }
}

void BCMineInterestItemWidget::setHeadImage(const QString &image)
{
    QPixmap pixmap;
    if(pixmap.load(image))
    {
        mHeadImageLabel->setPixmap(pixmap.scaled(100,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }
}

void BCMineInterestItemWidget::setName(const QString &name)
{
    mNameLabel->setText(name);
    mNameLabel->adjustSize();
}
