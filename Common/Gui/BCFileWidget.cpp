#include "BCFileWidget.h"

BCFileWidget::BCFileWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
    initStyle();
}

void BCFileWidget::setIcon(const QString &icon)
{
    QPixmap pixmap;
    if(pixmap.load(icon))
    {
        mIconLabel->setScaledContents(true);
        mIconLabel->setPixmap(pixmap);
    }
}

void BCFileWidget::setText(const QString &text)
{
    mNameLabel->setText(text);
}

void BCFileWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCFileWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mIconLabel->setFixedSize(64,64);
    mNameLabel->setFixedSize(this->width(),this->height() - 64);
}

void BCFileWidget::init()
{
    mMainVLayout = new QVBoxLayout(this);

    mMainVLayout->setMargin(0);
    mMainVLayout->setSpacing(0);

    createIconWidget();
    mNameLabel = new BCPolymorphicLabel(this);

    mMainVLayout->addWidget(mIconWidget);
    mMainVLayout->addWidget(mNameLabel);

    setLayout(mMainVLayout);
}

void BCFileWidget::initStyle()
{
    mNameLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mNameLabel->setFontStyle(20);
}

void BCFileWidget::createIconWidget()
{
    mIconWidget = new QWidget(this);
    mIconHLayout = new QHBoxLayout(mIconWidget);
    mIconHLayout->setMargin(0);
    mIconHLayout->setSpacing(0);

    mIconLabel = new BCPolymorphicLabel(this);

    mIconHLayout->addWidget(mIconLabel);

    mIconWidget->setLayout(mIconHLayout);
}
