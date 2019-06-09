#include "BCPostMasterWidget.h"
#include "BCMainWindow.h"

BCPostMasterWidget::BCPostMasterWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
    initConnect();
}

void BCPostMasterWidget::initData()
{
    setHeadImage(QStringLiteral(":/res/common/defaultHeadImage.png"));
    setName(QStringLiteral("土卡拉"));
    setCity(QStringLiteral("土卡拉"));
    setSchool(QStringLiteral("土卡拉"));
    setPostingsNum(QStringLiteral("66666"));
    setFansNum(QStringLiteral("666"));
    setIsFollow(false);

    updateGeometry();
}

void BCPostMasterWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCPostMasterWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    updateGeometry();
}

void BCPostMasterWidget::init()
{
    mBackButton = new BCPolymorphicButton(this);

    mHeadImageView = new BCImageView(this);
    mNameLabel = new BCPolymorphicLabel(this);
    mCityLabel = new BCPolymorphicLabel(this);
    mSchoolLabel = new BCPolymorphicLabel(this);
    mPostingsNumLabel = new BCPolymorphicLabel(this);
    mFansNumLabel = new BCPolymorphicLabel(this);

    mFollowButton = new BCPolymorphicButton(this);
    mFollowedButton = new BCPolymorphicButton(this);
}

void BCPostMasterWidget::initStyle()
{
    mBackButton->setImageStyle(":/res/common/back.png");

    mNameLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mNameLabel->setFontStyle(35,63);
    mCityLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mCityLabel->setFontStyle(25);
    mSchoolLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mSchoolLabel->setFontStyle(25);
    mPostingsNumLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mPostingsNumLabel->setFontStyle(25);
    mFansNumLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mFansNumLabel->setFontStyle(25);

    mFollowButton->setText(QStringLiteral("关注"));
    mFollowButton->setFontStyle(22);
    mFollowButton->setColorStyle("rgb(247,187,100,255)",
                                 "rgb(247,187,100,178)",
                                 "rgb(247,187,100,255)",
                                 "#656C81",
                                 "rgb(255,255,255)",
                                 0,
                                 "transparent",mFollowButton->height()/2);
    mFollowedButton->setText(QStringLiteral("已关注"));
    mFollowedButton->setFontStyle(22);
    mFollowedButton->setColorStyle("rgb(149,149,149,255)",
                                   "rgb(149,149,149,178)",
                                   "rgb(149,149,149,255)",
                                   "#656C81",
                                   "#333333",
                                   0,
                                   "transparent",mFollowedButton->height()/2);
}

void BCPostMasterWidget::initConnect()
{
    connect(mBackButton,&BCPolymorphicButton::clicked,this,[](){
        BCMainWindow::instance()->showPage(Page::PostDetail);
    });

    connect(mFollowButton,&BCPolymorphicButton::clicked,this,[this](){
        setIsFollow(true);
    });
    connect(mFollowedButton,&BCPolymorphicButton::clicked,this,[this](){
        setIsFollow(false);
    });
}

void BCPostMasterWidget::updateGeometry()
{
    mBackButton->setGeometry(75,25,50,50);

    mHeadImageView->setGeometry(this->width()/2 - 50,100,100,100);
    mNameLabel->setGeometry(0,250,this->width(),50);
    mCityLabel->setGeometry(0,400,this->width(),30);
    mSchoolLabel->setGeometry(0,470,this->width(),30);
    mPostingsNumLabel->setGeometry(0,540,this->width(),30);
    mFansNumLabel->setGeometry(0,610,this->width(),30);

    mFollowButton->setGeometry(this->width()/2 - 100,800,200,50);
    mFollowedButton->setGeometry(this->width()/2 - 100,800,200,50);

    initStyle();
}

void BCPostMasterWidget::setHeadImage(const QString &image)
{
    mHeadImageView->setImage(image);
}

void BCPostMasterWidget::setName(const QString &name)
{
    mNameLabel->setText(name);
}

void BCPostMasterWidget::setCity(const QString &city)
{
    mCityLabel->setText(QStringLiteral("所在城市：") + city);
}

void BCPostMasterWidget::setSchool(const QString &school)
{
    mSchoolLabel->setText(QStringLiteral("所在学校：") + school);
}

void BCPostMasterWidget::setPostingsNum(const QString &num)
{
    mPostingsNumLabel->setText(QStringLiteral("发帖数量：") + num);
}

void BCPostMasterWidget::setFansNum(const QString &num)
{
    mFansNumLabel->setText(QStringLiteral("粉丝数量：") + num);
}

void BCPostMasterWidget::setIsFollow(bool isFollow)
{
    mFollowButton->setVisible(!isFollow);
    mFollowedButton->setVisible(isFollow);
}
