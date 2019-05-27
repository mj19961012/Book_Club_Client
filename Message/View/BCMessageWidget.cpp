#include "BCMessageWidget.h"
#include "BCCommonEnumData.h"
#include <QPainter>

BCMessageWidget::BCMessageWidget(QWidget * parent)
    :QWidget (parent)
{
    init();
    initConnect();
}

void BCMessageWidget::showPage(MessagePage::BCMessagePageEnum page)
{
    switch(page)
    {
    case MessagePage::ChatList:
        mStackedWidget->setCurrentWidget(mChatListWidget);
        mChatListWidget->addListItem(ListItem::MessageChat);
        break;
    case MessagePage::PostingList:
        mStackedWidget->setCurrentWidget(mPostingListWidget);
        mPostingListWidget->addListItem(ListItem::MessagePosting);
        break;
    case MessagePage::Chat:

        break;
    }
}

void BCMessageWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.drawRect(0,108,this->width(),2);
}

void BCMessageWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    int buttonWidth = (this->width() - 150)/2;

    mChatListButton->setGeometry(75,50,buttonWidth,60);
    mPostingListButton->setGeometry(mChatListButton->pos().x() + mChatListButton->width(),50,
                                    buttonWidth,60);

    mHasBeenReadButton->setGeometry(this->width() - 275,120,200,50);

    mStackedWidget->setGeometry(75,180,this->width() - 150,this->height() - 180);

    initStyle();
}

void BCMessageWidget::slotMessageButtonClicked()
{
    if(sender() == mChatListButton)
    {
        mChatListButton->setColorStyle("qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                       "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                       "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                       "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                       "#333333",QString("2,2,2,0").split(","),
                                       QString("#F7BB64,#F7BB64,#F7BB64,#F7BB64").split(","),0);
        mPostingListButton->setColorStyle("qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                          "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                          "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                          "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                          "#333333",QString("0,0,0,2").split(","),
                                          QString("transparent,transparent,transparent,#F7BB64").split(","),0);
        mChatListButton->setFontStyle(25);
        mPostingListButton->setFontStyle(25);
        showPage(MessagePage::ChatList);
    }
    else if(sender() == mPostingListButton)
    {
        mPostingListButton->setColorStyle("qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                          "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                          "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                          "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                          "#333333",QString("2,2,2,0").split(","),
                                          QString("#F7BB64,#F7BB64,#F7BB64,#F7BB64").split(","),0);
        mChatListButton->setColorStyle("qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                       "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                       "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                       "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                       "#333333",QString("0,0,0,2").split(","),
                                       QString("transparent,transparent,transparent,#F7BB64").split(","),0);
        mChatListButton->setFontStyle(25);
        mPostingListButton->setFontStyle(25);
        showPage(MessagePage::PostingList);
    }
}

void BCMessageWidget::slotHasBeenReadButtonClicked()
{
    if(mStackedWidget->currentWidget() == mChatListWidget)
    {
        mChatListWidget->setMessageChatListHasBeenRead();
    }
    else if(mStackedWidget->currentWidget() == mPostingListWidget)
    {
        mPostingListWidget->setMessagePostingListHasBeenRead();
    }
}

void BCMessageWidget::init()
{
    mChatListButton = new BCPolymorphicButton(this);
    mPostingListButton = new BCPolymorphicButton(this);

    mHasBeenReadButton = new BCPolymorphicButton(this);

    mChatListButton->setText(QStringLiteral("私信消息"));
    mPostingListButton->setText(QStringLiteral("帖子消息"));

    mStackedWidget = new QStackedWidget(this);

    addPage(MessagePage::ChatList);
    addPage(MessagePage::PostingList);
}

void BCMessageWidget::initStyle()
{
    mChatListButton->setColorStyle("qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                   "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                   "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                   "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,1), stop:1 rgb(255,255,255))",
                                   "#333333",QString("2,2,2,0").split(","),
                                   QString("#F7BB64,#F7BB64,#F7BB64,#F7BB64").split(","),0);
    mPostingListButton->setColorStyle("qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                      "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                      "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                      "qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(247,187,100,0.5), stop:1 rgb(255,255,255))",
                                      "#333333",QString("0,0,0,2").split(","),
                                      QString("transparent,transparent,transparent,#F7BB64").split(","),0);
    mChatListButton->setFontStyle(25);
    mPostingListButton->setFontStyle(25);

    mHasBeenReadButton->setColorStyle("transparent","transparent","transparent","transparent",
                                      "#333333",2,"rgb(247,187,100,)",
                                      QString("%1,%1,%1,%1").arg(mHasBeenReadButton->height()/2).split(","));
    mHasBeenReadButton->setFontStyle(25);
    mHasBeenReadButton->setText(QStringLiteral("一键标记已读"));
}

void BCMessageWidget::initConnect()
{
    connect(mChatListButton,&BCPolymorphicButton::clicked,this,&BCMessageWidget::slotMessageButtonClicked);
    connect(mPostingListButton,&BCPolymorphicButton::clicked,this,&BCMessageWidget::slotMessageButtonClicked);
    connect(mHasBeenReadButton,&BCPolymorphicButton::clicked,this,&BCMessageWidget::slotHasBeenReadButtonClicked);
}

void BCMessageWidget::addPage(MessagePage::BCMessagePageEnum page)
{
    switch(page)
    {
    case MessagePage::ChatList:
    {
        mChatListWidget = new BCListWidget(this);
        mStackedWidget->addWidget(mChatListWidget);
        break;
    }
    case MessagePage::PostingList:
    {
        mPostingListWidget = new BCListWidget(this);
        mStackedWidget->addWidget(mPostingListWidget);
        break;
    }
    case MessagePage::Chat:
    {

        break;
    }
    }
}
