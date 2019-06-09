#include "BCActivityDetailWidget.h"
#include <QScrollBar>
#include <QDateTime>
#include "BCMainWindow.h"
#include "BCDataManager.h"
#include "BCMessageManager.h"
#include "BCToastTips.h"

BCActivityDetailWidget::BCActivityDetailWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initConnect();
}

void BCActivityDetailWidget::initData(const QString &id)
{
    auto action = BCDataManager::instance().getActionInfoWithId(id);
    auto user = BCDataManager::instance().getPersonalInformationWithId(action.getauthorId().c_str());
    setImage(user.getheadImage().c_str());
    setName(user.getnickName().c_str());
    setActivityName(action.getactionTitle().c_str());
    QString cityName = BCDataManager::instance().getBCCityNameWithId(QString::fromStdString(action.getactionCity()));
    setCity(cityName);
    QString begin = QDateTime::fromTime_t(QString::fromStdString(action.getbeginTime()).toUInt()).toString("yyyy-MM-dd");
    QString end = QDateTime::fromTime_t(QString::fromStdString(action.getendTime()).toUInt()).toString("yyyy-MM-dd");
    QString date = QStringLiteral("活动时间：") + begin + QStringLiteral(" 至 ") + end;
    auto currentUser = BCDataManager::instance().getCurrentLoginUserInfo();

    if(currentUser.getuserId() == user.getuserId())
    {
        mAttentionButton->hide();
    }
    else
    {
        BCDataManager::instance().setUpLoadInterest(QString().fromStdString(currentUser.getuserId()),QString().fromStdString(user.getuserId()));
    }

    setDate(date);
    setContent(action.getactionContent().c_str());

    initGeometry();
}

void BCActivityDetailWidget::receiveOperationResult(bool isSuccess, Page::BCPageEnum pageEnum)
{
    qDebug() << "BCActivityDetailWidget::receiveOperationResult" << "\n";
    switch (pageEnum)
    {
        case Page::Interest:
        {
            if(isSuccess)
            {
                BCToastTips::Instance().setToastTip(QStringLiteral("关注成功!"));
                auto user = BCDataManager::instance().getCurrentLoginUserInfo();
                BCDataManager::instance().setUpLoadMineFocus(QString().fromStdString(user.getuserId()));
                emit doInterestSomeBody(Page::BCPageEnum::MineFocus);
            }
            else
            {
                QString errorMsg = BCDataManager::instance().getErrorMsg();
                BCToastTips::Instance().setToastTip(errorMsg);
            }
            break;
        }
    }
}

void BCActivityDetailWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCActivityDetailWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    initGeometry();
}

void BCActivityDetailWidget::init()
{
    mBackButton = new BCPolymorphicButton(this);
    mImageView = new BCImageView(this);
    mNameLabel = new BCPolymorphicLabel(this);
    mAttentionButton = new BCPolymorphicButton(this);

    mActivityNameLabel = new BCPolymorphicLabel(this);
    mCityLabel = new BCPolymorphicLabel(this);
    mDateTimeLabel = new BCPolymorphicLabel(this);

    mContentTextBrowser = new QTextBrowser(this);
}

void BCActivityDetailWidget::initStyle()
{
    mBackButton->setImageStyle(":/res/common/back.png");

    mImageView->setDefaultImage(":/res/common/defaultHeadImage.png");

    mNameLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mNameLabel->setFontStyle(30,75);

    mAttentionButton->setColorStyle("rgba(247,187,100,1)",
                                    "rgba(247,187,100,0.8)",
                                    "rgba(247,187,100,1)",
                                    "rgba(247,187,100,1)",
                                    "white",0,"transparent",24);
    mAttentionButton->setFontStyle(20);
    mAttentionButton->setText(QStringLiteral("关注"));

    mActivityNameLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mActivityNameLabel->setFontStyle(30,75);

    mCityLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mCityLabel->setFontStyle(18,25);

    mDateTimeLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mDateTimeLabel->setFontStyle(18,25);

    QFont font;
    font.setFamily("Microsoft Yahei");
    font.setPixelSize(20);
    mContentTextBrowser->setFont(font);
    mContentTextBrowser->setObjectName("mContentLabel");
    mContentTextBrowser->setStyleSheet("QWidget#mContentLabel{"
                                       "border:0px;"
                                       "}");
    mContentTextBrowser->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"
                                                            "width:8px;"
                                                            "background:rgba(0,0,0,0%);"
                                                            "margin:0px,0px,0px,0px;"
                                                            "padding-top:0px;"
                                                            "padding-bottom:0px;"
                                                            "}"
                                                            "QScrollBar::handle:vertical{"
                                                            "width:8px;"
                                                            "background:rgba(0,0,0,50%);"
                                                            "border-radius:4px;"
                                                            "min-height:20;"
                                                            "}"
                                                            "QScrollBar::add-line:vertical{"
                                                            "height:0px;width:0px;"
                                                            "subcontrol-position:bottom;"
                                                            "}"
                                                            "QScrollBar::sub-line:vertical{"
                                                            "height:0px;width:0px;"
                                                            "subcontrol-position:top;"
                                                            "}");
}

void BCActivityDetailWidget::initGeometry()
{
    initStyle();

    mBackButton->setGeometry(75,25,50,50);

    mImageView->setGeometry(75,100,100,100);
    mNameLabel->setMinimumHeight(100);
    mNameLabel->adjustSize();
    mNameLabel->move(mImageView->pos().x() + mImageView->width() + 20,100);
    mAttentionButton->setGeometry(this->width() - 175,125,100,50);

    mActivityNameLabel->adjustSize();
    mActivityNameLabel->move(75,210);
    mCityLabel->adjustSize();
    mCityLabel->move(75,mActivityNameLabel->pos().y() + mActivityNameLabel->height() + 10);
    mDateTimeLabel->adjustSize();
    mDateTimeLabel->move(mCityLabel->pos().x() + mCityLabel->width() + 20,
                         mActivityNameLabel->pos().y() + mActivityNameLabel->height() + 10);

    mContentTextBrowser->setGeometry(75,300,this->width() - 150,this->height() - 150);
}

void BCActivityDetailWidget::initConnect()
{
    connect(mBackButton,&BCPolymorphicButton::clicked,this,[](){
        BCMainWindow::instance()->showPage(Page::Activity);
    });
    connect(this,&BCActivityDetailWidget::doInterestSomeBody,BCMessageManager::getInstance(),&BCMessageManager::getPageVlaues);
    connect(mAttentionButton,&BCPolymorphicButton::clicked,this,[this](){
        emit doInterestSomeBody(Page::BCPageEnum::Interest);
    });
    connect(BCMessageManager::getInstance(),&BCMessageManager::sendOperationResultSignal,this,&BCActivityDetailWidget::receiveOperationResult);
}

void BCActivityDetailWidget::setImage(const QString &image)
{
    mImageView->setImage(image);
}

void BCActivityDetailWidget::setName(const QString &name)
{
    mNameLabel->setText(name);
}

void BCActivityDetailWidget::setActivityName(const QString &name)
{
    mActivityNameLabel->setText(name);
}

void BCActivityDetailWidget::setCity(const QString &city)
{
    mCityLabel->setText(city);
}

void BCActivityDetailWidget::setDate(const QString &date)
{
    mDateTimeLabel->setText(date);
}

void BCActivityDetailWidget::setContent(const QString &content)
{
    mContentTextBrowser->setText(content);
}
