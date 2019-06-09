#include "BCMessageChatWidget.h"
#include <QPainter>
#include "BCMainWindow.h"
#include "BCToastTips.h"
#include "BCDataManager.h"
#include "BCMessageManager.h"

BCMessageChatWidget::BCMessageChatWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initConnect();
}

void BCMessageChatWidget::initData()
{
    auto chatInfo = BCDataManager::instance().getUpLoadChat();
    auto sessionUser = BCDataManager::instance().getPersonalInformationWithId(chatInfo.accepterid);
    qDebug() << "sessionUserId:" << sessionUser.getuserId().c_str() << "--nickname:" << QString().fromStdString(sessionUser.getnickName()) << "\n";
    setName(QString().fromStdString(sessionUser.getnickName()));
    mChatListWidget->addListItem(ListItem::MessageChatBubble);
}

void BCMessageChatWidget::receiveOperationResult(bool isSuccess, Page::BCPageEnum pageEnum)
{
    qDebug() << "BCMessageChatWidget::receiveOperationResult" << "\n";
    switch (pageEnum)
    {
        case Page::Chat:
        {
            if(!isSuccess)
            {
                QString errorMsg = BCDataManager::instance().getErrorMsg();
                BCToastTips::Instance().setToastTip(errorMsg);
                return;
            }
            mChatListWidget->addListItem(ListItem::MessageChatBubble);
            break;
        }
    }
}

void BCMessageChatWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setPen(QPen(QColor(247,187,100),4));
    painter.setBrush(Qt::transparent);
    painter.drawRect(73,148,this->width() - 146,674);
}

void BCMessageChatWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mBackButton->setGeometry(75,25,50,50);
    mNameLabel->setGeometry(75,100,this->width() - 150,50);
    mChatListWidget->setGeometry(75,150,this->width() - 150,670);
    mInputWidget->setGeometry(75,850,this->width() - 150,150);

    initStyle();
}

void BCMessageChatWidget::init()
{
    mBackButton = new BCPolymorphicButton(this);
    mNameLabel = new BCPolymorphicLabel(this);
    mChatListWidget = new BCListWidget(this);
    mInputWidget = new BCInputWidget(this);
}

void BCMessageChatWidget::initStyle()
{
    mBackButton->setImageStyle(":/res/common/back.png");
    mNameLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mNameLabel->setFontStyle(30,63);
}

void BCMessageChatWidget::initConnect()
{
    connect(mBackButton,&BCPolymorphicButton::clicked,this,[](){
        BCMainWindow::instance()->showPage(Page::Message);
    });
    connect(mInputWidget,&BCInputWidget::onSubmitButtonClicked,this,[this](){
        auto chat = BCDataManager::instance().getUpLoadChat();
        chat.sessionid = chat.accepterid;
        chat.messgaebody = mInputWidget->getInputContent();
        chat.messagetype = 1;
        mInputWidget->clearInputContent();
        BCDataManager::instance().setUpLoadChat(chat.messgaebody,chat.senderid,chat.accepterid,chat.sessionid,chat.messagetype);
        emit doSendMessage(Page::BCPageEnum::Chat);
    });
    connect(this,&BCMessageChatWidget::doSendMessage,BCMessageManager::getInstance(),&BCMessageManager::getPageVlaues);
    connect(BCMessageManager::getInstance(),&BCMessageManager::sendOperationResultSignal,this,&BCMessageChatWidget::receiveOperationResult);
}

void BCMessageChatWidget::setName(const QString &name)
{
    mNameLabel->setText(name);
}
