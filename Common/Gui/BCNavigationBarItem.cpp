#include "BCNavigationBarItem.h"
#include "BCPolymorphicLabel.h"

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
    case NavigationBar::MineInfo:
        setIcon(QIcon(":/res/NavigationBar/mine.png"));
        setIconSize(QSize(55,55));
        setText(QStringLiteral("我的"));
        break;
    }
}

void BCNavigationBarItem::setIsSelected(bool isSelected)
{
    if(isSelected)
    {
        setStyleSheet(QString("QToolButton{"
                              "background-color: rgba(255,255,255,100);"
                              "}"
                              "QToolButton:hover{"
                              "background-color:transparent;"
                              "}"
                              "QToolButton:pressed{"
                              "background-color:transparent;"
                              "}"));
    }
    else
    {
        setStyleSheet(QString("QToolButton{"
                              "background-color:transparent;"
                              "}"
                              "QToolButton:hover{"
                              "background-color:transparent;"
                              "}"
                              "QToolButton:pressed{"
                              "background-color:transparent;"
                              "}"));
    }
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
