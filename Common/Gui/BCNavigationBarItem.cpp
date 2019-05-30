#include "BCNavigationBarItem.h"
#include "BCPolymorphicLabel.h"
#include <QPainter>

BCNavigationBarItem::BCNavigationBarItem(QWidget *parent)
    :QToolButton(parent)
{
    init();
    initStyle();
}

void BCNavigationBarItem::setType(NavigationBar::BCNavigationBarEnum itemEnum)
{
    switch(itemEnum)
    {
    case NavigationBar::Postings:
        setIcon(QIcon(":/res/NavigationBar/postings.png"));
        setIconSize(QSize(55,55));
        setText(QStringLiteral("问答"));
        break;
    case NavigationBar::Activity:
        setIcon(QIcon(":/res/NavigationBar/activity.png"));
        setIconSize(QSize(55,55));
        setText(QStringLiteral("活动"));
        break;
    case NavigationBar::Message:
        setIcon(QIcon(":/res/NavigationBar/message.png"));
        setIconSize(QSize(55,55));
        setText(QStringLiteral("消息"));
        break;
    case NavigationBar::Search:
        setIcon(QIcon(":/res/NavigationBar/search.png"));
        setIconSize(QSize(55,55));
        setText(QStringLiteral("搜索"));
        break;
    case NavigationBar::PersonalInformation:
        setIcon(QIcon(":/res/NavigationBar/mine.png"));
        setIconSize(QSize(55,55));
        setText(QStringLiteral("我的"));
        break;
    }
}

void BCNavigationBarItem::setIsSelected(bool isSelected)
{
    mIsSelected = isSelected;
    update();
}

void BCNavigationBarItem::paintEvent(QPaintEvent *event)
{
    QToolButton::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(255,255,255));
    if(mIsSelected)
    {
        painter.setOpacity(0.5);
    }
    else
    {
        painter.setOpacity(0);
    }
    painter.drawRect(0,0,this->width(),this->height());
}

void BCNavigationBarItem::init()
{
    setCursor(Qt::PointingHandCursor);
    setFocusPolicy(Qt::NoFocus);
    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    setObjectName("BCNavigationBarItem");
    setStyleSheet(QString("QToolButton#BCNavigationBarItem{background:transparent; color:#2c2c2c;}"));
}

void BCNavigationBarItem::initStyle()
{
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setWeight(63);
    font.setPixelSize(25);

    setFont(font);
}
