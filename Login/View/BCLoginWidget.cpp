#include "BCLoginWidget.h"
#include <QFont>
#include <QPainter>
#include <QPushButton>
#include "BCToastTips.h"
#include "BCMainWindow.h"
#include "BCLoginInputWidget.h"
#include "BCRegisterWidget.h"

BCLoginWidget::BCLoginWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initConnect();
}

void BCLoginWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.setOpacity(0.7);
    painter.drawRect(0,0,this->width(),this->height());
}

void BCLoginWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    mLoginInputWidget->setGeometry(this->width()/2 - 466/2,this->height()/2 - 475/2,466,475);

    mRegisterWidget->setGeometry(this->width()/2 - 1000/2,this->height()/2 - 700/2,1000,700);
}

void BCLoginWidget::init()
{
    mLoginInputWidget = new BCLoginInputWidget(this);

    mRegisterWidget = new BCRegisterWidget(this);
    mRegisterWidget->hide();
}

void BCLoginWidget::initConnect()
{
    connect(mLoginInputWidget,&BCLoginInputWidget::sigLoginButtonClicked,this,[this](){
//        if(mLoginInputWidget->getUserPhoneLineEdit()->isEmpty())
//        {
//            BCToastTips::Instance().initData(QStringLiteral("请输入手机号~"));
//        }
//        else if(mLoginInputWidget->getPasswordLineEdit()->isEmpty())
//        {
//            BCToastTips::Instance().initData(QStringLiteral("请输入密码~"));
//        }
//        else if(!mLoginInputWidget->getPasswordLineEdit()->isEmpty()
//                && !mLoginInputWidget->getUserPhoneLineEdit()->isEmpty())
//        {
//            if(mLoginInputWidget->getUserPhoneLineEdit()->isMaxInputLength())
//            {
//                BCToastTips::Instance().initData(QStringLiteral("请输入正确的手机号！"));
//            }
//            else if (mLoginInputWidget->getPasswordLineEdit()->isMaxInputLength())
//            {
//                BCToastTips::Instance().initData(QStringLiteral("请输入6~12位字符，支持数字、字母、数字和字母组合。"));
//            }
//            else
//            {
                BCMainWindow::instance()->showBasePage(BasePage::MainWindow);
//            }
//        }
    });

    connect(mLoginInputWidget,&BCLoginInputWidget::sigRegisterButtonClicked,this,[this](){
        mLoginInputWidget->reset();
        mLoginInputWidget->hide();
        mRegisterWidget->show();
    });

    connect(mRegisterWidget,&BCRegisterWidget::sigRegisterCloseButtonClicked,this,[this](){
        mRegisterWidget->hide();
        mLoginInputWidget->reset();
        mLoginInputWidget->show();
    });
}
