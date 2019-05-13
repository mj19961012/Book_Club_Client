#include "BCLoginInputWidget.h"
#include "BCPolymorphicButton.h"
#include <QFont>
#include <QPainter>

BCLoginInputWidget::BCLoginInputWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initConnect();
}

void BCLoginInputWidget::reset()
{
    mUserPhoneLineEdit->clear();
    mPasswordLineEdit->clear();
}

BCLoginLineEdit *BCLoginInputWidget::getUserPhoneLineEdit() const
{
    return mUserPhoneLineEdit;
}

BCLoginLineEdit *BCLoginInputWidget::getPasswordLineEdit() const
{
    return mPasswordLineEdit;
}

void BCLoginInputWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(255,255,255));
    painter.drawRoundedRect(0,0,this->width(),this->height(),40,40,Qt::AbsoluteSize);

    QPixmap pixmap;
    pixmap.load(":/res/common/start_logo.png");
    painter.drawPixmap(this->width()/2 - 96/2,40,96,100,pixmap.scaled(96,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPixelSize(14);
    painter.setFont(font);
    painter.setPen(QPen(QColor(16,16,16),3));
    painter.drawText(0,155,this->width(),20,Qt::AlignCenter,QStringLiteral("学更多的知识，交更好的朋友，过更丰富的大学生活！"));
}

void BCLoginInputWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mUserPhoneLineEdit->setGeometry(this->width()/2 - 300/2,210,300,60);
    mPasswordLineEdit->setGeometry(this->width()/2 - 300/2,290,300,60);

    mLoginButton->setFontStyle(22,63);
    mLoginButton->setGeometry(this->width()/2 - 200/2,385,200,50);

    mRegisterButton->setGeometry(0,440,this->width(),20);

    initStyle();
}

void BCLoginInputWidget::init()
{
    mUserPhoneLineEdit = new BCLoginLineEdit(this);
    mUserPhoneLineEdit->setImage(":/res/Login/phone.png");
    mUserPhoneLineEdit->setType(Login_LineEdit_Phone);
    mUserPhoneLineEdit->setMaxInputLength(11);
    mUserPhoneLineEdit->setTips(QStringLiteral("请输入手机号..."));

    mPasswordLineEdit = new BCLoginLineEdit(this);
    mPasswordLineEdit->setImage(":/res/Login/password.png");
    mPasswordLineEdit->setType(Login_LineEdit_Password);
    mPasswordLineEdit->setMaxInputLength(12);
    mPasswordLineEdit->setTips(QStringLiteral("请输入密码..."));

    mLoginButton = new BCPolymorphicButton(this);

    mRegisterButton = new BCPolymorphicButton(this);
}

void BCLoginInputWidget::initStyle()
{
    mLoginButton->setText(QStringLiteral("登录"));
    mLoginButton->setFontStyle(22);
    mLoginButton->setColorStyle("rgb(247,187,100,255)",
                                "rgb(247,187,100,178)",
                                "rgb(247,187,100,255)",
                                "#656C81",
                                "rgb(255,255,255)",
                                0,
                                "transparent",mLoginButton->height()/2);

    mRegisterButton->setText(QStringLiteral("没有账号？去注册一个"));
    mRegisterButton->setFontStyle(15);
    mRegisterButton->setColorStyle("transparent",
                                   "transparent",
                                   "transparent",
                                   "transparent",
                                   "skyblue",0,"transparent",0);
}

void BCLoginInputWidget::initConnect()
{
    connect(mLoginButton,&BCPolymorphicButton::clicked,this,[this](){
        emit sigLoginButtonClicked();
    });

    connect(mRegisterButton,&BCPolymorphicButton::clicked,this,[this](){
        emit sigRegisterButtonClicked();
    });
}
