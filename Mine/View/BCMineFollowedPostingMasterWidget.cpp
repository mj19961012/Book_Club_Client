#include "BCMineFollowedPostingMasterWidget.h"

BCMineFollowedPostingMasterWidget::BCMineFollowedPostingMasterWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
    initConnect();
}

void BCMineFollowedPostingMasterWidget::initData()
{
    setHeadImage(QStringLiteral(":/res/common/defaultHeadImage.png"));
    setName(QStringLiteral("土卡拉"));
    setCity(QStringLiteral("土卡拉"));
    setSchool(QStringLiteral("土卡拉"));
    setFansNum(QStringLiteral("666"));

    updateGeometry();
}

void BCMineFollowedPostingMasterWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCMineFollowedPostingMasterWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    updateGeometry();
}

void BCMineFollowedPostingMasterWidget::init()
{
    mBackButton = new BCPolymorphicButton(this);

    mHeadImageView = new BCImageView(this);
    mNameLabel = new BCPolymorphicLabel(this);
    mChatButton = new BCPolymorphicButton(this);
    mChatButton->setText(QStringLiteral("私信"));

    mCityLabel = new BCPolymorphicLabel(this);
    mSchoolLabel = new BCPolymorphicLabel(this);
    mFansNumLabel = new BCPolymorphicLabel(this);
}

void BCMineFollowedPostingMasterWidget::initStyle()
{
    mBackButton->setImageStyle(":/res/common/back.png");

    mNameLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mNameLabel->setFontStyle(35,63);
    mCityLabel->setStyle("transparent","#333333",Qt::AlignLeft | Qt::AlignVCenter);
    mCityLabel->setFontStyle(25);
    mSchoolLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mSchoolLabel->setFontStyle(25);
    mFansNumLabel->setStyle("transparent","#333333",Qt::AlignRight | Qt::AlignVCenter);
    mFansNumLabel->setFontStyle(25);

    mChatButton->setColorStyle("rgba(247,187,100,1)",
                               "rgba(247,187,100,0.8)",
                               "rgba(247,187,100,1)",
                               "rgba(247,187,100,1)",
                               "white",0,"transparent",mChatButton->height()/2);
    mChatButton->setFontStyle(20);
}

void BCMineFollowedPostingMasterWidget::initConnect()
{
    connect(mBackButton,&BCPolymorphicButton::clicked,this,[this](){
        emit sigMineFollowedPostingMasterBack();
    });
}

void BCMineFollowedPostingMasterWidget::updateGeometry()
{
    mBackButton->setGeometry(75,25,50,50);
    mHeadImageView->setGeometry(this->width()/2 - 100,25,100,100);
    mNameLabel->setGeometry(this->width()/2,25,this->width()/2,100);
    mChatButton->setGeometry(this->width() - 300,50,100,50);

    mCityLabel->setGeometry(0,150,this->width(),50);
    mSchoolLabel->setGeometry(0,150,this->width(),50);
    mFansNumLabel->setGeometry(0,150,this->width(),50);

    initStyle();
}

void BCMineFollowedPostingMasterWidget::setHeadImage(const QString &image)
{
    mHeadImageView->setImage(image);
}

void BCMineFollowedPostingMasterWidget::setName(const QString &name)
{
    mNameLabel->setText(name);
}

void BCMineFollowedPostingMasterWidget::setCity(const QString &city)
{
    mCityLabel->setText(QStringLiteral("所在城市：") + city);
}

void BCMineFollowedPostingMasterWidget::setSchool(const QString &school)
{
    mSchoolLabel->setText(QStringLiteral("所在学校：") + school);
}

void BCMineFollowedPostingMasterWidget::setFansNum(const QString &num)
{
    mFansNumLabel->setText(QStringLiteral("粉丝数量：") + num);
}
