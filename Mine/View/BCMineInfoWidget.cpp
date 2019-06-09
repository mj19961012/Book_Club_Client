#include "BCMineInfoWidget.h"
#include "BCMainWindow.h"
#include "BCDataManager.h"

BCMineInfoWidget::BCMineInfoWidget(QWidget *parent)
    :QWidget (parent)
{
    init();
    initConnect();
}

void BCMineInfoWidget::initData()
{
    auto user = BCDataManager::instance().getCurrentLoginUserInfo();
    setHeadImage(QString().fromStdString(user.getheadImage()));
    setName(QString().fromStdString(user.getnickName()));
    auto city = BCDataManager::instance().getBCCityNameWithId(QString().fromStdString(user.getCity()));
    setCity(city);
    setSchool(QString().fromStdString(user.getSchool()));
    setPhone(QString().fromStdString(user.getphoneNumber()));
    setPassword(QStringLiteral("******"));
    setFansNum(QString::number(user.getfunsNumber()));
}

void BCMineInfoWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void BCMineInfoWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mHeadImageView->setGeometry(this->width()/2 - 50,100,100,100);
    mNameLabel->setGeometry(0,250,this->width(),50);
    mCityLabel->setGeometry(0,400,this->width(),30);
    mSchoolLabel->setGeometry(0,470,this->width(),30);
    mPhoneLabel->setGeometry(0,540,this->width(),30);
    mPasswordLabel->setGeometry(0,610,this->width(),30);
    mFansNumLabel->setGeometry(0,680,this->width(),30);

    mEditInfoButton->setGeometry(this->width() - 200,100,200,50);
    mLogoutButton->setGeometry(this->width()/2 - 150,800,300,50);

    initStyle();
}

void BCMineInfoWidget::slotLogoutButtonClicked()
{
    BCMainWindow::instance()->showBasePage(BasePage::Login);
    BCDataManager::instance().release();
}

void BCMineInfoWidget::init()
{
    mHeadImageView = new BCImageView(this);
    mNameLabel = new BCPolymorphicLabel(this);
    mCityLabel = new BCPolymorphicLabel(this);
    mSchoolLabel = new BCPolymorphicLabel(this);
    mPhoneLabel = new BCPolymorphicLabel(this);
    mPasswordLabel = new BCPolymorphicLabel(this);
    mFansNumLabel = new BCPolymorphicLabel(this);

    mEditInfoButton = new BCPolymorphicButton(this);
    mLogoutButton = new BCPolymorphicButton(this);
}

void BCMineInfoWidget::initStyle()
{
    mNameLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mNameLabel->setFontStyle(35,63);
    mCityLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mCityLabel->setFontStyle(25);
    mSchoolLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mSchoolLabel->setFontStyle(25);
    mPhoneLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mPhoneLabel->setFontStyle(25);
    mPasswordLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mPasswordLabel->setFontStyle(25);
    mFansNumLabel->setStyle("transparent","#333333",Qt::AlignCenter);
    mFansNumLabel->setFontStyle(25);

    mEditInfoButton->setText(QStringLiteral("编辑信息"));
    mEditInfoButton->setFontStyle(22);
    mEditInfoButton->setColorStyle("rgb(247,187,100,255)",
                                   "rgb(247,187,100,178)",
                                   "rgb(247,187,100,255)",
                                   "#656C81",
                                   "rgb(255,255,255)",
                                   0,
                                   "transparent",mEditInfoButton->height()/2);

    mLogoutButton->setText(QStringLiteral("退出登录"));
    mLogoutButton->setFontStyle(22);
    mLogoutButton->setColorStyle("rgb(247,187,100,255)",
                                 "rgb(247,187,100,178)",
                                 "rgb(247,187,100,255)",
                                 "#656C81",
                                 "rgb(255,255,255)",
                                 0,
                                 "transparent",mLogoutButton->height()/2);
}

void BCMineInfoWidget::initConnect()
{
    connect(mEditInfoButton,&BCPolymorphicButton::clicked,this,&BCMineInfoWidget::sigEditInfo);
    connect(mLogoutButton,&BCPolymorphicButton::clicked,this,&BCMineInfoWidget::slotLogoutButtonClicked);
}

void BCMineInfoWidget::setHeadImage(const QString &image)
{
    mHeadImageView->setImage(image);
}

void BCMineInfoWidget::setName(const QString &name)
{
    mNameLabel->setText(name);
}

void BCMineInfoWidget::setCity(const QString &city)
{
    mCityLabel->setText(QStringLiteral("所在城市：") + city);
}

void BCMineInfoWidget::setSchool(const QString &school)
{
    mSchoolLabel->setText(QStringLiteral("所在学校：") + school);
}

void BCMineInfoWidget::setPhone(const QString &phone)
{
    mPhoneLabel->setText(QStringLiteral("电话号码：") + phone);
}

void BCMineInfoWidget::setPassword(const QString &password)
{
    mPasswordLabel->setText(QStringLiteral("密码：") + password);
}

void BCMineInfoWidget::setFansNum(const QString &num)
{
    mFansNumLabel->setText(QStringLiteral("粉丝数量：") + num);
}
