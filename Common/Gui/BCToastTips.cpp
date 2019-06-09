#include "BCToastTips.h"
#include "BCMainWindow.h"
#include "BCPolymorphicLabel.h"
#include <QDebug>
#include <QPainter>
#include <iomanip>

BCToastTips *BCToastTips::sMessageTips = nullptr;

BCToastTips &BCToastTips::Instance()
{
    if(!sMessageTips)
    {
        sMessageTips = new BCToastTips(BCMainWindow::instance());
    }
    return *sMessageTips;
}

void BCToastTips::setToastTip(QString strMessage, QColor backgroundColor, double opacity, int durationSeconds)
{
    if(!(strMessage.count() > 0))
    {
        return;
    }

    setVisible(false);
    mMessageText = strMessage;
    mBackgroundColor = backgroundColor;
    mOpacity = opacity;

    mMessageLabel->setStyle("transparent","white",Qt::AlignCenter);
    mMessageLabel->setFontStyle(28,63);

    mMessageLabel->setText(mMessageText);
    mMessageLabel->adjustSize();

    this->setMinimumSize(mMessageLabel->width() + 36,
                         mMessageLabel->height() + 60);

    update();

    this->adjustSize();
    this->move(parentWidget()->width()/2 - this->width()/2,
               parentWidget()->height()/2 - this->height()/2);

    setVisible(true);

    mOpacityPropertyAnimation->setDuration(durationSeconds);
    mOpacityPropertyAnimation->start(QPropertyAnimation::KeepWhenStopped);
}

void BCToastTips::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(mBackgroundColor);
    painter.setOpacity(mOpacity);
    painter.drawRoundedRect(0,0,this->width(),this->height(),12,12,Qt::AbsoluteSize);
}

BCToastTips::BCToastTips(QWidget *parent)
    :QWidget(parent)
    ,mBackgroundColor("")
    ,mOpacity(0.7)
{
    init();
    initConnect();
}

void BCToastTips::init()
{
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("QWidget{background:transparent;}");

    mMainHBoxLayout = new QHBoxLayout(this);

    mMessageLabel = new BCPolymorphicLabel(this);

    mMainHBoxLayout->setContentsMargins(18,30,18,30);
    mMainHBoxLayout->setSpacing(0);

    mMainHBoxLayout->addWidget(mMessageLabel);

    this->setLayout(mMainHBoxLayout);

    mOpacityGraphicsOpacityEffect = new QGraphicsOpacityEffect(this);
    this->setGraphicsEffect(mOpacityGraphicsOpacityEffect);

    mOpacityPropertyAnimation = new QPropertyAnimation(mOpacityGraphicsOpacityEffect,"opacity",this);

    //淡入淡出效果
    mOpacityPropertyAnimation->setKeyValueAt(0, 0);
    mOpacityPropertyAnimation->setKeyValueAt(0.1, 0.5);
    mOpacityPropertyAnimation->setKeyValueAt(0.2, 1);
    mOpacityPropertyAnimation->setKeyValueAt(0.3, 1);
    mOpacityPropertyAnimation->setKeyValueAt(0.5, 0.9);
    mOpacityPropertyAnimation->setKeyValueAt(0.7, 0.6);
    mOpacityPropertyAnimation->setKeyValueAt(0.9, 0.3);
    mOpacityPropertyAnimation->setKeyValueAt(1, 0);
}

void BCToastTips::initConnect()
{
    connect(mOpacityPropertyAnimation,&QPropertyAnimation::finished,this,&QWidget::hide,Qt::UniqueConnection);
}
