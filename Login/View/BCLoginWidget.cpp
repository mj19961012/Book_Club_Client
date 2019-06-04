#include "BCLoginWidget.h"
#include <QFont>
#include <QPainter>
#include <QPushButton>
#include "BCToastTips.h"
#include "BCMainWindow.h"
#include "BCLoginInputWidget.h"
#include "BCRegisterWidget.h"
#include "BCDataManager.h"
#include "BCMessageManager.h"

BCLoginWidget::BCLoginWidget(QWidget *parent)
    :QWidget(parent)
{
    init();
    initConnect();
}

void BCLoginWidget::receiveOperationResult(bool isSuccess, Page::BCPageEnum pageEnum)
{
    switch (pageEnum)
    {
        case Page::PersonalInformation:
            {
                if(isSuccess)
                {
                    qDebug() << "Login Success" << "\n";
                    BCToastTips::Instance().setToastTip(QStringLiteral("尊敬的用户，恭喜您登录成功"));
                    qDebug() << "getCurrentLoginUserInfo:" << BCDataManager::instance().getCurrentLoginUserInfo().getheadImage().c_str() << "\n";
                    BCMainWindow::instance()->showBasePage(BasePage::MainWindow);
                }
                else
                {
                    QString errorMsg = BCDataManager::instance().getErrorMsg();
                    BCToastTips::Instance().setToastTip(errorMsg);
                }
                break;
            }
        default:
        {
            return;
        }
    }
}

void BCLoginWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    painter.setBrush(QColor(247,187,100));
    painter.setOpacity(0.3);
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
    connect(this,SIGNAL(doLoginSignal(Page::BCPageEnum)),BCMessageManager::getInstance(),SLOT(getPageVlaues(Page::BCPageEnum)));
    connect(mLoginInputWidget,&BCLoginInputWidget::sigLoginButtonClicked,this,[this](){
        if(mLoginInputWidget->getUserPhoneLineEdit()->isEmpty())
        {
            BCToastTips::Instance().setToastTip(QStringLiteral("请输入手机号~"));
        }
        else if(mLoginInputWidget->getPasswordLineEdit()->isEmpty())
        {
            BCToastTips::Instance().setToastTip(QStringLiteral("请输入密码~"));
        }
        else if(!mLoginInputWidget->getPasswordLineEdit()->isEmpty()
                && !mLoginInputWidget->getUserPhoneLineEdit()->isEmpty())
        {
            if(mLoginInputWidget->getUserPhoneLineEdit()->isMaxInputLength())
            {
                BCToastTips::Instance().setToastTip(QStringLiteral("请输入正确的手机号！"));
            }
            else if (mLoginInputWidget->getPasswordLineEdit()->isMaxInputLength())
            {
                BCToastTips::Instance().setToastTip(QStringLiteral("请输入6~12位字符，支持数字、字母、数字和字母组合。"));
            }
            else
            {
                QString username = mLoginInputWidget->getUserPhoneLineEdit()->getInputText();
                QString password = mLoginInputWidget->getPasswordLineEdit()->getInputText();
                qDebug() << "username:" << username << "\n";
                qDebug() << "password:" << password << "\n";
                BCDataManager::instance().setUpLoadPersonalInformation(username,password);
                emit doLoginSignal(Page::BCPageEnum::PersonalInformation);
                BCMainWindow::instance()->showPage(Page::Postings);
            }
        }
//        BCMainWindow::instance()->showBasePage(BasePage::MainWindow);
    });
    connect(BCMessageManager::getInstance(),SIGNAL(sendOperationResultSignal(bool,Page::BCPageEnum)),this,SLOT(receiveOperationResult(bool,Page::BCPageEnum)));

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
